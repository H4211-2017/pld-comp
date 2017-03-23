#$(word n, $^) is the nth word of the dependency list
#which is strictly equivalent to '$<'

SRC_DIRECTORY=./
BIN_DIRECTORY=../../bin/flex/
RULE_MEMBER_DIRECTORY=$(SRC_DIRECTORY)rulemember/
AST_DIRECTORY=$(SRC_DIRECTORY)AST/
TEST_DIRECTORY=../../test/flex/
LIB_DIRECTORY=../../lib/
INC_DIRECTORY=../../include/
EXPR_DIRECTORY=$(BIN_DIRECTORY)Expression/


CPP_FLAGS=-std=c++11 -DYYDEBUG -g
CPP_FLAGS_OBJ=-c
BISON_FLAGS=-v -d


#SRC=$(find . -name "*.cpp")
#HEADERS=$(find . -name "*.h")


###############################################
#                                             #
#  MAIN DEPENDENCIES FOR AST BUILDING         #
#                                             #
###############################################

#To be updated after each change in list of files
EXPR=Expression/AbstractBinaryExpression.cpp Expression/AbstractExpression.cpp Expression/AddExpression.cpp Expression/Constant.cpp
SRC_AST_NOPATH =$(EXPR) AbstractInstruction.cpp SequenceInstruction.cpp AbstractNode.cpp UnitInstruction.cpp BlockNode.cpp Value.cpp ComposedInstruction.cpp  VariableAssignmentExpression.cpp MainArg.cpp VariableDeclaration.cpp MainBody.cpp	VariableScope.cpp MainType.cpp VariableSignature.cpp
SRC_AST=$(SRC_AST_NOPATH:%.cpp=$(AST_DIRECTORY)%.cpp)
OBJ_AST=$(SRC_AST_NOPATH:%.cpp=$(BIN_DIRECTORY)%.o)
HEADERS_AST=$(SRC_AST_NOPATH:%.cpp=$(AST_DIRECTORY)%.h)



SRCS=$(SRC_RM) $(SRC_AST_NOPATH)
OBJS=$(OBJ_RULE_MEMBER) $(OBJ_AST)
HEADERS=$(HEADERS_RULE_MEMBER) $(HEADERS_AST)
INCLUDE_DIRECTORIES=-I$(BIN_DIRECTORY) -I$(AST_DIRECTORY) -I$(AST_DIRECTORY)Expression -I$(BIN_DIRECTORY)Expression

EXE=$(BIN_DIRECTORY)CParser

all: $(EXE)

$(EXE): $(SRC_DRECTORY)../main.cpp $(BIN_DIRECTORY)bison.tab.cpp $(BIN_DIRECTORY)lex.yy.cpp $(OBJS) $(HEADERS) $(BIN_DIRECTORY) 
	echo $(OBJS)
	g++ $(CPP_FLAGS) -o $(BIN_DIRECTORY)test $(SRC_DIRECTORY)../main.cpp $(BIN_DIRECTORY)lex.yy.cpp $(BIN_DIRECTORY)bison.tab.cpp $(OBJS) $(INCLUDE_DIRECTORIES)

flex: $(BIN_DIRECTORY)lex.yy.cpp 

bison: $(BIN_DIRECTORY)bison.tab.cpp

$(BIN_DIRECTORY)lex.yy.cpp: $(SRC_DRECTORY)tokens.lex $(HEADERS) $(BIN_DIRECTORY)
	flex -o $@ $< 

$(BIN_DIRECTORY)bison.tab.cpp: $(SRC_DRECTORY)bison.ypp $(HEADERS) $(BIN_DIRECTORY)
	bison $(BISON_FLAGS) -Wother -o $@ $< 

$(BIN_DIRECTORY)%.o: $(RULE_MEMBER_DIRECTORY)%.cpp $(HEADERS_RULE_MEMBER) $(BIN_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)

$(BIN_DIRECTORY)%.o: $(AST_DIRECTORY)%.cpp $(HEADERS_AST) $(BIN_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)
	
$(BIN_DIRECTORY)Expression/%.o: $(AST_DIRECTORY)Expression/%.cpp $(HEADERS_AST) $(BIN_DIRECTORY) $(EXPR_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)

$(BIN_DIRECTORY):
	mkdir $(BIN_DIRECTORY)
	
$(EXPR_DIRECTORY):
	mkdir $(EXPR_DIRECTORY)

cleanAll: cleano cleanBison cleanFlex

cleano:
	rm $(BIN_DIRECTORY)*.o $(EXPR_DIRECTORY)*.o 

cleanBison:
	rm $(BIN_DIRECTORY)bison.tab.cpp

cleanFlex:
	rm $(BIN_DIRECTORY)lex.yy.cpp
