#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast_c.h"

extern FunctionEntry* function_table;

void generate_all_functions(FILE* out) {
    for (FunctionEntry* f = function_table; f; f = f->next) {
        fprintf(out, "int %s(", f->id);
        for (int i = 0; i < f->param_count; ++i) {
            ASTNode* param = f->params[i];
            if (i > 0) fprintf(out, ", ");
            if (param->decl.decl_type == NODE_INT)
                fprintf(out, "int %s", param->decl.id);
            else if (param->decl.decl_type == NODE_FLOAT)
                fprintf(out, "float %s", param->decl.id);
            else if (param->decl.decl_type == NODE_STRING)
                fprintf(out, "char* %s", param->decl.id);
        }
        fprintf(out, ") {\n");
        generate_code(out, f->body);
        fprintf(out, "}\n\n");
    }
}

void generate_code(FILE* out, ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_INT:
            fprintf(out, "%d", node->ival);
            break;

        case NODE_FLOAT:
            fprintf(out, "%f", node->fval);
            break;

        case NODE_STRING:
            fprintf(out, "\"%s\"", node->sval);
            break;

        case NODE_ID:
            fprintf(out, "%s", node->sval);
            break;

        case NODE_DECL:
            switch (node->decl.decl_type) {
                case NODE_INT: fprintf(out, "int %s;\n", node->decl.id); break;
                case NODE_FLOAT: fprintf(out, "float %s;\n", node->decl.id); break;
                case NODE_STRING: fprintf(out, "char %s[100];\n", node->decl.id); break;
                default: break;
            }
            break;

        case NODE_ASSIGN: {
            Symbol* symbol = get_symbol(node->assign.id);
            if (symbol && symbol->type == NODE_STRING) {
                if (node->assign.value->type == NODE_BINOP &&
                    strcmp(node->assign.value->binop.op, "+") == 0 &&
                    node->assign.value->binop.left->data_type == NODE_STRING &&
                    node->assign.value->binop.right->data_type == NODE_STRING) {

                    fprintf(out, "char __temp_concat[200];\n");
                    fprintf(out, "strcpy(__temp_concat, ");
                    generate_code(out, node->assign.value->binop.left);
                    fprintf(out, ");\n");
                    fprintf(out, "strcat(__temp_concat, ");
                    generate_code(out, node->assign.value->binop.right);
                    fprintf(out, ");\n");
                    fprintf(out, "strcpy(%s, __temp_concat);\n", node->assign.id);
                } else {
                    fprintf(out, "strcpy(%s, ", node->assign.id);
                    generate_code(out, node->assign.value);
                    fprintf(out, ");\n");
                }
            } else {
                fprintf(out, "%s = ", node->assign.id);
                generate_code(out, node->assign.value);
                fprintf(out, ";\n");
            }
            break;
        }

        case NODE_PRINT:
            if (!node->print.value) break;
            switch (node->print.value->data_type) {
                case NODE_INT: fprintf(out, "printf(\"%%d\\n\", "); break;
                case NODE_FLOAT: fprintf(out, "printf(\"%%f\\n\", "); break;
                case NODE_STRING: fprintf(out, "printf(\"%%s\\n\", "); break;
                default: break;
            }
            generate_code(out, node->print.value);
            fprintf(out, ");\n");
            break;

        case NODE_READ: {
            Symbol* sym = get_symbol(node->sval);
            if (!sym) {
                fprintf(stderr, "Error: variable '%s' no declarada para lectura.\n", node->sval);
                exit(1);
            }

            fprintf(out, "{\n");
            fprintf(out, "  char __input_buf[100];\n");
            fprintf(out, "  fgets(__input_buf, sizeof(__input_buf), stdin);\n");

            if (sym->type == NODE_INT) {
                fprintf(out, "  if (sscanf(__input_buf, \"%%d\", &%s) != 1) {\n", node->sval);
                fprintf(out, "    fprintf(stderr, \"Error: se esperaba un número entero para '%s'.\\n\");\n", node->sval);
                fprintf(out, "    exit(1);\n");
                fprintf(out, "  }\n");
            } else if (sym->type == NODE_FLOAT) {
                fprintf(out, "  if (sscanf(__input_buf, \"%%f\", &%s) != 1) {\n", node->sval);
                fprintf(out, "    fprintf(stderr, \"Error: se esperaba un número decimal para '%s'.\\n\");\n", node->sval);
                fprintf(out, "    exit(1);\n");
                fprintf(out, "  }\n");
            } else if (sym->type == NODE_STRING) {
                fprintf(out, "  sscanf(__input_buf, \"%%s\", %s);\n", node->sval);
            } else {
                fprintf(out, "  fprintf(stderr, \"Error: tipo no soportado para lectura.\\n\");\n");
                fprintf(out, "  exit(1);\n");
            }

            fprintf(out, "}\n");
            break;
        }

        case NODE_BINOP:
            if ((strcmp(node->binop.op, "/") == 0 || strcmp(node->binop.op, "%") == 0)) {
                
                fprintf(out, "({ ");
                fprintf(out, "int __right; ");
                fprintf(out, "__right = ");
                generate_code(out, node->binop.right);
                fprintf(out, "; ");
                fprintf(out, "if (__right == 0) { fprintf(stderr, \"Error: división por cero.\\n\"); exit(1); } ");
                generate_code(out, node->binop.left);
                fprintf(out, " %s __right; ", node->binop.op);
                fprintf(out, "})");
            } else {
                fprintf(out, "(");
                generate_code(out, node->binop.left);
                fprintf(out, " %s ", node->binop.op);
                generate_code(out, node->binop.right);
                fprintf(out, ")");
            }
            break;

        case NODE_IF:
            fprintf(out, "if (");
            generate_code(out, node->ifstmt.cond);
            fprintf(out, ") {\n");
            generate_code(out, node->ifstmt.then_branch);
            fprintf(out, "}\n");
            if (node->ifstmt.else_branch) {
                fprintf(out, "else {\n");
                generate_code(out, node->ifstmt.else_branch);
                fprintf(out, "}\n");
            }
            break;

        case NODE_WHILE:
            fprintf(out, "while (");
            generate_code(out, node->whilestmt.cond);
            fprintf(out, ") {\n");
            generate_code(out, node->whilestmt.body);
            fprintf(out, "}\n");
            break;

        case NODE_FOR:
            fprintf(out, "{\n");
            generate_code(out, node->forstmt.init);
            fprintf(out, "while (");
            generate_code(out, node->forstmt.cond);
            fprintf(out, ") {\n");
            generate_code(out, node->forstmt.body);
            generate_code(out, node->forstmt.update);
            fprintf(out, "}\n");
            fprintf(out, "}\n");
            break;

        case NODE_BLOCK:
            for (int i = 0; i < node->block.stmt_count; ++i) {
                generate_code(out, node->block.stmts[i]);
            }
            break;

        case NODE_FUNCCALL:
            fprintf(out, "%s(", node->funccall.id);
            for (int i = 0; i < node->funccall.arg_count; ++i) {
                if (i > 0) fprintf(out, ", ");
                generate_code(out, node->funccall.args[i]);
            }
            fprintf(out, ");\n");
            break;

        case NODE_RETURN:
            fprintf(out, "return ");
            generate_code(out, node->returnstmt.value);
            fprintf(out, ";\n");
            break;

        default:
            break;
    }
}
