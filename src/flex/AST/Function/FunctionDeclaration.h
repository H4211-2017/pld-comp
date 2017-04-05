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
		 * @brief FunctionDeclaration
		 * @param signature a shared_ptr to the FunctionSignature of the declared function
		 * @param function a shared_ptr to the Function itself
		 * @param scope a shared_ptr to the current Scope
		 */
        FunctionDeclaration(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Function> function, std::shared_ptr<Scope> scope);

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

    protected:
        std::shared_ptr<FunctionSignature> sig;
        std::shared_ptr<LArguments> args;
        std::shared_ptr<Function> fct;
    };
}

#endif
