#ifndef UNITINSTRUCTION_H
#define UNITINSTRUCTION_H

#include "AbstractInstruction.h"
#include "AbstractExpression.h"
#include "Block.h"
#include "AbstractNode.h"

namespace AST {

    class UnitInstruction : public AbstractInstruction
    {
    public:
        UnitInstruction();
        UnitInstruction(std::shared_ptr<Block> block);
        
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
    	enum Content content;
    };
}


#endif // UNITINSTRUCTION_H
