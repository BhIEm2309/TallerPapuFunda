#include <stdio.h>
#include <string.h>
#include "ast_c.h"

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
                fprintf(out, "strcpy(%s, ", node->assign.id);
                generate_code(out, node->assign.value);
                fprintf(out, ");\n");
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
        case NODE_FUNC_DEF:
            fprintf(out, "void %s() {\n", node->func_def.name);
            generate_code(out, node->func_def.body);
            fprintf(out, "}\n");
            break;

        case NODE_FUNC_CALL:
            fprintf(out, "%s();\n", node->func_call.name);
            break;
        case NODE_RETURN:
            fprintf(out, "return ");
            generate_code(out, node->retstmt.value);
            fprintf(out, ";\n");
            break;
        default:
            break;
    }
}
