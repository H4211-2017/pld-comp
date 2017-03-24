#ifndef ARGUMENTLIST_H
#define ARGUMENTLIST_H

#include <vector>

#include "AbstractNode.h"
#include "VariableSignature.h"

namespace AST {
    class ArgumentList : public AbstractNode
    {
    public:
        ArgumentList(VariableSignature variableSignature);
        ArgumentList(VariableSignature variableSignature, ArgumentList argumentList);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;

    private:
        std::vector<VariableSignature> variableSignatureList;
    };
}


#endif // ARGUMENTLIST_H
