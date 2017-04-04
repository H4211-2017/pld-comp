#ifndef BITEWISESHIFTLEFTEXPRESSION_H
#define BITEWISESHIFTLEFTEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitwiseShiftLeftExpression : public AbstractBinaryExpression
{
public:
    BitwiseShiftLeftExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitwiseShiftLeftExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;
};
}

#endif // BITEWISESHIFTLEFTEXPRESSION_H
