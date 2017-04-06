#include "AddExpression.h"

#include <algorithm>

#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorPlus.h"

using namespace AST;

AddExpression::AddExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("AddExpression", leftMember, rightMember)
{
	this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));
}


AddExpression::~AddExpression() {
	// TODO Auto-generated destructor stub
}

Value AddExpression::evaluate() const
{
	Value leftVal = this->leftMember->evaluate();
	Value rightVal = this->rightMember->evaluate();
	Value ret(std::max(leftVal.getValue().first, rightVal.getValue().first), leftVal.getValue().second + rightVal.getValue().second);
	return ret;
}

IR::sh_Memory AddExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	IR::Generator gen;
	IR::sh_Memory leftMem = leftMember->buildIR(currentBasicBlock);
	IR::sh_Memory rightMem = rightMember->buildIR(currentBasicBlock);
	
	IR::Type irType = value.getIRType();
	IR::sh_Memory destMem = gen.getNewUnusedMemmory(irType);
	
	std::list<IR::sh_AbsInstruction> instructionsList = gen.binaryOperator<IR::OperatorPlus>(leftMem, rightMem, destMem);
	
	currentBasicBlock->pushInstructionBack(instructionsList);
	
	return destMem;
}

void AddExpression::printOperator() const
{
    std::cout << "+";
}
