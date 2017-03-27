#ifndef DECLARATION_FONCTION_H
#define DECLARATION_FONCTION_H

#include "AbstractInstruction.h"
#include "Fonction.h"
#include "FonctionSignature.h"

namespace AST
{

	class Scope;
	
	class DeclarationFonction : public AbstractInstruction
	{
	public:
        
        DeclarationFonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<Fonction> fonction, std::shared_ptr<Scope> scope);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
        
    protected:
        std::shared_ptr<FonctionSignature> sig;
        std::shared_ptr<LArguments> args;
        std::shared_ptr<Fonction> fct;
    };
}

#endif
