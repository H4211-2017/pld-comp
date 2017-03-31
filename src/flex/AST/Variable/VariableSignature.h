#ifndef VARIABLESIGNATURE_H
#define VARIABLESIGNATURE_H

#include <string>

#include "AbstractNode.h"


namespace AST {

    class VariableSignature : public AbstractNode
    {
    public:
        VariableSignature(std::string identifiant, Type type);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

        std::string getIdentifiant() const;
        Value getValue() const;

    private:
        std::string identifiant;
    };
}

#endif // VARIABLESIGNATURE_H
