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

void VariableScope::declareVariable(std::string identifiant, Value variable)
{
    scope.emplace(identifiant, std::make_shared<Value>(variable) );
}

std::shared_ptr<Value> VariableScope::findVariable(std::string identifiant)
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
