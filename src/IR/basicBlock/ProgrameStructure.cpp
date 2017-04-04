#include "ProgrameStructure.h"

using namespace IR;

ProgrameStructure::ProgrameStructure()
{

}

void ProgrameStructure::addFunction(std::shared_ptr<FunctionBlock> function)
{
    this->funtionList.push_back(function);
}

void ProgrameStructure::printASM(std::ostream &os, AsmType asmType)
{
    switch (asmType)
    {
    case AsmType::X64Linux:
        printX64prolog(os);
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

void ProgrameStructure::printX64prolog(std::ostream &os)
{
    os << "\t.text" << std::endl;
}

std::list<std::shared_ptr<FunctionBlock> > ProgrameStructure::getFuntionList() const
{
    return funtionList;
}
