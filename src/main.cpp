#include <iostream>
#include "bison.tab.hpp"
#include <list>

#include "IR/generator/Generator.h"
#include "IR/function/FunctionBlock.h"
#include "IR/instructions/AbstractInstruction.h"

extern "C" int yylex();

void yyerror(int * param, const char * msg)
{
    std::cout << msg << std::endl;
}

int main(int argc, char *argv[])
{
    IR::FunctionBlock mainFunction("main");
    IR::Generator gen;
    IR::sh_Memory memA = gen.getNewUnusedMemmory(IR::Type::Long);
    IR::sh_Memory memB = gen.getNewUnusedMemmory(IR::Type::Long);
    IR::sh_Memory memC = gen.getNewUnusedMemmory(IR::Type::Long);
    std::list<IR::sh_AbsInstruction> instList = gen.binaryOperator<IR::OperatorPlus>(memA,memB,memC);
    mainFunction.getFunctionCore()->pushInstructionBack(instList);
    mainFunction.generateBasicBlockList();
    mainFunction.printIR(std::cout);
    return 0;
}


//int main(void)
//{
//	int i = 0;
//	yyparse(&i);
//	cout << i << endl;
//}
