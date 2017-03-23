///*
// * AddExpression.cpp
// *
// *  Created on: Mar 23, 2017
// *      Author: florent
// */

//#include "AddExpression.h"

//using namespace AST;

//AddExpression::AddExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember)
//    : AbstractBinaryExpression(rightMember, leftMember){}


//AddExpression::~AddExpression() {
//	// TODO Auto-generated destructor stub
//}



//std::shared_ptr<std::pair<TypeValue,Type>> AddExpression::evaluate() const
//{
//    std::shared_ptr<std::pair<TypeValue,Type>> right = rightMember->evaluate();
//    std::shared_ptr<std::pair<TypeValue,Type>> left = leftMember->evaluate();

//    if(right == nullptr || left == nullptr)
//    {
//        std::cerr << "AddExpression::evaluate non evaluable expression" << std::endl;

//        return nullptr;
//    }
//    else{
//        Type typeReturn = std::max(right->second , left->second);

//        switch( typeReturn ){

//        case CHAR:
//            char rightChar = (char) right->first.character;
//            char leftChar = (char) left->first.character;
//            return std::make_shared<std::pair<TypeValue,Type>>(rightChar + leftChar, typeReturn  );
//            // return std::make_shared<std::pair<<TypeValue,Type>>((char)right->first + (char)left->first , typeReturn  );
//            break;

//        case INT_32:
//            return std::make_shared<std::pair<TypeValue,Type>>((int)right->first + (int)left->first , typeReturn  );
//            break;

//        case INT_64:
//            return std::make_shared<std::pair<TypeValue,Type>>((long)right->first + (long)left->first , typeReturn  );
//            break;
//        }
//    }
//}
