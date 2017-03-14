#ifndef TYPEINT64_H
#define TYPEINT64_H

#include "Variable.h"

using namespace std;

class TypeInt64 : public Variable
{
public:
	
    TypeInt64(long int val, string name);
    
	virtual void setValue(int val);
	virtual void setValue(long int val);
	
	virtual string toString();
    
};

#endif // TYPEINT64_H
