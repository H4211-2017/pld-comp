#ifndef SUPEXPRESSION_H
#define SUPEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class SupExpression : public AbstractBinaryExpression
{

public:

    SupExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~SupExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //SUPEXPRESSION_H
