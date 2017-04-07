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
		/**
		 * @brief ArrayDeclaration constructor
		 * @param signature a shared_ptr to the array's VariableSignature
		 * @param size long int the size of the array
		 * @param scope a shared_ptr to the current Scope
		 */
        ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, std::shared_ptr<Scope> scope);

		/**
		 * @brief ArrayDeclaration constructor
		 * @param signature a shared_ptr to the array's VariableSignature
		 * @param size long int the size of the array
		 * @param valeurs char* the string containing all the values of the array
		 * @param scope a shared_ptr to the current Scope
		 */
		ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, char* valeurs, std::shared_ptr<Scope> scope);
		
		/**
		 * @brief ArrayDeclaration constructor
		 * @param signature a shared_ptr to the array's VariableSignature
		 * @param valeurs char* the string containing values of the array
		 * @param scope a shared_ptr to the current Scope
		 */	
		ArrayDeclaration(std::shared_ptr<VariableSignature> signature,
						char* valeurs, std::shared_ptr<Scope> scope);
		
		/**
		 * @brief ArrayDeclaration constructor
		 * @param signature a shared_ptr to the array's VariableSignature
		 * @param size long int the size of the array
		 * @param valeurs a shared_ptr to the ComposedInstruction containing values of the array 
		 * @param scope a shared_ptr to the current Scope
		 */		
		ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, std::shared_ptr<ComposedInstruction> valeurs, std::shared_ptr<Scope> scope);
		
		/**
		 * @brief ArrayDeclaration constructor
		 * @param signature a shared_ptr to the array's VariableSignature
		 * @param valeurs a shared_ptr to the ComposedInstruction containing values of the array 
		 * @param scope a shared_ptr to the current Scope
		 */
		ArrayDeclaration(std::shared_ptr<VariableSignature> signature,
						std::shared_ptr<ComposedInstruction> valeurs, std::shared_ptr<Scope> scope);
        
         /**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
        virtual void printTree(int tabulationNumber) const;
        
        /**
		 * @brief evaluate the Value of the variable
		 * @return the "Value" of the expression, mainly it's type.
		 */
        virtual Value evaluate() const;
        
        /**
		* @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
		* 		that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    protected:
        std::shared_ptr<Array> array;
        std::vector<std::shared_ptr<AbstractExpression>> eventualTabInit;
        char *eventualInit;
    };
}


#endif // ARRAYDECLARATION_H
