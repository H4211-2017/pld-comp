//#include "IncrRightExpression.h"

//#include <algorithm>

//using namespace AST;

//IncrRightExpression::IncrRightExpression(std::shared_ptr<AbstractExpression> leftMember)
//    : AbstractBinaryExpression("IncrRightExpression", leftMember)
//{
//    this->setType(leftMember->getValue().getValue().first);

//}


//IncrRightExpression::~IncrRightExpression() {
//    // TODO Auto-generated destructor stub
//}
//Value IncrRightExpression::evaluate() const
//{
//    Value leftVal = this->leftMember->evaluate();
//    Value ret(leftVal.getValue().first, leftVal.getValue().second++);
//    return ret;
//}

//// TODO : create class CFG and replace comment below.
//void IncrRightExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
//{

//}

//void IncrRightExpression::printOperator() const
//{
//    std::cout << "++";
//}
