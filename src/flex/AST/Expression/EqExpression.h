#ifndef EQEXPRESSION_H
#define EQEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST
{
	class EqExpression : public AbstractBinaryExpression
	{

	public:

		/**
		 * @brief EqExpression constructor
		 * @param leftMember a shared_ptr on the left part of the expression
		 * @param rightMember a shared_ptr on the right part of the expression
		 */
		EqExpression(std::shared_ptr<AbstractExpression> leftMember, std::shared_ptr<AbstractExpression> rightMember);
		
		/**
		 * @brief EqExpression destructor
		 */
		virtual ~EqExpression();

		/**
		 * @brief evaluate compute evaluation if possible beacuse of constants-composed expression
		 * @return the "Value" of the expression if evaluable, or error-type value else
		 */
		virtual Value evaluate() const;

        /**
		* @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once executed
		* 		or nullptr if the node shouldn't be calculated to be a value
		*/
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

	protected:
	
		/**
		 * @brief printOperator Prints the operator of the binary expression. Used in printTree
		 */
		virtual void printOperator() const;
	};
} /* namespace AST */

#endif //EQEXPRESSION_H
