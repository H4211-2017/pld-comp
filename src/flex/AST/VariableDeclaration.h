#ifndef VARIABLEDECLARATION_H
#define VARIABLEDECLARATION_H

#include "AbstractNode.h"
#include "VariableSignature.h"

namespace AST {
    class VariableDeclaration : public AbstractNode
    {
    public:
        VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<VariableScope> variableScope);
    };
}


#endif // VARIABLEDECLARATION_H
