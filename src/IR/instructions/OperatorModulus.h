#ifndef OPERATORMODULUS_H
#define OPERATORMODULUS_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorModulus : public AbstractOperator
    {
    public:
        OperatorModulus(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
    };
}


#endif // OPERATORMODULUS_H
