#include <iostream>
#include "bison.tab.h"

using namespace std;

void yyerror(int * param, const char * msg)
{
	cout << msg << endl;
}

int main(void)
{
	int i = 0;
	yyparse(&i);
	cout << i << endl;
}
