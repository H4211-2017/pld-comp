#include <iostream>
#include "bison.tab.hpp"

using namespace std;
extern int yylex();

void yyerror(int * param, const char * msg)
{
	cout << msg << endl;
}

int main(void)
{
	long int i = 0;
	yyparse(&i);
	cout << i << endl;
}
