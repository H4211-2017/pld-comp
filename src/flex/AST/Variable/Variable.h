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
        
        Variable(std::shared_ptr<VariableSignature> signature, bool decl, const IR::Generator &generator);
        
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
              
    private:
        std::shared_ptr<IR::Memory> memory;
    };
}

#endif
