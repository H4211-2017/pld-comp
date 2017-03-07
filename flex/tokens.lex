%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

%}

%option noyywrap 
 
digit		[0-9]
alphahex	[a-fA-F]
alpha		[a-zA-Z_]
alphanum    ({digit}|{alpha})
alphanums   {alphanum}*
alphanumex [ !#-\[\]-~\t]|"\n"|"\t"|"\r"|"\0"
alphanumsex {alphanumex}*
ident		{alpha}{alphanum}
number      {digit}+
hextail		({digit}|{alphahex}){1,8}
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
"{"       			{printf('{'); return LBRACK;}
"}"       			{printf('}'); return RBRACK;}
"("      			{printf("("); return LPAR;}
")"      			{printf(")"); return RPAR;}
"["					{printf("["); return LSQU;}
"]"					{printf("]"); return RSQU;}
"=="				{printf("=="); return BOOL_EQ;}
"!="				{printf("!="); return BOOL_DIF;}
"<="				{printf("<="); return BOOL_LEQ;}
">="				{printf(">="); return BOOL_GEQ;}
"< "				{printf("< "); return BOOL_LT;}
"> "				{printf("> "); return BOOL_GT;}
"+="				{printf("+="); return I_ADD;}
"-="				{printf("-="); return I_SUB;}
"*="				{printf("*="); return I_MULT;}
"/="				{printf("/="); return I_DIV;}
"%="				{printf("%="); return I_MOD;}
"++"				{printf("++"); return INC;}
"--"				{printf("--"); return DEC;}
"="					{printf("="); return AFF_EQ;}
"+"					{printf("+"); return PLUS;}
"-"					{printf("-"); return MINUS;}
"*"					{printf("*"); return MULT;}
"/"					{printf("/"); return DIV;}
"%"					{printf("%"); return MOD;}
"&&"				{printf("&&"); return BOOL_AND;}
"||"				{printf("||"); return BOOL_OR;}
"!"					{printf("!"); return BOOL_NOT;}
"&"					{printf("&"); return BIT_AND;}
"|"					{printf("|"); return BIT_OR;}
"^"					{printf("^"); return BIT_NOT;}
"<<"				{printf("<<"); return BIT_LSHIFT;}
">>"				{printf(">>"); return BIT_RSHIFT;}
"void"				{printf("void"); return VOID;}
"char"				{printf("char"); return CHAR;}
"int32_t"			{printf("int32_t"); return INT32;}
"int64_t"			{printf("int64_t"); return INT64;}
{number}			{printf("{number}"); 
						yylval.val = atoi(yytext); 
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
[ \n\t\r]+    		{return IGNORED;}
.					{return UNEXPECTED;}
%%

