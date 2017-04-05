#ifndef APPEL_FONCTION_H
#define APPEL_FONCTION_H
#include "Function.h"
#include "LParametres.h"
#include "AbstractExpression.h"

#include "Scope.h"
namespace AST {

class FunctionCall : public AbstractExpression
{
	
public:

	/**
	 * @brief FunctionCall constructor
	 * @param id string the identifier of the called function
	 * @param params a shared_ptr to the LParametres object representing the list of parameters
	 * @param scope a shared_ptr to the current Scope
	 */
    FunctionCall(std::string id,  std::shared_ptr<LParametres> params, std::shared_ptr<Scope> scope);
	
	/**
	 * @brief FunctionCall destructor 
	 */
    virtual ~FunctionCall();
    
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
    
    std::shared_ptr<Function> fct;
    std::shared_ptr<LParametres> parametres;

};

} /* namespace AST */

#endif //ID_EXPRESSION_H
