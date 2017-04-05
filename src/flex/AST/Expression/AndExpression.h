#ifndef ANDEXPRESSION_H
#define ANDEXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class AndExpression : public AbstractBinaryExpression
{

public:

    AndExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

    virtual ~AndExpression();

    virtual Value evaluate() const;

    // TODO : create class CFG and replace comment below.
    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //ANDEXPRESSION_H