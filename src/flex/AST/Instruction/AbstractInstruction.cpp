#include "AbstractInstruction.h"

#include "ComposedInstruction.h"
#include "UnitInstruction.h"
#include "Variable/VariableDeclaration.h"
#include "Fonction/DeclarationFonction.h"

using namespace AST;

AbstractInstruction::AbstractInstruction(std::string name)
    : AbstractNode(name)
{

}

std::shared_ptr<AbstractInstruction> make_shared_instr(AbstractInstruction* ptr)
{
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
	else if(name == "DeclarationFonction")
	{
		return std::make_shared<DeclarationFonction>( *( static_cast< DeclarationFonction* >(ptr) ) );
	}
	else
	{	
		
        std::cerr<< " AbstractInstruction :: make_shared_ptr found no type like '" << name << "'" << std::endl;
        throw std::runtime_error("Bad cast");
	}
}

