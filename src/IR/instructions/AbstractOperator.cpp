#include "AbstractOperator.h"

using namespace IR;

AbstractOperator::AbstractOperator(sh_Register resultRegister,
                                   sh_Register firstValueRegister,
                                   sh_Register secondValueRegister):
    AbstractInstruction(),
    firstValue(firstValueRegister),
    secondValue(secondValueRegister),
    destination(resultRegister)
{
    this->readRegisterList.push_back(firstValueRegister);
    this->readRegisterList.push_back(secondValueRegister);

    this->writtenRegisterList.push_back(resultRegister);

    firstValue->incrementReadCount();
    secondValue->incrementReadCount();
    destination->incrementWriteCount();
}

AbstractOperator::~AbstractOperator()
{
    firstValue->decrementReadCount();
    secondValue->decrementReadCount();
    destination->decrementWriteCount();
}
