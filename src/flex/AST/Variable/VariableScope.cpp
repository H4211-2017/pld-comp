#include <iostream>

#include "VariableScope.h"
#include "Variable.h"

using namespace AST;


VariableScope::VariableScope()
{

}

void VariableScope::declareVariable(std::string identifiant, std::shared_ptr<AbstractVariable> variable)
{
    auto pair = std::pair<std::string, std::shared_ptr<AbstractVariable> >(identifiant, variable);
    auto result = scope.insert(pair);
    if (!result.second)
    {
        std::cerr << "VariableScope::declareVariable : a variable already existed with name " << identifiant << std::endl;
        exit(-1);
    }
}

std::shared_ptr<AbstractVariable> VariableScope::findVariable(std::string identifiant)
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

std::shared_ptr<AbstractVariable>* VariableScope::findVariableAddress(std::string identifiant)
{
	auto it = scope.find(identifiant);
	if( it == scope.end() )
	{
		throw UndeclaredIdException();
		
	}
	else
	{
		return &it->second;
	}
}

VariableScope::~VariableScope()
{}

UndeclaredIdException::UndeclaredIdException()
{
    this->text = "Error : Undeclared Identifier";
}

UndeclaredIdException::UndeclaredIdException(std::string text)
{
    this->text = text;
}
