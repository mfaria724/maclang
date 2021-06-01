default:
	flex lexer.l
	g++ lex.yy.c -o lex.out
	make clean

clean:
	rm lex.yy.c