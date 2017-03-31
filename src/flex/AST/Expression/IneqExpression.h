#ifndef INEQEXPRESSION_H
#define INEQEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class IneqExpression : public AbstractBinaryExpression
{

public:

    IneqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~IneqExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //INEQEXPRESSION_H
