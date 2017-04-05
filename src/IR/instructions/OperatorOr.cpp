#include "OperatorOr.h"

using namespace IR;

OperatorOr::OperatorOr(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorOr::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " || ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorOr::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getAsmRegisterName() );
    ret.append( ", %rax" );
    ret.append( "\n\addq\t");
    ret.append( this->secondValue->getAsmRegisterName() );
    ret.append( ", %rax");
    ret.append("\ncmpq\t%rax, $0");
    ret.append("\nsetg\t%al\ncmovne\t$1, %al\ncmove\t$0, %al\nmovq\t%rax, ");
    ret.append( destination->getAsmRegisterName() );
    return ret;
}

/* Code en sortie :
    movq	-24(%rbp), %rax
    addq	-16(%rbp), %rax  // a + b
    cmpq    %rax, $0
    setg 	%al
    cmovne	$1, %al
    cmove $0, %al
    movq	%rax, -8(%rbp)
*/
