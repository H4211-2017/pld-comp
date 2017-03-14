#ifndef OperatorEquals_H
#define OperatorEquals_H

#include "AbstractOperator.h"

class OperatorEquals : public AbstractOperator
{
public:
    OperatorEquals(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
};

#endif // OperatorEquals_H
