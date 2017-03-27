#ifndef ARRAYDECLARATION_H
#define ARRAYDECLARATION_H

#include "AbstractDeclaration.h"
#include "AbstractExpression.h"
#include "Scope.h"

namespace AST {
    class ArrayDeclaration : public AbstractDeclaration
    {
    public:
        ArrayDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> size, std::shared_ptr<Scope> scope);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
        
    protected:
        std::shared_ptr<AbstractExpression> size;
    };
}

#endif // ARRAYDECLARATION_H
