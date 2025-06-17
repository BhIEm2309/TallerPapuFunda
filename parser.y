%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast_c.h"

ASTNode* root;

int yylex(void);
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
%}

%union {
    int ival;
    float fval;
    char* id;
    void* node;
    struct {
        struct ASTNode** list;
        int count;
    } node_list;
}

%token <ival> NUMBER
%token <fval> FLOATNUM
%token <id> ID STRING_LITERAL

%token INT FLOAT STRING IF ELSE WHILE FOR PRINT WRITE FUNCTION RETURN
%token EQ NEQ LEQ GEQ LT GT

%left '+' '-'
%left '*' '/' '%'
%left EQ NEQ LT GT LEQ GEQ
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type <node> program stmt stmt_list expr func_def func_call return_stmt param_decl
%type <node_list> param_list param_list_opt arg_list arg_list_opt

%%

program:
    stmt_list               { root = (ASTNode*)$1; }
    ;

stmt_list:
      stmt                 {
                            ASTNode** stmts = malloc(sizeof(ASTNode*));
                            stmts[0] = (ASTNode*)$1;
                            ASTNode* block = malloc(sizeof(ASTNode));
                            block->type = NODE_BLOCK;
                            block->block.stmts = stmts;
                            block->block.stmt_count = 1;
                            $$ = block;
                          }
    | stmt_list stmt       {
                            ASTNode* block = (ASTNode*)$1;
                            int n = block->block.stmt_count + 1;
                            block->block.stmts = realloc(block->block.stmts, n * sizeof(ASTNode*));
                            block->block.stmts[n-1] = (ASTNode*)$2;
                            block->block.stmt_count = n;
                            $$ = block;
                          }
    ;

stmt:
      INT ID ';'               { add_symbol($2, NODE_INT); $$ = make_decl_node($2, NODE_INT); }
    | FLOAT ID ';'             { add_symbol($2, NODE_FLOAT); $$ = make_decl_node($2, NODE_FLOAT); }
    | STRING ID ';'            { add_symbol($2, NODE_STRING); $$ = make_decl_node($2, NODE_STRING); }
    | ID '=' expr ';'          { $$ = make_assign_node($1, (ASTNode*)$3); }
    | PRINT expr ';'           { $$ = make_print_node((ASTNode*)$2); }
    | WRITE ID ';'             { $$ = make_read_node($2, -1); }
    | IF '(' expr ')' stmt %prec LOWER_THAN_ELSE
                                { $$ = make_if_node((ASTNode*)$3, (ASTNode*)$5, NULL); }
    | IF '(' expr ')' stmt ELSE stmt
                                { $$ = make_if_node((ASTNode*)$3, (ASTNode*)$5, (ASTNode*)$7); }
    | WHILE '(' expr ')' stmt  { $$ = make_while_node((ASTNode*)$3, (ASTNode*)$5); }
    | '{' stmt_list '}'        { $$ = $2; }
    | FOR '(' expr ';' expr ';' expr ')' stmt
                                { $$ = make_for_node((ASTNode*)$3, (ASTNode*)$5, (ASTNode*)$7, (ASTNode*)$9); }
    | func_call ';'            { $$ = $1; }
    | func_def                 { $$ = NULL; }
    ;

func_def:
    FUNCTION ID '(' param_list_opt ')' '{' stmt_list return_stmt '}'
    {
        $$ = make_funcdef_node($2, $4.list, $4.count, $7, $8);
        add_function($2, $4.list, $4.count, $7, $8);
    }
;

param_list_opt
    : /* vacío */ { $$.list = NULL; $$.count = 0; }
    | param_list { $$ = $1; }
    ;

param_list
    : param_decl {
        $$.list = malloc(sizeof(ASTNode*) * 1);
        $$.list[0] = (ASTNode*)$1;
        $$.count = 1;
    }
    | param_list ',' param_decl {
        $1.list = realloc($1.list, sizeof(ASTNode*) * ($1.count + 1));
        $1.list[$1.count++] = (ASTNode*)$3;
        $$ = $1;
    }
    ;

param_decl
    : INT ID    { $$ = make_decl_node($2, NODE_INT); add_symbol($2, NODE_INT); }
    | FLOAT ID  { $$ = make_decl_node($2, NODE_FLOAT); add_symbol($2, NODE_FLOAT); }
    | STRING ID { $$ = make_decl_node($2, NODE_STRING); add_symbol($2, NODE_STRING); }
    ;

return_stmt:
    RETURN expr ';' { $$ = make_return_node($2); }
    ;

func_call:
    ID '(' arg_list_opt ')' {
        $$ = make_funccall_node_with_args($1, $3.list, $3.count);
    }
    ;

arg_list_opt
    : /* vacío */ { $$.list = NULL; $$.count = 0; }
    | arg_list { $$ = $1; }
    ;

arg_list
    : expr {
        $$.list = malloc(sizeof(ASTNode*) * 1);
        $$.list[0] = (ASTNode*)$1;
        $$.count = 1;
    }
    | arg_list ',' expr {
        $1.list = realloc($1.list, sizeof(ASTNode*) * ($1.count + 1));
        $1.list[$1.count++] = (ASTNode*)$3;
        $$ = $1;
    }
    ;

expr:
      expr '+' expr      { $$ = make_binop_node("+", $1, $3); }
    | expr '-' expr      { $$ = make_binop_node("-", $1, $3); }
    | expr '*' expr      { $$ = make_binop_node("*", $1, $3); }
    | expr '/' expr      { $$ = make_binop_node("/", $1, $3); }
    | expr '%' expr      { $$ = make_binop_node("%", $1, $3); }
    | expr EQ expr       { $$ = make_binop_node("==", $1, $3); }
    | expr NEQ expr      { $$ = make_binop_node("!=", $1, $3); }
    | expr LEQ expr      { $$ = make_binop_node("<=", $1, $3); }
    | expr GEQ expr      { $$ = make_binop_node(">=", $1, $3); }
    | expr LT expr       { $$ = make_binop_node("<", $1, $3); }
    | expr GT expr       { $$ = make_binop_node(">", $1, $3); }
    | ID '=' expr        { $$ = make_assign_node($1, (ASTNode*)$3); }
    | ID '(' arg_list_opt ')' { $$ = make_funccall_node_with_args($1, $3.list, $3.count); }
    | NUMBER             { $$ = make_int_node($1); }
    | ID                 { $$ = make_id_node($1); }
    | FLOATNUM           { $$ = make_float_node($1); }
    | STRING_LITERAL     { $$ = make_string_node($1); }
    ;

%%

int main() {
    if (yyparse() == 0) {
        FILE* out = fopen("output.c", "w");
        fprintf(out, "#include <stdio.h>\n");
        fprintf(out, "#include <string.h>\n");
        fprintf(out, "#include <stdlib.h>\n");

        generate_all_functions(out);

        fprintf(out, "int main() {\n");
        generate_code(out, root);
        fprintf(out, "return 0;\n}\n");
        fclose(out);
        printf("Código C generado en output.c\n");
    }
    return 0;
}