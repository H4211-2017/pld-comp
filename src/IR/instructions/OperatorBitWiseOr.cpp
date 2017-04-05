#include "OperatorBitWiseOr.h"

using namespace IR;

OperatorBitWiseOr::OperatorBitWiseOr(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorBitWiseOr::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " | ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorBitWiseOr::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getAsmRegisterName() );
    ret.append( ", %rax" );
    ret.append( "\n\torq\t");
    ret.append( this->secondValue->getAsmRegisterName() );
    ret.append( ", ");
    ret.append( destination->getAsmRegisterName() );
    return ret;
}

/* Code en sortie :
    movq	-24(%rbp), %rax
    testq	-16(%rbp), %rax
    setg	%al
    movzbl	%al, %eax
    movq	%rax, -8(%rbp)
*/