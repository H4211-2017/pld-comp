#include "AbstractNode.h"

using namespace AST;

AbstractNode::AbstractNode()
{
	value.int64 = 0;
	type = INT_64;
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
        std::cout << "Int_32 " << value.int32 << " ";
        break;
    case INT_64:
        std::cout << "Int_64 " << value.int64 << " ";
        break;
    case CHAR:
        std::cout << "Char " << value.character << " ";
        break;
    default:
        std::cerr << "AbstractNode::printTree : Error in value of type : " << type << std::endl;
    }


}
