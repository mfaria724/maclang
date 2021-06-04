default:
	bison -d parser.y 
	flex lexer.l 
	g++ parser.tab.c lex.yy.c -g
	make clean

clean:
	rm lex.yy.c