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
        virtual std::shared_ptr<std::pair<TypeValue, Type>> evaluate() const;
        virtual void buildIR() const;

    private:
        std::string m_identifiant;
    };
}

#endif // VARIABLESIGNATURE_H
