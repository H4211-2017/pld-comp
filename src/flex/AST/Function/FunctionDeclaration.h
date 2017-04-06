#ifndef DECLARATION_FONCTION_H
#define DECLARATION_FONCTION_H

#include "Instruction/AbstractInstruction.h"

#include "Function.h"
#include "FunctionSignature.h"

namespace AST
{
    class Scope;

    class FunctionDeclaration : public AbstractInstruction
    {
    
    public:
		
		/**
		 * @brief FunctionDeclaration constructor
		 * @param signature a shared_ptr to the FunctionSignature of the declared function
		 * @param function a shared_ptr to the Function itself
		 * @param scope a shared_ptr to the current Scope
		 */
        FunctionDeclaration(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Function> function, std::shared_ptr<Scope> scope);

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

    protected:
        std::shared_ptr<FunctionSignature> sig;
        std::shared_ptr<LArguments> args;
        std::shared_ptr<Function> fct;
    };
}

#endif
