#include "Constant.h"

using namespace AST;

Constant::Constant()
    : AbstractExpression("Constant")
{
	
}

Constant::Constant(long int value)
    : AbstractExpression("Constant", Type::INT_64, value)
{

}

Constant::~Constant()
{
	
}

Value Constant::evaluate() const
{
    return value;
}
 
void Constant::buildIR() const
{
	//TODO Complete IR
}

void Constant::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
}
