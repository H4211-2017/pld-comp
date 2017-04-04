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
        UnitInstruction();
        /**
         * @brief UnitInstruction construcor, if this instruction is a block
         * @param block the bloc that is the main component of this instruction
         */
        UnitInstruction(std::shared_ptr<Block> block);

        /**
         * @brief UnitInstruction construcor, if this instruction is a controle structure (if, while, for...)
         * @param struc the struc that is the main component of this instruction
         */
        UnitInstruction(std::shared_ptr<AbstractStructure> struc);
        UnitInstruction(std::shared_ptr<ReturnInstruction> ret);
        
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock);
        
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
