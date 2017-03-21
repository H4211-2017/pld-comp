#ifndef CONSTANT_H
#define CONSTANT_H

#include <memory>
#include "Node.h"

namespace AST{
	
class Constant : public Node
{
public:
	Constant();
	Constant(long int value);
	Constant(char value);
	virtual ~Constant();
	
    virtual std::pair<TypeValue, Type> evaluate() const;
	/**
	 * return a shared pointer to the value instancited by new if evaluable 
	 * or empty shared pointer else
	 */
	 
	virtual std::string toIR() const; 
	
};

}
#endif // EXPRCONSTANT_H
