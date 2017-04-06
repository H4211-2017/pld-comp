#ifndef L_ARGUMENTS_H
#define L_ARGUMENTS_H

#include "AbstractNode.h"

#include <memory>
#include <vector>

#include "Variable/VariableSignature.h"

namespace AST
{
	class LParametres;
	
	class LArguments : public AbstractNode
	{
	public:
	
		/**
		 * @brief LArguments default constructor, with a empty list of arguments
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
		 * @brief compare the arguments list with another LArguments
		 * @param larg2 a shared_ptr on the LArguments to compare with
		 * @return true if the lists ares the sames, false otherwise
		 */
		bool compareSignature(std::shared_ptr<LArguments> larg2) const;
		
		/**
         * @brief checks if the parameters given correspond to the one expected for each argument of the list
         * @param params a shared_ptr to a LParametres to be checked
         * @return true if the parameters matche, false if it doesn't
         */
		bool checkParametres(std::shared_ptr<LParametres> params) const;
		
		/**
		 * @brief checks if at least one the arguments is not named (also this list is only for function declaration)
		 * @return true if it is the case, false otherwise
		 */
		bool isForDeclaration() const;
		
		/**
		 * @brief initialise the scope using the contained arguments
		 */
		void prepareScope(std::shared_ptr<Scope> scope) const;
		
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
		
		std::vector<std::shared_ptr<VariableSignature> > arguments;
		bool isForDecl;
		
	};

}

#endif
