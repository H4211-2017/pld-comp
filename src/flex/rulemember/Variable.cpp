#include "Variable.h"
#include <string>
#include <typeinfo>

using namespace std;

Variable::Variable(string name) : id(name),
affected(true)
{
	
}

Variable::Variable(string name, int type) : id(name), affected(false)
{
	value.type = type;
}

bool Variable::isAffected() {return affected;}

string Variable::getId() {return id;}

union TypeVariable Variable::getValue() {return value;}


void Variable::setValue(char val) 
{
	throw string(("Error : variable <"+id+"> of type <"+typeid(*this).name()+"> cannot accept value with type <"+typeid(val).name()+">\n"));
}

void Variable::setValue(int val)
{
	throw string(("Error : variable <"+id+"> of type <"+typeid(*this).name()+"> cannot accept value with type <"+typeid(val).name()+">\n"));
}

void Variable::setValue(long int val)
{
	throw string(("Error : variable <"+id+"> of type <"+typeid(*this).name()+"> cannot accept value with type <"+typeid(val).name()+">\n"));
}

string Variable::toString() 
{
	return to_string(value.type) + "\n";
}
