#include "ast_c.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


Symbol* symbol_table = NULL;
Symbol* get_symbol(const char* id);

Symbol* get_symbol(const char* id) {
    for (Symbol* s = symbol_table; s; s = s->next)
        if (strcmp(s->id, id) == 0)
            return s;
    return NULL;
}

void add_symbol(const char* id, NodeType type) {
    if (get_symbol(id)) return;
    Symbol* sym = malloc(sizeof(Symbol));
    sym->id = strdup(id);
    sym->type = type;
    sym->next = symbol_table;
    symbol_table = sym;
}

NodeType get_symbol_type(const char* id) {
    Symbol* s = get_symbol(id);
    if (!s) {
        fprintf(stderr, "Error: variable '%s' no declarada.\n", id);
        exit(1);
    }
    return s->type;
}

ASTNode* make_int_node(int val) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_INT;
    node->ival = val;
    node->data_type = NODE_INT;
    printf("[DEBUG] Nodo INT creado con valor %d\n", val);
    return node;
}

ASTNode* make_float_node(float value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FLOAT;
    node->fval = value;
    node->data_type = NODE_FLOAT;
    return node;
}

ASTNode* make_string_node(const char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_STRING;
    node->sval = strdup(value);
    node->data_type = NODE_STRING;
    return node;
}

ASTNode* make_id_node(const char* name) {
    Symbol* sym = get_symbol(name);
    if (!sym) {
        fprintf(stderr, "Error: variable '%s' no declarada.\n", name);
        exit(1);
    }
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ID;
    node->sval = strdup(name);
    node->data_type = sym->type;
    return node;
}

ASTNode* make_binop_node(const char* op, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_BINOP;
    node->binop.op = strdup(op);
    node->binop.left = left;
    node->binop.right = right;

    if (left->data_type == NODE_STRING || right->data_type == NODE_STRING) {
        if (strcmp(op, "+") != 0) {
            fprintf(stderr, "Error: operación '%s' no válida con strings.\n", op);
            exit(1);
        }
        node->data_type = NODE_STRING;
    } else if (left->data_type == NODE_FLOAT || right->data_type == NODE_FLOAT) {
        node->data_type = NODE_FLOAT;
    } else {
        node->data_type = NODE_INT;
    }

    return node;
}

ASTNode* make_assign_node(const char* id, ASTNode* expr) {
    NodeType declared_type = get_symbol_type(id);

    if (declared_type != expr->data_type) {
        fprintf(stderr, "Error: tipo incompatible en asignación a '%s'.\n", id);
        exit(1);
    }

    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ASSIGN;
    node->assign.id = strdup(id);
    node->assign.value = expr;
    node->data_type = declared_type;
    return node;
}

ASTNode* make_print_node(ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_PRINT;
    node->data_type = expr->data_type;
    node->print.value = expr; 
}


ASTNode* make_read_node(const char* id, int dummy) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_READ;
    node->sval = strdup(id);
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

ASTNode* make_for_node(ASTNode* init, ASTNode* cond, ASTNode* update, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FOR;
    node->forstmt.init = init;
    node->forstmt.cond = cond;
    node->forstmt.update = update;
    node->forstmt.body = body;
    return node;
}

ASTNode* make_func_def_node(const char* name, ASTNode* params, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FUNC_DEF;
    node->func_def.name = strdup(name);
    node->func_def.params = params;
    node->func_def.body = body;
    return node;
}

ASTNode* make_func_call_node(const char* name, ASTNode* args) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FUNC_CALL;
    node->func_call.name = strdup(name);
    node->func_call.args = args;
    return node;
}

ParamList* make_param_list(const char* name, ParamList* next) {
    ParamList* param = malloc(sizeof(ParamList));
    param->name = strdup(name);
    param->next = next;
    return param;
}

ASTNode* append_param(ASTNode* list, const char* id) {
    list->param_list.count++;
    list->param_list.ids = realloc(list->param_list.ids, list->param_list.count * sizeof(char*));
    list->param_list.ids[list->param_list.count - 1] = strdup(id);
    return list;
}

ASTNode* make_arg_list(ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ARG_LIST;
    node->arg_list.count = 1;
    node->arg_list.args = malloc(sizeof(ASTNode*));
    node->arg_list.args[0] = expr;
    return node;
}

ASTNode* append_arg(ASTNode* list, ASTNode* expr) {
    list->arg_list.count++;
    list->arg_list.args = realloc(list->arg_list.args, list->arg_list.count * sizeof(ASTNode*));
    list->arg_list.args[list->arg_list.count - 1] = expr;
    return list;
}


void print_ast(ASTNode* node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; ++i) printf("  ");
    switch (node->type) {
        case NODE_INT: printf("Int: %d\n", node->ival); break;
        case NODE_FLOAT: printf("Float: %f\n", node->fval); break;
        case NODE_STRING: printf("String: \"%s\"\n", node->sval); break;
        case NODE_ID: printf("Id: %s\n", node->sval); break;
        default: printf("Tipo de nodo: %d\n", node->type); break;
    }
}
