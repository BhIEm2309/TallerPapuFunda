#ifndef AST_C_H
#define AST_C_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
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
    NODE_FOR,
    NODE_BLOCK,
    NODE_DECL,
    NODE_FUNCDEF,
    NODE_FUNCCALL
} NodeType;

typedef struct ASTNode {
    NodeType type;
    NodeType data_type; // Solo útil para expresiones

    union {
        int ival;
        float fval;
        char* sval;

        struct {
            struct ASTNode* value;
        } print;

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
            struct ASTNode* init;
            struct ASTNode* cond;
            struct ASTNode* update;
            struct ASTNode* body;
        } forstmt;

        struct {
            struct ASTNode** stmts;
            int stmt_count;
        } block;

        struct {
            char* id;
            NodeType decl_type;
        } decl;

        struct {
            char* id;
            struct ASTNode* body;
        } funcdef;

        struct {
            char* id;
        } funccall;
    };
} ASTNode;

// AST
ASTNode* make_int_node(int value);
ASTNode* make_float_node(float value);
ASTNode* make_string_node(const char* value);
ASTNode* make_id_node(const char* name);
ASTNode* make_binop_node(const char* op, ASTNode* left, ASTNode* right);
ASTNode* make_assign_node(const char* id, ASTNode* value);
ASTNode* make_print_node(ASTNode* expr);
ASTNode* make_read_node(const char* id, int dummy);
ASTNode* make_decl_node(const char* id, NodeType decl_type);
ASTNode* make_if_node(ASTNode* cond, ASTNode* then_branch, ASTNode* else_branch);
ASTNode* make_while_node(ASTNode* cond, ASTNode* body);
ASTNode* make_for_node(ASTNode* init, ASTNode* cond, ASTNode* update, ASTNode* body);
ASTNode* make_funccall_node(const char* id);
void print_ast(ASTNode* node, int indent);
void generate_code(FILE* out, ASTNode* node);

// Tabla de símbolos
typedef struct Symbol {
    char* id;
    NodeType type;
    struct Symbol* next;
} Symbol;

extern Symbol* symbol_table;
void add_symbol(const char* id, NodeType type);
Symbol* get_symbol(const char* id);
NodeType get_symbol_type(const char* id);

// Tabla de funciones
typedef struct FunctionEntry {
    char* id;
    ASTNode* body;
    struct FunctionEntry* next;
} FunctionEntry;

void add_function(const char* id, ASTNode* body);
ASTNode* get_function(const char* id);
void generate_all_functions(FILE* out);

#endif
