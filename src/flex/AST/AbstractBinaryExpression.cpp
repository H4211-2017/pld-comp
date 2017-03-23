/*
 * AbstractBinaryExpression.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#include "AbstractBinaryExpression.h"

AbstractBinaryExpression::AbstractBinaryExpression(std::shared_ptr<AbstractExpression> rightMember,  std::shared_ptr<AbstractExpression> leftMember) {
	this.rightMember = rightMember;
	this.leftMember = leftMember;
}

AbstractBinaryExpression::~AbstractBinaryExpression() {
}

