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
    return dataType;
}
