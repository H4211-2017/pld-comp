#include "Call.h"

using namespace IR;

Call::Call(std::shared_ptr<AbstractFunction> function, std::list<sh_AbstractData> parameters, sh_Register returnRegister):
    AbstractInstruction(),
    calledFunction(function),
    functionParam(parameters),
    functionReturn(returnRegister)
{

}

std::string Call::toLinuxX64() const
{

}

std::string Call::toString() const
{
    std::string ret = "Call function: ";
    ret.append( calledFunction->getFunctionName() );
    if(functionParam.size() != 0)
    {
        ret.append( " with " );
        ret.append( std::to_string(functionParam.size()) );
        ret.append( "parameter(s) " );
    }
    if(functionReturn != nullptr)
    {
        ret.append( "and return to " );
        ret.append( functionReturn->getName() );
    }

    return ret;
}
