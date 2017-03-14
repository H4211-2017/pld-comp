#$(word n, $^) is the nth word of the dependency list

SRC_DIRECTORY=./
BIN_DIRECTORY=../../bin/flex/
AST_DIRECTORY=AST/
TEST_DIRECTORY=../../test/flex/
LIB_DIRECTORY=../../lib/
INC_DIRECTORY=../../include/

INCLUDE_DIRECTORIES=-I$(INC_DIRECTORY)

CPP_FLAGS=-DYYDEBUG -g -o
CPP_FLAGS_OBJ= -c
BISON_FLAGS=-v -d

#To be updated after each change in list of files
SRC=TypeChar.cpp  TypeInt32.cpp  TypeInt64.cpp  Variable.cpp
SRC_AST=$(SRC:%.cpp=$(AST_DIRECTORY)%.cpp)
HEADERS_AST=$(SRC:%.cpp=$(AST_DIRECTORY)%.h) $(AST_DIRECTORY)
OBJ_AST=$(SRC:%.cpp=$(BIN_DIRECTORY)%.o)

$(BIN_DIRECTORY)test: $(SRC_DRECTORY)../main.cpp $(BIN_DIRECTORY)bison.tab.cpp $(BIN_DIRECTORY)lex.yy.c $(OBJ_AST) $(BIN_DIRECTORY) LIB
	g++ $(CPP_FLAGS) $(BIN_DIRECTORY)test $(SRC_DIRECTORY)../main.cpp -L$(LIB_DIRECTORY) $(INCLUDE_DIRECTORIES) -lbisontab -llexyy $(BIN_DIRECTORY)lex.yy.c

$(BIN_DIRECTORY)lex.yy.c: $(SRC_DRECTORY)tokens.lex $(BIN_DIRECTORY)
	flex -o $(BIN_DIRECTORY)lex.yy.c $(SRC_DRECTORY)tokens.lex

$(BIN_DIRECTORY)bison.tab.cpp: $(SRC_DRECTORY)bison.ypp $(BIN_DIRECTORY)
	bison $(BISON_FLAGS) -o $(BIN_DIRECTORY)bison.tab.cpp $(SRC_DRECTORY)bison.ypp
	
	
$(BIN_DIRECTORY)%.o: $(AST_DIRECTORY)%.cpp $(HEADERS_AST) $(BIN_DIRECTORY)
	g++ $(CPP_FLAGS) $@ $(CPP_FLAGS_OBJ) $(word 1,$^) $(INCLUDE_DIRECTORIES)

LIB: $(LIB_DIRECTORY)libbisontab.a $(LIB_DIRECTORY)liblexyy.a

$(LIB_DIRECTORY)libbisontab.a: $(BIN_DIRECTORY)bison.tab.o
	ar rcs $(LIB_DIRECTORY)libbisontab.a $(BIN_DIRECTORY)bison.tab.o
	cp $(BIN_DIRECTORY)bison.tab.hpp $(INC_DIRECTORY)

$(LIB_DIRECTORY)liblexyy.a: $(BIN_DIRECTORY)lex.yy.o
	ar rcs $(LIB_DIRECTORY)liblexyy.a $(BIN_DIRECTORY)lex.yy.o

$(BIN_DIRECTORY):
	mkdir $(BIN_DIRECTORY)
