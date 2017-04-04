#include "OperatorMult.h"

using namespace IR;

OperatorMult::OperatorMult(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorMult::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " * ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorMult::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getAsmRegisterName() );
    ret.append( ", " );
    ret.append( destination->getAsmRegisterName() );
    ret.append( "\n\timulq\t");
    ret.append( this->secondValue->getAsmRegisterName() );
    ret.append( ", ");
    ret.append( destination->getAsmRegisterName() );
    return ret;
}
