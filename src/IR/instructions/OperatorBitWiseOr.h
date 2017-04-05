#ifndef OPERATOR_BITWISE_OR_H
#define OPERATOR_BITWISE_OR_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBitWiseOr : public AbstractOperator
    {
    public:
        OperatorBitWiseOr(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OPERATOR_BITWISE_OR_H
