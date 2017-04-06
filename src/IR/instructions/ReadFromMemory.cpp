#include "ReadFromMemory.h"

using namespace IR;

ReadFromMemory::ReadFromMemory(sh_Memory from, sh_Register to):
    AbstractMemoryAcess(),
    source(from),
    destination(to)
{
    this->readMemoryList.push_back(from);
    this->writtenRegisterList.push_back(to);

    source->incrementReadCount();
    destination->incrementWriteCount();
}

ReadFromMemory::~ReadFromMemory()
{
    source->decrementReadCount();
    destination->decrementWriteCount();
}

std::string ReadFromMemory::toString() const
{
    std::string ret = "";
    ret.append( source->getName() );
    ret.append( " -> " );
    ret.append( destination->getName() );
    return ret;
}

std::string ReadFromMemory::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( std::to_string(source->getAsmBasePointerOffset()) );
    ret.append( "(%rbp), " );
    ret.append( destination->getASMname(AsmType::X64Linux) );
    return ret;
}
