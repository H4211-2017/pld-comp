#ifndef OperatorSmallerOrEqual_H
#define OperatorSmallerOrEqual_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorSmallerOrEqual : public AbstractOperator
    {
    public:
        OperatorSmallerOrEqual(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
    };
}


#endif // OperatorSmallerOrEqual_H
