#include "DecrIncrRightExpression.h"

#include <algorithm>

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

IR::sh_Memory DecrIncrRightExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
    return nullptr;
}
