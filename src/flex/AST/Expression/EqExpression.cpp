#include "EqExpression.h"

#include <algorithm>
#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/OperatorEquals.h"


using namespace AST;

EqExpression::EqExpression(std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractBinaryExpression("EqExpression", leftMember, rightMember)
{
    this->setType(Type::CHAR);

}


EqExpression::~EqExpression() {
    // TODO Auto-generated destructor stub
}

Value EqExpression::evaluate() const
{
    Value left = this->leftMember->evaluate();
    Value right = this->rightMember->evaluate();
    Value ret(std::max(left.getValue().first, right.getValue().first), left.getValue().second == right.getValue().second);
    return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory EqExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	IR::Generator gen;
	IR::sh_Memory leftMem = leftMember->buildIR(currentBasicBlock);
	IR::sh_Memory rightMem = rightMember->buildIR(currentBasicBlock);
	
	IR::Type irType = value.getIRType();
	IR::sh_Memory destMem = gen.getNewUnusedMemmory(irType);
	
	std::list<IR::sh_AbsInstruction> instructionsList = gen.binaryOperator<IR::OperatorEquals>(leftMem, rightMem, destMem);
	
	currentBasicBlock->pushInstructionBack(instructionsList);
	
	return destMem;
}

void EqExpression::printOperator() const
{
    std::cout << "==";
}
