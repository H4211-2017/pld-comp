#ifndef CONSTANT_H
#define CONSTANT_H

#include <memory>
#include "AbstractNode.h"

namespace AST{
	
    class Constant : public AbstractNode
    {
    public:
        Constant();
        Constant(long int value);
        Constant(char value);
        virtual ~Constant();

        virtual std::shared_ptr<std::pair<TypeValue, Type>> evaluate() const;
        /**
         * return a shared pointer to the value instancited by new if evaluable
         * or empty shared pointer else
         */

        virtual void buildIR() const;

        virtual void printTree(int tabulationNumber) const;

    };

}
#endif // EXPRCONSTANT_H
