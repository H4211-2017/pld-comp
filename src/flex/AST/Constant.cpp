#include "Constant.h"

using namespace AST;

Constant::Constant() : Node()
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
	this->value.car = value;
	this->type = CHAR;
}

Constant::~Constant()
{
	
}

std::pair<TypeValue, Type> Constant::evaluate() const
{
	return std::pair<TypeValue, Type>(value, type);
}
 
std::string Constant::toIR() const
{
	return "";
	//TODO Complete IR
}
