#include "ExternalFunction.h"

using namespace IR;

ExternalFunction::ExternalFunction(std::string name,
                                   std::list<sh_AbstractData> param,
                                   sh_Register returnRegister):
    AbstractFunction(name, param, returnRegister)
{

}
