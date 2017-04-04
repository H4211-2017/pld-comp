#ifndef OperatorNotEquals_H
#define OperatorNotEquals_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorNotEquals : public AbstractOperator
    {
    public:
        OperatorNotEquals(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX86() const;
        virtual std::string toString() const;
    };
}


#endif // OperatorNotEquals_H
