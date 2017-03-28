#ifndef BITEWISESHIFTLEFTEXPRESSION_H
#define BITEWISESHIFTLEFTEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitewiseShiftLeftExpression : AbstractBinaryExpression
{
public:
    BitewiseShiftLeftExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitewiseShiftLeftExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;
};
}

#endif // BITEWISESHIFTLEFTEXPRESSION_H