#include "OperatorPlus.h"

using namespace IR;

OperatorPlus::OperatorPlus(sh_Register resultRegister,
                           sh_Register firstValueRegister,
                           sh_Register secondValueRegister):
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorPlus::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " + ");
    ret.append( this->secondValue->getName() );
    return ret;
}


std::string OperatorPlus::toLinuxX86() const
{

}
