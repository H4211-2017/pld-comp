#include "Call.h"

using namespace IR;

Call::Call(std::shared_ptr<AbstractFunction> function, std::list<sh_AbstractData> parameters):
    AbstractInstruction(),
    calledFunction(function),
    functionParam(parameters)
{

}

std::string Call::toLinuxX86() const
{

}
