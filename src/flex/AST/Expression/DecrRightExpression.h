#ifndef DecrRight_EXPRESSION_H
#define DecrRight_EXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class DecrRightExpression : public AbstractBinaryExpression
{

public:

    DecrRightExpression(std::shared_ptr<AbstractExpression> leftMember);

    virtual ~DecrRightExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //DecrRight_EXPRESSION_H
