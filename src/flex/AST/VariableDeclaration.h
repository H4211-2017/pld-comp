#ifndef VARIABLEDECLARATION_H
#define VARIABLEDECLARATION_H

#include "AbstractInstruction.h"
#include "AbstractExpression.h"
#include "VariableSignature.h"

namespace AST {
    class VariableDeclaration : public AbstractInstruction
    {
    public:
        VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<VariableScope> variableScope);
        
        VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<VariableScope> variableScope);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
        
    protected:
        std::shared_ptr<VariableSignature> sig;
        std::shared_ptr<AbstractExpression> val;
    };
}


#endif // VARIABLEDECLARATION_H
