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
#include "IR/basicBlock/ProgrameStructure.h"

extern "C" int yylex();
extern FILE* yyin;

int main(int argc, char *argv[])
{
    std::string fileToCompile;
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
            fileToCompile = argv[i];
		}
	}
	
    if(fileToCompile.length() > 0)
	{
        yyin = fopen(fileToCompile.c_str(), "r");
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
	
    if(fileToCompile.length() > 0)
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


    std::shared_ptr<IR::ProgrameStructure> programStructure = program->buildIR();

    programStructure->printIR(std::cout);

    //programStructure->printASM(std::cout, IR::AsmType::X64Linux);
	delete program;

    return 0;
}
