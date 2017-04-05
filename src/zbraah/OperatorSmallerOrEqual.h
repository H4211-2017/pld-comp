#ifndef OperatorSmallerOrEqual_H
#define OperatorSmallerOrEqual_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorSmallerOrEqual : public AbstractOperator
    {
    public:
        OperatorSmallerOrEqual(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OperatorSmallerOrEqual_H
