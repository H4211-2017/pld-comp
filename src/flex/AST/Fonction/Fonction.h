#ifndef FONCTION_H
#define FONCTION_H

#include "Instruction/AbstractInstruction.h"
#include "Block.h"
#include "LArguments.h"
#include "FonctionSignature.h"

namespace AST
{
	class Fonction : public AbstractNode
	{
	public:
        
        Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<Scope> parentScope);
        Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Scope> parentScope);
        
        Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope);
        Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Block> content, std::shared_ptr<Scope> parentScope);
        
        bool compareArguments(std::shared_ptr<Fonction> f2) const;
        
        bool checkParametres(std::shared_ptr<LParametres> params) const;
        
        bool isDeclaration() const;
        
        void setBlock(std::shared_ptr<Block> content);
        
        std::shared_ptr<FonctionSignature> getSignature() const;
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
        
    protected:
        std::shared_ptr<FonctionSignature> sig;
        std::shared_ptr<LArguments> args;
        std::shared_ptr<Block> content;
    };
}

#endif
