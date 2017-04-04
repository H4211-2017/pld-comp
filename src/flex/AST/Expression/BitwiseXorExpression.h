#ifndef BINARYXOREXPRESSION_H
#define BINARYXOREXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitwiseXorExpression : public AbstractBinaryExpression
{
public:
    BitwiseXorExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitwiseXorExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;
};
}
#endif // BINARYXOREXPRESSION_H
