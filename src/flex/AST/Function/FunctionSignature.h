#ifndef FONCTIONSIGNATURE_H
#define FONCTIONSIGNATURE_H

#include <string>

#include "AbstractNode.h"


namespace AST {

    class FunctionSignature : public AbstractNode
    {
    public:
    
        FunctionSignature(std::string identifiant);
        FunctionSignature(std::string identifiant, Type type);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

        std::string getIdentifiant() const;
        Value getValue() const;
        

    private:
        std::string identifiant;
    };
}

#endif // FONCTIONSIGNATURE_H
