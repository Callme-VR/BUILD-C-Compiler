# Simple Language Compiler Build Script
Write-Host "Building Simple Language Compiler..." -ForegroundColor Green

# Compile all source files
g++ -c ast.cpp -o ast.o
g++ -c ir_generator.cpp -o ir_generator.o
g++ -c test_compiler.cpp -o test_compiler.o
g++ test_compiler.o ast.o ir_generator.o -o test_compiler.exe

g++ -c demo_example.cpp -o demo_example.o
g++ demo_example.o ast.o ir_generator.o -o demo_example.exe

Write-Host "Build completed! Run with: .\test_compiler.exe or .\demo_example.exe" -ForegroundColor Yellow 