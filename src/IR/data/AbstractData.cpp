#include "AbstractData.h"

using namespace IR;

AbstractData::AbstractData(Type type, std::string name):
    dataName(name), dataType(type)
{

}

std::string AbstractData::getName() const
{
    return dataName;
}

Type AbstractData::getType() const
{
    return dataType;
}

int AbstractData::getSizeInMemory() const
{
    //return dataType;
    return Type::INT_64; //force data to be long
    //TODO remove that
}

std::string AbstractData::getASMname(AsmType asmType) const
{
    switch (asmType) {
    case AsmType::X64Linux:
        return getX64name();
        break;
    default:
        break;
    }
}

void AbstractData::incrementReadCount()
{
    readCount++;
}

void AbstractData::decrementReadCount()
{
    readCount--;
}

void AbstractData::incrementWriteCount()
{
    writeCount++;
}

void AbstractData::decrementWriteCount()
{
    writeCount--;
}

int AbstractData::getReadCount() const
{
    return readCount;
}

int AbstractData::getWriteCount() const
{
    return writeCount;
}
