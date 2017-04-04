#ifndef OperatorEquals_H
#define OperatorEquals_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorEquals : public AbstractOperator
    {
    public:
        OperatorEquals(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OperatorEquals_H
