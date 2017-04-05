#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include "IDExpression.h"

#include "Variable/Variable.h"
#include "Scope.h"
#include "AbstractExpression.h"

namespace AST {

	class ArrayExpression : public IDExpression 
	{
		
	public:
	
		/**
		 * @brief ArrayExpression constructor
		 * @param id string the identifier of the Array
		 * @param caseExpression a shared_ptr that evaluates to the accessed index of the array
		 * @param scope a shared_ptr on the current scope
		 */
		ArrayExpression(std::string id, std::shared_ptr<AbstractExpression> caseExpression,
				std::shared_ptr<Scope> scope);
		
		/**
		 * @brief ArrayExpression destructor
		 */
		virtual ~ArrayExpression();

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
		*/.
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
		
		/**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
		void printTree(int tabulationNumber) const;

	protected:
		
		std::shared_ptr<AbstractExpression> caseExpression;

	};
} /* namespace AST */

#endif //ARRAYEXPRESSION_H
