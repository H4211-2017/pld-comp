#ifndef ARRAYDECLARATION_H
#define ARRAYDECLARATION_H

#include "Instruction/AbstractInstruction.h"

namespace AST {
	
	class VariableSignature;
	class Array;
	class Scope;
	
    class ArrayDeclaration : public AbstractInstruction
    {
    public:
    
        ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, std::shared_ptr<Scope> scope);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    protected:
        std::shared_ptr<Array> array;
    };
}


#endif // ARRAYDECLARATION_H
