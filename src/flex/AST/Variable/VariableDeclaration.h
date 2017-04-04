#ifndef VARIABLEDECLARATION_H
#define VARIABLEDECLARATION_H

#include "Instruction/AbstractInstruction.h"
#include "AbstractExpression.h"
#include "VariableSignature.h"
#include "Variable.h"
#include "Scope.h"

namespace AST {
    class VariableDeclaration : public AbstractInstruction
    {
    public:
        VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<Scope> scope);
        
        VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    protected:
        std::shared_ptr<Variable> var;
        std::shared_ptr<AbstractExpression> val;
    };
}


#endif // VARIABLEDECLARATION_H
