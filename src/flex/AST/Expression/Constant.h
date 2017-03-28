#ifndef ASTCONSTANT_H
#define ASTCONSTANT_H

#include <memory>
#include "AbstractExpression.h"

namespace AST{
	
    class Constant : public AbstractExpression
    {
    public:
        Constant();
        Constant(long int value);
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
