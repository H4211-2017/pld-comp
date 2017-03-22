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
