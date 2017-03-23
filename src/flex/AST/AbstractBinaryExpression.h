/*
 * AbstractBinaryExpression.h
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#ifndef SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_
#define SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_
#include "AbstractExpression.h"


namespace AST{

class AbstractBinaryExpression : public AbstractExpression{
public:
	AbstractBinaryExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember);
	virtual ~AbstractBinaryExpression();
protected:
	std::shared_ptr<AbstractExpression> rightMember;
	std::shared_ptr<AbstractExpression> leftMember;
};
}
#endif /* SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_ */
