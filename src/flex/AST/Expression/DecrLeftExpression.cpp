//#include "DecrLeftExpression.h"

//#include <algorithm>

//using namespace AST;

//DecrLeftExpression::DecrLeftExpression(std::shared_ptr<AbstractExpression> rightMember)
//    : AbstractBinaryExpression("DecrLeftExpression", rightMember)
//{
//    this->setType(rightMember->getValue().getValue().first);

//}


//DecrLeftExpression::~DecrLeftExpression() {
//    // TODO Auto-generated destructor stub
//}

//Value DecrLeftExpression::evaluate() const
//{
//    Value right = this->rightMember->evaluate();
//    Value ret(right.getValue().first, ++right.getValue().second);
//    return ret;
//}

//// TODO : create class CFG and replace comment below.
//IR::sh_Memory DecrLeftExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
//{

//}

//void DecrLeftExpression::printOperator() const
//{
//    std::cout << "++";
//}
