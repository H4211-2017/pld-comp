#include "DeclarationFonction.h"
#include "Scope.h"

using namespace AST;

DeclarationFonction::DeclarationFonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<Fonction> fonction, std::shared_ptr<Scope> scope)
	: AbstractInstruction("DeclarationFonction")
{
	sig = signature;
	fct = fonction;
	scope->declareFonction(sig->getIdentifiant(), fct);
}

void DeclarationFonction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    
	std::cout << std::endl;
	if(this->fct != nullptr)
		this->fct->printTree(tabulationNumber + 1);
    

}

Value DeclarationFonction::evaluate() const
{
	return Value();
}

void DeclarationFonction::buildIR() const
{

}

