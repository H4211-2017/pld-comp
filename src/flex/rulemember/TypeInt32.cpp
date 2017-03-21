#include "TypeInt32.h"

using namespace std;

TypeInt32::TypeInt32(int val, string name) : 
Variable(name)
{
	value.int32 = val;
}

void TypeInt32::setValue(int val)
{
	value.int32 = val;
}

void TypeInt32::setValue(long int val)
{
	value.int32 = val;
}

string TypeInt32::toString() 
{
	return "INT32 " + to_string(value.int32) + "\n";
}
