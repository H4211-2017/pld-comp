#ifndef OPERATORMODULUS_H
#define OPERATORMODULUS_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorModulus : public AbstractOperator
    {
    public:
        OperatorModulus(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister);
    };
}


#endif // OPERATORMODULUS_H
