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

void yyerror(int * param, const char * msg)
{
	std::cout << msg << std::endl;
    std::cout << msg << std::endl;
}

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

    IR::FunctionBlock mainFunction("main");
    IR::Generator gen;
    IR::sh_Memory memA = gen.getNewUnusedMemmory(IR::Type::INT_64);
    IR::sh_Memory memB = gen.getNewUnusedMemmory(IR::Type::INT_64);
    IR::sh_Memory memC = gen.getNewUnusedMemmory(IR::Type::INT_64);
    std::list<IR::sh_AbsInstruction> instList = gen.binaryOperator<IR::OperatorPlus>(memA,memB,memC);
    mainFunction.getFunctionCore()->pushInstructionBack(instList);
    mainFunction.generateIR();
    mainFunction.printIR(std::cout);
    return 0;
}


//int main(void)
//{
//	int i = 0;
//	yyparse(&i);
//	cout << i << endl;
//}
