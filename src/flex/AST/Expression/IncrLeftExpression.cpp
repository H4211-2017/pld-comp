//#include "IncrLeftExpression.h"

//#include <algorithm>

//using namespace AST;

//IncrLeftExpression::IncrLeftExpression(std::shared_ptr<AbstractExpression> rightMember)
//    : AbstractBinaryExpression("IncrLeftExpression", rightMember)
//{
//    this->setType(rightMember->getValue().getValue().first);

//}


//IncrLeftExpression::~IncrLeftExpression() {
//    // TODO Auto-generated destructor stub
//}
//Value IncrLeftExpression::evaluate() const
//{
//    Value right = this->rightMember->evaluate();
//    Value ret(right.getValue().first, ++right.getValue().second);
//    return ret;
//}

//// TODO : create class CFG and replace comment below.
//void IncrLeftExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
//{

//}

//void IncrLeftExpression::printOperator() const
//{
//    std::cout << "++";
//}
