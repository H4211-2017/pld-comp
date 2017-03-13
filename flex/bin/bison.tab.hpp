/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BIN_BISON_TAB_HPP_INCLUDED
# define YY_YY_BIN_BISON_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SHARP = 258,
    LINE_COM = 259,
    BEGIN_COM = 260,
    END_COM = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    FOR = 265,
    MAIN = 266,
    LEFT_BRACES = 267,
    RIGHT_BRACES = 268,
    LEFT_PARENTHESIS = 269,
    RIGHT_PARENTHESIS = 270,
    LEFT_BRACKET = 271,
    RIGHT_BRACKET = 272,
    BOOL_EQUAL = 273,
    RETURN = 274,
    BOOL_DIF = 275,
    BOOL_LESS_OR_EQUAL = 276,
    BOOL_GREATER_OR_EQUAL = 277,
    BOOL_LESS = 278,
    BOOL_GREATER = 279,
    AFFECT_ADD = 280,
    AFFECT_SUB = 281,
    AFFECT_MULT = 282,
    AFFECT_DIV = 283,
    AFFECT_MOD = 284,
    INCREMENT = 285,
    DECREMENT = 286,
    AFFECT = 287,
    ADD = 288,
    SUB = 289,
    MULT = 290,
    DIV = 291,
    MOD = 292,
    BOOL_AND = 293,
    BOOL_OR = 294,
    BOOL_NOT = 295,
    BIT_AND = 296,
    BIT_OR = 297,
    BIT_XOR = 298,
    BIT_NOT = 299,
    BIT_LEFT_SHIFT = 300,
    BIT_RIGHT_SHIFT = 301,
    VOID = 302,
    CHAR = 303,
    INT32 = 304,
    INT64 = 305,
    SEMICOLON = 306,
    COMMA = 307,
    UNEXPECTED = 308,
    CHAR_VAL = 309,
    INT_VAL = 310,
    CHAIN = 311,
    ID = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "bison.ypp" /* yacc.c:1909  */

	char cVal;
	int iVal;
	char * sVal;
	char * id;
	int eval;

#line 120 "../bin/bison.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (int * renvoi);

#endif /* !YY_YY_BIN_BISON_TAB_HPP_INCLUDED  */
