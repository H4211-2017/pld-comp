#include <iostream>
#include <map>
#include "../include/fcBison.h"
#include <memory>
#include "bison.tab.hpp"

using namespace std;
extern "C" int yylex();

void yyerror(int * param, const char * msg)
{
	cout << msg << endl;
}

int main(void)
{
	/*shared_ptr< mapVar > i = make_shared< mapVar >();
	
	try
	{
		yyparse(&i);
	}
	catch(string s)
	{
		cout << s << endl;
	}
	
	for(mapVar::iterator it = i->begin(); it != i->end(); it++)
	{
		cout << it->second->toString();
	}*/
	
	int i = 0;
	
	yyparse(&i);
	cout << i << endl;

}
