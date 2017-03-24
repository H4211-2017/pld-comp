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

Constant::Constant(char value)
    : AbstractExpression("Constant", Type::CHAR, value)
{

}

Constant::~Constant()
{
	
}

Value Constant::evaluate() const
{
    Value ret = this->value;
    return ret;
    //return std::make_shared<std::pair<TypeValue, Type>>(value, type);
}
 
void Constant::buildIR() const
{
	//TODO Complete IR
}

void Constant::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
}
