#ifndef FONCTION_H
#define FONCTION_H

#include "Instruction/AbstractInstruction.h"
#include "Block.h"
#include "LArguments.h"
#include "FonctionSignature.h"

namespace AST
{
	class Fonction : public AbstractInstruction
	{
	public:
        
        Fonction(std::shared_ptr<FonctionSignature> signature);
        Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<LArguments> arguments);
        Fonction(std::shared_ptr<FonctionSignature> signature, std::shared_ptr<LArguments> arguments, std::shared_ptr<Block> content);
        
        bool compareArguments(std::shared_ptr<Fonction> f2) const;
        
        bool isDeclaration() const;
        
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
