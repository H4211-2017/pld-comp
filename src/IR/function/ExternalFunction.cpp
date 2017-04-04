#include "ExternalFunction.h"

using namespace IR;

ExternalFunction::ExternalFunction(std::string name,
                                   Type returnType,
                                   std::list<sh_AbstractData> param):
    AbstractFunction(name, returnType, param)
{

}
