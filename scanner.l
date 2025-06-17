%{
#include "parser.tab.h"
#include "ast_c.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern YYSTYPE yylval;
%}

DIGIT   [0-9]+
ID      [a-zA-Z_][a-zA-Z0-9_]*
FLOAT   {DIGIT}"."{DIGIT}

%%

"chain"         { return STRING; }
"integer"       { return INT; }
"floating"      { return FLOAT; }

"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }

"print"         { return PRINT; }
"write"         { return WRITE; }

"function"      { return FUNCTION; }
"return"        { return RETURN; }

"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LEQ; }
">="            { return GEQ; }
"<"             { return LT; }
">"             { return GT; }
"**"            { return POW; }
"%"             { return '%'; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"="             { return '='; }
";"             { return ';'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }

{FLOAT}         { yylval.fval = atof(yytext); return FLOATNUM; }
{DIGIT}         { yylval.ival = atoi(yytext); return NUMBER; }
{ID}            { yylval.id = strdup(yytext); return ID; }

\"([^\"]*)\"    {
    yylval.id = (char*)malloc(yyleng - 1);
    strncpy(yylval.id, yytext + 1, yyleng - 2);
    yylval.id[yyleng - 2] = '\0';
    return STRING_LITERAL;
}

[ \t\r\n]+      { /* Ignorar espacios */ }

.               { return *yytext; }

%%

int yywrap() {
    return 1;
}
