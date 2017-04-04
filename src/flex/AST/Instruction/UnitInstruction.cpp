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

UnitInstruction::UnitInstruction(std::shared_ptr<ReturnInstruction> ret)
	: UnitInstruction()
{
	this->ret = ret;
	this->content = RETURN;
	this->value = this->ret->getValue();
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
		case RETURN:
			this->ret->printTree(tabulationNumber + 1);
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

IR::sh_Memory UnitInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock)
{
	IR::sh_Memory memory = nullptr;
	
    switch (content)
    {
		case BLOCK:
		    memory = block->buildIR(currentBasicBlock);
		    break;
		case STRUCT:
		    memory = struc->buildIR(currentBasicBlock);
		    break;
		case RETURN:
			memory = ret->buildIR(currentBasicBlock);
		default:
			std::cerr << "ERROR : UnitInstruction::buildIR : bad construction of unit instruction" << std::endl;
		    break;
    }
    
    return memory;
}
