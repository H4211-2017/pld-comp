#ifndef UNARYOPERATOR_H
#define UNARYOPERATOR_H

#include <memory>

#include "AbstractInstruction.h"
#include "../data/Register.h"
#include "../../flex/AST/Expression/UnaryExpression.h"

namespace IR {
    class UnaryOperator : public AbstractInstruction
    {
    public:
        UnaryOperator(sh_Register resultRegister, sh_Register firstValueRegister, enum AST::UnaryOp op);
        ~UnaryOperator();
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    protected:
        sh_Register destination;
        sh_Register firstValue;
        enum AST::UnaryOp op;
    };
}


#endif // UNARYOPERATOR_H
