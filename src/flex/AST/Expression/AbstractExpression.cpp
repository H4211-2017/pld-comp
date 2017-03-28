#include <memory>
#include <string>
#include <stdexcept>

#include "AbstractExpression.h"
#include "AddExpression.h"
#include "IDExpression.h"
#include "AffectationExpression.h"
#include "Constant.h"
#include "Function/FunctionCall.h"

using namespace AST;


AbstractExpression::AbstractExpression(std::string name)
    : AbstractNode(name)
{
	
}

AbstractExpression::AbstractExpression(std::string name, Value value)
    : AbstractNode(name, value)
{
	
}

AbstractExpression::AbstractExpression(std::string name, Type type)
    : AbstractNode(name, type)
{

}

AbstractExpression::AbstractExpression(std::string name, Type type, long int value)
    : AbstractNode(name, type, value)
{
	
}

std::shared_ptr<AbstractExpression> make_shared_expr(AbstractExpression* ptr)
{
	std::string name = ptr->getName();
	if( name == "Constant")
	{
		return std::make_shared<Constant>( *( static_cast< Constant* >(ptr) ) );
	}
	else if(name == "AddExpression")
	{
		return std::make_shared<AddExpression>( *( static_cast< AddExpression* >(ptr) ) );
	}
	else if(name == "IDExpression")
	{
		return std::make_shared<IDExpression>( *( static_cast< IDExpression* >(ptr) ) );
	}
	else if(name == "AffectationExpression")
	{
		return std::make_shared<AffectationExpression>( *( static_cast< AffectationExpression* >(ptr) ) );
	}
    else if(name == "FunctionCall")
	{
        return std::make_shared<FunctionCall>( *( static_cast< FunctionCall* >(ptr) ) );
	}
	else
	{	
		
		std::cerr<< " AbstractExpression :: make_shared_ptr found no type like '" << name << "'" << std::endl;
		throw std::runtime_error("Runtime Error");
	}
}
