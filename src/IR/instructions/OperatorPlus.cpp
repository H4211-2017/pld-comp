#include "OperatorPlus.h"

OperatorPlus::OperatorPlus(std::shared_ptr<Register> resultRegister,
                           std::shared_ptr<Register> firstValueRegister,
                           std::shared_ptr<Register> secondValueRegister):
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
