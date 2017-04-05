#ifndef OPERATOR_BITWISE_SHIFT_LEFT_H
#define OPERATOR_BITWISE_SHIFT_LEFT_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBitWiseShiftLeft : public AbstractOperator
    {
    public:
        OperatorBitWiseShiftLeft(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OPERATOR_BITWISE_SHIFT_LEFT_H
