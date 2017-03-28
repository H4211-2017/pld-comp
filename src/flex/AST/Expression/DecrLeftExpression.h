#ifndef DecrLeft_EXPRESSION_H
#define DecrLeft_EXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class DecrLeftExpression : public AbstractBinaryExpression
{

public:

    DecrLeftExpression(std::shared_ptr<AbstractExpression> rightMember);

    virtual ~DecrLeftExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //DecrLeft_EXPRESSION_H
