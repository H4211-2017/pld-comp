#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H
#include "AbstractBinaryExpression.h"
namespace AST {

class AddExpression : public AbstractBinaryExpression 
{
	
public:

	AddExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember);
	
	virtual ~AddExpression();

	virtual Value evaluate() const;

	virtual void printTree(int tabulationNumber) const;

	// TODO : create class CFG and replace comment below.
	virtual void buildIR(/*std::shared_ptr<CFG>*/) const;

};

} /* namespace AST */

#endif //ADD_EXPRESSION_H
