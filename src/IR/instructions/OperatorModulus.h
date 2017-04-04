#ifndef OPERATORMODULUS_H
#define OPERATORMODULUS_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorModulus : public AbstractOperator
    {
    public:
        OperatorModulus(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
        virtual std::string toLinuxX86() const;
        virtual std::string toString() const;
    };
}


#endif // OPERATORMODULUS_H
