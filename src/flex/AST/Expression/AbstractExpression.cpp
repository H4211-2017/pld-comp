#include "AbstractExpression.h"

using namespace AST;

AbstractExpression::AbstractExpression(std::string name)
    : AbstractNode(name)
{
	
}

AbstractExpression::AbstractExpression(std::string name, Value value)
    : AbstractNode(name, value)
{
	
}

AbstractExpression::AbstractExpression(std::string name, Type type, long int value)
    : AbstractNode(name, type, value)
{
	
}
