#ifndef FONCTIONSIGNATURE_H
#define FONCTIONSIGNATURE_H

#include <string>

#include "AbstractNode.h"


namespace AST {

    class FunctionSignature : public AbstractNode
    {
    public:
		
		/**
		 * @brief FunctionSignature constructor
		 * @param identifiant string the identifier of the function
		 */
        FunctionSignature(std::string identifiant);
        
        /**
		 * @brief FunctionSignature constructor
		 * @param identifiant string the identifier of the function
		 * @param type AST::Type the type of the function
		 */
        FunctionSignature(std::string identifiant, Type type);

		/**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
        virtual void printTree(int tabulationNumber) const;
        
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
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

		/**
		 * @brief identifiant attribute getter
		 * @return a string
		 */
        std::string getIdentifiant() const;
        
        /**
         * @brief value attribute getter
         * @return a Value object
         */
        Value getValue() const;
        

    private:
        std::string identifiant;
    };
}

#endif // FONCTIONSIGNATURE_H
