#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <memory>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Value.h"
#include "../../IR/basicBlock/BasicBlock.h"

namespace AST{

    class Scope;

    class AbstractNode
    {
    public:
        /**
         * @brief AbstractNode constructor
         * @param name the type of the node (used by printTree)
         */
        AbstractNode(std::string name);

        /**
         * @brief AbstractNode constructor
         * @param name the name of the node
         * @param value setting the Value of this node, with its type.
         */
        AbstractNode(std::string name, Value value);

        /**
         * @brief AbstractNode constructor
         * @param name the name of this node (used by printTree)
         * @param type type of the value of this node
         * @param value the integer value of this node
         */
        AbstractNode(std::string name, Type type, long int value);

        /**
         * @brief AbstractNode constructor
         * @param name the name of the node (used by printTree)
         * @param type the type of the Value of this node, sets the integer value to 0.
         */
        AbstractNode(std::string name, Type type);

        /**
         * @brief AbstractNode constructor
         * @param name name of this node (used by printTree)
         * @param scope of this node
         */
        AbstractNode(std::string name, std::shared_ptr<Scope> scope);

        /**
         * @brief AbstractNode constructor
         * @param name name of this node (used by printTree)
         * @param value the Value of this node
         * @param scope of this node
         */
        AbstractNode(std::string name, Value value, std::shared_ptr<Scope> scope);

        /**
         * @brief AbstractNode constructor
         * @param name name of this node (used by printTree)
         * @param type type of the value of this node
         * @param value the integer value of this node
         * @param scope of this node
         */
        AbstractNode(std::string name, Type type, long int value, std::shared_ptr<Scope> scope);

        /**
         * @brief AbstractNode constructor
         * @param name name of this node (used by printTree)
         * @param type the type of the Value of this node, sets the integer value to 0.
         * @param scope of this node
         */
        AbstractNode(std::string name, Type type, std::shared_ptr<Scope> scope);

        virtual ~AbstractNode();

        /**
         * return a shared pointer to the value instancited by new if evaluable
         * or empty shared pointer else
         */
        virtual Value evaluate() const = 0;

        /**
         * @brief printTree Print the tree from this node, with a number a tabulation equal to tabulationNumber
         * @param tabulationNumber The number of tabulation before each line of the tree of this node
         */
        virtual void printTree(int tabulationNumber) const;

        /**
		* @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
		* 		that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
        virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const = 0;
        
        /**
         * @brief get a reference on the most local Scope for the node
         * @return a shared pointer on the Scope object
         */
        virtual std::shared_ptr<Scope> getScope() const;
        
        /**
         * @brief sets the Parent Scope of the node's most local Scope
         * @param scope shared_ptr<Scope> a reference on the scope to be set as parent to the most local Scope
         */
        virtual void setParentScope(std::shared_ptr<Scope> scope);

		/**
		 * @brief getter for the value attribute of the node
		 * @return a Value object
		 */
        Value getValue() const;
        
        /**
         * @brief set the type for the node
         * @param type AST::Type the type to be set
         */
		virtual void setType(Type type);
        
        /**
         * @brief getter for the name attribute of the node
         * @return a string
         * @remark the name of the node define its use inside the AST
         */
        std::string getName() const;

    protected:

        Value value;
        std::shared_ptr<Scope> currentScope;

    private:
        std::string name;

    };

}
	
#endif // ABSTRACTNODE_H
