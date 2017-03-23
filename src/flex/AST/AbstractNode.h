#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <memory>
#include <cstdlib>
#include <iostream>

#include "Value.h"

namespace AST{

    union TypeValue {
        char character;
        int int32;
        long int int64;
    };
    typedef union TypeValue TypeValue;

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

        virtual void printTree(int tabulationNumber) const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const = 0;

    protected:
        Value value;

    };

}
	
#endif // ABSTRACTNODE_H
