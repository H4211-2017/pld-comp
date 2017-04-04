#include "FunctionStructure.h"

using namespace IR;

FunctionStructure::FunctionStructure()
{

}

void FunctionStructure::addFunction(std::shared_ptr<IR::FunctionBlock> function)
{
    this->funtionList.push_back(function);
}
