#ifndef APPEL_FONCTION_H
#define APPEL_FONCTION_H

#include "AbstractExpression.h"

#include "Function.h"
#include "LParametres.h"
#include "Scope.h"

namespace AST 
{
	class FunctionCall : public AbstractExpression
	{	
	public:

		/**
		 * @brief FunctionCall constructor
		 * @param id string the identifier of the called function
		 * @param params a shared_ptr to the LParametres object representing the list of parameters
		 * @param scope a shared_ptr to the current Scope
		 */
		FunctionCall(std::string id, std::shared_ptr<LParametres> params, std::shared_ptr<Scope> scope);

		/**
		 * @brief FunctionCall destructor 
		 */
		virtual ~FunctionCall();
	
		/**
		 * @brief deprecated fucnction for this class
		 * @return an error-type value = 0;
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
		
		std::string functionIdentifiant;
		std::shared_ptr<LParametres> parameters;
	};
} /* namespace AST */

#endif //ID_EXPRESSION_H
