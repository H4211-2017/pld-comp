#include <memory>

#include "AbstractExpression.h"
#include "Constant.h"

using namespace AST;


class Constant;

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

std::shared_ptr<AbstractExpression> make_shared_expr(AbstractExpression* ptr)
{
	std::cout<<"coucou"<<std::endl;
	return nullptr;
}
