#ifndef MULTEXPRESSION_H
#define MULTEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class MultExpression : public AbstractBinaryExpression
{

public:

    MultExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~MultExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //MULTEXPRESSION_H
