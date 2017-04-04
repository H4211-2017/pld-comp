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
    AST::ProgramNode * program;
    yyparse(&program);

    std::shared_ptr<IR::ProgrameStructure> programStructure = program->buildIR();
    programStructure->printASM(std::cout, IR::AsmType::X64Linux);
}
