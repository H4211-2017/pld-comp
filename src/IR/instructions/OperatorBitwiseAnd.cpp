#include "OperatorBitWiseAnd.h"

using namespace IR;

OperatorBitWiseAnd::OperatorBitWiseAnd(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorBitWiseAnd::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " & ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorBitWiseAnd::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getASMname(AsmType::X64Linux) );
    ret.append( ", %rax" );
    ret.append( "\n\tandq\t");
    ret.append( this->secondValue->getASMname(AsmType::X64Linux) );
    ret.append( ", ");
    ret.append( destination->getASMname(AsmType::X64Linux) );
    return ret;
}

/* Code en sortie :
    movq	-24(%rbp), %rax
    testq	-16(%rbp), %rax
    setg	%al
    movzbl	%al, %eax
    movq	%rax, -8(%rbp)
*/
