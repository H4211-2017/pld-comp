#ifndef DECR_INCR_LEFT_EXPRESSION_H
#define DECR_INCR_LEFT_EXPRESSION_H

#include "AbstractExpression.h"

#include "Variable/Variable.h"

namespace AST
{
	class DecrIncrLeftExpression : public AbstractExpression
	{

	public:

		/**
		* @brief DecrIncrLeftExpression constructor
		* @param valueOfIncrement int the value of incrementation
		* @remark value of incrementation +1 is an incrementation, value of incrementation -1 is a decrementation 
		*/
		DecrIncrLeftExpression(std::shared_ptr<AbstractVariable> var, int valueOfIncrement);

		/**
		 * @brief DecrIncrLeft destructor
		 */
		virtual ~DecrIncrLeftExpression();

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
		virtual void printTree(int tabulationNumber) const;

	private:
	
		std::shared_ptr<AbstractVariable> var;
		int valueOfIncrement;
	};
} /* namespace AST */

#endif //DECR_INCR_LEFT_EXPRESSION_H
