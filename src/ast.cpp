#include "ast.h"

NumNode::NumNode(int v) : value(v) {}

void NumNode::generateIR()
{
    IRGenerator::generateLoadConst(value);
}

AddNode::AddNode(ASTNode *l, ASTNode *r) : lhs(l), rhs(r) {}

AddNode::~AddNode()
{
    delete lhs;
    delete rhs;
}

void AddNode::generateIR()
{
    lhs->generateIR();
    rhs->generateIR();
    IRGenerator::generateAdd();
}

IdNode::IdNode(const char *n) : name(n) {}

IdNode::~IdNode() {}

void IdNode::generateIR()
{
    IRGenerator::generateLoadVar(name);
}

LetNode::LetNode(const char *n, ASTNode *e) : name(n), expr(e) {}

LetNode::~LetNode()
{
    delete expr;
}

void LetNode::generateIR()
{
    expr->generateIR();
    IRGenerator::generateStoreVar(name);
}

PrintNode::PrintNode(ASTNode *e) : expr(e) {}

PrintNode::~PrintNode()
{
    delete expr;
}

void PrintNode::generateIR()
{
    expr->generateIR();
    IRGenerator::generatePrint();
}