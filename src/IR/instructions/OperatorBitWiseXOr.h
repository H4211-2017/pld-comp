#ifndef OPERATOR_BITWISE_XOR_H
#define OPERATOR_BITWISE_XOR_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBitWiseXOr : public AbstractOperator
    {
    public:
        OperatorBitWiseXOr(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OPERATOR_BITWISE_XOR_H
