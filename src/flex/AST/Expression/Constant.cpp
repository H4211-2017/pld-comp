#include "Constant.h"

#include <climits>

#include "../../../IR/data/Constant.h"
#include "../../../IR/generator/Generator.h"

using namespace AST;

Constant::Constant()
    : AbstractExpression("Constant")
{
	
}

Constant::Constant(long int value)
    : AbstractExpression("Constant", Type::INT_64, value)
{
	if(value < INT_MAX)
	{
		this->setType(Type::INT_32);
	}
}

Constant::~Constant()
{
	
}

Value Constant::evaluate() const
{
    return value;
}
 
IR::sh_Memory Constant::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	IR::Type irType = value.getIRType();
	IR::Generator gen;
	
	IR::Constant constant(irType, value.getValue().second);
	IR::sh_Memory memory = gen.getNewUnusedMemmory(irType);	
	
	currentBasicBlock->pushInstructionBack(gen.setValue(constant, memory));
	return memory;
}

void Constant::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << "| Value : " << value.getValue().second;
}
