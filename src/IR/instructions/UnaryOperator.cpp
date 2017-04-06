#include "UnaryOperator.h"

using namespace IR;

UnaryOperator::UnaryOperator(sh_Register resultRegister, sh_Register firstValueRegister, AST::UnaryOp opVal):
    destination(resultRegister), firstValue(firstValueRegister), op(opVal)
{
    this->readRegisterList.push_back(firstValueRegister);
    this->writtenRegisterList.push_back(resultRegister);

    destination->incrementWriteCount();
    firstValue->incrementReadCount();
}

UnaryOperator::~UnaryOperator()
{
    destination->decrementWriteCount();
    firstValue->decrementReadCount();
}

std::string UnaryOperator::toString() const
{
    std::string ret = "";
    ret.append( destination->getName() );
    ret.append( " = ");
    switch(op)
	{
		case AST::UnaryOp::UMINUS:
			ret.append( " - ");
			break;
		case AST::UnaryOp::UPLUS:
			ret.append( " + ");
			break;
		case AST::UnaryOp::UBITN:
			ret.append( " ~ ");
			break;
		case AST::UnaryOp::UBOOLN:
			ret.append( " ! ");
			break;
		default:
			std::cerr << "UnaryOperator::toString() : ERROR unknown op" << std::endl;
	}
    ret.append( this->firstValue->getName() );
    return ret;
}

std::string UnaryOperator::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( this->firstValue->getASMname(AsmType::X64Linux) );
    ret.append( ", %rax" );
    switch(op)
	{
		case AST::UnaryOp::UMINUS:
			ret.append("\n\tmovq\t$0, %rdx");
			ret.append( "\n\tsubq\t%rax, %rdx");
			ret.append("\n\tmovq\t%rdx, ");
			ret.append( destination->getASMname(AsmType::X64Linux) );
			break;
		case AST::UnaryOp::UPLUS:
			ret.append("\n\tmovq\t%rax, ");
			ret.append( destination->getASMname(AsmType::X64Linux) );
			break;
		case AST::UnaryOp::UBITN:
			ret.append("\n\tmovq\t$0xFFFFFFFFFFFFFFFF, %rdx");
			ret.append( "\n\txorq\t%rax, %rdx");
			ret.append("\n\tmovq\t%rdx, ");
			ret.append( destination->getASMname(AsmType::X64Linux) );
			break;
		case AST::UnaryOp::UBOOLN:		
			ret.append( "\n\tcmpq\t$0");
			ret.append( ", %rax");
			ret.append("\n\tsete\t%al\n\tmovzbl\t%al, %eax\n\tmovq\t%rax, ");
			ret.append( destination->getASMname(AsmType::X64Linux) );
			break;
		default:
			std::cerr << "UnaryOperator::toLinuxX64() : ERROR unknown op" << std::endl;
	}
	
	return ret;
}

/* Code en sortie :
    movq	-24(%rbp), %rax
    imulq	-16(%rbp), %rax  // a & b
    cmpq 	$0, %rax
    movq	$0, %rcx
	movq	$1, %rdx
    cmovne	%rdx, %rax
    cmove %rcx, %rax
    movq	%rax, -8(%rbp)
*/
