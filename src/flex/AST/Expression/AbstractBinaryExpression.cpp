/*
 * AbstractBinaryExpression.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#include "AbstractBinaryExpression.h"
using namespace AST;
AbstractBinaryExpression::AbstractBinaryExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember)
    : AbstractExpression(std::max(rightMember->getValue().getValue().first, leftMember->getValue().getValue().first), 0)
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
    std::cout << std::endl;

    for (int i = 0; i < tabulationNumber + 1; i++)
    {
        std::cout << "\t";
    }
    printOperator();
    std::cout << std::endl;
    leftMember->printTree(tabulationNumber + 1);
    std::cout << std::endl;
    rightMember->printTree(tabulationNumber + 1);
    std::cout << std::endl;
}

