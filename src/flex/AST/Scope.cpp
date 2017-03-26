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

void Scope::declareVariable(std::string identifiant, std::shared_ptr<AbstractExpression> variable)
{
    vScope.declareVariable(identifiant, variable);
}

std::shared_ptr<AbstractExpression> Scope::findVariable(std::string identifiant)
{
	try
	{
		auto val = vScope.findVariable(identifiant);
		return val;
		
		
	}
	catch(UndeclaredIdException& e)
	{
		try {
			return mother->findVariable(identifiant);
		}
		catch(std::exception& e)
		{
			std::cerr << "VariableScope::findVariable ( " << identifiant << " ) : "<< e.what() << std::endl;
			exit(-1);
		}	
	}	
}

void Scope::setVariable(std::string identifiant, std::shared_ptr<AbstractExpression> newExpr)
{
	try
	{
		vScope.setVariable(identifiant, newExpr);
		
		
	}
	catch(UndeclaredIdException& e)
	{
		try {
			return mother->setVariable(identifiant, newExpr);
		}
		catch(std::exception& e)
		{
			std::cerr << "VariableScope::setVariable ( " << identifiant << " ) : "<< e.what() << std::endl;
			exit(-1);
		}	
	}	
}

void Scope::declareFonction(std::string identifiant, std::shared_ptr<DeclarationFonction> decl)
{
    fScope.declareFonction(identifiant, decl);
}

std::shared_ptr<DeclarationFonction> Scope::findFonction(std::string identifiant, std::shared_ptr<ListArg> args)
{
	try
	{
		auto val = fScope.findFonction(identifiant, args);
		return val;
		
		
	}
	catch(UndeclaredIdFctException& e)
	{
		try {
			return mother->findFonction(identifiant, args);
		}
		catch(std::exception& e)
		{
			std::cerr << "FonctionScope::findFonction ( " << identifiant << " ) : "<< e.what() << std::endl;
			exit(-1);
		}	
	}	
}

void Scope::setFonction(std::string identifiant, std::shared_ptr<DeclarationFonction> decl)
{
	try
	{
		fScope.setFonction(identifiant, decl);
		
		
	}
	catch(UndeclaredIdFctException& e)
	{
		try {
			return mother->setFonction(identifiant, decl);
		}
		catch(std::exception& e)
		{
			std::cerr << "FonctionScope::setFonction ( " << identifiant << " ) : "<< e.what() << std::endl;
			exit(-1);
		}	
	}	
}
        
std::shared_ptr<Scope> Scope::getMother() const
{
	return mother;
}

Scope::~Scope()
{}
