#ifndef IR_GENERATOR_H
#define IR_GENERATOR_H

#include <string>
#include <iostream>

class IRGenerator {
public:
    static void generateLoadConst(int value) {
        std::cout << "load_const " << value << "\n";
    }

    static void generateLoadVar(const std::string& name) {
        std::cout << "load_var " << name << "\n";
    }

    static void generateStoreVar(const std::string& name) {
        std::cout << "store_var " << name << "\n";
    }

    static void generateAdd() {
        std::cout << "add\n";
    }

    static void generatePrint() {
        std::cout << "print\n";
    }
};

#endif // IR_GENERATOR_H
