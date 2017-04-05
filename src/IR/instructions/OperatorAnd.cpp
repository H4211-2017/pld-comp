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
    ret.append( this->firstValue->getASMname(AsmType::X64Linux) );
    ret.append( ", %rax" );
    ret.append( "\n\ttestq\t");
    ret.append( this->secondValue->getASMname(AsmType::X64Linux) );
    ret.append( ", %rax");
    ret.append("\nsetg\t%al\ncmovne\t$1, %al\ncmove\t$0, %al\nmovq\t%rax, ");
    ret.append( destination->getAsmRegisterName() );
    return ret;
}

/* Code en sortie :
    movq	-24(%rbp), %rax
    testq	-16(%rbp), %rax  // a & b
    setg 	%al
    cmovne	$1, %al
    cmove $0, %al
    movq	%rax, -8(%rbp)
*/
