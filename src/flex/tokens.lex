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
//etat de lexing
%x comment

%%
			int comment_caller;

"/*"      				  	{printf("MULTILINE COMMENT : %s",yytext);
								comment_caller = INITIAL;
								BEGIN(comment);}
<comment>[^*\n]*        	{printf("%s",yytext);}/* eat anything that's not a '*' */
<comment>"*"+[^/\n]*	   	{printf("%s",yytext);}//* eat up '*'s not followed by '/'s */
<comment>"\n"            	{printf("%s",yytext);}
<comment>"*"+"/"        	{printf("%s\nEND OF MULTILINE COMMENT",yytext);
								BEGIN(comment_caller);}

"#"{anyinlinechain}"\n" 	{printf("PREPROCESSOR : %s", yytext);}
"//"{anyinlinechain}"\n"	{printf("LINE_COM : %s", yytext);}
"if"      					{printf("IF "); return IF;}
"else"    					{printf("ELSE "); return ELSE;}
"while"   					{printf("WHILE "); return WHILE;}
"for"     					{printf("FOR "); return FOR;}
"main"						{printf("MAIN "); return MAIN;}
"{"       					{printf("LEFT_BRACES "); return LEFT_BRACES;}
"}"       					{printf("RIGHT_BRACES "); return RIGHT_BRACES;}
"("      					{printf("LEFT_PARENTHESIS "); return LEFT_PARENTHESIS;}
")"      					{printf("RIGHT_PARENTHESIS "); return RIGHT_PARENTHESIS;}
"["							{printf("LEFT_BRACKET "); return LEFT_BRACKET;}
"]"							{printf("RIGHT_BRACKET "); return RIGHT_BRACKET;}
"=="						{printf("BOOL_EQUAL "); return BOOL_EQUAL;}
"return"					{printf("RETURN "); return RETURN;}
"!="						{printf("BOOL_DIF "); return BOOL_DIF;}
"<="						{printf("BOOL_LESS_OR_EQUAL "); return BOOL_LESS_OR_EQUAL;}
">="						{printf("BOOL_GREATER_OR_EQUAL "); return BOOL_GREATER_OR_EQUAL;}
"< "						{printf("BOOL_LESS "); return BOOL_LESS;}
"> "						{printf("BOOL_GREATER "); return BOOL_GREATER;}
"?"							{printf("TERNARY_ASK "); return TERNARY_ASK;}
":"							{printf("TERNARY_CHOOSE "); return TERNARY_CHOOSE;}
"+="						{printf("AFFECT_ADD "); return AFFECT_ADD;}
"-="						{printf("AFFECT_SUB "); return AFFECT_SUB;}
"*="						{printf("AFFECT_MULT "); return AFFECT_MULT;}
"/="						{printf("AFFECT_DIV "); return AFFECT_DIV;}
"%="						{printf("AFFECT_MOD "); return AFFECT_MOD;}
"&="						{printf("AFFECT_BIT_AND "); return AFFECT_BIT_AND;}
"^="						{printf("AFFECT_BIT_XOR "); return AFFECT_BIT_XOR;}
"|="						{printf("AFFECT_BIT_OR "); return AFFECT_BIT_OR;}
"<<="						{printf("AFFECT_BIT_LEFT_SHIFT "); return AFFECT_BIT_LEFT_SHIFT;}
">>="						{printf("AFFECT_BIT_RIGHT_SHIFT "); return AFFECT_BIT_RIGHT_SHIFT;}
"++"						{printf("INCREMENT "); return INCREMENT;}
"--"						{printf("DECREMENT "); return DECREMENT;}
"="							{printf("AFFECT "); return AFFECT;}
"+"							{printf("ADD "); return ADD;}
"-"							{printf("SUB "); return SUB;}
"*"							{printf("MULT "); return MULT;}
"/"							{printf("DIV "); return DIV;}
"%"							{printf("MOD "); return MOD;}
"&&"						{printf("BOOL_AND "); return BOOL_AND;}
"||"						{printf("BOOL_OR "); return BOOL_OR;}
"!"							{printf("BOOL_NOT "); return BOOL_NOT;}
"&"							{printf("BIT_AND "); return BIT_AND;}
"|"							{printf("BIT_OR "); return BIT_OR;}
"^"							{printf("BIT_XOR "); return BIT_XOR;}
"~"							{printf("BIT_NOT "); return BIT_NOT;}
"<<"						{printf("BIT_LEFT_SHIFT "); return BIT_LEFT_SHIFT;}
">>"						{printf("BIT_RIGHT_SHIFT "); return BIT_RIGHT_SHIFT;}
"void"						{printf("VOID "); return VOID;}
"char"						{printf("CHAR "); return CHAR;}
"int32_t"					{printf("INT32 "); return INT32;}
"int64_t"					{printf("INT64 "); return INT64;}
{number}					{printf("{number} ");
								std::stringstream ss(strdup(yytext));
								long int tmp;
								ss >> tmp;
								yylval.lVal = tmp;
								return INT_VAL;}
"'"{alphanumex}"'"			{printf("'{alphanumex}' "); 
								yylval.cVal = strdup(yytext)[1]; 
								return CHAR_VAL;}
"\""{alphanumsex}"\"" 		{printf("\"{alphanumsex}\" "); 
								yylval.sVal = strndup(&yytext[1], sizeof(char)*(strlen(yytext)-2));
								return CHAIN;}
{ident}						{printf("identifiant "); 
								yylval.id = strdup(yytext); 
								return ID;}
";"							{printf("SEMICOLON "); return SEMICOLON;}
","							{printf("COMMA "); return COMMA;}
[ \t\n\r]					{printf("%s", yytext);}
.							{printf("UNEXPECTED "); return UNEXPECTED;}
%%

