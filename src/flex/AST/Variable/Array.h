#ifndef ARRAY_H
#define ARRAY_H

#include "AbstractVariable.h"
#include "VariableSignature.h"

namespace AST
{
	class Array : public AbstractVariable
	{
	public:
        
        Array(std::shared_ptr<VariableSignature> signature, long int size);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    protected:
        long int size;    
    };
}

#endif // ARRAY_H
