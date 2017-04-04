#include "Call.h"

#include <iostream>

#include "../config/config.h"

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
    std::string ret = "";
    //write function param into the wanted memory / register
    auto regNameIt = ASM_X64_CALL_PARAMETERS_REGISTRY.rbegin();
    auto memParmIt = this->functionParam.begin();
    while (memParmIt != this->functionParam.end()) {
        if(regNameIt != ASM_X64_CALL_PARAMETERS_REGISTRY.rend())
        {
            //if we are still on param passed by register
            //move the wanted AbstracData to it's coresponding register
            const sh_AbstractData &absData = *memParmIt;
            ret.append("\tmovq\t");
            ret.append(absData->getASMname(AsmType::X64Linux));
            ret.append(", ");
            ret.append(*regNameIt);
            ret.append("\n");
            //TODO: manage arrays on function param (pointer...)
            regNameIt++;
        }
        else
        {
            //TODO: read value from the stack and but it to memory
            std::cerr << "call with more than six parameters is not handled" << std::endl;
            exit(-1);
        }
        memParmIt++;
    }
    return ret;
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
