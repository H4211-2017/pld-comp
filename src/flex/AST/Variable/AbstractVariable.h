#ifndef ABSTRACTVARIABLE_H
#define ABSTRACTVARIABLE_H

#include "AbstractNode.h"
#include "VariableSignature.h"

namespace AST
{
	class AbstractVariable : public AbstractNode
	{
	public:
        
        /**
         * @brief AbstractVariable constructor
         * @param name string the type of the node
         * @param signature a shared_ptr to the variable's VariableSignature
         * @param decl bool whether or not the variable is simply declared without definition
         */
        AbstractVariable(std::string name, std::shared_ptr<VariableSignature> signature, bool decl);
        
        /**
         * @brief checks if the variable's Value is still not set
         * @return true if it isnt set, false if it can be evaluated
         */
        bool isDeclaration() const;
        
        /**
         * @brief declares that the variable can now be evaluated
         */
        void noLongerDeclaration();
        
         /**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
        virtual void printTree(int tabulationNumber) const;
      
		/**
		* @brief signature attribute getter
		* @return a shared_ptr on the variable's signature
		*/
        std::shared_ptr< VariableSignature> getSignature() const;
        
		/**
		* @brief buildIR build the IR from this node, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock, the reference to a shared pointer on the BasicBlock that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once executed
		* 		or nullptr if the node shouldn't be calculated to be a value
		*/
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const = 0;
        
    protected:
        std::shared_ptr<VariableSignature> sig;
        bool declaration;
    };
}

#endif // ABSTRACTVARIABLE_H
