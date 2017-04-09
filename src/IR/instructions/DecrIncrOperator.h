#ifndef DECRINCROPERATOR_H
#define DECRINCROPERATOR_H

#include <memory>

#include "AbstractInstruction.h"
#include "../data/Register.h"
#include "../data/Memory.h"
#include "../../flex/AST/Expression/UnaryExpression.h"

namespace IR {
    class DecrIncrOperator : public AbstractInstruction
    {
    public:
        DecrIncrOperator(sh_Register resultRegister, sh_Register firstValueRegister, int valueOfIncrement, bool isBefore);
        ~DecrIncrOperator();
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    protected:
        sh_Register destination;
        sh_Register firstValue;
        int value;
        bool isBef;
    };
}


#endif // DECRINCROPERATOR_H
