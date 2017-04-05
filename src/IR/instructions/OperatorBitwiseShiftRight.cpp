#include "OperatorBitWiseShiftRight.h"

using namespace IR;

OperatorBitWiseShiftRight::OperatorBitWiseShiftRight(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorBitWiseShiftRight::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " >> ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorBitWiseShiftRight::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getAsmRegisterName() );
    ret.append( ", %rax" );
    ret.append( "\n\tshrq\t");
    ret.append( this->secondValue->getAsmRegisterName() );
    ret.append( ", ");
    ret.append( destination->getAsmRegisterName() );
    return ret;
}
