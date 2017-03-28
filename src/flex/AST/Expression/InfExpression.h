#ifndef INFEXPRESSION_H
#define INFEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class InfExpression : public AbstractBinaryExpression
{

public:

    InfExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~InfExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //INFEXPRESSION_H
