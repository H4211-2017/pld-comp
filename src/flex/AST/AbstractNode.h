#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <memory>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Value.h"
#include "VariableScope.h"

namespace AST{

    class VariableScope;

    class AbstractNode
    {
    public:
        AbstractNode(std::string name);
        AbstractNode(std::string name, Value value);
        AbstractNode(std::string name, Type type, long int value);
        AbstractNode(std::string name, Type type);

        AbstractNode(std::string name, std::shared_ptr<VariableScope>);
        AbstractNode(std::string name, Value value, std::shared_ptr<VariableScope>);
        AbstractNode(std::string name, Type type, long int value, std::shared_ptr<VariableScope>);
        AbstractNode(std::string name, Type type, std::shared_ptr<VariableScope>);

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
        virtual void buildIR(/*std::shared_ptr<IR::BasicBloc>*/) const = 0;

        Value getValue() const;
        std::string getName() const;

    protected:

        Value value;
        std::shared_ptr<VariableScope> currentVariableScope;

    private:
        std::string name;

    };

}
	
#endif // ABSTRACTNODE_H
