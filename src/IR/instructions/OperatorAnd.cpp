#include "OperatorAnd.h"

using namespace IR;

OperatorAnd::OperatorAnd(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorAnd::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " && ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorAnd::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getAsmRegisterName() );
    ret.append( ", %rax" );
    ret.append( "\n\ttestq\t");
    ret.append( this->secondValue->getAsmRegisterName() );
    ret.append( ", %rax");
    ret.append("\nsetg\t%al\n\tmovzbl\t%al, %eax\nmovq\t%rax, ");
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
