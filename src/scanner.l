%{
#include "parser.tab.h"
#ifdef __cplusplus
extern "C" {
#endif
int yylex(void); // Declare yylex with C linkage
#ifdef __cplusplus
}
#endif
%}

%%
[ \t\n]+        ;
let             return LET;
print           return PRINT;
[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return ID; }
"="             return ASSIGN;
";"             return SEMI;
"("             return LPAREN;
")"             return RPAREN;
"+"             return PLUS;
.               return yytext[0];

%%

int yywrap() { return 1; }