#ifndef OperatorBiggerOrEqual_H
#define OperatorBiggerOrEqual_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBiggerOrEqual : public AbstractOperator
    {
    public:
        OperatorBiggerOrEqual(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
    };
}


#endif // OperatorBiggerOrEqual_H
