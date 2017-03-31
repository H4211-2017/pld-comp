#include <iostream>

#include "Scope.h"

using namespace AST;


Scope::Scope()
	: mother(nullptr)
{
}

Scope::Scope( std::shared_ptr<Scope> Scope )
{
	mother = Scope;
}

Scope::~Scope()
{
}

void Scope::declareVariable(std::string identifiant, std::shared_ptr<AbstractVariable> variable)
{	
    vScope.declareVariable(identifiant, variable);
}

std::shared_ptr<AbstractVariable> Scope::findVariable(std::string identifiant)
{
	try
	{
		auto val = vScope.findVariable(identifiant);
		return val;
		
		
	}
	catch(UndeclaredIdException& e)
	{
		try {
			if(mother != nullptr)
				return mother->findVariable(identifiant);
			else
				throw UndeclaredIdException();
		}
		catch(std::exception& e)
		{
			std::cerr << "VariableScope::findVariable ( " << identifiant << " ) : "<< e.what() << std::endl;
			exit(-1);
		}	
	}	
}



void Scope::declareFunction(std::string identifiant, std::shared_ptr<Function> decl)
{
    fScope.declareFunction(identifiant, decl);
}

std::shared_ptr<Function> Scope::findFunction(std::string identifiant)
{
	try
	{
        auto val = fScope.findFunction(identifiant);
		return val;
		
		
	}
	catch(UndeclaredIdFctException& e)
	{
		try {
			if(mother != nullptr)
                return mother->findFunction(identifiant);
			else
				throw UndeclaredIdFctException();
		}
		catch(std::exception& e)
		{
			std::cerr << "FonctionScope::findFonction ( " << identifiant << " ) : "<< e.what() << std::endl;
			exit(-1);
		}	
	}	
}
    
std::shared_ptr<Scope> Scope::getMother() const
{
	return mother;
}

void Scope::setMother(std::shared_ptr<Scope> newMother)
{
	mother = newMother;
}

IR::Generator &Scope::getGenerator()
{
	return generator;
}

