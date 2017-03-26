#include <iostream>

#include "VariableScope.h"
#include "AbstractExpression.h"

using namespace AST;


VariableScope::VariableScope()
	: mother(nullptr)
{

}

VariableScope::VariableScope( std::shared_ptr<VariableScope> variableScope )
{
	mother = variableScope;
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
	try
	{
		auto it = scope.find(identifiant);
		if( it == scope.end() )
		{
			if( mother == nullptr )
			{
				throw UndeclaredIdException();
			}
			else
			{
				return mother->findVariable(identifiant);
			}
		}
		else
		{
			return it->second;
		}
		
		
	}
	catch(std::exception& e)
	{
		std::cerr << "VariableScope::findVariable ( " << identifiant << " ) : "<< e.what() << std::endl;
		exit(-1);
	}	
}

void VariableScope::setVariable(std::string identifiant, std::shared_ptr<AbstractExpression> newExpr)
{
	try
	{
		auto it = scope.find(identifiant);
		if( it == scope.end() )
		{
			if( mother == nullptr )
			{
				throw UndeclaredIdException();
			}
			else
			{
				mother->setVariable(identifiant, newExpr);
			}
		}
		else
		{
			newExpr->setType(scope[identifiant]->getValue().getValue().first);
			scope[identifiant] = newExpr;
		}
		
		
	}
	catch(std::exception& e)
	{
		std::cerr << "VariableScope::setVariable ( " << identifiant << " ) : "<< e.what() << std::endl;
		exit(-1);
	}	
}
        
std::shared_ptr<VariableScope> VariableScope::getMother() const
{
	return mother;
}

VariableScope::~VariableScope()
{}
