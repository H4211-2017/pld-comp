#ifndef BINARYANDEXPRESSION_H
#define BINARYANDEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitwiseAndExpression : public AbstractBinaryExpression
{
public:

    BitwiseAndExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitwiseAndExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;

};
}

#endif // BINARYANDEXPRESSION_H
