#include "AbstractOperator.h"

using namespace IR;

AbstractOperator::AbstractOperator(sh_Register resultRegister,
                                   sh_Register firstValueRegister,
                                   sh_Register secondValueRegister):
    AbstractInstruction(),
    firstValuePointer(std::make_shared<sh_Register>(firstValueRegister)),
    secondValuePointer(std::make_shared<sh_Register>(secondValueRegister)),
    destinationPointer(std::make_shared<sh_Register>(resultRegister)),
    firstValue(*firstValuePointer),
    secondValue(*secondValuePointer),
    destination(*destinationPointer)
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
