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

        // TODO : replace comment below.
        /**
         * @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
         */
        //virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const = 0;
        
        virtual std::shared_ptr<Scope> getScope() const;
        
        //virtual void setParentScope(std::shared_ptr<Scope> scope);

        Value getValue() const;
        
		virtual void setType(Type type);
        
        std::string getName() const;

    protected:

        Value value;
        std::shared_ptr<Scope> currentScope;

    private:
        std::string name;

    };

}
	
#endif // ABSTRACTNODE_H
