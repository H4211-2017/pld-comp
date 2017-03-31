#ifndef ABSTRACTVARIABLE_H
#define ABSTRACTVARIABLE_H

#include "AbstractNode.h"
#include "VariableSignature.h"

namespace AST
{
	class AbstractVariable : public AbstractNode
	{
	public:
        
        AbstractVariable(std::string name, std::shared_ptr<VariableSignature> signature, bool decl);
        
        bool isDeclaration() const;
        void noLongerDeclaration();
        
        virtual void printTree(int tabulationNumber) const;
      
        const std::shared_ptr<const VariableSignature> getVariableSignature() const;
        
    protected:
        std::shared_ptr<VariableSignature> sig;
        bool declaration;
    };
}

#endif // ABSTRACTVARIABLE_H
