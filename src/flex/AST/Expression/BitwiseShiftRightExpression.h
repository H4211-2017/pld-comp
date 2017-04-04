#ifndef BITEWISESHIFTRIGHTEXPRESSION_H
#define BITEWISESHIFTRIGHTEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitwiseShiftRightExpression : public AbstractBinaryExpression
{
public:
    BitwiseShiftRightExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitwiseShiftRightExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;
};
}

#endif // BITEWISESHIFTLEFTEXPRESSION_H
