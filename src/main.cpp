#include "ast.h"
#include <iostream> // For std::cerr
extern int yyparse();
extern ASTNode *root;

int main()
{
    yyparse();
    if (root)
    {
        root->generateIR();
        delete root; // Free the AST
        return 0;
    }
    else
    {
        std::cerr << "Error: No valid AST generated.\n";
        return 1;
    }
}