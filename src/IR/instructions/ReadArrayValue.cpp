#include "ReadArrayValue.h"

using namespace IR;

ReadArrayValue::ReadArrayValue(sh_MemoryArray array, sh_Register caseNumber, sh_Register dest):
    AbstractInstruction(),
    arraySource(array),
    caseNumberRegister(caseNumber),
    destRegister(dest)
{
    this->readMemoryList.push_back(arraySource);
    this->readRegisterList.push_back(caseNumberRegister);
    this->writtenRegisterList.push_back(destRegister);
}

std::string ReadArrayValue::toString() const
{
    std::string ret = "";
    ret.append( arraySource->getName() );
    ret.append( "[" );
    ret.append( caseNumberRegister->getName() );
    ret.append( "] -> " );
    ret.append( destRegister->getName() );
    return ret;
}

std::string ReadArrayValue::toLinuxX86() const
{

}
