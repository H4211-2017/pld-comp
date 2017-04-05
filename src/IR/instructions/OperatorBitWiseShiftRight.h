#ifndef OPERATOR_BITWISE_SHIFT_RIGHT_H
#define OPERATOR_BITWISE_SHIFT_RIGHT_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBitWiseShiftRight : public AbstractOperator
    {
    public:
        OperatorBitWiseShiftRight(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OPERATOR_BITWISE_SHIFT_RIGHT_H
