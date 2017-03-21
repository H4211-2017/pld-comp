#ifndef OperatorSmaller_H
#define OperatorSmaller_H

#include "AbstractOperator.h"

namespace IR {
    class OperatorSmaller : public AbstractOperator
    {
    public:
        OperatorSmaller(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
    };
}


#endif // OperatorSmaller_H
