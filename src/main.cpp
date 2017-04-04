#include <iostream>
#include <map>
#include <memory>

#include "includeCommun.h"


#include "bison.tab.hpp"
#include <list>

#include "IR/generator/Generator.h"
#include "IR/function/FunctionBlock.h"
#include "IR/instructions/AbstractInstruction.h"
#include "IR/basicBlock/ProgrameStructure.h"

extern "C" int yylex();


int main(int argc, char *argv[])
{
//	shared_ptr< mapVar > i = make_shared< mapVar >();

//	try
//	{
//		yyparse(&i);
//	}
//	catch(string s)
//	{
//		cout << s << endl;
//	}

//	for(mapVar::iterator it = i->begin(); it != i->end(); it++)
//	{
//		cout << it->second->toString();
//	}

//    long int i = 0;

//	yyparse(&i);
//	std::cout << i << std::endl;

//}

//int main(void)
//{
//    AST::ProgramNode * program;
	
//	yyparse(&program);
	
//	program->printTree(0);
	
//	std::cout << std::endl;
	
//	delete program;
    std::list<IR::sh_Memory> listArg;

    IR::ProgrameStructure structure;
    IR::sh_FunctionBlock mainFunction = std::make_shared<IR::FunctionBlock>("main", IR::INT_32, listArg);
    IR::Generator gen;
    IR::sh_Memory memA = gen.getNewUnusedMemmory(IR::Type::INT_64);
    IR::sh_Memory memB = gen.getNewUnusedMemmory(IR::Type::INT_64);
    IR::sh_Memory memC = gen.getNewUnusedMemmory(IR::Type::INT_64);
    std::list<IR::sh_AbsInstruction> instList = gen.binaryOperator<IR::OperatorPlus>(memA,memB,memC);
    mainFunction->getFunctionCore()->pushInstructionBack(instList);
    instList = gen.binaryOperator<IR::OperatorPlus>(memB,memC,memA);
    mainFunction->getFunctionCore()->pushInstructionBack(instList);
//    mainFunction.generateIR();
//    mainFunction.printIR(std::cout);
    structure.addFunction(mainFunction);
    structure.printASM(std::cout, IR::AsmType::X64Linux);
    return 0;
}


//int main(void)
//{
//	int i = 0;
//	yyparse(&i);
//	cout << i << endl;
//}
