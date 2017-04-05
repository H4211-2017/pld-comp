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
    std::cout << "main avant flex" << std::endl;
    AST::ProgramNode * program;
    yyparse(&program);
    program->printTree(0);
    std::cout << "main apres flex" << std::endl;

    IR::sh_ProgrameStructure programStructure = program->buildIR();

    std::cout << "main apres buildIR" << std::endl;

    programStructure->printASM(std::cout, IR::AsmType::X64Linux);

    std::cout << "main apres printASM" << std::endl;
}
