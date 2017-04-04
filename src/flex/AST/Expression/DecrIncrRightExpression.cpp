#include "DecrIncrRightExpression.h"

#include <algorithm>

using namespace AST;

DecrIncrRightExpression::DecrIncrRightExpression(std::shared_ptr<Variable> var, int valueOfIncrement)
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
        std::cout << "| ++ right" << std::endl;
    }
    else if (valueOfIncrement == -1)
    {
        std::cout << "| -- right" << std::endl;
    }
    else
    {
        std::cerr << "DecrIncrRightExpression::printTree : error of valueOfIncrement : " << valueOfIncrement << std::endl;
    }
}
Value DecrIncrRightExpression::evaluate() const
{
    Value leftVal = this->var->evaluate();
    Value ret(leftVal.getValue().first, leftVal.getValue().second + valueOfIncrement);
    return ret;
}

// TODO : create class CFG and replace comment below.
void DecrIncrRightExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{

}
