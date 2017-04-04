#ifndef IncrRight_EXPRESSION_H
#define IncrRight_EXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class IncrRightExpression : public AbstractBinaryExpression
{

public:

    IncrRightExpression(std::shared_ptr<AbstractExpression> leftMember);

    virtual ~IncrRightExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //IncrRight_EXPRESSION_H
