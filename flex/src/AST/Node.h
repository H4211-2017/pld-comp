#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	
	virtual ~Node();
	
	virtual shared_ptr<long> evaluate() const = 0;
	/**
	 * return a shared pointer to the value instancited by new if evaluable 
	 * or empty shared pointer else
	 */
};

#endif // EXPRNODE_H
