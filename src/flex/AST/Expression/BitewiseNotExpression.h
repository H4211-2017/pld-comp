#ifndef BITEWISENOTEXPRESSION_H
#define BITEWISENOTEXPRESSION_H


#include "AbstractBinaryExpression.h"

namespace AST{
class BitewiseNotExpression : AbstractBinaryExpression
{
public:
    BitewiseNotExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~BitewiseNotExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;
};
}
#endif // MINUSEXPRESSION_H

#endif // BITEWISENOTEXPRESSION_H
