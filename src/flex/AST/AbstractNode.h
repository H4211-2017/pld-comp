#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <memory>
#include <cstdlib>
#include <iostream>

#include "Value.h"

namespace AST{

    class AbstractNode
    {
    public:
        AbstractNode();
        AbstractNode(Value value);
        AbstractNode(Type type, long int value);

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

    protected:
        Value value;

    };

}
#endif // ABSTRACTNODE_H
