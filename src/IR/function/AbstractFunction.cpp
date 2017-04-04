#include "AbstractFunction.h"

using namespace IR;

AbstractFunction::AbstractFunction(std::string name,
                                   Type returnType,
                                   std::list<sh_AbstractData> param):
    functionName(name),
    functionParam(param),
    functionReturnType(returnType)
{

}

void AbstractFunction::pushBackNewParam(const sh_AbstractData &newParam)
{
    functionParam.push_back(newParam);
}

std::string AbstractFunction::getFunctionName() const
{
    return functionName;
}

Type AbstractFunction::getFunctionReturnType() const
{
    return functionReturnType;
}
