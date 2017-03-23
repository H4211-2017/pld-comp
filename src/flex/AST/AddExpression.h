/*
 * AddExpression.h
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#ifndef SRC_FLEX_AST_ADDEXPRESSION_H_
#define SRC_FLEX_AST_ADDEXPRESSION_H_

namespace AST {

class AddExpression : public AbstractBinaryExpression {
public:
	AddExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<leftMember>);
	virtual ~AddExpression();
private:
	virtual long int evaluate();
	virtual void printTree(int tabulationNumber);
};

} /* namespace AST */

#endif /* SRC_FLEX_AST_ADDEXPRESSION_H_ */
