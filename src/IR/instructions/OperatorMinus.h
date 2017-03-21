#ifndef OperatorMinus_H
#define OperatorMinus_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorMinus : public AbstractOperator
    {
    public:
        OperatorMinus(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
    };
}


#endif // OperatorMinus_H
