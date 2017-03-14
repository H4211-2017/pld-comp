#$(word n, $^) is the nth word of the dependency list

SRC_DIRECTORY=../src/
BIN_DIRECTORY=../bin/
AST_DIRECTORY=../src/AST/
TEST_DIRECTORY=../test/

INCLUDE_DIRECTORIES=-I $(BIN_DIRECTORY)

CPP_FLAGS=-DYYDEBUG -g -o
CPP_FLAGS_OBJ= -c
BISON_FLAGS=-v -d

#To be updated after each change in list of files
SRC=#TypeChar.cpp  TypeInt32.cpp  TypeInt64.cpp  Variable.cpp
SRC_AST=$(SRC:%.cpp=$(AST_DIRECTORY)%.cpp)
HEADERS_AST=$(SRC:%.cpp=$(AST_DIRECTORY)%.h) $(AST_DIRECTORY)
OBJ_AST=$(SRC:%.cpp=$(BIN_DIRECTORY)%.o)

$(BIN_DIRECTORY)test: $(SRC_DRECTORY)main.cpp $(BIN_DIRECTORY)bison.tab.cpp $(BIN_DIRECTORY)lex.yy.c $(OBJ_AST)
	g++ $(CPP_FLAGS) $(BIN_DIRECTORY)test $(SRC_DIRECTORY)main.cpp $(BIN_DIRECTORY)lex.yy.c $(BIN_DIRECTORY)bison.tab.cpp $(INCLUDE_DIRECTORIES)

$(BIN_DIRECTORY)lex.yy.c: $(SRC_DRECTORY)tokens.lex
	flex -o $(BIN_DIRECTORY)lex.yy.c $(SRC_DRECTORY)tokens.lex

$(BIN_DIRECTORY)bison.tab.cpp: $(SRC_DRECTORY)bison.ypp
	bison $(BISON_FLAGS) -o $(BIN_DIRECTORY)bison.tab.cpp $(SRC_DRECTORY)bison.ypp
	
	
$(BIN_DIRECTORY)%.o: $(AST_DIRECTORY)%.cpp $(HEADERS_AST)
	g++ $(CPP_FLAGS) $@ $(CPP_FLAGS_OBJ) $(word 1,$^) $(INCLUDE_DIRECTORIES)

