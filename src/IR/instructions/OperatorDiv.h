#ifndef OperatorDiv_H
#define OperatorDiv_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorDiv : public AbstractOperator
    {
    public:
        OperatorDiv(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX86() const;
        virtual std::string toString() const;
    };
}


#endif // OperatorDiv_H
