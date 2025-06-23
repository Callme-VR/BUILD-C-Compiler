all: compiler

compiler: parser.tab.o lex.yy.o ast.o main.o ir_generator.o
	g++ -o compiler parser.tab.o lex.yy.o ast.o main.o ir_generator.o

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

lex.yy.c: scanner.l
	flex scanner.l

parser.tab.o: parser.tab.c
	g++ -c parser.tab.c

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o lex.yy.c parser.tab.* compiler