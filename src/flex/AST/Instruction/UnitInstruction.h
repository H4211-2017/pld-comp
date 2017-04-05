#ifndef UNITINSTRUCTION_H
#define UNITINSTRUCTION_H

#include "AbstractInstruction.h"
#include "Structure/AbstractStructure.h"
#include "Block.h"
#include "Instruction/ReturnInstruction.h"
#include "AbstractNode.h"

namespace AST {

    class UnitInstruction : public AbstractInstruction
    {
    public:
    
		/**
		 * @brief UnitInstruction constructor
		 */
        UnitInstruction();
        /**
         * @brief UnitInstruction constructor, if this instruction is a block
         * @param block a shared_ptr to the Block that is the main component of this instruction
         */
        UnitInstruction(std::shared_ptr<Block> block);

        /**
         * @brief UnitInstruction constructor, if this instruction is a controle structure (if, while, for...)
         * @param struc a shared_ptr to the AbstractStructure that is the main component of this instruction
         */
        UnitInstruction(std::shared_ptr<AbstractStructure> struc);
        
        /**
         * @brief UnitInstruction constructor, if this instruction is a return
         * @param ret a shared_ptr to the ReturnInstruction that is the main component of this instruction
         */
        UnitInstruction(std::shared_ptr<ReturnInstruction> ret);
        
        /**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
        virtual void printTree(int tabulationNumber) const;
        
        /**
		 * @brief evaluate pure virtual function
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
    
    	enum Content
    	{
    		BLOCK,
    		STRUCT,
    		RETURN,
    		ERROR
    	};
    
    	std::shared_ptr<Block> block;
    	std::shared_ptr<AbstractStructure> struc;
    	std::shared_ptr<ReturnInstruction> ret;
    	enum Content content;
    };
}

std::shared_ptr<AST::UnitInstruction> make_shared_uinstr(AST::UnitInstruction* ptr);

#endif // UNITINSTRUCTION_H
