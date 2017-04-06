#include <memory>
#include <string>
#include <stdexcept>

#include "AbstractExpression.h"
#include "UnaryExpression.h"
#include "AddExpression.h"
#include "IDExpression.h"
#include "AffectationExpression.h"
#include "Constant.h"
#include "Function/FunctionCall.h"
#include "BitwiseAndExpression.h"
#include "BitwiseOrExpression.h"
#include "BitwiseShiftLeftExpression.h"
#include "BitwiseShiftRightExpression.h"
#include "BitwiseXorExpression.h"
#include "ModuloExpression.h"
#include "DecrIncrRightExpression.h"
#include "DecrIncrLeftExpression.h"
#include "Ternary.h"
#include "ParenthesisExpression.h"

#include "AndExpression.h"
#include "DivExpression.h"
#include "EqExpression.h"
#include "IneqExpression.h"
#include "InfEqExpression.h"
#include "InfExpression.h"
#include "MultExpression.h"
#include "OrExpression.h"
#include "SubExpression.h"
#include "SupEqExpression.h"
#include "SupExpression.h"

using namespace AST;


AbstractExpression::AbstractExpression(std::string name)
    : AbstractNode(name)
{
	
}

AbstractExpression::AbstractExpression(std::string name, Value value)
    : AbstractNode(name, value)
{
	
}

AbstractExpression::AbstractExpression(std::string name, Type type)
    : AbstractNode(name, type)
{

}

AbstractExpression::AbstractExpression(std::string name, Type type, long int value)
    : AbstractNode(name, type, value)
{
	
}

AbstractExpression::AbstractExpression(std::string name, std::shared_ptr<Scope> scope)
    : AbstractNode(name, scope)
{

}

std::shared_ptr<AbstractExpression> make_shared_expr(AbstractExpression* ptr)
{
    std::string name = ptr->getName();
    if( name == "Constant")
    {
        return std::make_shared<Constant>( *( static_cast< Constant* >(ptr) ) );
    }
    else if(name == "UnaryExpression")
    {
        return std::make_shared<UnaryExpression>( *( static_cast< UnaryExpression* >(ptr) ) );
    }
    else if(name == "AddExpression")
    {
        return std::make_shared<AddExpression>( *( static_cast< AddExpression* >(ptr) ) );
    }
    else if(name == "BitwiseAndExpression")
    {
        return std::make_shared<BitwiseAndExpression>( *( static_cast< BitwiseAndExpression* >(ptr) ) );
    }
    else if(name == "BitwiseOrExpression")
    {
        return std::make_shared<BitwiseOrExpression>( *( static_cast< BitwiseOrExpression* >(ptr) ) );
    }
    else if(name == "BitwiseShiftLeftExpression")
    {
        return std::make_shared<BitwiseShiftLeftExpression>( *( static_cast< BitwiseShiftLeftExpression* >(ptr) ) );
    }
    else if(name == "BitwiseShiftRightExpression")
    {
        return std::make_shared<BitwiseShiftRightExpression>( *( static_cast< BitwiseShiftRightExpression* >(ptr) ) );
    }
    else if(name == "BitwiseXorExpression")
    {
        return std::make_shared<BitwiseXorExpression>( *( static_cast< BitwiseXorExpression* >(ptr) ) );
    }
    else if(name == "AndExpression")
    {
        return std::make_shared<AndExpression>( *( static_cast< AndExpression* >(ptr) ) );
    }else if(name == "DivExpression")
    {
        return std::make_shared<DivExpression>( *( static_cast< DivExpression* >(ptr) ) );
    }
    else if(name == "EqExpression")
    {
        return std::make_shared<EqExpression>( *( static_cast< EqExpression* >(ptr) ) );
    }
    else if(name == "IneqExpression")
    {
        return std::make_shared<IneqExpression>( *( static_cast< IneqExpression* >(ptr) ) );
    }
    else if(name == "InfEqExpression")
    {
        return std::make_shared<InfEqExpression>( *( static_cast< InfEqExpression* >(ptr) ) );
    }
    else if(name == "InfExpression")
    {
        return std::make_shared<InfExpression>( *( static_cast< InfExpression* >(ptr) ) );
    }
    else if(name == "MultExpression")
    {
        return std::make_shared<MultExpression>( *( static_cast< MultExpression* >(ptr) ) );
    }
    else if(name == "OrExpression")
    {
        return std::make_shared<OrExpression>( *( static_cast< OrExpression* >(ptr) ) );
    }
    else if(name == "SubExpression")
    {
        return std::make_shared<SubExpression>( *( static_cast< SubExpression* >(ptr) ) );
    }
    else if(name == "SupEqExpression")
    {
        return std::make_shared<SupEqExpression>( *( static_cast< SupEqExpression* >(ptr) ) );
    }
    else if(name == "SupExpression")
    {
        return std::make_shared<SupExpression>( *( static_cast< SupExpression* >(ptr) ) );
    }
    else if(name == "ModuloExpression")
    {
        return std::make_shared<ModuloExpression>( *( static_cast< ModuloExpression* >(ptr) ) );
    }
    else if(name == "IDExpression")
    {
        return std::make_shared<IDExpression>( *( static_cast< IDExpression* >(ptr) ) );
    }
    else if(name == "AffectationExpression")
    {
        return std::make_shared<AffectationExpression>( *( static_cast< AffectationExpression* >(ptr) ) );
    }
    else if(name == "FunctionCall")
    {
        return std::make_shared<FunctionCall>( *( static_cast< FunctionCall* >(ptr) ) );
    }
    else if (name == "DecrIncrLeftExpression")
    {
        return std::make_shared<DecrIncrLeftExpression>( *( static_cast< DecrIncrLeftExpression* >(ptr) ) );
    }
    else if (name == "DecrIncrRightExpression")
    {
        return std::make_shared<DecrIncrRightExpression>( *( static_cast< DecrIncrRightExpression* >(ptr) ) );
    }
    else if(name == "Ternary")
	{
        return std::make_shared<Ternary>( *( static_cast< Ternary* >(ptr) ) );
	}
    else if (name == "ParenthesisExpression")
    {
        return std::make_shared<ParenthesisExpression>( *( static_cast< ParenthesisExpression* >(ptr) ) );
    }
    else
    {
        std::cerr<< " AbstractExpression :: make_shared_ptr found no type like '" << name << "'" << std::endl;
        throw std::runtime_error("Runtime Error");
    }
}
