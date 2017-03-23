#include <iostream>

#include "VariableScope.h"

using namespace AST;


VariableScope::VariableScope() :
	mother(nullptr)
{
}

VariableScope::VariableScope( VariableScope & variableScope ) :
	mother( &variableScope )
{
	
}

void VariableScope::declareVariable( std::string identifiant, std::pair<Type, TypeValue> variable)
{
	scope.emplace(identifiant, variable);
}

std::pair<Type, TypeValue> VariableScope::findVariable( std::string identifiant )
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


VariableScope::~VariableScope()
{}
