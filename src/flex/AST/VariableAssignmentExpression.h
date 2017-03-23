#ifndef VARIABLEASSIGNMENTEXPRESSION_H
#define VARIABLEASSIGNMENTEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class VariableAssignmentExpression : public AbstractBinaryExpression
{
public:
    VariableAssignmentExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember);
    virtual Value evaluate() const;
    void printTree(int tabulationNumber) const;
};
}
#endif // VARIABLEASSIGNMENTEXPRESSION_H
