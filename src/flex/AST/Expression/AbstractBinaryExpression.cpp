/*
 * AbstractBinaryExpression.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#include "AbstractBinaryExpression.h"

#include "../../../IR/instructions/AbstractOperator.h"

using namespace AST;
AbstractBinaryExpression::AbstractBinaryExpression(std::string name, std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember)
    : AbstractExpression(name, std::max(rightMember->getValue().getValue().first, leftMember->getValue().getValue().first), 0)
{
    this->rightMember = rightMember;
    this->leftMember = leftMember;
}

AbstractBinaryExpression::~AbstractBinaryExpression() 
{
}

void AbstractBinaryExpression::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
	std::cout << '\t';
    printOperator();
    std::cout << std::endl;
    leftMember->printTree(tabulationNumber + 1);
    std::cout << std::endl;
    rightMember->printTree(tabulationNumber + 1);
}

