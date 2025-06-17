#ifndef AST_C_H
#define AST_C_H

typedef struct ParamList {
    char* name;
    struct ParamList* next;
} ParamList;

typedef struct ArgList {
    struct ASTNode* expr;
    struct ArgList* next;
} ArgList;

typedef struct Symbol {
    char* id;
    int type;
    struct Symbol* next;
} Symbol;

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
    NODE_BLOCK,
    NODE_DECL,
    NODE_FOR,
    NODE_FUNC_DEF,
    NODE_FUNC_CALL,
    NODE_RETURN
} NodeType;

typedef struct ASTNode {
    NodeType type;
    NodeType data_type;
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

        struct {
            char* name;
            ParamList* params;
            struct ASTNode* body;
        } funcdef;

        struct {
            char* name;
            ArgList* args;
        } funccall;

        struct {
            struct ASTNode* value;
        } returnstmt;

        struct {
            struct ASTNode* value;
        } print;
    };
} ASTNode;

/* Declaración de funciones */
ASTNode* make_int_node(int value);
ASTNode* make_float_node(float value);
ASTNode* make_string_node(const char* value);
ASTNode* make_id_node(const char* name);
ASTNode* make_binop_node(const char* op, ASTNode* left, ASTNode* right);
ASTNode* make_assign_node(const char* id, ASTNode* value);
ASTNode* make_print_node(ASTNode* expr);
ASTNode* make_read_node(const char* id, int type);
ASTNode* make_decl_node(const char* id, NodeType decl_type);
ASTNode* make_if_node(ASTNode* cond, ASTNode* then_branch, ASTNode* else_branch);
ASTNode* make_while_node(ASTNode* cond, ASTNode* body);
ASTNode* make_for_node(ASTNode* init, ASTNode* cond, ASTNode* incr, ASTNode* body);
ASTNode* make_return_node(ASTNode* value);
ASTNode* make_func_def_node(const char* name, ParamList* params, ASTNode* body);
ASTNode* make_func_call_node(const char* name, ArgList* args);
ParamList* append_param(ParamList* list, const char* name);
ParamList* make_param_list(const char* name, ParamList* next);
ArgList* make_arg_list(ASTNode* expr, ArgList* next);
ArgList* append_arg(ArgList* list, ASTNode* expr);
void add_symbol(const char* id, NodeType type);
Symbol* get_symbol(const char* id);
NodeType get_symbol_type(const char* id);

void generate_code(FILE* out, ASTNode* node);
void print_ast(ASTNode* node, int indent);

#endif
