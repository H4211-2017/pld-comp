#ifndef TYPEINT32_H
#define TYPEINT32_H

#include "Variable.h"

using namespace std;

class TypeInt32 : public Variable
{
public:
    TypeInt32(int val, string name);
    
	virtual void setValue(int val);
	virtual void setValue(long int val);
	
	virtual string toString();
    
};

#endif // TYPEINT32_H
