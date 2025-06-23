%code requires {
    #include "ast.h" // Ensure ASTNode is defined before %union
}

%{
#include <iostream>
#include <cstdlib>
#include "parser.tab.h"

#ifdef __cplusplus
extern "C" int yylex(void); // Declare yylex with C linkage
#endif

ASTNode* root = nullptr;

void yyerror(const char* s) {
    std::cerr << "Error: " << s << "\n";
}
%}

%union {
    int num;
    char* id;
    ASTNode* node;
}

%token <num> NUMBER
%token <id> ID
%token LET PRINT
%token ASSIGN SEMI LPAREN RPAREN PLUS

%type <node> stmt expr
%left PLUS

%destructor { free($$); } ID
%destructor { delete $$; } stmt expr

%%
program : stmt { root = $1; }
       ;

stmt : LET ID ASSIGN expr SEMI   { $$ = new LetNode($2, $4); free($2); }
     | PRINT LPAREN expr RPAREN SEMI { $$ = new PrintNode($3); }
     ;

expr : expr PLUS expr { $$ = new AddNode($1, $3); }
     | NUMBER         { $$ = new NumNode($1); }
     | ID             { $$ = new IdNode($1); free($1); }
     ;
%%