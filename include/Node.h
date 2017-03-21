#ifndef NODE_H
#define NODE_H

#include <memory>
#include <cstdlib>

namespace AST{

union TypeValue
{
	int int32;
	long int int64;
	char car;
};
typedef union TypeValue TypeValue;

enum Type 
{
	INT_32,
	INT_64,
	CHAR,
};
typedef enum Type Type;

class Node
{
public:
	Node();
	
	virtual ~Node();
	
    virtual std::pair<TypeValue, Type> evaluate() const = 0;
	/**
	 * return a shared pointer to the value instancited by new if evaluable 
	 * or empty shared pointer else
	 */
	 
	virtual std::string toIR() const = 0;

protected:

	TypeValue value;
	Type type;

};

}
#endif // EXPRNODE_H
