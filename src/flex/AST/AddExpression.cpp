/*
 * AddExpression.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#include "AddExpression.h"

namespace AST {

AddExpression::AddExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember)
    : AbstractBinaryExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember){}


AddExpression::~AddExpression() {
	// TODO Auto-generated destructor stub
}

} /* namespace AST */

int AddExpression::evaluate(){
	return rightMember->evaluate() + leftMember->evaluate();
}

void AddExpression::printTree(int tabulationNumber){
	AbstractNode::printTree(tabulationNumber);
	std::cout<<rightMember->printTree(tabulationNumber+1)<<"+"<<leftMember->printTree(tabulationNumber + 1);
}
