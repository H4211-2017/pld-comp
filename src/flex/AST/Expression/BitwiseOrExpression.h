#ifndef BINARYOREXPRESSION_H
#define BINARYOREXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitwiseOrExpression : public AbstractBinaryExpression
{
public:
    BitwiseOrExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitwiseOrExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;
};
}
#endif // BINARYOREXPRESSION_H
