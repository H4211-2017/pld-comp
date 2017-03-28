#ifndef EQEXPRESSION_H
#define EQEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class EqExpression : public AbstractBinaryExpression
{

public:

    EqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~EqExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //EQEXPRESSION_H
