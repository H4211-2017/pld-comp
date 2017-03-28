#ifndef BINARYOREXPRESSION_H
#define BINARYOREXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitewiseOrExpression : public AbstractBinaryExpression
{
public:
    BitewiseOrExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitewiseOrExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;
};
}
#endif // BINARYOREXPRESSION_H
