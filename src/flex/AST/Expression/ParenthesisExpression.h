#ifndef PARENTHESIS_EXPRESSION_H
#define PARENTHESIS_EXPRESSION_H

#include "AbstractExpression.h"

#include "Instruction/AbstractInstruction.h"
#include "Scope.h"

namespace AST
{
	class ParenthesisExpression : public AbstractExpression 
	{
	
	public:

		/**
		 * @brief ParenthesisExpression constructor
		 * @param instr a shared_ptr on the contained instruction
		 */
		ParenthesisExpression(std::shared_ptr<AbstractInstruction> instr);
	
		/**
		 * @brief ParenthesisExpression destructor
		 */
		virtual ~ParenthesisExpression();

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
	
 		/**
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
		void printTree(int tabulationNumber) const;

	protected:
		
		std::shared_ptr<AbstractInstruction> instr;
	};
} /* namespace AST */

#endif //PARENTHESIS_EXPRESSION_H
