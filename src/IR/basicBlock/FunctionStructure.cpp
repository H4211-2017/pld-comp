#include "FunctionStructure.h"

FunctionStructure::FunctionStructure()
{

}

void IR::FunctionStructure::addFunction(std::shared_ptr<IR::FunctionBlock> function)
{
    this->funtionList.push_back(function);
}

void IR::FunctionStructure::printASM(std::ostream &os, IR::AsmType asmType)
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
        func->printASM(os,asmType);
    }

    //add epilog ? :)

}

void IR::FunctionStructure::printX86prolog(std::ostream &os)
{
    os << "\t.text" << std::endl;
    os << "\t.globl\tmain" << std::endl;
    os << "\t.type\tmain, @function" << std::endl;
}

std::list<std::shared_ptr<FunctionBlock> > FunctionStructure::getFuntionList() const
{
    return funtionList;
}
