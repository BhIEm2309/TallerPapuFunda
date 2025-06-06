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
}

%token <ival> NUMBER
%token <fval> FLOATNUM
%token <id> ID STRING_LITERAL

%token INT FLOAT STRING IF ELSE WHILE FOR PRINT WRITE
%token EQ NEQ LEQ GEQ LT GT

%left '+' '-'
%left '*' '/'
%left EQ NEQ LT GT LEQ GEQ
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type <node> program stmt stmt_list expr

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
    | PRINT ID ';'             { $$ = make_print_node(make_id_node($2)); }
    | PRINT STRING_LITERAL ';' { $$ = make_print_node(make_string_node($2)); }
    | WRITE ID ';'             { $$ = make_read_node($2, -1); }
    | IF '(' expr ')' stmt %prec LOWER_THAN_ELSE
                                { $$ = make_if_node((ASTNode*)$3, (ASTNode*)$5, NULL); }
    | IF '(' expr ')' stmt ELSE stmt
                                { $$ = make_if_node((ASTNode*)$3, (ASTNode*)$5, (ASTNode*)$7); }
    | WHILE '(' expr ')' stmt  { $$ = make_while_node((ASTNode*)$3, (ASTNode*)$5); }
    | '{' stmt_list '}'        { $$ = $2; }
    | FOR '(' stmt expr ';' stmt ')' stmt { $$ = make_for_node($3, (ASTNode*)$4, $6, $8); }
    ;

expr:
      expr '+' expr      { $$ = make_binop_node("+", $1, $3); }
    | expr '-' expr      { $$ = make_binop_node("-", $1, $3); }
    | expr '*' expr      { $$ = make_binop_node("*", $1, $3); }
    | expr '/' expr      { $$ = make_binop_node("/", $1, $3); }
    | expr EQ expr       { $$ = make_binop_node("==", $1, $3); }
    | expr NEQ expr      { $$ = make_binop_node("!=", $1, $3); }
    | expr LEQ expr      { $$ = make_binop_node("<=", $1, $3); }
    | expr GEQ expr      { $$ = make_binop_node(">=", $1, $3); }
    | expr LT expr       { $$ = make_binop_node("<", $1, $3); }
    | expr GT expr       { $$ = make_binop_node(">", $1, $3); }
    | NUMBER             { $$ = make_int_node($1); }
    | ID                 { $$ = make_id_node($1); }
    | FLOATNUM           { $$ = make_float_node($1); }
    | STRING_LITERAL     { $$ = make_string_node($1); }
;

%%

int main() {
    if (yyparse() == 0) {
        FILE* out = fopen("output.c", "w");
        fprintf(out, "#include <stdio.h>\nint main() {\n");
        generate_code(out, root);
        fprintf(out, "return 0;\n}\n");
        fclose(out);
        printf("Código C generado en output.c\n");
    }
    return 0;
}