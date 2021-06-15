LEXER   = flex 
PARSER  = bison
POPT    = -d
CXX     = g++
COPT    = -g

default:
	(cd src && \
	$(PARSER) $(POPT) parser.y && \
	$(LEXER) lexer.l && \
	$(CXX) $(OPT) ast.cpp table.cpp parser.tab.c lex.yy.c -o ../bin/parser.out) || \
	(echo -e "\n\e[1;31mError. \e[0mCompilation termined." && exit 1)
	make clean
	echo -e "\n\e[1;36mCompilation successfully.\e[0m"

clean:
	rm src/*.c src/*.h