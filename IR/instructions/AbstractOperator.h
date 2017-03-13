#ifndef ABSTRACTOPERATOR_H
#define ABSTRACTOPERATOR_H

#include <memory>

#include "AbstractInstruction.h"
#include "../data/Register.h"

class AbstractOperator : public AbstractInstruction
{
public:
    AbstractOperator(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
private:
    std::shared_ptr<Register> destination;
    std::shared_ptr<Register> firstValue;
    std::shared_ptr<Register> secondValue;
};

#endif // ABSTRACTOPERATOR_H
