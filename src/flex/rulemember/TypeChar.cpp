#include "TypeChar.h"

using namespace std;

TypeChar::TypeChar(char val, string name) :
Variable(name)
{
	value.car = val;
}

void TypeChar::setValue(char val) 
{
	value.car = val;
}

string TypeChar::toString() 
{
	return "CHAR " + to_string(value.car) + "\n";
}
