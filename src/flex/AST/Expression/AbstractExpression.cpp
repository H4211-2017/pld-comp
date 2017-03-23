#include "AbstractExpression.h"

using namespace AST;

AbstractExpression::AbstractExpression() : AbstractNode()
{
	
}

AbstractExpression::AbstractExpression(Value value) : AbstractNode(value)
{
	
}

AbstractExpression::AbstractExpression(Type type, long int value) : AbstractNode(type, value)
{
	
}
