/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_TEST2_TAB_H_INCLUDED
# define YY_YY_TEST2_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 46 "test2.y"

#include<string>
using namespace std;


#line 54 "test2.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FLOATCONST = 258,
    STRINGCONST = 259,
    CHARCONST = 260,
    INTCONST = 261,
    FLOATTYPE = 262,
    VOIDTYPE = 263,
    INTTYPE = 264,
    DOUBLETYPE = 265,
    STRINGTYPE = 266,
    CHARTYPE = 267,
    RETURN = 268,
    MAINFUNC = 269,
    ID = 270,
    ASSIGNOP = 271,
    LEFTPAREN = 272,
    RIGHTPAREN = 273,
    LCB = 274,
    RCB = 275,
    SEMICOLON = 276,
    COMMA = 277,
    UNTIL = 278,
    LB = 279,
    RB = 280,
    ELSE = 281,
    IF = 282,
    ARITHMATICOP_1 = 283,
    ARITHMATICOP_2 = 284,
    ARITHMATICOP_3 = 285,
    ARITHMATICOP_4 = 286,
    ARITHMATICOP_5 = 287,
    ASSIGN = 288,
    BITWISEOP_1 = 289,
    BITWISEOP_2 = 290,
    BREAK = 291,
    CONTINUE = 292,
    FOREACH = 293,
    LOGICOP_1 = 294,
    LOGICOP_2 = 295,
    LOGICOP_3 = 296,
    PRINTFUNC = 297,
    RELATIONOP_1 = 298,
    RELATIONOP_2 = 299,
    RELATIONOP_3 = 300,
    RELATIONOP_4 = 301,
    RELATIONOP_5 = 302,
    RELATIONOP_6 = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "test2.y"

    struct evalt{
    int value;    //const   var
    int feature; //0:empty 1:const  2:array  3:func_arr   4:variable   5:others  6:tem_ent
	  int count;
	  char* name;     //ID   , FuncID
	  char type[30];   //const , id , func
	  int typeD;
	  //int line;             //...
	  char code[30];
    char preOrder[1000];  //...
    }eVal;

#line 128 "test2.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TEST2_TAB_H_INCLUDED  */
