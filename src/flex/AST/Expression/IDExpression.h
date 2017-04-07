#ifndef ID_EXPRESSION_H
#define ID_EXPRESSION_H

#include "AbstractExpression.h"

#include "Variable/Variable.h"
#include "Scope.h"

namespace AST
{
	class IDExpression : public AbstractExpression 
	{
		
	public:

		/**
		 * @brief IDExpression constructor
		 * @param id string the identifier of the Variable evaluated by the expression
		 * @param scope a shared_ptr on the current Scope
		 */
		IDExpression(std::string id, std::shared_ptr<Scope> scope);
		
		/**
		 * @brief IDExpression constructor
		 * @param name string the type of the node
		 * @param id string the identifier of the Variable evaluated by the expression
		 * @param scope a shared_ptr on the current Scope
		 */
		IDExpression(std::string name, std::string id,  std::shared_ptr<Scope> scope);
		
		/**
		 * @brief IDExpression constructor
		 * @param variable the Variable evaluated by the expression
		 * @param scope a shared_ptr on the current Scope
		 */
		IDExpression(std::shared_ptr<AbstractVariable> variable, std::shared_ptr<Scope> scope);
		
		/**
		 * @brief IDExpression constructor
		 * @param id string the identifier of the Variable evaluated by the expression
		 * @param scope a shared_ptr on the current Scope
		 */
		IDExpression(std::string name, std::shared_ptr<AbstractVariable> variable, std::shared_ptr<Scope> scope);
		
		/**
		 * @brief IDExpression destructor
		 */
		virtual ~IDExpression();

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
		
		std::shared_ptr<AbstractVariable> val;
	};
} /* namespace AST */

#endif //ID_EXPRESSION_H
