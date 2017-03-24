#include "ReadArrayValue.h"

using namespace IR;

ReadArrayValue::ReadArrayValue(sh_MemoryArray array, sh_Register caseNumber, sh_Register dest):
    AbstractInstruction(),
    arraySource(array),
    caseNumberRegister(caseNumber),
    destRegister(dest)
{
    this->readMemoryVector.push_back(arraySource);
    this->readRegisterVector.push_back(caseNumberRegister);
    this->wroteRegisterVector.push_back(destRegister);
}
