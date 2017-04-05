#include "DivExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorDiv.h"

using namespace AST;

DivExpression::DivExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("DivExpression", leftMember, rightMember)
{
    this->setType(std::max(leftMember->getValue().getValue().first, rightMember->getValue().getValue().first));

}


DivExpression::~DivExpression() {
    // TODO Auto-generated destructor stub
}

Value DivExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second / right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory DivExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	IR::Generator gen;
	IR::sh_Memory leftMem = leftMember->buildIR(currentBasicBlock);
	IR::sh_Memory rightMem = rightMember->buildIR(currentBasicBlock);
	
	IR::Type irType = value.getIRType();
	IR::sh_Memory destMem = gen.getNewUnusedMemmory(irType);
	
	std::list<IR::sh_AbsInstruction> instructionsList = gen.binaryOperator<IR::OperatorDiv>(leftMem, rightMem, destMem);
	
	currentBasicBlock->pushInstructionBack(instructionsList);
	
	return destMem;
}

void DivExpression::printOperator() const
{
    std::cout << "/";
}
