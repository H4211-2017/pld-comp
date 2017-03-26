#include "AbstractFunction.h"

using namespace IR;

AbstractFunction::AbstractFunction(std::string name): functionName(name)
{

}

std::string AbstractFunction::getFunctionName() const
{
    return functionName;
}
