#include "AbstractOperator.h"

using namespace IR;

AbstractOperator::AbstractOperator(sh_Register resultRegister, sh_Register firstValueRegister, sh_Register secondValueRegister):
    destination(resultRegister), firstValue(firstValueRegister), secondValue(secondValueRegister)
{
    this->readRegisterList.push_back(firstValueRegister);
    this->readRegisterList.push_back(secondValueRegister);

    this->writtenRegisterList.push_back(resultRegister);
}
