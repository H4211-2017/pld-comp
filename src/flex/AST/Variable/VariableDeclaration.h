#ifndef VARIABLEDECLARATION_H
#define VARIABLEDECLARATION_H

#include "Instruction/AbstractInstruction.h"
#include "AbstractExpression.h"
#include "VariableSignature.h"
#include "Variable.h"
#include "Scope.h"

namespace AST
{
    class VariableDeclaration : public AbstractInstruction
    {
    public:
    
		/**
		 * @brief VariableDeclaration constructor
		 * @param signature a shared_ptr to the variable's VariableSignature
		 * @param scope a shared_ptr to the current Scope
		 */
        VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<Scope> scope);
        
        /**
		 * @brief VariableDeclaration constructor
		 * @param signature a shared_ptr to the variable's VariableSignature
		 * @param rightMember a shared_ptr to the expression whose evaluation the variable is initialised to
		 * @param scope a shared_ptr to the current Scope
		 */
        VariableDeclaration(std::shared_ptr<VariableSignature> signature, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope);
        
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
        std::shared_ptr<Variable> var;
        std::shared_ptr<AbstractExpression> val;
    };
}


#endif // VARIABLEDECLARATION_H
