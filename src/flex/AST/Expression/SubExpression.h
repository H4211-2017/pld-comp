#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class SubExpression : public AbstractBinaryExpression
{

public:

    SubExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~SubExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //SUBEXPRESSION_H
