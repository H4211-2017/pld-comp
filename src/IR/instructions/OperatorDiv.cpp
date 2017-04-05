#include "OperatorDiv.h"

using namespace IR;

OperatorDiv::OperatorDiv(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorDiv::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " / ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorDiv::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getASMname(AsmType::X64Linux) );
    ret.append( ", " );
    ret.append( destination->getASMname(AsmType::X64Linux) );
    ret.append( "\n\tcqto\n\tidivq\t");
    ret.append( this->secondValue->getASMname(AsmType::X64Linux) );
    ret.append(" \n\tmovq\t%rax,");
    ret.append( destination->getASMname(AsmType::X64Linux) );
    return ret;
}
