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
    for(; it != scope.end() && !it->first.compare(name); it++)
    {
    	if(it->second->compareArguments(decl) && (it->second->isDeclaration() == decl->isDeclaration() || decl->isDeclaration()))
    	{
    		std::stringstream ss;
    		ss << "ERROR : multiple declaration of function <" << name << ">";
    		std::cerr << ss.str() << std::endl;
    		exit(-1);
    	} 
    }
    
    scope.insert(std::pair<std::string, std::shared_ptr<Fonction> >(name, decl));
    
}

std::shared_ptr<Fonction> FonctionScope::findFonction(std::string identifiant, std::shared_ptr<ListArg> args)
{
	
}

void FonctionScope::setFonction(std::string identifiant, std::shared_ptr<Fonction> decl)
{
	
}

FonctionScope::~FonctionScope()
{}
