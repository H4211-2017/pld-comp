#include "AbstractFunction.h"

using namespace IR;

AbstractFunction::AbstractFunction(std::string name,
                                   std::list<sh_AbstractData> param,
                                   sh_Register returnRegister):
    functionName(name),
    functionParam(param),
    functionReturn(returnRegister)
{

}

std::string AbstractFunction::getFunctionName() const
{
    return functionName;
}
