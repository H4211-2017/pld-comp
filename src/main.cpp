#include <iostream>
#include <map>
#include <memory>

#include "includeCommun.h"


#include "bison.tab.hpp"


extern "C" int yylex();

void yyerror(int * param, const char * msg)
{
	std::cout << msg << std::endl;
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
	
    long int i = 0;
	
	yyparse(&i);
	std::cout << i << std::endl;

}


