/*
 * AbstractBinaryExpression.h
 *
 *  Created on: Mar 23, 2017
 *      Author: florent
 */

#ifndef SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_
#define SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_
#include "AbstractExpression.h"

#include "../../../IR/generator/Generator.h"

namespace AST
{
	class AbstractBinaryExpression : public AbstractExpression
	{
	
	public:
		AbstractBinaryExpression(std::string name, std::shared_ptr<AbstractExpression> leftMember,  std::shared_ptr<AbstractExpression> rightMember);
		virtual ~AbstractBinaryExpression();

		/**
		 * @brief printTree Prints the structure of the expression
		 * @param tabulationNumber the tabulation of this current node.
		 */
		virtual void printTree(int tabulationNumber) const;

		/**
		 * @brief evaluate pure virtual function
		 * @return the "Value" of the expression, mainly it's type.
		 */
		virtual Value evaluate() const =0;
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const =0;
		
	protected:
		virtual void printOperator() const =0;

		std::shared_ptr<AbstractExpression> rightMember;
		std::shared_ptr<AbstractExpression> leftMember;
		
		template<typename T> 
		IR::sh_Memory fcBuildIR(IR::sh_BasicBlock & currentBasicBlock) const
		{ 
			IR::Generator gen; 
			IR::sh_Memory leftMem = this->leftMember->buildIR(currentBasicBlock); 
			IR::sh_Memory rightMem = this->rightMember->buildIR(currentBasicBlock); 
			IR::Type irType = this->value.getIRType(); 
			IR::sh_Memory destMem = gen.getNewUnusedMemmory(irType); 
			std::list<IR::sh_AbsInstruction> instructionsList = gen.binaryOperator<T>(leftMem, rightMem, destMem); 
			currentBasicBlock->pushInstructionBack(instructionsList); 
			return destMem; 
		}
		
	};
	
}


#endif /* SRC_FLEX_AST_ABSTRACTBINARYEXPRESSION_H_ */
