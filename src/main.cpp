#include <iostream>
#include <map>
#include <memory>

#include "includeCommun.h"


#include "bison.tab.hpp"
#include <list>
#include <cstring>
#include <fstream> 
#include <iostream> 

#include "IR/generator/Generator.h"
#include "IR/function/FunctionBlock.h"
#include "IR/instructions/AbstractInstruction.h"

extern "C" int yylex();
extern FILE* yyin;


int main(int argc, char *argv[])
{
	std::string fichierACompiler;
	std::string target;
	std::string ASTtarget;
	std::streambuf* oldBuf;
	bool verbose = false;
	int i = 1;
	if( argc > 7 )
	{
		std::cerr << "ERROR : Too many arguments" << std::endl;
		exit(-1);
	}
	for(; i<argc; i++)
	{
		if(strcmp(argv[i], "-o") == 0)
		{
			i++;
			if(i == argc || argv[i][0] == '-')
			{
				std::cerr << "ERROR : no target defined" << std::endl;
				exit(-1);
			}
			target = argv[i];
		}
		else if(strcmp(argv[i], "-t") == 0)
		{
			i++;
			if(i == argc || argv[i][0] == '-')
			{
				std::cerr << "ERROR : no AST-target defined" << std::endl;
				exit(-1);
			}
			ASTtarget = argv[i];
		}
		else if(strcmp(argv[i], "-v") == 0)
		{
			verbose = true;
		}
		else
		{
			fichierACompiler = argv[i];
		}
	}
	
	if(fichierACompiler.length() > 0)
	{
		yyin = fopen(fichierACompiler.c_str(), "r");
	}
	
    AST::ProgramNode * program;
	
	if(!verbose)
	{
		std::cout.setstate(std::ios_base::failbit);
		yyparse(&program);
		std::cout.clear();
	}
	else
	{
		yyparse(&program);	
	}
	
	if(fichierACompiler.length() > 0)
		fclose(yyin);
    
    if(ASTtarget.length() > 0)
    {
		std::ofstream out(ASTtarget); 
		oldBuf = std::cout.rdbuf(out.rdbuf()); 
	  	
		program->printTree(0);
		// Restauration du streambuf initial de std::cout (affichage sur la console) 
		std::cout.rdbuf(oldBuf); 
	}
	else if(verbose)
	{
		program->printTree(0);				
		std::cout << std::endl;
	}
	
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
    mainFunction.printASM(std::cout,IR::AsmType::X86Linux);*/
    return 0;
}
