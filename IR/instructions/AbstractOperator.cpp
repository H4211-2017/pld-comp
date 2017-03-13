#include "AbstractOperator.h"

AbstractOperator::AbstractOperator(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister):
    destination(resultRegister), firstValue(firstValueRegister), secondValue(secondValueRegister)
{

}
