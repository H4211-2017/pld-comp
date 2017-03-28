#ifndef ARGUMENTLIST_H
#define ARGUMENTLIST_H

#include <vector>

#include "AbstractNode.h"
#include "Variable/VariableSignature.h"

namespace AST {
    class ArgumentList : public AbstractNode
    {
    public:
        ArgumentList(std::shared_ptr<VariableSignature> variableSignature);

        void addArgument(std::shared_ptr<VariableSignature> argument);
        bool checkValidForFunctionDefinition() const;

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;

    private:
        std::vector<std::shared_ptr<VariableSignature>> variableSignatureList;
    };
}


#endif // ARGUMENTLIST_H
