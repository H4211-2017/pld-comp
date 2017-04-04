#include "FunctionStructure.h"

FunctionStructure::FunctionStructure()
{

}

void IR::FunctionStructure::addFunction(std::shared_ptr<IR::FunctionBlock> function)
{
    this->funtionList.push_back(function);
}
