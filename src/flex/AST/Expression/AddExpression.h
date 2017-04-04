#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST
{

class AddExpression : public AbstractBinaryExpression 
{
	
public:

    AddExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);
	
	virtual ~AddExpression();

	virtual Value evaluate() const;

    virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
    virtual void printOperator() const;

};

} /* namespace AST */

#endif //ADD_EXPRESSION_H
