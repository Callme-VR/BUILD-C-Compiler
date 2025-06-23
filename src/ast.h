#ifndef AST_H
#define AST_H

#include <iostream>
#include <string> // For std::string in IdNode and LetNode
#include "ir_generator.h"

class ASTNode
{
public:
    virtual void generateIR() = 0;
    virtual ~ASTNode() {}
};

class NumNode : public ASTNode
{
    int value;

public:
    NumNode(int v);
    void generateIR() override;
};

class AddNode : public ASTNode
{
    ASTNode *lhs, *rhs;

public:
    AddNode(ASTNode *l, ASTNode *r);
    ~AddNode() override;
    void generateIR() override;
};

class IdNode : public ASTNode
{
    std::string name;

public:
    IdNode(const char *n);
    ~IdNode() override;
    void generateIR() override;
};

class LetNode : public ASTNode
{
    std::string name;
    ASTNode *expr;

public:
    LetNode(const char *n, ASTNode *e);
    ~LetNode() override;
    void generateIR() override;
};

class PrintNode : public ASTNode
{
    ASTNode *expr;

public:
    PrintNode(ASTNode *e);
    ~PrintNode() override;
    void generateIR() override;
};

#endif // AST_H