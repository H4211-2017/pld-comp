#ifndef L_ARGUMENTS_H
#define L_ARGUMENTS_H

#include <memory>
#include <vector>

#include "AbstractNode.h"
#include "Variable/VariableSignature.h"

namespace AST
{

	class LParametres;
	
	class LArguments : public AbstractNode
	{
	public:
	
		/**
		 * @brief LArguments constructor
		 */
		LArguments();
		
		/**
		 * @brief LArguments constructor
		 * @param argument a shared_ptr to the first argument contained in the LArguments
		 */
		LArguments(std::shared_ptr<VariableSignature> argument);
		
		/**
		 * @brief add an Argument to the LArguments
		 * @param argument a shared_ptr to the argument that must be added
		 */
		void addArgument(std::shared_ptr<VariableSignature> argument);
		
		/**
		 * @brief compare the signatures within two LArguments
		 * @param larg2 a shared_ptr on the LArguments to compare with
		 * @return true if the signatures matches, false otherwise
		 */
		bool compareSignature(std::shared_ptr<LArguments> larg2) const;
		
		/**
         * @brief checks if the number of parameters given correspond to the one expected by the function
         * @param params a shared_ptr to a LParametres
         * @return true if the number matches, false if it doesnt
         */
		bool checkParametres(std::shared_ptr<LParametres> params) const;
		
		/**
		 * @brief checks whether the instance is used within a declaration or not
		 * @return true if the instance is used within a declaration, false otherwise
		 */
		bool isForDeclaration() const;
		
		/**
		 * @brief initialise the scope using the contained arguments
		 */
		void prepareScope(std::shared_ptr<Scope> scope) const;
		
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
		
		std::vector<std::shared_ptr<VariableSignature> > arguments;
		bool isForDecl;
		
	};

}

#endif
