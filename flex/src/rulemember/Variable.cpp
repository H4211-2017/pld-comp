#include "Variable.h"

using namespace std;

Variable::Variable(string name) : id(name)
{

}

string Variable::getId() {return id;}

union typeVariable Variable::getValue() {return value;}
