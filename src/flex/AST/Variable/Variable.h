#ifndef VARIABLE_H
#define VARIABLE_H

#include "Variable/AbstractVariable.h"
#include "../../../IR/generator/Generator.h"

namespace IR
{
	class Memory;
}

namespace AST
{
	class Variable : public AbstractVariable
	{
	public:
        
        Variable(std::string name, std::shared_ptr<VariableSignature> signature, bool decl);
        Variable(std::shared_ptr<VariableSignature> signature, bool decl, const IR::Generator &generator);
        
        bool isDeclaration() const;
        void noLongerDeclaration();
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
              
    private:
        std::shared_ptr<IR::Memory> memory;
    };
}

#endif
