#ifndef DECLARATION_FONCTION_H
#define DECLARATION_FONCTION_H

#include "Instruction/AbstractInstruction.h"
#include "Function.h"
#include "FunctionSignature.h"

namespace AST
{

    class Scope;

    class FunctionDeclaration : public AbstractInstruction
    {
    public:

        FunctionDeclaration(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Function> function, std::shared_ptr<Scope> scope);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;

    protected:
        std::shared_ptr<FunctionSignature> sig;
        std::shared_ptr<LArguments> args;
        std::shared_ptr<Function> fct;
    };
}

#endif
