#include "AbstractInstruction.h"

#include "ComposedInstruction.h"
#include "UnitInstruction.h"
#include "Variable/VariableDeclaration.h"
#include "Variable/ArrayDeclaration.h"
#include "Function/FunctionDeclaration.h"

using namespace AST;

AbstractInstruction::AbstractInstruction(std::string name)
    : AbstractNode(name)
{

}

std::shared_ptr<AbstractInstruction> make_shared_instr(AbstractInstruction* ptr)
{
	if(ptr == nullptr)
	{
		return nullptr;
	}
	std::string name = ptr->getName();
	if( name == "ComposedInstruction")
	{
		return std::make_shared<ComposedInstruction>( *( static_cast< ComposedInstruction* >(ptr) ) );
	}
	else if(name == "UnitInstruction")
	{
		return std::make_shared<UnitInstruction>( *( static_cast< UnitInstruction* >(ptr) ) );
	}
	else if(name == "VariableDeclaration")
	{
		return std::make_shared<VariableDeclaration>( *( static_cast< VariableDeclaration* >(ptr) ) );
	}
    else if(name == "ArrayDeclaration")
	{
        return std::make_shared<ArrayDeclaration>( *( static_cast< ArrayDeclaration* >(ptr) ) );
	}
    else if(name == "FunctionDeclaration")
	{
        return std::make_shared<FunctionDeclaration>( *( static_cast< FunctionDeclaration* >(ptr) ) );
	}
	else
	{	
		
        std::cerr<< " AbstractInstruction :: make_shared_ptr found no type like '" << name << "'" << std::endl;
        throw std::runtime_error("Bad cast");
	}
}

