#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

using namespace std;

union typeVariable
{
	int int32;
	long int int64;
	char car;
};

class Variable
{
public:
    Variable(string name);

	string getId();
	
	union typeVariable getValue();
	
protected:
    union typeVariable value;

private:
    string id;
};

#endif // VARIABLE_H
