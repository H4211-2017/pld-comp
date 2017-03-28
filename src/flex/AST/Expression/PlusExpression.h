#ifndef PLUSEXPRESSION_H
#define PLUSEXPRESSION_H


#include "AbstractBinaryExpression.h"

namespace AST{
class PlusExpression : AbstractBinaryExpression
{
public:
    PlusExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

        virtual ~PlusExpression();

        virtual Value evaluate() const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

protected:
    virtual void printOperator() const;
};
}
#endif // MINUSEXPRESSION_H
#endif // PLUSEXPRESSION_H
