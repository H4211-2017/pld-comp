#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

using namespace std;

union TypeVariable
{
	int int32;
	long int int64;
	char car;
	int type;
};

class Variable
{
public:
    Variable(string name);
    Variable(string name, int type);

	string getId();
	
	union TypeVariable getValue();
	virtual void setValue(char val);
	virtual void setValue(int val);
	virtual void setValue(long int val);
	
	bool isAffected();
	
	virtual string toString();
	
protected:
    union TypeVariable value;

private:
    string id;
    bool affected;
};

#endif // VARIABLE_H
