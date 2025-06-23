#include "ast.h"
#include <iostream>

int main() {
    std::cout << "=== Simple Language Compiler Test ===\n\n";
    
    // Test 1: Simple number
    std::cout << "Test 1: Number 42\n";
    NumNode* num = new NumNode(42);
    num->generateIR();
    delete num;
    std::cout << "\n";
    
    // Test 2: Addition
    std::cout << "Test 2: Addition (10 + 5)\n";
    AddNode* add = new AddNode(new NumNode(10), new NumNode(5));
    add->generateIR();
    delete add;
    std::cout << "\n";
    
    // Test 3: Variable assignment
    std::cout << "Test 3: Variable assignment (let a = 10)\n";
    LetNode* let = new LetNode("a", new NumNode(10));
    let->generateIR();
    delete let;
    std::cout << "\n";
    
    // Test 4: Print statement
    std::cout << "Test 4: Print statement (print 100)\n";
    PrintNode* print = new PrintNode(new NumNode(100));
    print->generateIR();
    delete print;
    std::cout << "\n";
    
    // Test 5: Complex expression (let sum = a + b)
    std::cout << "Test 5: Complex expression (let sum = a + b)\n";
    AddNode* complexAdd = new AddNode(new IdNode("a"), new IdNode("b"));
    LetNode* complexLet = new LetNode("sum", complexAdd);
    complexLet->generateIR();
    delete complexLet;
    std::cout << "\n";
    
    std::cout << "=== Test completed successfully! ===\n";
    return 0;
} 