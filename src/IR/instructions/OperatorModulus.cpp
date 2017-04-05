#include "OperatorModulus.h"

#include <sstream>

using namespace IR;

OperatorModulus::OperatorModulus(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}


std::string OperatorModulus::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    ret.append( this->firstValue->getName() );
    ret.append( " % ");
    ret.append( this->secondValue->getName() );
    return ret;
}

std::string OperatorModulus::toLinuxX64() const
{
    std::stringstream ret;  
    ret << "\tmovq\t$0, %rdx";
    ret << "\n\tmovq\t";
    ret << this->firstValue->getASMname(AsmType::X64Linux);
    ret << ", %rax";
    ret << "\n\tidivq\t";
    ret << this->secondValue->getASMname(AsmType::X64Linux);
    ret << "\n\tmovq\t%rdx, ";
    ret << destination->getASMname(AsmType::X64Linux);
    return ret.str();
}

//rax % -16(%rbp)
/* Code en sortie :
	movq $0, %rdx
    movq	-24(%rbp), %rax
    idivq	-16(%rbp)
    movq	%rdx, -8(%rbp)
*/

