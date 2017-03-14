#include "fcBison.h"

#include <typeinfo>
#include <iostream>
#include "TypeChar.h"
#include "TypeInt32.h"
#include "TypeInt64.h"

using namespace std;

void createVariable(shared_ptr< mapVar > variables, InfosSigVar infos)
{
	if(variables->find(infos.id) == variables->end())
	{
		variables->insert(pair<string, shared_ptr<Variable> >(infos.id, make_shared<Variable>(infos.id, infos.type)));
		
	}
	else
	{
		throw string(("Error: Multiple declarations of var <" + infos.id + ">\n"));
	}
}

void affectVariable(shared_ptr< mapVar > variables, string id, char valeur)
{
	mapVar::iterator it = variables->find(id);
	Variable v("truc", -1);
	if(it != variables->end() )
	{
		//TODO : gerer les collisions de type
		shared_ptr<Variable> preVar = it->second;
		if(typeid(*preVar).name() == typeid(v).name())
		{
			
			shared_ptr<Variable> newVar;
			switch(preVar->getValue().type)
			{
				 case 0: //CHAR
					newVar = make_shared<TypeChar>(valeur, id);
					break;
					
				 default:
					throw string(("Error : variable <"+id+"> of type <CHAR> cannot accept value with type <"+typeid(valeur).name()+">\n"));
					break;
			}
			(*variables)[id] = newVar;
		}
		else
		{
			preVar->setValue(valeur);
		}
	}
	else
	{
		
	}
}

void affectVariable(shared_ptr< mapVar > variables, string id, int valeur)
{
	mapVar::iterator it = variables->find(id);
	Variable v("truc", -1);
	if(it != variables->end() )
	{
		//TODO : gerer les collisions de type
		shared_ptr<Variable> preVar = it->second;
		if(typeid(*preVar).name() == typeid(v).name())
		{
			
			shared_ptr<Variable> newVar;
			switch(preVar->getValue().type)
			{
				 case 1: // INT32
					newVar = make_shared<TypeInt32>(valeur, id);
					break;
					
				 case 2: // INT64
					newVar = make_shared<TypeInt64>(valeur, id);
					break;
					
				 default:
					throw string(("Error : variable <"+id+"> of type <Int32> cannot accept value with type <"+typeid(valeur).name()+">\n"));
					break;
			}
			(*variables)[id] = newVar;
		}
		else
		{
			preVar->setValue(valeur);
		}
	}
	else
	{
		
	}
}

void affectVariable(shared_ptr< mapVar > variables, string id, long int valeur)
{
	mapVar::iterator it = variables->find(id);
	Variable v("truc", -1);
	if(it != variables->end() )
	{
		//TODO : gerer les collisions de type
		shared_ptr<Variable> preVar = it->second;
		if(typeid(*preVar).name() == typeid(v).name())
		{
			
			shared_ptr<Variable> newVar;
			switch(preVar->getValue().type)
			{
				 case 1: // INT32
					newVar = make_shared<TypeInt32>(valeur, id);
					cout << "Warning : variable <" << id << "> of type <Int32> may cut the value of type <" << typeid(valeur).name() << ">\n";
					break;
					
				 case 2: // INT64
					newVar = make_shared<TypeInt64>(valeur, id);
					break;
					
				 default:
					throw string(("Error : variable <"+id+"> of type <Int64> cannot accept value with type <"+typeid(valeur).name() + ">\n"));
					break;
			}
			(*variables)[id] = newVar;
		}
		else
		{
			preVar->setValue(valeur);
		}
	}
	else
	{
		throw string("Error : Undefined variable <"+id+">\n");
	}
}
