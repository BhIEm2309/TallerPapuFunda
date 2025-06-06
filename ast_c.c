#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast_c.h"

ASTNode* make_int_node(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_INT;
    node->ival = value;
    return node;
}

ASTNode* make_id_node(const char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ID;      // Ya está bien
    node->sval = strdup(name);
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

ASTNode* make_for_node(ASTNode* init, ASTNode* condition, ASTNode* increment, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FOR;
    node->forstmt.init = init;
    node->forstmt.cond = condition;
    node->forstmt.incr = increment;
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

void print_indent(int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
}

void print_ast(ASTNode* node, int indent) 
{
    if (!node) return;

    print_indent(indent);
    switch (node->type) {
        case NODE_INT:
            printf("Int: %d\n", node->ival);
            break;
        case NODE_ID:
            printf("Id: %s\n", node->sval);
            break;
        case NODE_BINOP:
            printf("Op: %s\n", node->binop.op);
            print_ast(node->binop.left, indent + 1);
            print_ast(node->binop.right, indent + 1);
            break;
        case NODE_ASSIGN:
            printf("Asignación: %s =\n", node->assign.id);
            print_ast(node->assign.value, indent + 1);
            break;
        case NODE_PRINT:
            printf("Print:\n");
            print_ast(node->assign.value, indent + 1);
            break;
        case NODE_DECL:
            printf("Declaración (%s): %s\n",
                   node->decl.decl_type == NODE_INT ? "int" :
                   node->decl.decl_type == NODE_FLOAT ? "float" : "string",
                   node->decl.id);
            break;
        case NODE_IF:
            printf("If:\n");
            print_indent(indent + 1); printf("Condición:\n");
            print_ast(node->ifstmt.cond, indent + 2);
            print_indent(indent + 1); printf("Then:\n");
            print_ast(node->ifstmt.then_branch, indent + 2);
            if (node->ifstmt.else_branch) {
                print_indent(indent + 1); printf("Else:\n");
                print_ast(node->ifstmt.else_branch, indent + 2);
            }
            break;
        case NODE_WHILE:
            printf("While:\n");
            print_indent(indent + 1); printf("Condición:\n");
            print_ast(node->whilestmt.cond, indent + 2);
            print_indent(indent + 1); printf("Cuerpo:\n");
            print_ast(node->whilestmt.body, indent + 2);
            break;
        case NODE_BLOCK:
            printf("Bloque:\n");
            for (int i = 0; i < node->block.stmt_count; i++) {
                print_ast(node->block.stmts[i], indent + 1);
            }
            break;
        default:
            printf("Nodo desconocido\n");
            break;
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
            fprintf(out, "%s", node->sval);
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
        case NODE_ASSIGN:
            fprintf(out, "%s = ", node->assign.id);
            generate_code(out, node->assign.value);
            fprintf(out, ";\n");
            break;
        case NODE_PRINT:
            if (node->assign.value->type == NODE_INT) {
                fprintf(out, "printf(\"%%d\\n\", ");
            } else if (node->assign.value->type == NODE_FLOAT) {
                fprintf(out, "printf(\"%%f\\n\", ");
            } else if (node->assign.value->type == NODE_STRING || node->assign.value->type == NODE_ID) {
                fprintf(out, "printf(\"%%s\\n\", ");
            } else {
                fprintf(out, "printf(\"<unsupported>\\n\"");
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
        case NODE_BLOCK:
            for (int i = 0; i < node->block.stmt_count; ++i) {
                generate_code(out, node->block.stmts[i]);
            }
            break;
        case NODE_FOR:
            generate_code(out, node->forstmt.init);
            fprintf(out, "while (");
            generate_code(out, node->forstmt.cond);
            fprintf(out, ") {\n");
            generate_code(out, node->forstmt.body);
            generate_code(out, node->forstmt.incr);
            fprintf(out, "}\n");
            break;
        case NODE_READ:
            switch (node->read.type) {
                case 0: // int
                    fprintf(out, "scanf(\"%%d\", &%s);\n", node->read.id);
                    break;
                case 1: // float
                    fprintf(out, "scanf(\"%%f\", &%s);\n", node->read.id);
                    break;
                case 2: // string
                    fprintf(out, "scanf(\"%%s\", %s);\n", node->read.id);  // sin &
                    break;
            }
            break;
        default:
            break;
    }
}
