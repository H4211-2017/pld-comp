#include "AbstractNode.h"

using namespace AST;

AbstractNode::AbstractNode()
{
}

AbstractNode::AbstractNode(Value value)
    : value(value)
{

}

AbstractNode::AbstractNode(Type type, long int value)
    : value(type, value)
{

}

AbstractNode::AbstractNode(Type type)
    : value(type, 0)
{

}

AbstractNode::~AbstractNode()
{
	
}

void AbstractNode::printTree(int tabulationNumber) const
{
    for (int i = 0; i < tabulationNumber; i++)
    {
        std::cout << "\t";
    }

    switch (value.getValue().first) {
    case INT_32:
        std::cout << "Int_32 ";
        break;
    case INT_64:
        std::cout << "Int_64 ";
        break;
    case CHAR:
        std::cout << "Char ";
        break;
    default:
        std::cerr << "AbstractNode::printTree : Error in value of type : " << value.getValue().first << std::endl;
        break;
    }

    std::cout << value.getValue().second << std::endl;


}
