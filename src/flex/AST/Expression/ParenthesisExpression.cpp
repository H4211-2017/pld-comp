#include "ParenthesisExpression.h"

using namespace AST;

ParenthesisExpression::ParenthesisExpression(std::shared_ptr<AbstractInstruction> instr)
    : AbstractExpression("ParenthesisExpression")
{
	this->instr = instr;
	this->setType(instr->getValue().getValue().first);
}


ParenthesisExpression::~ParenthesisExpression() 
{

}

Value ParenthesisExpression::evaluate() const
{
	return Value();
}

void ParenthesisExpression::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    instr->printTree(tabulationNumber + 1);
}

IR::sh_Memory ParenthesisExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{	
	return instr->buildIR(currentBasicBlock);
}
