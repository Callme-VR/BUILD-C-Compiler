🛠️ How to Build
Requirements
GCC/G++

Bison

Flex

Make

Build Using Make
bash
Copy
Edit
cd src
make clean     # Clear old files
make all       # Build the compiler
make test      # Run tests
make demo      # Build and run demo
Build Manually (Without Make)
bash
Copy
Edit
cd src
g++ -c ast/ast.cpp -o build/ast.o
g++ -c ir/ir_generator.cpp -o build/ir_generator.o
g++ -c main.cpp -o build/main.o
g++ build/*.o -o build/compiler.exe
▶️ How to Run
bash
Copy
Edit
./build/compiler.exe           # Run compiler
./build/test_compiler.exe      # Run tests
./build/demo_example.exe       # Run demo program
🔍 Example Output
Input code:

javascript
Copy
Edit
let a = 10;
let b = 5;
let sum = a + b;
print(sum);
Output IR:

css
Copy
Edit
load_const 10
store_var a
load_const 5
store_var b
load_var a
load_var b
add
store_var sum
load_var sum
print
🧪 How to Add New Features
Lexer: Add new tokens in src/parser/scanner.l

Parser: Add grammar rules in src/parser/parser.y

AST: Add new node classes in src/ast/

IR: Add IR code generation in src/ir/

✅ Project Progress
✅ AST and IR working

✅ Supports variables, math, and print

🔄 Still improving parser and error messages

🔄 Planning optimizations

🤝 Contributing
Fork the project

Make a new branch for your feature

Add your changes and tests

Submit a pull request

📄 License
This project is for learning and educational use.

yaml
Copy
Edit
