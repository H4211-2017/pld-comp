#ifndef FONCTION_H
#define FONCTION_H

#include "Instruction/AbstractInstruction.h"
#include "Block.h"
#include "LArguments.h"
#include "FunctionSignature.h"

#include "../../../IR/function/ExternalFunction.h"

namespace AST
{
    class Function : public AbstractNode
	{
	public:
        
        /**
         * @brief Function constructor
         * @param signature a shared_ptr to the function's FunctionSignature
         * @param parentScope a shared_ptr to the Scope in which the function is declared
         */
        Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Scope> parentScope);
        
        /**
         * @brief Function constructor
         * @param signature a shared_ptr to the function's FunctionSignature
         * @param arguments a shared_ptr to the LArgument the function expects
         * @param parentScope a shared_ptr to the Scope in which the function is declared
         */
        Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Scope> parentScope);
        
        /**
         * @brief Function constructor
         * @param signature a shared_ptr to the function's FunctionSignature
         * @param content a shared_ptr to the block containing the function's instructions
         * @param parentScope a shared_ptr to the Scope in which the function is declared
         */
        Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope);
        
        /**
         * @brief Function constructor
         * @param signature a shared_ptr to the function's FunctionSignature
         * @param arguments a shared_ptr to the LArgument the function expects
         * @param content a shared_ptr to the block containing the function's instructions
         * @param parentScope a shared_ptr to the Scope in which the function is declared
         */
        Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope);
       
		//TODO : Comment on this method
        std::shared_ptr<IR::ExternalFunction> getIrFunction();
 
		/**
		 * @brief checks if the number of f2 parameters correspond to the one expected by the function
		 * @param f2 a shared_ptr to another function
		 * @return true if the numbers matche, false if they dont
		 */
        bool compareArguments(std::shared_ptr<Function> f2) const;
        
        /**
         * @brief checks if the number of parameters given correspond to the one expected by the function
         * @param params a shared_ptr to a LParametres
         * @return true if the number matches, false if it doesnt
         */
        bool checkParametres(std::shared_ptr<LParametres> params) const;
        
        /**
         * @brief checks if the function is declared but not defined
         * @return true if the function isn't defined, false if it is
         */
        bool isDeclaration() const;
        
        /**
         * @brief setter for the content attribute
         * @param content a shared_ptr to the Block containing the function's instructions
         */
        void setBlock(std::shared_ptr<Block> content);
        
        /**
         * @brief signature attribute getter
         * @return a shared_ptr to a FunctionSignature
         */
        std::shared_ptr<FunctionSignature> getSignature() const;
        
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
        std::shared_ptr<Block> content;
        std::shared_ptr<IR::ExternalFunction> irFunction;
        
    };
}

#endif
