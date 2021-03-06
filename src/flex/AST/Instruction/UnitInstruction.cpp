#include "UnitInstruction.h"

#include "ReturnInstruction.h"

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

UnitInstruction::UnitInstruction(bool isBreak)
	: UnitInstruction()
{
	if(isBreak)
		this->content = BREAK;
	else
		this->content = CONTINUE;
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
		case RETURN:
			this->ret->printTree(tabulationNumber + 1);
			break;
		case BREAK:
			for(int i=0; i<=tabulationNumber; i++, std::cout << "  ");
			std::cout << "BreakInstruction";
			break;
		case CONTINUE:
			for(int i=0; i<=tabulationNumber; i++, std::cout << "  ");
			std::cout << "BreakInstruction";
			break;
		default:
			break;
	}
}

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

IR::sh_Memory UnitInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{	
    switch (content)
    {
		case BLOCK:
		    return block->buildIR(currentBasicBlock);
		    break;
		case STRUCT:
		    return struc->buildIR(currentBasicBlock);
		    break;
		case RETURN:
			return ret->buildIR(currentBasicBlock);
			break;
		case BREAK:
			return nullptr;
			break;
		case CONTINUE:
			return nullptr;
			break;
		default:
			std::cerr << "ERROR : UnitInstruction::buildIR : bad construction of unit instruction" << std::endl;
		    break;
    }
    
    return nullptr;
}
