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

std::string Call::toString() const
{
    std::string ret = "Call function: ";
    ret.append( calledFunction->getFunctionName() );
    ret.append( " with " );
    ret.append( std::to_string(functionParam.size()) );
    ret.append( "parameter(s)" );
    return ret;
}
