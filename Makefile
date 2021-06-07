SRC=./src/

default: parser.y lexer.l ast.cpp
	bison -d parser.y 
	flex lexer.l 
	g++ ast.cpp parser.tab.c lex.yy.c -g -o bin/parser.out
	make clean

parser.y:
	cp src/parser.* .

lexer.l:
	cp src/lexer.* .

ast.cpp:
	cp src/ast.* .



clean:
	rm *.c *.h *.cpp *.hpp *.l *.y