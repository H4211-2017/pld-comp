#ifndef INFEQEXPRESSION_H
#define INFEQEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class InfEqExpression : public AbstractBinaryExpression
{

public:

    InfEqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~InfEqExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //INFEQEXPRESSION_H
