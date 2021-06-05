default: parser.y lexer.l ast.cpp
	bison -d parser.y 
	flex lexer.l 
	g++ ast.cpp parser.tab.c lex.yy.c -g -o parser.out
	make clean

clean:
	rm lex.yy.c parser.tab.h parser.tab.c