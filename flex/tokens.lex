/*
 * get tokens from sources
 */
 
digit		[0-9]
alpha		[a-fA-F]
alphanum    ({digit|alpha})*
number      digit*
hextail		({digit}|{alpha}){1,8}
hex		    0[xX]{hextail}


%%
#       printf('#');
//      printf("//");
/*      printf("/*");
*/      printf("*/");
if      printf("if");
else    printf("else");
while   printf("while");
for     printf("for");
{       printf('{');
}       printf('}');
(       printf("(");
)       printf("if");
==
!=
<=
>=
<
>
+=
-=
*=
/=
%=
++
--
=
+
-
*
/
%
&&
||
!
&
|
^
<<
>>
void
char
int32_t
int64_t
[{number}]
'{alphanum}'
;
,
%%

main()
{
  printf("hello world");
  yylex();
}
