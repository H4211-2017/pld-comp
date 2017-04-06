#ifndef L_PARAMETRES_H
#define L_PARAMETRES_H

#include "AbstractNode.h"

#include <memory>
#include <vector>

#include "AbstractExpression.h"

namespace AST
{
	class LParametres : public AbstractNode
	{
	public:
		
		friend class LArguments;
        friend class Function;
		
		/**
		 * @brief LParametres default constructor, with an empty list of parameters
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
		 * @brief deprecated fucnction for this class
		 * @return an error-type value = 0;
		 */
		virtual Value evaluate() const;
		
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
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
		
	protected:
		
		std::vector<std::shared_ptr<AbstractExpression> > parametres;		
	};
}

#endif
