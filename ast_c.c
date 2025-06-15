#include "ast_c.h"

Symbol* symbol_table = NULL;

void add_symbol(const char* id, NodeType type) {
    if (get_symbol(id)) return;
    Symbol* sym = malloc(sizeof(Symbol));
    sym->id = strdup(id);
    sym->type = type;
    sym->next = symbol_table;
    symbol_table = sym;
}

Symbol* get_symbol(const char* id) {
    for (Symbol* s = symbol_table; s; s = s->next)
        if (strcmp(s->id, id) == 0)
            return s;
    return NULL;
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
    return node;
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

ASTNode* make_func_def_node(const char* name, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FUNC_DEF;
    node->func_def.name = strdup(name);
    node->func_def.body = body;
    return node;
}

ASTNode* make_func_call_node(const char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FUNC_CALL;
    node->func_call.name = strdup(name);
    return node;
}

ASTNode* make_return_node(ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_RETURN;
    node->retstmt.value = value;
    return node;
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
