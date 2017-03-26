#include <iostream>

#include "FonctionScope.h"

using namespace AST;


FonctionScope::FonctionScope()
{

}

void FonctionScope::declareFonction(std::string name, std::shared_ptr<DeclarationFonction> decl)
{
    
}

std::shared_ptr<DeclarationFonction> FonctionScope::findFonction(std::string identifiant, std::shared_ptr<ListArg> args)
{
	
}

void FonctionScope::setFonction(std::string identifiant, std::shared_ptr<DeclarationFonction> decl)
{
	
}

FonctionScope::~FonctionScope()
{}
