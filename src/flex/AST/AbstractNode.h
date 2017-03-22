#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H

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

class AbstractNode
{
public:
    AbstractNode();
	
    virtual ~AbstractNode();
	
    /**
     * return a shared pointer to the value instancited by new if evaluable
     * or empty shared pointer else
     */
    virtual std::shared_ptr<std::pair<TypeValue, Type>> evaluate() const = 0;

    // TODO : create class CFG and replace comment below.
    virtual void buildIR(/*std::shared_ptr<CFG>*/) const = 0;

protected:

	TypeValue value;
	Type type;

};

}
#endif // ABSTRACTNODE_H
