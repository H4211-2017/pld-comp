#include "Constant.h"

#include <climits>

using namespace AST;

Constant::Constant()
    : AbstractExpression("Constant")
{
	
}

Constant::Constant(long int value)
    : AbstractExpression("Constant", Type::INT_64, value)
{
	if(value < INT_MAX)
	{
		this->setType(Type::INT_32);
	}
}

Constant::~Constant()
{
	
}

Value Constant::evaluate() const
{
    return value;
}
 
void Constant::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	//TODO Complete IR
}

void Constant::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
}
