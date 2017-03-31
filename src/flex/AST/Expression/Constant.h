#ifndef AST_CONSTANT_H
#define AST_CONSTANT_H

#include <memory>
#include "AbstractExpression.h"

namespace AST{
	
    class Constant : public AbstractExpression
    {
    public:
        Constant();
        Constant(long int value);
        virtual ~Constant();


        /**
         * @brief evaluate returns the value of the constant, and the type is int_32 or int_64 if constant is too large.
         * @return
         */

        virtual Value evaluate() const;

        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;

        virtual void printTree(int tabulationNumber) const;
    };

}
#endif // AST_CONSTANT_H
