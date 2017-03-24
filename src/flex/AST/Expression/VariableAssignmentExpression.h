#ifndef VARIABLEASSIGNMENTEXPRESSION_H
#define VARIABLEASSIGNMENTEXPRESSION_H

#include "AbstractBinaryExpression.h"
#include "Variable.h"

namespace AST{
    class VariableAssignmentExpression : public AbstractBinaryExpression
    {

    public:
        VariableAssignmentExpression(std::shared_ptr<Variable> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual Value evaluate() const;

        virtual void printOperator() const;

    };
}
#endif // VARIABLEASSIGNMENTEXPRESSION_H
