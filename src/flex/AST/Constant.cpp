#include "Constant.h"

using namespace AST;

Constant::Constant()
{
	
}

/*Constant::Constant(TypeValue value, Type type)
    : Constant()
{
	this->value = value;
	this->type = type;
}*/

Constant::Constant(long int value)
    : AbstractNode(Type::INT_64, value)
{

}

Constant::Constant(char value)
    : AbstractNode(Type::CHAR, value)
{

}

Constant::~Constant()
{
	
}

Value Constant::evaluate() const
{
    Value ret;
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
