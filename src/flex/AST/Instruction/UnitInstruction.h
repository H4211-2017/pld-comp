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
        UnitInstruction(std::shared_ptr<Block> block);
        UnitInstruction(std::shared_ptr<AbstractStructure> struc);
        UnitInstruction(std::shared_ptr<ReturnInstruction> ret);
        
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;
        
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
