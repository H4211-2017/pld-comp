#include "UnitInstruction.h"

using namespace AST;

UnitInstruction::UnitInstruction()
    : AbstractInstruction("UnitInstruction"), content(ERROR)
{

}

UnitInstruction::UnitInstruction(std::shared_ptr<Block> block) 
	: UnitInstruction()
{
	this->block = block;
	this->content = BLOCK;
	this->value = this->block->getValue();
}

UnitInstruction::UnitInstruction(std::shared_ptr<AbstractStructure> struc)
	: UnitInstruction()
{
	this->struc = struc;
	this->content = STRUCT;
	this->value = Value();
}

void UnitInstruction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    
    switch(content)
	{
		case BLOCK:
			this->block->printTree(tabulationNumber + 1);
			break;
		case STRUCT:
			this->struc->printTree(tabulationNumber + 1);
			break;
		default:
			break;
	}
}

// TODO
Value UnitInstruction::evaluate() const
{
	switch(content)
	{
		case BLOCK:
			return this->block->evaluate();
		default:
			return Value();
	}
}

void UnitInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    switch (content) {
    case Content::BLOCK:
        block->buildIR(currentBasicBlock);
        break;
    case Content::STRUCT:
        struc->buildIR(currentBasicBlock);
        break;
    default:
        break;
    }
}
