#ifndef FONCTION_H
#define FONCTION_H

#include "AbstractNode.h"

#include "Instruction/AbstractInstruction.h"
#include "Block.h"
#include "LArguments.h"
#include "FunctionSignature.h"

#include "../../../IR/function/FunctionBlock.h"

namespace AST
{
    class Block;

    class Function : public AbstractNode
	{
	
	public:
        
        /**
         * @brief Function constructor
         * @param signature a shared_ptr to the function's signature
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
		 * @brief checks if the f2 arguments correspond to the function ones
		 * @param f2 a shared_ptr to another function
		 * @return true if the arguments matche, false if they don't
		 */
        bool compareArguments(std::shared_ptr<Function> f2) const;
        
        /**
         * @brief checks if the parameters given correspond to the one expected by the function
         * @param params a shared_ptr to a LParametres
         * @return true if they matche, false if it don't
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
         * @return a shared_ptr to signature of the function
         */
        std::shared_ptr<FunctionSignature> getSignature() const;
        
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

		// TODO comment
        std::shared_ptr<IR::FunctionBlock> getIrFunction() const;
        
    protected:
    
        std::shared_ptr<FunctionSignature> sig;
        std::shared_ptr<LArguments> args;
        std::shared_ptr<Block> content;
        std::shared_ptr<IR::FunctionBlock> irFunction;
    };
}

#endif
