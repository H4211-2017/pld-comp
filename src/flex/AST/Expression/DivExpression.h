#ifndef DIVEXPRESSION_H
#define DIVEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class DivExpression : public AbstractBinaryExpression
{

public:

    DivExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~DivExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //DIVEXPRESSION_H
