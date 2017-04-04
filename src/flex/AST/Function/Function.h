#ifndef FONCTION_H
#define FONCTION_H

#include "Instruction/AbstractInstruction.h"
#include "Block.h"
#include "LArguments.h"
#include "FunctionSignature.h"

#include "../../../IR/function/FunctionBlock.h"

namespace AST
{
    class Function : public AbstractNode
	{
	public:
        
        Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Scope> parentScope);
        Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Scope> parentScope);
        
        Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope);
        Function(std::shared_ptr<FunctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope);

        std::shared_ptr<IR::FunctionBlock> getIrFunction();

 
        bool compareArguments(std::shared_ptr<Function> f2) const;
        
        bool checkParametres(std::shared_ptr<LParametres> params) const;
        
        bool isDeclaration() const;
        
        void setBlock(std::shared_ptr<Block> content);
        
        std::shared_ptr<FunctionSignature> getSignature() const;
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

        std::shared_ptr<IR::FunctionBlock> getIrFunction() const;
    protected:
        std::shared_ptr<FunctionSignature> sig;
        std::shared_ptr<LArguments> args;
        std::shared_ptr<Block> content;
        std::shared_ptr<IR::FunctionBlock> irFunction;
        
    };
}

#endif
