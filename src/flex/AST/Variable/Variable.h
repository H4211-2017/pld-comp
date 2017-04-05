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
        
        /**
		 * @brief ArrayDeclaration constructor
		 * @param name string the type of the node
		 * @param signature a shared_ptr to the array's VariableSignature
		 * @param decl bool whether or not the variable is declared without being initialised
		 */
        Variable(std::string name, std::shared_ptr<VariableSignature> signature, bool decl);
        
        //TODO Comment this
        Variable(std::shared_ptr<VariableSignature> signature, bool decl, const IR::Generator &generator);
        
        /**
         * @brief Variable destructor
         */
        virtual ~Variable();
        
        /**
         * @brief checks if the variable's Value is still not set
         * @return true if it isnt set, false if it can be evaluated
         */
        bool isDeclaration() const;
        
        /**
         * @brief declares that the variable can now be evaluated
         */
        void noLongerDeclaration();
        
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
              
    private:
        std::shared_ptr<IR::Memory> memory;
    };
}

#endif
