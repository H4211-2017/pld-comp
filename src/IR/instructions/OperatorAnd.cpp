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
    ret.append("\n\tmovq\t$0, %rcx\n\tmovq\t$1, %rdx");
    ret.append("\n\tcmovne\t%rdx, %al\n\tcmove\t%rcx, %al\n\tmovq\t%rax, ");
    ret.append( destination->getASMname(AsmType::X64Linux) );
    return ret;
}

/* Code en sortie :
    movq	-24(%rbp), %rax
    testq	-16(%rbp), %rax  // a & b
    movq	$0, %rcx
	movq	$1, %rdx
    cmovne	$1, %rax
    cmove $0, %rax
    movq	%rax, -8(%rbp)
*/
