#include "AbstractNode.h"

#include "Scope.h"

using namespace AST;

AbstractNode::AbstractNode(std::string name)
    : name(name)
{
}

AbstractNode::AbstractNode(std::string name, Value value)
    : name(name), value(value)
{

}

AbstractNode::AbstractNode(std::string name, Type type, long int value)
    : name(name), value(type, value)
{

}

AbstractNode::AbstractNode(std::string name, Type type)
    : name(name), value(type, 0)
{

}

AbstractNode::AbstractNode(std::string name, std::shared_ptr<Scope> scope)
    : name(name)
{
	currentScope = scope;
}

AbstractNode::~AbstractNode()
{
	
}

std::shared_ptr<Scope> AbstractNode::getScope() const
{
	return currentScope;
}

Value AbstractNode::getValue() const
{
    return value;
}

void AbstractNode::setType(Type type)
{
	this-> value = Value(type, this->value.getValue().second);
}

std::string AbstractNode::getName() const
{
    return name;
}

void AbstractNode::printTree(int tabulationNumber) const
{
    for (int i = 0; i < tabulationNumber; i++)
    {
        std::cout << "  ";
    }

    switch (value.getValue().first) {
    case INT_32:
        std::cout << "TYPE : Int_32 ";
        break;
    case INT_64:
        std::cout << "TYPE : Int_64 ";
        break;
    case CHAR:
        std::cout << "TYPE : Char ";
        break;
    case ERROR:
        std::cout << "TYPE : Error ";
        break;
    case VOID:
        std::cout << "TYPE : Void ";
        break;
    default:
        std::cerr << "ERROR AbstractNode::printTree : Error in value of type : " << value.getValue().first << std::endl;
        break;
    }

    std::cout << "| Node name : " << name << " ";
}

