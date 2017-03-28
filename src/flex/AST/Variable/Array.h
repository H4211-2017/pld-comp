#ifndef ARRAY_H
#define ARRAY_H

#include "Variable.h"
#include "VariableSignature.h"

namespace AST
{
	class Array : public Variable
	{
	public:
        
        Array(std::shared_ptr<VariableSignature> signature, long int size);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
        
    protected:
        long int size;
    };
}

#endif // ARRAY_H
