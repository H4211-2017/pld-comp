#include "TypeInt64.h"

using namespace std;

TypeInt64::TypeInt64(long int val, string name) : 
Variable(name)
{
	value.int64 = val;
}

void TypeInt64::setValue(int val)
{
	value.int64 = val;
}

void TypeInt64::setValue(long int val)
{
	value.int64 = val;
}

string TypeInt64::toString() 
{
	return "INT64 " + to_string(value.int64) + "\n";
}
