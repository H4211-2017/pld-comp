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
    ret.append( source->getASMname(AsmType::X64Linux) );
    ret.append( ", " );
    ret.append( destination->getASMname(AsmType::X64Linux) );
//    ret.append( "\t; ");
//    ret.append( source->getASMname(AsmType::X64Linux) );
//    ret.append( " r:");
//    ret.append( std::to_string(source->getReadCount()));
//    ret.append( " w:");
//    ret.append( std::to_string(source->getWriteCount()));
//    ret.append( "\t");
//    ret.append( destination->getASMname(AsmType::X64Linux) );
//    ret.append( " r:");
//    ret.append( std::to_string(destination->getReadCount()));
//    ret.append( " w:");
//    ret.append( std::to_string(destination->getWriteCount()));
    return ret;
}
