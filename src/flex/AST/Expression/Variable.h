#ifndef VARIABLE_H
#define VARIABLE_H

#include "AbstractExpression.h"

namespace AST {
    class Variable : public AbstractExpression
    {
    public:
        Variable(std::string identifiant, std::shared_ptr<VariableScope>);
    };
}


#endif // VARIABLE_H
