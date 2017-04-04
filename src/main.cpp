#include <iostream>
#include <map>
#include <memory>

#include "includeCommun.h"


#include "bison.tab.hpp"
#include <list>

#include "IR/generator/Generator.h"
#include "IR/function/FunctionBlock.h"
#include "IR/instructions/AbstractInstruction.h"

extern "C" int yylex();


int main(int argc, char *argv[])
{
    AST::ProgramNode * program;
	
	yyparse(&program);
	
	program->printTree(0);
	
	std::cout << std::endl;
	
	delete program;


/*    IR::FunctionBlock mainFunction("main");
    IR::Generator gen;
    IR::sh_Memory memA = gen.getNewUnusedMemmory(IR::Type::INT_64);
    IR::sh_Memory memB = gen.getNewUnusedMemmory(IR::Type::INT_64);
    IR::sh_Memory memC = gen.getNewUnusedMemmory(IR::Type::INT_64);
    std::list<IR::sh_AbsInstruction> instList = gen.binaryOperator<IR::OperatorPlus>(memA,memB,memC);
    mainFunction.getFunctionCore()->pushInstructionBack(instList);
    instList = gen.binaryOperator<IR::OperatorPlus>(memB,memC,memA);
    mainFunction.getFunctionCore()->pushInstructionBack(instList);
//    mainFunction.generateIR();
//    mainFunction.printIR(std::cout);
    mainFunction.generateASM(IR::AsmType::X86Linux);
    mainFunction.printASM(std::cout,IR::X86Linux);*/
    return 0;
}
