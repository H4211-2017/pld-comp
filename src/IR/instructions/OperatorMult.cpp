#include "OperatorMult.h"

OperatorMult::OperatorMult(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}