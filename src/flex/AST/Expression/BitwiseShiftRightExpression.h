#ifndef BITEWISESHIFTRIGHTEXPRESSION_H
#define BITEWISESHIFTRIGHTEXPRESSION_H

#include "AbstractBinaryExpression.h"

namespace AST{
class BitwiseShiftRightExpression : public AbstractBinaryExpression
{
public:
		/**
		 * @brief BitwiseShiftRightExpression constructor
		 * @param leftMember a shared_ptr on the left part of the expression
		 * @param rightMember a shared_ptr on the right part of the expression
		 */
		BitwiseShiftRightExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);

		/**
		 * @brief BitwiseShiftLeftExpression destructor
		 */
        virtual ~BitwiseShiftRightExpression();

		/**
		 * @brief evaluate pure virtual function
		 * @return the "Value" of the expression, mainly it's type.
		 */
        virtual Value evaluate() const;

        /**
		* @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
		* 		that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

protected:
		/**
		 * @brief printOperator Prints the operator of the binary expression. Used in printTree
		 */
		virtual void printOperator() const;
};
}

#endif // BITEWISESHIFTLEFTEXPRESSION_H
