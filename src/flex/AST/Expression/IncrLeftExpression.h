#ifndef IncrLeft_EXPRESSION_H
#define IncrLeft_EXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class IncrLeftExpression : public AbstractBinaryExpression
{

public:

    IncrLeftExpression(std::shared_ptr<AbstractExpression> rightMember);

    virtual ~IncrLeftExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //IncrLeft_EXPRESSION_H
