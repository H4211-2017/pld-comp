#ifndef SUPEQEXPRESSION_H
#define SUPEQEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class SupEqExpression : public AbstractBinaryExpression
{

public:

    SupEqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~SupEqExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //SUPEQEXPRESSION_H
