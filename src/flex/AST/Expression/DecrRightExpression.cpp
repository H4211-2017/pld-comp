//#include "DecrRightExpression.h"

//#include <algorithm>

//using namespace AST;

//DecrRightExpression::DecrRightExpression(std::shared_ptr<AbstractExpression> leftMember)
//    : AbstractBinaryExpression("DecrRightExpression", leftMember)
//{
//    this->setType(leftMember->getValue().getValue().first);

//}


//DecrRightExpression::~DecrRightExpression() {
//    // TODO Auto-generated destructor stub
//}
//Value DecrRightExpression::evaluate() const
//{
//    Value leftVal = this->leftMember->evaluate();
//    Value ret(leftVal.getValue().first, leftVal.getValue().second--);
//    return ret;
//}

//// TODO : create class CFG and replace comment below.
//void DecrRightExpression::buildIR(/*std::shared_ptr<BasicBlock>*/) const
//{

//}

//void DecrRightExpression::printOperator() const
//{
//    std::cout << "--";
//}
