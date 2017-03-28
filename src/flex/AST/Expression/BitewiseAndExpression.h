#ifndef BINARYANDEXPRESSION_H
#define BINARYANDEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitewiseAndExpression : public AbstractBinaryExpression
{
public:

    BitewiseAndExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitewiseAndExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;

};
}

#endif // BINARYANDEXPRESSION_H
