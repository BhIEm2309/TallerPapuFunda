#ifndef AST_C_H
#define AST_C_H

#include <stdio.h>

typedef enum {
    NODE_UNKNOWN = -1,
    NODE_INT,
    NODE_FLOAT,
    NODE_STRING,
    NODE_ID,
    NODE_BINOP,
    NODE_ASSIGN,
    NODE_PRINT,
    NODE_READ,
    NODE_IF,
    NODE_WHILE,
    NODE_BLOCK,
    NODE_DECL,
    NODE_FOR
} NodeType;

typedef struct ASTNode {
    NodeType type;
    union {
        int ival;
        float fval;
        char* sval;
        struct {
            char* op;
            struct ASTNode* left;
            struct ASTNode* right;
        } binop;
        struct {
            char* id;
            struct ASTNode* value;
        } assign;
        struct {
            struct ASTNode* cond;
            struct ASTNode* then_branch;
            struct ASTNode* else_branch;
        } ifstmt;
        struct {
            struct ASTNode* cond;
            struct ASTNode* body;
        } whilestmt;
        struct {
            struct ASTNode** stmts;
            int stmt_count;
        } block;
        struct {
            char* id;
            NodeType decl_type;
        } decl;
        struct {
            struct ASTNode* init;
            struct ASTNode* cond;
            struct ASTNode* incr;
            struct ASTNode* body;
        } forstmt;
        struct {
            char* id;
            int type;
        } read;
    };
} ASTNode;

/* Tabla de símbolos */
typedef struct {
    char* name;
    int type;  // NODE_INT, NODE_FLOAT, NODE_STRING
} Symbol;

extern Symbol symbol_table[100];
extern int symbol_count;

/* Funciones AST */
ASTNode* make_int_node(int value);
ASTNode* make_id_node(const char* name);
ASTNode* make_binop_node(const char* op, ASTNode* left, ASTNode* right);
ASTNode* make_assign_node(const char* id, ASTNode* value);
ASTNode* make_print_node(ASTNode* expr);
ASTNode* make_decl_node(const char* id, NodeType decl_type);
ASTNode* make_if_node(ASTNode* cond, ASTNode* then_branch, ASTNode* else_branch);
ASTNode* make_while_node(ASTNode* cond, ASTNode* body);
ASTNode* make_float_node(float value);
ASTNode* make_string_node(const char* value);
ASTNode* make_for_node(ASTNode* init, ASTNode* condition, ASTNode* increment, ASTNode* body);
ASTNode* make_read_node(const char* id, int type);


void print_ast(ASTNode* node, int indent);
void generate_code(FILE* out, ASTNode* node);

void add_symbol(const char* name, int type);
int get_symbol_type(const char* name);

#endif
