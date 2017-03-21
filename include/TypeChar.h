#ifndef TYPECHAR_H
#define TYPECHAR_H

#include "Variable.h"

using namespace std;

class TypeChar : public Variable
{
public:
    TypeChar(char val, string name);
    
    virtual void setValue(char val);
	virtual string toString();
    
};

#endif // TYPECHAR_H
