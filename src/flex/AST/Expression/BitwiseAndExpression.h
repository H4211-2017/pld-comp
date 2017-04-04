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

        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};
}

#endif // BINARYANDEXPRESSION_H
