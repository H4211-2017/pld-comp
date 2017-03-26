#include <iostream>

#include "VariableScope.h"
#include "AbstractExpression.h"

using namespace AST;


VariableScope::VariableScope()
{

}

void VariableScope::declareVariable(std::string identifiant, std::shared_ptr<AbstractExpression> variable)
{
    auto pair = std::pair<std::string, std::shared_ptr<AbstractExpression> >(identifiant, variable);
    auto result = scope.insert(pair);
    if (!result.second)
    {
        std::cerr << "VariableScope::declareVariable : a variable already existed with name " << identifiant << std::endl;
    }
}

std::shared_ptr<AbstractExpression> VariableScope::findVariable(std::string identifiant)
{
	auto it = scope.find(identifiant);
	if( it == scope.end() )
	{
		throw UndeclaredIdException();
		
	}
	else
	{
		return it->second;
	}

}

void VariableScope::setVariable(std::string identifiant, std::shared_ptr<AbstractExpression> newExpr)
{
	auto it = scope.find(identifiant);
	if( it == scope.end() )
	{
		throw UndeclaredIdException();
	}
	else
	{
		newExpr->setType(scope[identifiant]->getValue().getValue().first);
		scope[identifiant] = newExpr;
	}
}

VariableScope::~VariableScope()
{}
