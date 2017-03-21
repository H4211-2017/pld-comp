#$(word n, $^) is the nth word of the dependency list
#which is strictly equivalent to '$<'

SRC_DIRECTORY=./
BIN_DIRECTORY=../../bin/flex/
RULE_MEMBER_DIRECTORY=$(SRC_DIRECTORY)rulemember/
AST_DIRECTORY=$(SRC_DIRECTORY)AST/
TEST_DIRECTORY=../../test/flex/
LIB_DIRECTORY=../../lib/
INC_DIRECTORY=../../include/

INCLUDE_DIRECTORIES=-I$(INC_DIRECTORY) -I$(BIN_DIRECTORY)

CPP_FLAGS=-std=c++11 -DYYDEBUG -g
CPP_FLAGS_OBJ=-c
BISON_FLAGS=-v -d

#To be updated after each change in list of files
SRC=TypeChar.cpp TypeInt32.cpp TypeInt64.cpp Variable.cpp fcBison.cpp
#SRC=$(find . -name "*.cpp")
HEADERS=$(find . -name "*.h")


SRC_RULE_MEMBER=$(SRC:%.cpp=$(RULE_MEMBER_DIRECTORY)%.cpp)
OBJ_RULE_MEMBER=$(SRC:%.cpp=$(BIN_DIRECTORY)%.o)
HEADERS_RULE_MEMBER=$(SRC:%.cpp=$(INC_DIRECTORY)%.h)

EXE=$(BIN_DIRECTORY)CParser

all: $(EXE)

$(EXE): $(SRC_DRECTORY)../main.cpp $(BIN_DIRECTORY)bison.tab.cpp $(BIN_DIRECTORY)lex.yy.cpp $(OBJ_RULE_MEMBER) $(HEADERS_RULE_MEMBER) $(BIN_DIRECTORY) 
	echo $(HEADERS_INC)
	g++ $(CPP_FLAGS) -o $(BIN_DIRECTORY)test $(SRC_DIRECTORY)../main.cpp $(BIN_DIRECTORY)lex.yy.cpp $(BIN_DIRECTORY)bison.tab.cpp $(OBJ_RULE_MEMBER) $(INCLUDE_DIRECTORIES)

flex: $(BIN_DIRECTORY)lex.yy.cpp

bison: $(BIN_DIRECTORY)bison.tab.cpp

$(BIN_DIRECTORY)lex.yy.cpp: $(SRC_DRECTORY)tokens.lex $(HEADERS_INC)
	flex -o $@ $< 

$(BIN_DIRECTORY)bison.tab.cpp: $(SRC_DRECTORY)bison.ypp $(HEADERS_INC)
	bison $(BISON_FLAGS) -Wother -o $@ $< 

reglealakon: $(BIN_DIRECTORY)Variable.o
	echo "coucou"

$(BIN_DIRECTORY)%.o: $(RULE_MEMBER_DIRECTORY)%.cpp $(HEADERS_INC) $(BIN_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)

$(BIN_DIRECTORY):
	mkdir $(BIN_DIRECTORY)

cleanAll: cleano cleanBison cleanFlex

cleano:
	rm $(BIN_DIRECTORY)*.o

cleanBison:
	rm $(BIN_DIRECTORY)bison.tab.cpp

cleanFlex:
	rm $(BIN_DIRECTORY)lex.yy.cpp
