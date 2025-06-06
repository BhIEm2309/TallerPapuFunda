#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast_c.h"

Symbol symbol_table[100];
int symbol_count = 0;

void add_symbol(const char* name, int type) {
    symbol_table[symbol_count].name = strdup(name);
    symbol_table[symbol_count].type = type;
    symbol_count++;
}

int get_symbol_type(const char* name) {
    for (int i = 0; i < symbol_count; ++i) {
        if (strcmp(symbol_table[i].name, name) == 0)
            return symbol_table[i].type;
    }
    return NODE_UNKNOWN;
}

/* AST Node Creation */
ASTNode* make_int_node(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_INT;
    node->ival = value;
    return node;
}

ASTNode* make_id_node(const char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ID;
    node->sval = strdup(name);
    return node;
}

ASTNode* make_float_node(float value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FLOAT;
    node->fval = value;
    return node;
}

ASTNode* make_string_node(const char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_STRING;
    node->sval = strdup(value);
    return node;
}

ASTNode* make_binop_node(const char* op, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_BINOP;
    node->binop.op = strdup(op);
    node->binop.left = left;
    node->binop.right = right;
    return node;
}

ASTNode* make_assign_node(const char* id, ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ASSIGN;
    node->assign.id = strdup(id);
    node->assign.value = value;
    return node;
}

ASTNode* make_print_node(ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_PRINT;
    node->assign.value = expr;
    return node;
}

ASTNode* make_decl_node(const char* id, NodeType decl_type) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_DECL;
    node->decl.id = strdup(id);
    node->decl.decl_type = decl_type;
    return node;
}

ASTNode* make_if_node(ASTNode* cond, ASTNode* then_branch, ASTNode* else_branch) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_IF;
    node->ifstmt.cond = cond;
    node->ifstmt.then_branch = then_branch;
    node->ifstmt.else_branch = else_branch;
    return node;
}

ASTNode* make_while_node(ASTNode* cond, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_WHILE;
    node->whilestmt.cond = cond;
    node->whilestmt.body = body;
    return node;
}

ASTNode* make_for_node(ASTNode* init, ASTNode* cond, ASTNode* incr, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FOR;
    node->forstmt.init = init;
    node->forstmt.cond = cond;
    node->forstmt.incr = incr;
    node->forstmt.body = body;
    return node;
}

ASTNode* make_read_node(const char* id, int type) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_READ;
    node->read.id = strdup(id);
    node->read.type = type;
    return node;
}

/* Code generation */
void generate_code(FILE* out, ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_INT: fprintf(out, "%d", node->ival); break;
        case NODE_FLOAT: fprintf(out, "%f", node->fval); break;
        case NODE_STRING: fprintf(out, "%s", node->sval); break;
        case NODE_ID: fprintf(out, "%s", node->sval); break;

        case NODE_DECL:
            switch (node->decl.decl_type) {
                case NODE_INT: fprintf(out, "int %s;\n", node->decl.id); break;
                case NODE_FLOAT: fprintf(out, "float %s;\n", node->decl.id); break;
                case NODE_STRING: fprintf(out, "char %s[100];\n", node->decl.id); break;
                default: break;
            }
            break;

        case NODE_ASSIGN:
            fprintf(out, "%s = ", node->assign.id);
            generate_code(out, node->assign.value);
            fprintf(out, ";\n");
            break;

        case NODE_PRINT:
            if (node->assign.value->type == NODE_INT)
                fprintf(out, "printf(\"%%d\\n\", ");
            else if (node->assign.value->type == NODE_FLOAT)
                fprintf(out, "printf(\"%%f\\n\", ");
            else if (node->assign.value->type == NODE_STRING)
                fprintf(out, "printf(\"%%s\\n\", ");
            else if (node->assign.value->type == NODE_ID) {
                int tipo = get_symbol_type(node->assign.value->sval);
                if (tipo == NODE_INT)
                    fprintf(out, "printf(\"%%d\\n\", ");
                else if (tipo == NODE_FLOAT)
                    fprintf(out, "printf(\"%%f\\n\", ");
                else
                    fprintf(out, "printf(\"%%s\\n\", ");
            } else {
                fprintf(out, "printf(\"<?>\\n\"");
            }
            generate_code(out, node->assign.value);
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
            generate_code(out, node->forstmt.init);
            fprintf(out, "while (");
            generate_code(out, node->forstmt.cond);
            fprintf(out, ") {\n");
            generate_code(out, node->forstmt.body);
            generate_code(out, node->forstmt.incr);
            fprintf(out, ";\n");
            fprintf(out, "}\n");
            break;
        case NODE_BLOCK:
            for (int i = 0; i < node->block.stmt_count; ++i) {
                generate_code(out, node->block.stmts[i]);
            }
            break;

        case NODE_READ:
            switch (get_symbol_type(node->read.id)) {
                case NODE_INT:
                    fprintf(out, "scanf(\"%%d\", &%s);\n", node->read.id);
                    break;
                case NODE_FLOAT:
                    fprintf(out, "scanf(\"%%f\", &%s);\n", node->read.id);
                    break;
                case NODE_STRING:
                    fprintf(out, "scanf(\"%%s\", %s);\n", node->read.id);
                    break;
                default:
                    fprintf(out, "/* Error: tipo no reconocido para scanf */\n");
                    break;
            }
            break;

        default: break;
    }
}