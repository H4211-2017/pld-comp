/*
 * AbstractBinaryExpression.h
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#ifndef SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_
#define SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_
#include "AbstractExpression.h"


namespace AST
{
	class AbstractBinaryExpression : public AbstractExpression
	{
	
	public:
		AbstractBinaryExpression(std::string name, std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);
		virtual ~AbstractBinaryExpression();

		/**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
		virtual void printTree(int tabulationNumber) const;

		/**
		 * @brief evaluate pure virtual function
		 * @return the "Value" of the expression, mainly it's type.
		 */
		virtual Value evaluate() const =0;
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const =0;
		
	protected:
		virtual void printOperator() const =0;

		std::shared_ptr<AbstractExpression> rightMember;
		std::shared_ptr<AbstractExpression> leftMember;
	};
}
#endif /* SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_ */
