SRC_DIRECTORY=../src/
BIN_DIRECTORY=../bin/
TEST_DIRECTORY=../test/

CPP_FLAGS=-DYYDEBUG -g -o
BISON_FLAGS=-v -d

test: $(SRC_DRECTORY)main.cpp $(BIN_DIRECTORY)bison.tab.c $(BIN_DIRECTORY)lex.yy.c $(BIN_DIRECTORY)bison.tab.h
	g++ $(CPP_FLAGS) $(BIN_DIRECTORY)test $(SRC_DRECTORY)main.cpp $(BIN_DIRECTORY)lex.yy.c $(BIN_DIRECTORY)bison.tab.c

lex.yy.c: $(SRC_DRECTORY)tokens.lex
	flex $(SRC_DRECTORY)tokens.lex

bison.tab.c: $(SRC_DRECTORY)bison.y
	bison $(BISON_FLAGS) $(SRC_DRECTORY)bison.y
	


	
