#include <stdio.h>
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
            fprintf(out, "%s", node->sval);
            break;
        case NODE_ID:
            fprintf(out, "%s", node->sval);
            break;
        case NODE_DECL:
            switch (node->decl.decl_type) {
                case NODE_INT:
                    fprintf(out, "int %s;
", node->decl.id);
                    break;
                case NODE_FLOAT:
                    fprintf(out, "float %s;
", node->decl.id);
                    break;
                case NODE_STRING:
                    fprintf(out, "char* %s;
", node->decl.id);
                    break;
                default:
                    break;
            }
            break;
        case NODE_ASSIGN:
            fprintf(out, "%s = ", node->assign.id);
            generate_code(out, node->assign.value);
            fprintf(out, ";
");
            break;
        case NODE_PRINT:
            fprintf(out, "printf("");
            if (node->assign.value->type == NODE_INT) fprintf(out, "%%d");
            else if (node->assign.value->type == NODE_FLOAT) fprintf(out, "%%f");
            else fprintf(out, "%%s");
            fprintf(out, "\n", ");
            generate_code(out, node->assign.value);
            fprintf(out, ");
");
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
            fprintf(out, ") {
");
            generate_code(out, node->ifstmt.then_branch);
            fprintf(out, "}
");
            if (node->ifstmt.else_branch) {
                fprintf(out, "else {
");
                generate_code(out, node->ifstmt.else_branch);
                fprintf(out, "}
");
            }
            break;
        case NODE_WHILE:
            fprintf(out, "while (");
            generate_code(out, node->whilestmt.cond);
            fprintf(out, ") {
");
            generate_code(out, node->whilestmt.body);
            fprintf(out, "}
");
            break;
        case NODE_BLOCK:
            for (int i = 0; i < node->block.stmt_count; ++i) {
                generate_code(out, node->block.stmts[i]);
            }
            break;
        default:
            break;
    }
}