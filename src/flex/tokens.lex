%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>


#include "includeCommun.h"


#include "bison.tab.hpp"

extern int yylex();

%}

%option noyywrap 
 
digit				[0-9]
alphahex			[a-fA-F]
alpha				[a-zA-Z_]
alphanum    		({digit}|{alpha})
alphanums   		{alphanum}*
alphanumex 			[ !#-\[\]-~\t]|"\n"|"\t"|"\r"|"\0"
alphanumsex 		{alphanumex}*
ident				{alpha}{alphanums}
number      		{digit}+
hextail				({digit}|{alphahex})+
hex		    		0[xX]{hextail}
anyinlinechain		(.)*
anymultilinechain	(.|\n|\r)*
/*Etat pendant qu on est dans un commentaire multiligne*/
%x comment

%%


"/*"      				  	{std::cout << "MULTILINE COMMENT : " << yytext;
								BEGIN(comment);}/*switch to comment state*/
<comment>[^*\n]*        	{std::cout << yytext;}/* eat anything that's not a '*' */
<comment>"*"+[^/\n]*	   	{std::cout << yytext;}/* eat up '*'s not followed by '/'s */
<comment>"\n"            	{std::cout << yytext;}
<comment>"*"+"/"        	{std::cout << "\nEND OF MULTILINE COMMENT" << yytext;
								BEGIN(INITIAL);}/*switch back to initial state*/

"#"{anyinlinechain}"\n" 	{std::cout << "PREPROCESSOR : " <<  yytext;}
"//"{anyinlinechain}"\n"	{std::cout << "LINE_COM : " <<  yytext;}
"if"      					{std::cout << "IF "; return IF;}
"else"    					{std::cout << "ELSE "; return ELSE;}
"while"   					{std::cout << "WHILE "; return WHILE;}
"for"     					{std::cout << "FOR "; return FOR;}
"main"						{std::cout << "MAIN "; return MAIN;}
"{"       					{std::cout << "LEFT_BRACES "; return LEFT_BRACES;}
"}"       					{std::cout << "RIGHT_BRACES "; return RIGHT_BRACES;}
"("      					{std::cout << "LEFT_PARENTHESIS "; return LEFT_PARENTHESIS;}
")"      					{std::cout << "RIGHT_PARENTHESIS "; return RIGHT_PARENTHESIS;}
"["							{std::cout << "LEFT_BRACKET "; return LEFT_BRACKET;}
"]"							{std::cout << "RIGHT_BRACKET "; return RIGHT_BRACKET;}
"=="						{std::cout << "BOOL_EQUAL "; return BOOL_EQUAL;}
"return"					{std::cout << "RETURN "; return RETURN;}
"!="						{std::cout << "BOOL_DIF "; return BOOL_DIF;}
"<="						{std::cout << "BOOL_LESS_OR_EQUAL "; return BOOL_LESS_OR_EQUAL;}
">="						{std::cout << "BOOL_GREATER_OR_EQUAL "; return BOOL_GREATER_OR_EQUAL;}
"<"							{std::cout << "BOOL_LESS "; return BOOL_LESS;}
">"							{std::cout << "BOOL_GREATER "; return BOOL_GREATER;}
"?"							{std::cout << "TERNARY_ASK "; return TERNARY_ASK;}
":"							{std::cout << "TERNARY_CHOOSE "; return TERNARY_CHOOSE;}
"+="						{std::cout << "AFFECT_ADD "; return AFFECT_ADD;}
"-="						{std::cout << "AFFECT_SUB "; return AFFECT_SUB;}
"*="						{std::cout << "AFFECT_MULT "; return AFFECT_MULT;}
"/="						{std::cout << "AFFECT_DIV "; return AFFECT_DIV;}
"%="						{std::cout << "AFFECT_MOD "; return AFFECT_MOD;}
"&="						{std::cout << "AFFECT_BIT_AND "; return AFFECT_BIT_AND;}
"^="						{std::cout << "AFFECT_BIT_XOR "; return AFFECT_BIT_XOR;}
"|="						{std::cout << "AFFECT_BIT_OR "; return AFFECT_BIT_OR;}
"<<="						{std::cout << "AFFECT_BIT_LEFT_SHIFT "; return AFFECT_BIT_LEFT_SHIFT;}
">>="						{std::cout << "AFFECT_BIT_RIGHT_SHIFT "; return AFFECT_BIT_RIGHT_SHIFT;}
"++"						{std::cout << "INCREMENT "; return INCREMENT;}
"--"						{std::cout << "DECREMENT "; return DECREMENT;}
"="							{std::cout << "AFFECT "; return AFFECT;}
"+"							{std::cout << "ADD "; return ADD;}
"-"							{std::cout << "SUB "; return SUB;}
"*"							{std::cout << "MULT "; return MULT;}
"/"							{std::cout << "DIV "; return DIV;}
"%"							{std::cout << "MOD "; return MOD;}
"&&"						{std::cout << "BOOL_AND "; return BOOL_AND;}
"||"						{std::cout << "BOOL_OR "; return BOOL_OR;}
"!"							{std::cout << "BOOL_NOT "; return BOOL_NOT;}
"&"							{std::cout << "BIT_AND "; return BIT_AND;}
"|"							{std::cout << "BIT_OR "; return BIT_OR;}
"^"							{std::cout << "BIT_XOR "; return BIT_XOR;}
"~"							{std::cout << "BIT_NOT "; return BIT_NOT;}
"<<"						{std::cout << "BIT_LEFT_SHIFT "; return BIT_LEFT_SHIFT;}
">>"						{std::cout << "BIT_RIGHT_SHIFT "; return BIT_RIGHT_SHIFT;}
"void"						{std::cout << "VOID "; return VOID;}
"char"						{std::cout << "CHAR "; return CHAR;}
"int32_t"					{std::cout << "INT32 "; return INT32;}
"int64_t"					{std::cout << "INT64 "; return INT64;}
{number}					{std::cout << "{number} ";
								std::stringstream ss(strdup(yytext));
								long int tmp;
								ss >> tmp;
								yylval.lVal = tmp;
								return INT_VAL;}
"'"{alphanumex}"'"			{std::cout << "'{alphanumex}' "; 
								yylval.cVal = strdup(yytext)[1]; 
								return CHAR_VAL;}
"\""{alphanumsex}"\"" 		{std::cout << "\"{alphanumsex}\" "; 
								yylval.sVal = strndup(&yytext[1], sizeof(char)*(strlen(yytext)-2));
								return CHAIN;}
{ident}						{std::cout << "identifiant "; 
								yylval.id = strdup(yytext); 
								return ID;}
";"							{std::cout << "SEMICOLON "; return SEMICOLON;}
","							{std::cout << "COMMA "; return COMMA;}
[ \t\n\r]					{std::cout  <<  yytext;}
.							{std::cout << "UNEXPECTED "; return UNEXPECTED;}
%%

