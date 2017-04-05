#ifndef OPERATORMULT_H
#define OPERATORMULT_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorMult : public AbstractOperator
    {
    public:
        OperatorMult(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX64() const;
        virtual std::string toString() const;
    };
}


#endif // OPERATORMULT_H
