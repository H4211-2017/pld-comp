#include "OperatorBiggerOrEqual.h"

OperatorBiggerOrEqual::OperatorBiggerOrEqual(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
