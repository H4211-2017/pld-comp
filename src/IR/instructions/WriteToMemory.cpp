#include "WriteToMemory.h"

using namespace IR;

WriteToMemory::WriteToMemory(sh_Register from, sh_Memory to) :
    AbstractMemoryAcess(), destination(to), source(from)
{
    this->readRegisterList.push_back(from);
    this->writtenMemoryList.push_back(to);

    source->incrementReadCount();
    destination->incrementWriteCount();
}

WriteToMemory::~WriteToMemory()
{
    source->decrementReadCount();
    destination->decrementWriteCount();
}

std::string WriteToMemory::toString() const
{
    std::string ret = "";
    ret.append( source->getName() );
    ret.append( " -> " );
    ret.append( destination->getName() );
    return ret;
}

std::string WriteToMemory::toLinuxX64() const
{
    std::string ret = "\tmovq\t";
    ret.append( source->getASMname(AsmType::X64Linux) );
    ret.append( ", " );
    ret.append( std::to_string(destination->getAsmBasePointerOffset()) );
    ret.append( "(%rbp)");
    return ret;
}
