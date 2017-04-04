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

std::string AbstractFunction::getFunctionName() const
{
    return functionName;
}
