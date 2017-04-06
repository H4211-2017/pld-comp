#include "SequenceInstruction.h"

#include "../../../IR/generator/Generator.h"

using namespace AST;

SequenceInstruction::SequenceInstruction()
    : AbstractNode("SequenceInstruction")
{
}

void SequenceInstruction::addInstruction(std::shared_ptr<AbstractInstruction> instruction)
{
    instructionsList.push_back(instruction);
    
    if(instruction != nullptr)
        this->value = instruction->getValue();
}

std::vector<std::shared_ptr<FunctionDeclaration>> SequenceInstruction::getListFunctionDeclaration() const
{
    std::vector<std::shared_ptr<FunctionDeclaration>> result;
    for (std::shared_ptr<AbstractInstruction> instruction : instructionsList)
    {
        std::shared_ptr<FunctionDeclaration> functionDeclaration = std::dynamic_pointer_cast<FunctionDeclaration>(instruction);
        if (functionDeclaration != nullptr)
        {
            result.push_back(functionDeclaration);
        }
    }
    return result;
}

void SequenceInstruction::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    for (int i=0; i<instructionsList.size(); i++)
    {
		if(instructionsList[i] != nullptr)
			instructionsList[i]->printTree(tabulationNumber + 1);
		else
		{
			for(int i=0; i<= tabulationNumber; i++, std::cout << "\t");
			std::cout << "EMPTY";
		}
        std::cout << std::endl;
    }
}

Value SequenceInstruction::evaluate() const
{
	return Value();
}

IR::sh_Memory SequenceInstruction::buildIR(IR::sh_BasicBlock & currentBasicBlock)
{
	IR::Generator gen;
	
	IR::sh_Memory last = nullptr;
	
	if (instructionsList.size() == 0)
	{
        // void intruction sequence has to have value = 0
		//~ IR::Constant constant(IR::VOID, 0);
		//~ last = gen.getNewUnusedMemmory(IR::VOID);
		//~ std::list<IR::sh_AbsInstruction> absIntructions = gen.setValue(constant, last);
		//~ currentBasicBlock->pushInstructionBack(absIntructions);	
	}
	else
	{
		for(std::shared_ptr<AbstractInstruction> instruction : instructionsList)
		{
			if (instruction != nullptr)
			{
                std::cout << "SequenceInstruction::buildIR : instruction : " << instruction << std::endl;
				last = instruction->buildIR(currentBasicBlock);
			}
		}
	}
	
	return last;
}



