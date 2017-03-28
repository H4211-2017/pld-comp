#ifndef BINARYXOREXPRESSION_H
#define BINARYXOREXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitewiseXorExpression : public AbstractBinaryExpression
{
public:
    BitewiseXorExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitewiseXorExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;
};
}
#endif // BINARYXOREXPRESSION_H
