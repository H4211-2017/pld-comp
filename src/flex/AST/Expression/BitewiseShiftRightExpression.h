#ifndef BITEWISESHIFTRIGHTEXPRESSION_H
#define BITEWISESHIFTRIGHTEXPRESSION_H


#include "AbstractBinaryExpression.h"
namespace AST{
class BitewiseShiftRightExpression : public AbstractBinaryExpression
{
public:
    BitewiseShiftRightExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitewiseShiftRightExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;
};
}

#endif // BITEWISESHIFTRIGHTEXPRESSION_H
