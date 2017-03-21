#include "OperatorSmallerOrEqual.h"

using namespace IR;

OperatorSmallerOrEqual::OperatorSmallerOrEqual(std::shared_ptr<Register> resultRegister, std::shared_ptr<Register> firstValueRegister, std::shared_ptr<Register> secondValueRegister) :
    AbstractOperator(resultRegister,firstValueRegister,secondValueRegister)
{

}
