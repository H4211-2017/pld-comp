#include <iostream>

#include "Scope.h"
#include "Function/Function.h"
#include "Function/FunctionSignature.h"
#include "Function/LArguments.h"
#include "Variable/VariableSignature.h"

using namespace AST;


Scope::Scope()
{
	std::shared_ptr<Function> getchar = std::make_shared<Function>(std::make_shared<FunctionSignature>("getchar", Type::CHAR), nullptr);
	std::shared_ptr<Function> putchar = std::make_shared<Function>(std::make_shared<FunctionSignature>("putchar", Type::ERROR), 
																	std::make_shared<LArguments>(std::make_shared<VariableSignature>("car", Type::CHAR)), 
																	nullptr);
	fScope.declareFunction("getchar", getchar);
	fScope.declareFunction("putchar", putchar);
    mother = nullptr;
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

std::shared_ptr<AbstractVariable>* Scope::findVariableAddress(std::string identifiant)
{
	try
	{
		auto val = vScope.findVariableAddress(identifiant);
		return val;
		
		
	}
	catch(UndeclaredIdException& e)
	{
		try {
			if(mother != nullptr)
				return mother->findVariableAddress(identifiant);
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
    //std::cout << "Scope::findFunction : fscope : " << fScope << std::endl;
	try
	{
        std::shared_ptr<Function> val = fScope.findFunction(identifiant);
		return val;
		
		
	}
	catch(UndeclaredIdFctException& e)
	{
		try {
            if(mother != nullptr && &(*mother) != this)
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
