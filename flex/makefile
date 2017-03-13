test: main.cpp bison.tab.c lex.yy.c bison.tab.h
	g++ -DYYDEBUG -g -o test main.cpp lex.yy.c bison.tab.c

lex.yy.c: tokens.lex
	flex tokens.lex

bison.tab.c: bison.y
	bison -v -d bison.y
	


	
