#include "ProgrameStructure.h"

using namespace IR;

ProgrameStructure::ProgrameStructure()
{

}

void IR::ProgrameStructure::addFunction(std::shared_ptr<IR::FunctionBlock> function)
{
    this->funtionList.push_back(function);
}

void IR::ProgrameStructure::printASM(std::ostream &os, IR::AsmType asmType)
{
    switch (asmType)
    {
    case AsmType::X86Linux:
        printX86prolog(os);
        break;
    default:
        break;
    }

    for(std::shared_ptr<FunctionBlock> func : this->funtionList)
    {
        func->generateASM(asmType);
        func->printASM(os,asmType);
    }

    //add epilog ? :)

}

void IR::ProgrameStructure::printX86prolog(std::ostream &os)
{
    os << "\t.text" << std::endl;
    os << "\t.globl\tmain" << std::endl;
    os << "\t.type\tmain, @function" << std::endl;
}

std::list<std::shared_ptr<FunctionBlock> > ProgrameStructure::getFuntionList() const
{
    return funtionList;
}
