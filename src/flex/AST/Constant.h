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

        virtual Value evaluate() const;
        /**
         * return a shared pointer to the value instancited by new if evaluable
         * or empty shared pointer else
         */

        virtual void buildIR() const;

        virtual void printTree(int tabulationNumber) const;

    };

}
#endif // EXPRCONSTANT_H
