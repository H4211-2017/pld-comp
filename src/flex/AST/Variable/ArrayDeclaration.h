#ifndef ARRAYDECLARATION_H
#define ARRAYDECLARATION_H

#include "Instruction/AbstractInstruction.h"
#include "Instruction/ComposedInstruction.h"
#include "Expression/AbstractExpression.h"

namespace AST {
	
	class VariableSignature;
	class Array;
	class Scope;
	
    class ArrayDeclaration : public AbstractInstruction
    {
    public:
    
        ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, std::shared_ptr<Scope> scope);
				
		ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, char* valeurs, std::shared_ptr<Scope> scope);
				
		ArrayDeclaration(std::shared_ptr<VariableSignature> signature,
						char* valeurs, std::shared_ptr<Scope> scope);
						
		ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, std::shared_ptr<ComposedInstruction> valeurs, std::shared_ptr<Scope> scope);
				
		ArrayDeclaration(std::shared_ptr<VariableSignature> signature,
						std::shared_ptr<ComposedInstruction> valeurs, std::shared_ptr<Scope> scope);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) ;
        
    protected:
        std::shared_ptr<Array> array;
        std::vector<std::shared_ptr<AbstractExpression>> eventualTabInit;
        char *eventualInit;
    };
}


#endif // ARRAYDECLARATION_H
