#ifndef OPERATORPLUS_H
#define OPERATORPLUS_H

#include "AbstractOperator.h"

class OperatorPlus : public AbstractOperator
{
public:
    OperatorPlus(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister);
};

#endif // OPERATORPLUS_H
