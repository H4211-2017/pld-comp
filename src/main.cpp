#include <iostream>
#include <map>
#include <memory>

#include "includeCommun.h"
#include "OptionScanner.h"

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
	lake::OptionScanner options = lake::OptionScanner();
	options.parseConsoleOptions(argc, argv);
	
	std::streambuf* oldBuf;
	
	/* ******************************************
	 * 			Fetching the Source File		*
	 * ******************************************/
	//Note : if no file is given, the input will be taken from cin
	if( options.srcFile.length() > 0)
	{
		yyin = fopen(options.srcFile.c_str(), "r");
	}
	
	
	
	/* ******************************************
	 * 				Building AST				*
	 * ******************************************/
    AST::ProgramNode * program;//AST storage for the whole source program
	if( !(options.verbose) )
	{
		//artificial muting of cout to ignore output from flex
		std::cout.setstate(std::ios_base::failbit);
		yyparse(&program);
		std::cout.clear();
	}
	else //verbose will display flex output
	{
		yyparse(&program);	
	}	
	// safely closing the Source File if it was specified
	if( options.srcFile.length() > 0)
		fclose(yyin);
    //Writing AST output in priority to the target
    if( options.ASTtarget.length() > 0)
    {
		std::ofstream out( options.ASTtarget); 
		oldBuf = std::cout.rdbuf(out.rdbuf()); 
	  	
		program->printTree(0);
		// Restauration du streambuf initial de std::cout (affichage sur la console) 
		std::cout.rdbuf(oldBuf); 
	}
	else if(options.verbose) //Writing AST output to the console
	{
		program->printTree(0);				
		std::cout << std::endl;
	}
	
	//Deleting the dynamically allocated AST node
	if (program)
	{
		delete program;
	}

    return 0;
}
