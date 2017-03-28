#ifndef VARIABLE_H
#define VARIABLE_H

#include "AbstractNode.h"
#include "VariableSignature.h"

namespace AST
{
	class Variable : public AbstractNode
	{
	public:
        
        Variable(std::shared_ptr<VariableSignature> signature, bool decl);
        
        bool isDeclaration() const;
        void noLongerDeclaration();
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
        
    protected:
        std::shared_ptr<VariableSignature> sig;
        bool declaration;
    };
}

#endif
