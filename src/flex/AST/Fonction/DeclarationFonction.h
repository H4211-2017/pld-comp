#ifndef DECLARATION_FONCTION_H
#define DECLARATION_FONCTION_H

#include "Instruction/AbstractInstruction.h"

namespace AST
{
	class DeclarationFonction : public AbstractInstruction
	{
	public:
        DeclarationFonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<VariableScope> variableScope);
        
        DeclarationFonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<VariableScope> variableScope);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
        
    protected:
        std::shared_ptr<VariableSignature> sig;
        std::shared_ptr<AbstractExpression> val;
    };
}

#endif
