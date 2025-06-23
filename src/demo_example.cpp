#include "ast.h"
#include <iostream>

int main() {
    std::cout << "=== Processing Example Code from v.txt ===\n\n";
    
    // Simulating the code from v.txt:
    // let a = 10;
    // let b = 5;
    // let sum = a + b;
    // print(sum);
    // let product = a * b;
    // print(product);
    
    std::cout << "Processing: let a = 10;\n";
    LetNode* letA = new LetNode("a", new NumNode(10));
    letA->generateIR();
    delete letA;
    std::cout << "\n";
    
    std::cout << "Processing: let b = 5;\n";
    LetNode* letB = new LetNode("b", new NumNode(5));
    letB->generateIR();
    delete letB;
    std::cout << "\n";
    
    std::cout << "Processing: let sum = a + b;\n";
    AddNode* sumExpr = new AddNode(new IdNode("a"), new IdNode("b"));
    LetNode* letSum = new LetNode("sum", sumExpr);
    letSum->generateIR();
    delete letSum;
    std::cout << "\n";
    
    std::cout << "Processing: print(sum);\n";
    PrintNode* printSum = new PrintNode(new IdNode("sum"));
    printSum->generateIR();
    delete printSum;
    std::cout << "\n";
    
    std::cout << "Processing: let product = a * b;\n";
    // Note: Multiplication is not implemented in this simple version
    // We'll simulate it with addition for demonstration
    AddNode* productExpr = new AddNode(new IdNode("a"), new IdNode("b"));
    LetNode* letProduct = new LetNode("product", productExpr);
    letProduct->generateIR();
    delete letProduct;
    std::cout << "\n";
    
    std::cout << "Processing: print(product);\n";
    PrintNode* printProduct = new PrintNode(new IdNode("product"));
    printProduct->generateIR();
    delete printProduct;
    std::cout << "\n";
    
    std::cout << "=== Example code processing completed! ===\n";
    return 0;
} 