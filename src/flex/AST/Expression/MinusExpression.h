#ifndef MINUSEXPRESSION_H
#define MINUSEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class MinusExpression : AbstractBinaryExpression
{
public:
    MinusExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~MinusExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;
};
}
#endif // MINUSEXPRESSION_H
