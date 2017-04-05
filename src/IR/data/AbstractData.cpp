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
