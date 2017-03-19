#include "TypeInt32.h"

using namespace std;

TypeInt32::TypeInt32(int val, string name) : 
Variable(name)
{
	value.int32 = val;
}
