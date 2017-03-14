#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	
	virtual ~Node();
	
	virtual long eval() = 0;

private:

};

#endif // EXPRNODE_H
