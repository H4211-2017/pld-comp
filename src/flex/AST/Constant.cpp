#include "Constant.h"

using namespace AST;

Constant::Constant() : AbstractNode()
{
	
}

/*Constant::Constant(TypeValue value, Type type) : 
Constant()
{
	this->value = value;
	this->type = type;
}*/

Constant::Constant(long int value) : 
Constant()
{
	this->value.int64 = value;
	this->type = INT_64;
}

Constant::Constant(char value) : 
Constant()
{
    this->value.character = value;
	this->type = CHAR;
}

Constant::~Constant()
{
	
}

std::shared_ptr<std::pair<TypeValue, Type>> Constant::evaluate() const
{
    return std::make_shared<std::pair<TypeValue, Type>>(value, type);
}
 
void Constant::buildIR() const
{
	//TODO Complete IR
}

void Constant::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
}
