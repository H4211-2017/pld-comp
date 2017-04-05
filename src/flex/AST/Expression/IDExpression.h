#ifndef ID_EXPRESSION_H
#define ID_EXPRESSION_H

#include "Variable/Variable.h"
#include "AbstractExpression.h"

#include "Scope.h"
namespace AST {

class IDExpression : public AbstractExpression 
{
	
public:

	/**
	 * @brief IDExpression constructor
	 * @param id string the identifier of the Variable
	 * @param scope a shared_ptr on the current Scope
	 */
    IDExpression(std::string id, std::shared_ptr<Scope> scope);
    
    /**
	 * @brief IDExpression constructor
	 * @param name string the type of the node
	 * @param id string the identifier of the Variable
	 * @param scope a shared_ptr on the current Scope
	 */
    IDExpression(std::string name, std::string id,  std::shared_ptr<Scope> scope);
    
    /**
	 * @brief IDExpression constructor
	 * @param variable the Variable evaluated by the expression
	 * @param scope a shared_ptr on the current Scope
	 */
    IDExpression(std::shared_ptr<AbstractVariable> variable, std::shared_ptr<Scope> scope);
    
    /**
	 * @brief IDExpression constructor
	 * @param id string the identifier of the Variable
	 * @param scope a shared_ptr on the current Scope
	 */
    IDExpression(std::string name, std::shared_ptr<AbstractVariable> variable, std::shared_ptr<Scope> scope);
	
	/**
	 * @brief IDExpression destructor
	 */
	virtual ~IDExpression();

	/**
     * @brief evaluate pure virtual function
     * @return the "Value" of the expression, mainly it's type.
     */
	virtual Value evaluate() const;

	/**
    * @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
    * @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
    * 		that is currently being completed
    * @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
    * 		shouldn't be callable
    */
	virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
	
	/**
     * @brief printTree Prints the structure of the expression
     * @param tabulationNumber the tabulation of this current node.
     */
	void printTree(int tabulationNumber) const;

protected:
    
    std::shared_ptr<AbstractVariable> val;

};

} /* namespace AST */

#endif //ID_EXPRESSION_H
