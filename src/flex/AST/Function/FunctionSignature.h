#ifndef FONCTIONSIGNATURE_H
#define FONCTIONSIGNATURE_H

#include "AbstractNode.h"

#include <string>

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
         * @brief printTree the AST tree corresponding to this node and it's children.
         * @param tabulationNumber the number of tabulations corresponding to this node
         */
        virtual void printTree(int tabulationNumber) const;
        
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
