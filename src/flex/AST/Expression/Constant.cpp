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
	IR::Type irType;
	IR::Generator gen;
	
	switch(value.getValue().first)
	{
		case CHAR :
			irType = IR::CHAR;
			break;
		case INT_32 :
			irType = IR::INT_32;
			break;
		case INT_64 :
			irType = IR::INT_64;
			break;
		default :
			std::cerr << "ERROR Constant::buildIR : Error in value of type : " << value.getValue().first << " Of Constant " << value.getValue().second << std::endl;
			break;
	}
	
	IR::Constant constant(irType, value.getValue().second);
	IR::sh_Memory memory = gen.getNewUnusedMemmory(irType);	
	
	currentBasicBlock->pushInstructionBack(gen.setValue(constant, memory));
	return memory;
}

void Constant::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
}
