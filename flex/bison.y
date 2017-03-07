%{
#include <map>
#include <string>
#include <iostream>

extern int yylex(void);

%}

%union {
	char cVal;
	int iVal;
	char * sVal;
	char * id;
}

%token
%token <cVal> CHAR
%token <iVal> INT_VAL
%token <sVal> CHAINE
%token <id> ID
	
