#ifndef DECLARATION_FONCTION_H
#define DECLARATION_FONCTION_H

#include "Instruction/AbstractInstruction.h"
#include "Function.h"
#include "FunctionSignature.h"
#include "../../../IR/function/FunctionBlock.h"

namespace AST
{

    class Scope;
    class FunctionBlock;

    class FunctionDeclaration : public AbstractInstruction
    {
    public:

        FunctionDeclaration(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Function> function, std::shared_ptr<Scope> scope);

        std::shared_ptr<IR::FunctionBlock> getIrFunction() const;

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock);

    protected:
        std::shared_ptr<FunctionSignature> sig;
        std::shared_ptr<Function> fct;
    };
}

#endif
