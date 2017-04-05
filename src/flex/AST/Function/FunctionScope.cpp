#include <iostream>

#include "FunctionScope.h"
#include "Function.h"

#include <sstream>

using namespace AST;


FunctionScope::FunctionScope()
{

}

FunctionScope::~FunctionScope()
{}

void FunctionScope::declareFunction(std::string name, std::shared_ptr<Function> function)
{
    std::map<std::string, std::shared_ptr<Function>>::iterator it = scope.find(name);
	
	if(it == scope.end())
	{
        scope.insert(std::pair<std::string, std::shared_ptr<Function> >(name, function));
	}
    else if(it->second->isDeclaration())
	{
		scope.erase(it);
        scope.insert(std::pair<std::string, std::shared_ptr<Function> >(name, function));
	}
    else if (!function->isDeclaration())
    {
        std::stringstream ss;
        ss << "ERROR : multiple declaration of function <" << name << ">";
        std::cerr << ss.str() << std::endl;
        exit(-1);
    }
}

std::shared_ptr<Function> FunctionScope::findFunction(std::string identifiant)
{
	auto it = scope.find(identifiant);
	if( it == scope.end() )
	{
		throw UndeclaredIdFctException();
		
	}
	else
	{
		return it->second;
	}
}

