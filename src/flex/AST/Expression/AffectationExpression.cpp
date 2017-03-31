#include "AffectationExpression.h"
#include "AddExpression.h"
#include "IDExpression.h"

using namespace AST;

AffectationExpression::AffectationExpression()
    : AbstractExpression("AffectationExpression")
{
	
}

AffectationExpression::AffectationExpression(std::string id, enum OPAffect op, std::shared_ptr<AbstractExpression> rightMember, std::shared_ptr<Scope> scope)
    : AbstractExpression("AffectationExpression")
{
	var = scope->findVariable(id);
	switch(op)
	{
		
		case AFFECT :
			this->transformedExpr = rightMember;
			var->noLongerDeclaration();
			break;
		case AFFECT_MULT :
			break;
		case AFFECT_DIV :
			break;
		case AFFECT_ADD :
			this->transformedExpr = std::make_shared<AddExpression>(std::make_shared<IDExpression>(id, scope), rightMember);
			break;
		case AFFECT_SUB :
			break;
		case AFFECT_MOD :
			break;
		case AFFECT_BIT_AND :
			break;
		case AFFECT_BIT_OR :
			break;
		case AFFECT_BIT_XOR :
			break;
		case AFFECT_BIT_LEFT_SHIFT :
			break;
		case AFFECT_BIT_RIGHT_SHIFT :
			break;
		default :
			break;
	}
	
	this->setType(this->transformedExpr->getValue().getValue().first);
}

AffectationExpression::~AffectationExpression()
{
	
}

Value AffectationExpression::evaluate() const
{
    Value val = this->transformedExpr->evaluate();
    return val;
}
 
IR::sh_Memory AffectationExpression::buildIR(IR::sh_BasicBlock & currentBasicBlock) const
{
	//TODO Complete IR
	return nullptr;
}

void AffectationExpression::printTree(int tabulationNumber) const
{
    AbstractNode::printTree(tabulationNumber);
    std::cout << std::endl;
    
    this->var->printTree(tabulationNumber + 1);
    std::cout << std::endl;
    
    this->transformedExpr->printTree(tabulationNumber + 1);
}
