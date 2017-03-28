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

void FunctionScope::declareFunction(std::string name, std::shared_ptr<Function> decl)
{
    auto it = scope.find(name);
	
	if(it == scope.end())
	{
        scope.insert(std::pair<std::string, std::shared_ptr<Function> >(name, decl));
	}
	else if(it->second->compareArguments(decl) && (it->second->isDeclaration() == decl->isDeclaration() || decl->isDeclaration()))
	{
		std::stringstream ss;
		ss << "ERROR : multiple declaration of function <" << name << ">";
		std::cerr << ss.str() << std::endl;
		exit(-1);
	} 
	else if(it->second->compareArguments(decl) && !decl->isDeclaration())
	{
		scope.erase(it);
        scope.insert(std::pair<std::string, std::shared_ptr<Function> >(name, decl));
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

