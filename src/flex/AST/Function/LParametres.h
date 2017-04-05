#ifndef L_PARAMETRES_H
#define L_PARAMETRES_H

#include <memory>
#include <vector>

#include "AbstractNode.h"
#include "AbstractExpression.h"

namespace AST
{

	class LParametres : public AbstractNode
	{
	public:
		
		friend class LArguments;
        friend class Function;
		
		/**
		 * @brief LParametres constructor
		 */
		LParametres();
		
		/**
		 * @brief LParametres constructor
		 * @param argument a shared_ptr to the first parametres contained in the LParametres
		 */
		LParametres(std::shared_ptr<AbstractExpression> parametre);
		
		/**
		 * @brief add a parametre to the LParametres
		 * @param argument a shared_ptr to the parametre that must be added
		 */
		void addParametre(std::shared_ptr<AbstractExpression> parametre);
		
		/**
		 * @brief evaluate pure virtual function
		 * @return the "Value" of the expression, mainly it's type.
		 */
		virtual Value evaluate() const;
		
		/**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
		virtual void printTree(int tabulationNumber) const;
		
		/**
		* @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
		* 		that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
		
	protected:
		
		std::vector<std::shared_ptr<AbstractExpression> > parametres;
		
	};

}

#endif
