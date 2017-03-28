#include "AbstractOperator.h"

using namespace IR;

AbstractOperator::AbstractOperator(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister):
    destination(resultRegister), firstValue(firstValueRegister), secondValue(secondValueRegister)
{
    this->readRegisterVector.push_back(firstValueRegister);
    this->readRegisterVector.push_back(secondValueRegister);

    this->writtenRegisterVector.push_back(resultRegister);
}
