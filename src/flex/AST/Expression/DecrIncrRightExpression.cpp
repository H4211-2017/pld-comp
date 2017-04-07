#include "DecrIncrRightExpression.h"

#include <algorithm>

#include "../../../IR/generator/Generator.h"
#include "../../../IR/instructions/DecrIncrOperator.h"

using namespace AST;

DecrIncrRightExpression::DecrIncrRightExpression(std::shared_ptr<AbstractVariable> var, int valueOfIncrement)
    : AbstractExpression("DecrIncrRightExpression", var->getValue()), var(var), valueOfIncrement(valueOfIncrement)
{

}


DecrIncrRightExpression::~DecrIncrRightExpression()
{
}

void DecrIncrRightExpression::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    if (valueOfIncrement == 1)
    {
        std::cout << "| ++ right";
    }
    else if (valueOfIncrement == -1)
    {
        std::cout << "| -- right";
    }
    else
    {
        std::cerr << "DecrIncrRightExpression::printTree : error of valueOfIncrement : " << valueOfIncrement << std::endl;
    }
    std::cout << std::endl;
    var->printTree(tabulationNumber + 1);
}
Value DecrIncrRightExpression::evaluate() const
{
    Value leftVal = this->var->evaluate();
    Value ret(leftVal.getValue().first, leftVal.getValue().second + valueOfIncrement);
    return ret;
}

// TODO : create class CFG and replace comment below.
IR::sh_Memory DecrIncrRightExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    IR::Generator gen; 
	IR::sh_Memory leftMem = this->var->buildIR(currentBasicBlock); 
	IR::Type irType = this->var->getValue().getIRType(); 
	IR::sh_Memory destMem = gen.getNewUnusedMemmory(irType); 
	std::list<IR::sh_AbsInstruction> instructionsList = gen.decrIncrOperator(leftMem, destMem, valueOfIncrement, false); 
	currentBasicBlock->pushInstructionBack(instructionsList); 
	return destMem; 
}
