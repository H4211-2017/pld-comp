#include "OperatorSmallerOrEqual.h"

using namespace IR;

OperatorSmallerOrEqual::OperatorSmallerOrEqual(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}

std::string OperatorSmallerOrEqual::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " <= ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorSmallerOrEqual::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getASMname(AsmType::X64Linux) );
    ret.append( ", %rax" );
    ret.append( "\n\tcmpq\t");
    ret.append( this->secondValue->getASMname(AsmType::X64Linux) );
    ret.append( ", %rax");
    ret.append("\n\tsetle\t%al\n\tmovzbl\t%al, %eax\n\tmovq\t%rax, ");
    ret.append( destination->getASMname(AsmType::X64Linux) );
    return ret;
}

/* Code en sortie :
    movq	-24(%rbp), %rax
    cmpq	-16(%rbp), %rax
    setle	%al
    movzbl	%al, %eax
    movq	%rax, -8(%rbp)
*/
