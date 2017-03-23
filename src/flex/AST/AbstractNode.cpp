#include "AbstractNode.h"

using namespace AST;

AbstractNode::AbstractNode()
{
	value.int64 = 0;
	type = INT_64;
}

AbstractNode::AbstractNode(Type type, long int value)
    : type(type)
{
    switch (type) {
    case CHAR:
        this->value.character = value;
        break;
    case INT_32:
        this->value.int32 = value;
        break;
    case INT_64:
        this->value.int64 = value;
        break;

    default:
        break;


    }
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

    switch (type) {
    case INT_32:
        std::cout << "Int_32 " << value.int32 << std::endl;
        break;
    case INT_64:
        std::cout << "Int_64 " << value.int64 << std::endl;
        break;
    case CHAR:
        std::cout << "Char " << value.character << std::endl;
        break;
    default:
        std::cerr << "AbstractNode::printTree : Error in value of type : " << type << std::endl;
    }


}
