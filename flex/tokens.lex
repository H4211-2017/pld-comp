%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bison.tab.h"

%}

%option noyywrap 
 
digit		[0-9]
alphahex	[a-fA-F]
alpha		[a-zA-Z_]
alphanum    ({digit}|{alpha})
alphanums   {alphanum}*
alphanumex [ !#-\[\]-~\t]|"\n"|"\t"|"\r"|"\0"
alphanumsex {alphanumex}*
ident		{alpha}{alphanums}
number      {digit}+
hextail		({digit}|{alphahex})+
hex		    0[xX]{hextail}


%%
"#"       			{printf("#"); return SHARP;}
"//"      			{printf("//"); return LINE_COM;}
"/*"      			{printf("/*"); return BEGIN_COM;}
"*/"      			{printf("*/"); return END_COM;}
"if"      			{printf("if"); return IF;}
"else"    			{printf("else"); return ELSE;}
"while"   			{printf("while"); return WHILE;}
"for"     			{printf("for"); return FOR;}
"main"				{printf("main"); return MAIN;}
"{"       			{printf("{"); return LEFT_BRACES;}
"}"       			{printf("}"); return RIGHT_BRACES;}
"("      			{printf("("); return LEFT_PARENTHESIS;}
")"      			{printf(")"); return RIGHT_PARENTHESIS;}
"["					{printf("["); return LEFT_BRACKET;}
"]"					{printf("]"); return RIGHT_BRACKET;}
"=="				{printf("=="); return BOOL_EQUAL;}
"return"			{printf("return"); return RETURN;}
"!="				{printf("!="); return BOOL_DIF;}
"<="				{printf("<="); return BOOL_LESS_OR_EQUAL;}
">="				{printf(">="); return BOOL_GREATER_OR_EQUAL;}
"< "				{printf("< "); return BOOL_LESS;}
"> "				{printf("> "); return BOOL_GREATER;}
"+="				{printf("+="); return AFFECT_ADD;}
"-="				{printf("-="); return AFFECT_SUB;}
"*="				{printf("*="); return AFFECT_MULT;}
"/="				{printf("/="); return AFFECT_DIV;}
"%="				{printf("MOD="); return AFFECT_MOD;}
"++"				{printf("++"); return INCREMENT;}
"--"				{printf("--"); return DECREMENT;}
"="					{printf("="); return AFFECT;}
"+"					{printf("+"); return ADD;}
"-"					{printf("-"); return SUB;}
"*"					{printf("*"); return MULT;}
"/"					{printf("/"); return DIV;}
"%"					{printf("MOD"); return MOD;}
"&&"				{printf("&&"); return BOOL_AND;}
"||"				{printf("||"); return BOOL_OR;}
"!"					{printf("!"); return BOOL_NOT;}
"&"					{printf("&"); return BIT_AND;}
"|"					{printf("|"); return BIT_OR;}
"^"					{printf("^"); return BIT_XOR;}
"~"					{printf("~"); return BIT_NOT;}
"<<"				{printf("<<"); return BIT_LEFT_SHIFT;}
">>"				{printf(">>"); return BIT_RIGHT_SHIFT;}
"void"				{printf("void"); return VOID;}
"char"				{printf("char"); return CHAR;}
"int32_t"			{printf("int32_t"); return INT32;}
"int64_t"			{printf("int64_t"); return INT64;}
{number}			{printf("{number}"); 
						yylval.iVal = atoi(yytext); 
						return INT_VAL;}
"'"{alphanumex}"'"	{printf("'{alphanumex}'"); 
						yylval.cVal = strdup(yytext)[1]; 
						return CHAR_VAL;}
"\""{alphanumsex}"\"" 	{printf("\"{alphanumsex}\""); 
						yylval.sVal = strndup(&yytext[1], sizeof(char)*(strlen(yytext)-2));
						return CHAIN;}
{ident}				{printf("identifiant"); 
						yylval.id = strdup(yytext); 
						return ID;}
";"					{printf(";"); return SEMICOLON;}
","					{printf(","); return COMMA;}
[ \n\t\r]+    		{printf("%s",yytext); return IGNORED;}
.					{printf("%s", yytext); return UNEXPECTED;}
%%

