#include "DecrIncrLeftExpression.h"

#include <algorithm>

using namespace AST;

DecrIncrLeftExpression::DecrIncrLeftExpression(std::shared_ptr<Variable> var, int valueOfIncrement)
    : AbstractExpression("DecrIncrLeftExpression", var->getValue()), var(var), valueOfIncrement(valueOfIncrement)
{

}


DecrIncrLeftExpression::~DecrIncrLeftExpression()
{
}

void DecrIncrLeftExpression::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    if (valueOfIncrement == 1)
    {
        std::cout << "| ++ left" << std::endl;
    }
    else if (valueOfIncrement == -1)
    {
        std::cout << "| -- left" << std::endl;
    }
    else
    {
        std::cerr << "DecrIncrRightExpression::printTree : error of valueOfIncrement : " << valueOfIncrement << std::endl;
    }
}
Value DecrIncrLeftExpression::evaluate() const
{
    Value leftVal = this->var->evaluate();
    Value ret(leftVal.getValue().first, leftVal.getValue().second + valueOfIncrement);
    return ret;
}

// TODO
void DecrIncrLeftExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

}
