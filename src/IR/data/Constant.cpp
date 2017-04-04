#include "Constant.h"

using namespace IR;

Constant::Constant(Type type, long value):
    AbstractData(type,"!c"), dataValue(value)
{

}

long Constant::getDataValue() const
{
    return dataValue;
}

std::string Constant::getX86name() const
{
    std::string ret = "$";
    ret.append( std::to_string(dataValue) );
    return ret;
}
