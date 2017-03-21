#ifndef OperatorBigger_H
#define OperatorBigger_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorBigger : public AbstractOperator
    {
    public:
        OperatorBigger(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
    };
}


#endif // OperatorBigger_H
