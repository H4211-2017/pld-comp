#ifndef ABSTRACTDECLARATION_H
#define ABSTRACTDECLARATION_H

#include "Instruction/AbstractInstruction.h"
#include "Instruction/VariableSignature.h"
#include "Scope.h"

namespace AST {
    class AbstractDeclaration : public AbstractInstruction
    {
    public:
        AbstractDeclaration(std::string name, std::shared_ptr<VariableSignature> signature);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        
    protected:
        std::shared_ptr<VariableSignature> sig;
    };
}


#endif // ABSTRACTDECLARATION_H
