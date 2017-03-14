#$(word n, $^) is the nth word of the dependency list

SRC_DIRECTORY=../src/
BIN_DIRECTORY=../bin/
RULE_MEMBER_DIRECTORY=../src/RuleMember/
TEST_DIRECTORY=../test/

INCLUDE_DIRECTORIES=-I $(BIN_DIRECTORY) -I $(RULE_MEMBER_DIRECTORY) -I $(SRC_DIRECTORY)

CPP_FLAGS=-std=c++11 -DYYDEBUG -g -o
CPP_FLAGS_OBJ= -c
BISON_FLAGS=-v -d

#To be updated after each change in list of files
SRC=TypeChar.cpp  TypeInt32.cpp  TypeInt64.cpp  Variable.cpp fcBison.cpp
SRC_RULE_MEMBER=$(SRC:%.cpp=$(RULE_MEMBER_DIRECTORY)%.cpp)
HEADERS_RULE_MEMBER=$(SRC:%.cpp=$(RULE_MEMBER_DIRECTORY)%.h) $(RULE_MEMBER_DIRECTORY)
OBJ_RULE_MEMBER=$(SRC:%.cpp=$(BIN_DIRECTORY)%.o)

$(BIN_DIRECTORY)CParser: $(OBJ_RULE_MEMBER) $(BIN_DIRECTORY)main.o $(BIN_DIRECTORY)bison.tab.cpp $(BIN_DIRECTORY)lex.yy.c
	g++ $(CPP_FLAGS) $@ $^ $(INCLUDE_DIRECTORIES) 

$(BIN_DIRECTORY)main.o: $(SRC_DRECTORY)main.cpp $(BIN_DIRECTORY)bison.tab.cpp $(BIN_DIRECTORY)lex.yy.c $(HEADERS_RULE_MEMBER) 
	g++ $(CPP_FLAGS) $@ $(CPP_FLAGS_OBJ) $(SRC_DRECTORY)main.cpp $(INCLUDE_DIRECTORIES) 

$(BIN_DIRECTORY)lex.yy.c: $(SRC_DRECTORY)tokens.lex $(HEADERS_RULE_MEMBER) 
	flex -o $(BIN_DIRECTORY)lex.yy.c $(SRC_DRECTORY)tokens.lex
	
$(BIN_DIRECTORY)bison.tab.cpp: $(SRC_DRECTORY)bison.ypp $(HEADERS_RULE_MEMBER)
	bison $(BISON_FLAGS) -o $(BIN_DIRECTORY)bison.tab.cpp $(SRC_DRECTORY)bison.ypp
	
$(BIN_DIRECTORY)%.o: $(RULE_MEMBER_DIRECTORY)%.cpp $(HEADERS_RULE_MEMBER)
	g++ $(CPP_FLAGS) $@ $(CPP_FLAGS_OBJ) $(word 1,$^) $(INCLUDE_DIRECTORIES)
