#ifndef SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H
#define SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H

#include "AbstractExpression.h"

namespace AST
{
	class AbstractBinaryExpression : public AbstractExpression
	{
	public:

		/**
		 * @brief AbstractBinaryExpression constructor
		 * @param name name of this node
		 * @param leftMember a shared_ptr on the left part of the expression
		 * @param rightMember a shared_ptr on the right part of the expression
		 */
		AbstractBinaryExpression(std::string name, std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);
		
		/**
		 * @brief AbstractBinaryExpression destructor
		 */
		virtual ~AbstractBinaryExpression();

		 /**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
		virtual void printTree(int tabulationNumber) const;
		

        /**
		* @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once executed
		* 		or nullptr if the node shouldn't be calculated to be a value
		*/
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const = 0;
		
	protected:
		 /**
		 * @brief printOperator Prints the operator of the binary expression. Used in printTree
		 */
		virtual void printOperator() const = 0;

		std::shared_ptr<AbstractExpression> rightMember;
		std::shared_ptr<AbstractExpression> leftMember;
	};
}
#endif // SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H
