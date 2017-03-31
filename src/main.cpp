#include <iostream>
#include <map>
#include <memory>

#include "includeCommun.h"


#include "bison.tab.hpp"


extern "C" int yylex();

int main(void)
{
    AST::ProgramNode * program;
	
	yyparse(&program);
	
	program->printTree(0);
	
	std::cout << std::endl;
	
	delete program;

}


