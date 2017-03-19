#include "TypeChar.h"

using namespace std;

TypeChar::TypeChar(char val, string name) :
Variable(name)
{
	value.car = val;
}
