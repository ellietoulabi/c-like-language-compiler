/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    TOKEN_ID = 258,
    TOKEN_RETURN = 259,
    TOKEN_STRINGCONST = 260,
    TOKEN_MAINFUNC = 261,
    TOKEN_PRFUNC = 262,
    TOKEN_LOOP = 263,
    TOKEN_ELSECONDITION = 264,
    TOKEN_IFCONDITION = 265,
    TOKEN_CONTINUESTMT = 266,
    TOKEN_BREAKSTMT = 267,
    TOKEN_INTTYPE = 268,
    TOKEN_FLOATTYPE = 269,
    TOKEN_DOUBLETYPE = 270,
    TOKEN_CHARTYPE = 271,
    TOKEN_STRINGTYPE = 272,
    TOKEN_VOIDTYPE = 273,
    TOKEN_CHARCONST = 274,
    TOKEN_ASSIGNOP = 275,
    TOKEN_LEFTPAREN = 276,
    TOKEN_RIGHTPAREN = 277,
    TOKEN_LCB = 278,
    TOKEN_RCB = 279,
    TOKEN_SEMICOLON = 280,
    TOKEN_COMMA = 281,
    TOKEN_UNTIL = 282,
    TOKEN_LB = 283,
    TOKEN_RB = 284,
    TOKEN_INTCONST = 285,
    TOKEN_FLOATCONST = 286,
    TOKEN_PLUS = 287,
    TOKEN_MINUS = 288,
    TOKEN_MUL = 289,
    TOKEN_DIV = 290,
    TOKEN_POW = 291,
    TOKEN_LOGICAND = 292,
    TOKEN_LOGICOR = 293,
    TOKEN_LOGICNOT = 294,
    TOKEN_BITWISEAND = 295,
    TOKEN_BITWISEOR = 296,
    TOKEN_EQ = 297,
    TOKEN_NOTEQ = 298,
    TOKEN_GR = 299,
    TOKEN_LS = 300,
    TOKEN_LSEQ = 301,
    TOKEN_GREQ = 302,
    TOKEN_RELATIONOP = 303,
    UMINUS = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "Parser.y"

     struct t {
          char*  _val;
          int    _cnt;
          int _datatype; //1:int 2:float 3:char 4:string :void 6:double
          char _byname [2056] ;
          char _byid [2056];
     }token;

#line 117 "Parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
