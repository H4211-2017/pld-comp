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
INSTR_DIRECTORY=$(BIN_DIRECTORY)Instruction/
FCT_DIRECTORY=$(BIN_DIRECTORY)Function/
VAR_DIRECTORY=$(BIN_DIRECTORY)Variable/
STRUCT_DIRECTORY=$(BIN_DIRECTORY)Structure/


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
STRUCT=Structure/AbstractStructure.cpp  Structure/ElseStructure.cpp  Structure/IfStructure.cpp
FCT=Function/FunctionScope.cpp Function/FunctionSignature.cpp Function/LArguments.cpp Function/Function.cpp Function/FunctionDeclaration.cpp Function/FunctionCall.cpp Function/LParametres.cpp
VAR=Variable/VariableSignature.cpp Variable/VariableDeclaration.cpp Variable/VariableScope.cpp Variable/Variable.cpp
EXPR=Expression/AbstractBinaryExpression.cpp  Expression/ArrayExpression.cpp  Expression/Constant.cpp  Expression/IDExpression.cpp Expression/InfExpression.cpp   Expression/SubExpression.cpp Expression/AbstractExpression.cpp  Expression/BitwiseAndExpression.cpp  Expression/ModuloExpression.cpp   Expression/SupEqExpression.cpp Expression/AddExpression.cpp   Expression/BitwiseOrExpression.cpp Expression/MultExpression.cpp   Expression/SupExpression.cpp Expression/AffectationExpression.cpp  Expression/BitwiseShiftLeftExpression.cpp  Expression/DivExpression.cpp Expression/IneqExpression.cpp Expression/OrExpression.cpp    Expression/UnaryExpression.cpp Expression/AndExpression.cpp   Expression/BitwiseXorExpression.cpp Expression/EqExpression.cpp  Expression/InfEqExpression.cpp Expression/ParenthesisExpression.cpp
INSTR=Instruction/AbstractInstruction.cpp Instruction/ComposedInstruction.cpp Instruction/SequenceInstruction.cpp Instruction/UnitInstruction.cpp
SRC_AST_NOPATH =$(EXPR) $(INSTR) $(FCT) $(VAR) $(STRUCT) AbstractNode.cpp Block.cpp Value.cpp  Scope.cpp 
SRC_AST=$(SRC_AST_NOPATH:%.cpp=$(AST_DIRECTORY)%.cpp)
OBJ_AST=$(SRC_AST_NOPATH:%.cpp=$(BIN_DIRECTORY)%.o)
HEADERS_AST=$(SRC_AST_NOPATH:%.cpp=$(AST_DIRECTORY)%.h)



SRCS=$(SRC_RM) $(SRC_AST_NOPATH)
OBJS=$(OBJ_RULE_MEMBER) $(OBJ_AST)
HEADERS=$(HEADERS_RULE_MEMBER) $(HEADERS_AST)
INCLUDE_DIRECTORIES=-I$(BIN_DIRECTORY) -I$(AST_DIRECTORY) -I$(AST_DIRECTORY)Expression -I$(BIN_DIRECTORY)Expression -I$(AST_DIRECTORY)Instruction -I$(BIN_DIRECTORY)Instruction -I$(AST_DIRECTORY)Function -I$(BIN_DIRECTORY)Function -I$(AST_DIRECTORY)Variable -I$(BIN_DIRECTORY)Variable -I$(AST_DIRECTORY)Structure -I$(BIN_DIRECTORY)Structure

EXE=$(BIN_DIRECTORY)CParser

all: $(EXE)

$(EXE): $(SRC_DRECTORY)../main.cpp $(BIN_DIRECTORY)bison.tab.cpp $(BIN_DIRECTORY)lex.yy.cpp $(OBJS) $(HEADERS) $(BIN_DIRECTORY) $(EXPR_DIRECTORY) $(INSTR_DIRECTORY) $(VAR_DIRECTORY) $(STRUCT_DIRECTORY)
	echo ;
	g++ $(CPP_FLAGS) -o $(BIN_DIRECTORY)CParser $(SRC_DIRECTORY)../main.cpp $(BIN_DIRECTORY)lex.yy.cpp $(BIN_DIRECTORY)bison.tab.cpp $(OBJS) $(INCLUDE_DIRECTORIES)

flex: $(BIN_DIRECTORY)lex.yy.cpp 

bison: $(BIN_DIRECTORY)bison.tab.cpp

$(BIN_DIRECTORY)lex.yy.cpp: $(SRC_DRECTORY)tokens.lex $(HEADERS) $(BIN_DIRECTORY)
	flex -o $@ $< 

$(BIN_DIRECTORY)bison.tab.cpp: $(SRC_DRECTORY)bison.ypp $(HEADERS) $(BIN_DIRECTORY)
	bison $(BISON_FLAGS) -Wno-other -Wconflicts-sr -o $@ $< 

$(BIN_DIRECTORY)%.o: $(AST_DIRECTORY)%.cpp $(HEADERS_AST) $(BIN_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)
	
$(EXPR_DIRECTORY)%.o: $(AST_DIRECTORY)Expression/%.cpp $(HEADERS_AST) $(BIN_DIRECTORY) $(EXPR_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)
	
$(INSTR_DIRECTORY)%.o: $(AST_DIRECTORY)Instruction/%.cpp $(HEADERS_AST) $(BIN_DIRECTORY) $(INSTR_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)
	
$(FCT_DIRECTORY)%.o: $(AST_DIRECTORY)Function/%.cpp $(HEADERS_AST) $(BIN_DIRECTORY) $(FCT_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)
	
$(VAR_DIRECTORY)%.o: $(AST_DIRECTORY)Function/%.cpp $(HEADERS_AST) $(BIN_DIRECTORY) $(VAR_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)
	
$(STRUCT_DIRECTORY)%.o: $(AST_DIRECTORY)Function/%.cpp $(HEADERS_AST) $(BIN_DIRECTORY) $(STRUCT_DIRECTORY)
	g++ $(CPP_FLAGS) -o $@ $(CPP_FLAGS_OBJ) $< $(INCLUDE_DIRECTORIES)

$(BIN_DIRECTORY):
	mkdir ../../bin
	mkdir $(BIN_DIRECTORY)
	
$(EXPR_DIRECTORY):
	mkdir $(EXPR_DIRECTORY)
	
$(INSTR_DIRECTORY):
	mkdir $(INSTR_DIRECTORY)
	
$(VAR_DIRECTORY):
	mkdir $(VAR_DIRECTORY)
	
$(STRUCT_DIRECTORY):
	mkdir $(STRUCT_DIRECTORY)

cleanAll: cleano cleanBison cleanFlex

cleano:
	rm $(BIN_DIRECTORY)*.o $(EXPR_DIRECTORY)*.o $(INSTR_DIRECTORY)*.o 

cleanBison:
	rm $(BIN_DIRECTORY)bison.tab.cpp

cleanFlex:
	rm $(BIN_DIRECTORY)lex.yy.cpp
