#include <iostream>

#include "FonctionScope.h"
#include "Fonction.h"

#include <sstream>

using namespace AST;


FonctionScope::FonctionScope()
{

}

void FonctionScope::declareFonction(std::string name, std::shared_ptr<Fonction> decl)
{
    auto it = scope.find(name);
	
	if(it == scope.end())
	{
		scope.insert(std::pair<std::string, std::shared_ptr<Fonction> >(name, decl));
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
		scope.insert(std::pair<std::string, std::shared_ptr<Fonction> >(name, decl));
	}
    
}

std::shared_ptr<Fonction> FonctionScope::findFonction(std::string identifiant)
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

FonctionScope::~FonctionScope()
{}
