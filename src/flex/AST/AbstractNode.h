#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

#include <memory>
#include <cstdlib>
#include <iostream>

namespace AST{

    union TypeValue
    {
        char character;
        int int32;
        long int int64;
    };
    typedef union TypeValue TypeValue;

    enum Type
    {
        CHAR,
        INT_32,
        INT_64,
        ERROR,
    };

    typedef enum Type Type;


    class AbstractNode
    {
    public:
        AbstractNode();
        AbstractNode(Type type, long int value);

        virtual ~AbstractNode();

        /**
         * return a shared pointer to the value instancited by new if evaluable
         * or empty shared pointer else
         */
        virtual std::shared_ptr<std::pair<TypeValue, Type>> evaluate() const = 0;

        virtual void printTree(int tabulationNumber) const;

        // TODO : create class CFG and replace comment below.
        virtual void buildIR(/*std::shared_ptr<CFG>*/) const = 0;

    protected:
        TypeValue value;
        Type type;

    };

}
#endif // ABSTRACTNODE_H
