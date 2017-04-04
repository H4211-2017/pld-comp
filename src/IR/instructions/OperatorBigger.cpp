#include "OperatorBigger.h"

using namespace IR;

OperatorBigger::OperatorBigger(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorBigger::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " > ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorBigger::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getAsmRegisterName() );
    ret.append( ", %rax" );
    ret.append( "\n\tcmpq\t");
    ret.append( this->secondValue->getAsmRegisterName() );
    ret.append( ", %rax");
    ret.append("\nsetg\t%al\n\tmovzbl\t%al, %eax\nmovq\t%rax, ");
    ret.append( destination->getAsmRegisterName() );
    return ret;
}

/* Code en sortie :
    movq	-24(%rbp), %rax
    cmpq	-16(%rbp), %rax
    setg	%al
    movzbl	%al, %eax
    movq	%rax, -8(%rbp)
*/
