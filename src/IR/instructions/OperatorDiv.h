#ifndef OperatorDiv_H
#define OperatorDiv_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorDiv : public AbstractOperator
    {
    public:
        OperatorDiv(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
    };
}


#endif // OperatorDiv_H
