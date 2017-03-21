#ifndef OPERATORMULT_H
#define OPERATORMULT_H

#include "AbstractOperator.h"

class OperatorMult : public AbstractOperator
{
public:
    OperatorMult(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
};

#endif // OPERATORMULT_H
