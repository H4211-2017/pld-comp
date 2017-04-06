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
    std::string ret = "";
    //move source into destination (unless they are the same or the operation is a '!')
    if(op != AST::UnaryOp::UBOOLN && firstValue->getASMname(AsmType::X64Linux) != destination->getASMname(AsmType::X64Linux))
    {
        ret.append( "\tmovq\t");
        ret.append( this->firstValue->getASMname(AsmType::X64Linux) );
        ret.append( ", ");
        ret.append( this->destination->getASMname(AsmType::X64Linux));
    }

    switch(op)
    {
    case AST::UnaryOp::UMINUS:
        ret.append("\n\tnegq\t");
        ret.append( this->destination->getASMname(AsmType::X64Linux) );
        break;
    case AST::UnaryOp::UPLUS:
        //nothing to do
        break;
    case AST::UnaryOp::UBITN:
        ret.append("\n\tnotq\t");
        ret.append( this->destination->getASMname(AsmType::X64Linux) );
        break;
    case AST::UnaryOp::UBOOLN:
        ret.append( "\n\tcmpq\t$0, " );
        ret.append( this->firstValue->getASMname(AsmType::X64Linux) );
        ret.append( "\n\tsete\t%al");
        ret.append( "\n\tmovzbl\t%al, %eax");
        ret.append( "\n\tmovq\t%rax, ");
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
