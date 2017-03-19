#include "TypeInt64.h"

using namespace std;

TypeInt64::TypeInt64(long int val, string name) : 
Variable(name)
{
	value.int64 = val;
}
