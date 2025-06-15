#include <stdio.h>
#include <string.h>
#include "ast_c.h"

extern FunctionEntry* function_table;

void generate_all_functions(FILE* out) {
    for (FunctionEntry* f = function_table; f; f = f->next) {
        fprintf(out, "void %s() {\n", f->id);
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
                case NODE_INT:
                    fprintf(out, "int %s;\n", node->decl.id);
                    break;
                case NODE_FLOAT:
                    fprintf(out, "float %s;\n", node->decl.id);
                    break;
                case NODE_STRING:
                    fprintf(out, "char %s[100];\n", node->decl.id);
                    break;
                default:
                    break;
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

            NodeType print_type = node->print.value->data_type;

            if (print_type == NODE_INT)
                fprintf(out, "printf(\"%%d\\n\", ");
            else if (print_type == NODE_FLOAT)
                fprintf(out, "printf(\"%%f\\n\", ");
            else
                fprintf(out, "printf(\"%%s\\n\", ");

            generate_code(out, node->print.value);
            fprintf(out, ");\n");
            break;

        case NODE_BINOP:
            fprintf(out, "(");
            generate_code(out, node->binop.left);
            fprintf(out, " %s ", node->binop.op);
            generate_code(out, node->binop.right);
            fprintf(out, ")");
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
            fprintf(out, "%s();\n", node->funccall.id);
            break;

        default:
            break;
    }
}
