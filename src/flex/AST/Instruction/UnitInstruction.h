#ifndef UNITINSTRUCTION_H
#define UNITINSTRUCTION_H

#include "AbstractInstruction.h"
#include "UnitStructure/AbstractStructure.h"
#include "Block.h"
#include "AbstractNode.h"

namespace AST {

    class UnitInstruction : public AbstractInstruction
    {
    public:
        UnitInstruction();
        UnitInstruction(std::shared_ptr<Block> block);
        UnitInstruction(std::shared_ptr<AbstractStructure> struc);
        
        
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
    	enum Content content;
    };
}

std::shared_ptr<AST::UnitInstruction> make_shared_uinstr(AST::UnitInstruction* ptr);

#endif // UNITINSTRUCTION_H
