#include <string>

#include "AbstractStructure.h"

#include "IfStructure.h"
#include "WhileStructure.h"
#include "ForStructure.h"

using namespace AST;

AbstractStructure::AbstractStructure(std::string name)
    : AbstractNode(name)
{
	
}

std::shared_ptr<AbstractStructure> make_shared_struct(AbstractStructure *ptr)
{
	std::string name = ptr->getName();
	if(name == "IfStructure")
	{
		return std::make_shared<IfStructure>( *(static_cast< IfStructure *>(ptr)));
	}
    if(name == "WhileStructure")
    {
        return std::make_shared<WhileStructure>( *(static_cast< WhileStructure *>(ptr)));
    }
    if(name == "ForStructure")
    {
        return std::make_shared<ForStructure>( *(static_cast< ForStructure *>(ptr)));
    }

	else
	{	
		std::cerr<< " AbstractStructure :: make_shared_ptr found no type like '" << name << "'" << std::endl;
		throw std::runtime_error("Runtime Error");
	}
}


