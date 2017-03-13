SRC_DIRECTORY=../src/
BIN_DIRECTORY=../bin/
TEST_DIRECTORY=../test/

CPP_FLAGS=-DYYDEBUG -g -o
BISON_FLAGS=-v -d

INCLUDE_DIRECTORIES=-I $(BIN_DIRECTORY)

$(BIN_DIRECTORY)test: $(SRC_DRECTORY)main.cpp $(BIN_DIRECTORY)bison.tab.c $(BIN_DIRECTORY)lex.yy.c
	g++ $(CPP_FLAGS) $(BIN_DIRECTORY)test $(SRC_DRECTORY)main.cpp $(BIN_DIRECTORY)lex.yy.c $(BIN_DIRECTORY)bison.tab.c $(INCLUDE_DIRECTORIES)

$(BIN_DIRECTORY)lex.yy.c: $(SRC_DRECTORY)tokens.lex
	flex -o $(BIN_DIRECTORY)lex.yy.c $(SRC_DRECTORY)tokens.lex

$(BIN_DIRECTORY)bison.tab.c: $(SRC_DRECTORY)bison.y
	bison $(BISON_FLAGS) -o $(BIN_DIRECTORY)bison.tab.c $(SRC_DRECTORY)bison.y

	
