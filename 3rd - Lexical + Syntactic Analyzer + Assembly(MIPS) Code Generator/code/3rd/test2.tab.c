/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "test2.y"

    #include <iostream>
    #include <vector>
    #include <string>
    #include <string.h>
    #include <sstream>

using namespace std;


    int yyerror(const char* m);
    extern int yylex();
    extern int line_counter;
    vector <vector<pair<string,string>>>tableVar ;
    vector <pair<string,string>>tableFunc ;
    vector <string> stack;
    int temp_num=-1;

    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss;
        ss.str(s);
        string item;
        while (getline(ss, item, delim)) {
        	elems.push_back(item);
        }
    }
    char* getType(char* name,int typeD){
        for(int i=0;i<tableVar.size();i++){
            if(strcmp(name,tableVar[i].first.c_str())==0) return (char*) tableVar[i].second.c_str();
            }
        return NULL;
        }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }





#line 114 "test2.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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


#line 163 "test2.tab.c"

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

#line 237 "test2.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TEST2_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    95,    96,    98,   108,   114,   117,   122,
     128,   133,   137,   143,   151,   154,   160,   165,   170,   177,
     178,   179,   180,   181,   182,   184,   185,   186,   187,   188,
     191,   195,   196,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   213,   218,   221,   225,   226,
     228,   234,   235,   237,   238,   241,   244,   248,   250,   252,
     255,   260,   263,   269,   274,   277,   283,   289,   295,   298,
     304,   309,   311,   312,   313,   315,   316,   317,   319,   323,
     328,   331,   380,   429,   437,   443,   480,   505,   513,   519,
     553,   554,   555,   556,   560,   561,   562
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOATCONST", "STRINGCONST", "CHARCONST",
  "INTCONST", "FLOATTYPE", "VOIDTYPE", "INTTYPE", "DOUBLETYPE",
  "STRINGTYPE", "CHARTYPE", "RETURN", "MAINFUNC", "ID", "ASSIGNOP",
  "LEFTPAREN", "RIGHTPAREN", "LCB", "RCB", "SEMICOLON", "COMMA", "UNTIL",
  "LB", "RB", "ELSE", "IF", "ARITHMATICOP_1", "ARITHMATICOP_2",
  "ARITHMATICOP_3", "ARITHMATICOP_4", "ARITHMATICOP_5", "ASSIGN",
  "BITWISEOP_1", "BITWISEOP_2", "BREAK", "CONTINUE", "FOREACH",
  "LOGICOP_1", "LOGICOP_2", "LOGICOP_3", "PRINTFUNC", "RELATIONOP_1",
  "RELATIONOP_2", "RELATIONOP_3", "RELATIONOP_4", "RELATIONOP_5",
  "RELATIONOP_6", "$accept", "Program", "DeclarationList",
  "Type_Declaration", "Declaration", "FuncDeclaration", "VarDeclaration",
  "IdentList_Dec", "Main_Function", "Func_Arg", "Func_ArgList",
  "Func_ArgList_Type", "Func_Types", "Var_Types", "CompoundStmt",
  "StmtList", "Stmt", "ForStmt", "IdTemp", "IfStmt", "ElsePart",
  "Local_Vars", "IdentList", "IdentList_DeforDec", "Print", "Call",
  "Call_ArgList", "Expr", "ExprLogical", "ExprBinary", "Rvalue",
  "Compare_1", "Compare_2", "Mag", "Term", "Factor", "Mutable", "Const",
  "Array_Var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,    -4,    21,    34,    36,    49,    53,    45,   -56,    65,
     -56,    79,    81,    84,   -56,   -56,   -56,    87,    24,   -56,
     -56,   -56,    86,   116,   116,    85,   -56,   -56,   -56,   -56,
     -56,   -56,   104,   102,   -56,   114,   113,   -56,   -56,   -56,
     -56,   111,    85,   115,   115,   117,    30,    60,    14,    56,
      68,   -56,   -56,   -56,   118,   116,   111,   118,     1,   120,
     122,   111,   -56,   -56,   123,   115,   115,   115,   115,   115,
     -56,   -56,   -56,   -56,   -56,   -56,   115,   115,   115,   115,
     115,   115,   -56,   -56,   -56,   -56,   -56,   121,   -56,   115,
     -56,   -56,   125,   -56,    60,    60,    14,    14,    14,    56,
      56,    68,    68,   -56,   -56,    10,   -56,    30,    50,   -16,
     -56,   -56,   128,   126,   127,   134,   133,   136,   -56,   -56,
     -56,   -56,   131,   132,   135,   137,   -56,   138,    85,    85,
     -56,   -56,   -56,   140,    29,    -6,   -56,   -56,   -56,   -56,
     -56,   -56,     6,   -56,   124,    85,   142,    85,   139,   -56,
     -56,    85,   118,   141,   -56,   -56,   136,   -56,   129,    85,
     -56,   118,   -56,   144,   -56,   118,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    22,    19,    20,    21,    23,    24,     0,     2,     0,
       4,     0,     0,     0,     6,     1,     3,     0,     0,     5,
       8,     7,     0,    15,    15,     0,    10,    27,    25,    26,
      28,    29,     0,    14,    17,     0,     0,    90,    91,    92,
      93,    94,     0,     0,     0,    12,    61,    64,    68,    71,
      80,    83,    87,    88,     0,     0,    94,     0,     0,    89,
       0,    94,    86,    85,     0,     0,     0,     0,     0,     0,
      73,    74,    72,    77,    75,    76,     0,     0,     0,     0,
       0,     0,    32,     9,    16,    18,    13,     0,    96,     0,
      84,    89,     0,    11,    63,    62,    66,    67,    65,    69,
      70,    78,    79,    81,    82,     0,    95,    60,     0,    94,
      30,    44,     0,     0,     0,     0,     0,     0,    36,    31,
      33,    34,     0,     0,     0,     0,    38,     0,    59,     0,
      39,    40,    46,     0,     0,    94,    50,    37,    42,    43,
      35,    41,     0,    58,     0,     0,     0,     0,    52,    54,
      56,     0,     0,     0,    55,    53,     0,    57,    49,     0,
      51,     0,    47,     0,    48,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   145,   -56,   -56,   151,   -56,   101,   -56,   143,
     -56,   119,   -56,     3,   -55,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,    12,   -56,   -56,   -56,   -56,   -42,    77,    46,
      13,   -56,   -56,    39,    55,   -38,    35,   -56,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    19,    14,    21,    22,    10,    32,
      33,    34,    11,    35,    83,   105,   119,   120,   133,   121,
     162,   122,   136,   148,   123,   124,   142,    45,    46,    47,
      48,    76,    77,    49,    50,    51,    52,    53,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,   128,    86,    12,    85,    62,    63,    87,    58,    91,
     147,   -27,    12,    37,    38,    39,    40,    27,    58,    28,
      29,    30,    31,   108,   150,   109,    88,    42,   151,    82,
     110,   111,    37,    38,    39,    40,    13,   112,    43,    44,
      25,    23,   103,   104,    61,    15,   113,   114,   115,   -25,
     118,   -26,   116,    37,    38,    39,    40,    70,    71,    72,
      73,    74,    75,   125,   -28,    41,   127,    42,   -29,    65,
      66,   126,     1,     2,     3,     4,     5,     6,    43,    44,
      96,    97,    98,   149,    78,    79,   143,   144,    37,    38,
      39,    40,    67,    17,    68,    69,    18,   158,    80,    81,
      41,    23,    42,   153,    24,   155,   164,    26,   117,   157,
     166,    94,    95,    43,    44,    99,   100,   163,    37,    38,
      39,    40,    54,    27,    55,    28,    29,    30,    31,    56,
      61,    57,    42,   101,   102,    58,    89,    82,    92,    64,
      90,    25,   152,    43,    44,   129,   106,   130,   131,   132,
     134,   135,   137,   138,    16,   161,   139,   145,   140,   141,
     154,   156,   165,    20,   159,    93,   107,    36,   160,   146,
       0,     0,     0,     0,    84
};

static const yytype_int16 yycheck[] =
{
      42,    17,    57,     0,    56,    43,    44,     6,    24,    61,
      16,    15,     9,     3,     4,     5,     6,     7,    24,     9,
      10,    11,    12,    13,    18,    15,    25,    17,    22,    19,
      20,    21,     3,     4,     5,     6,    15,    27,    28,    29,
      16,    17,    80,    81,    15,     0,    36,    37,    38,    15,
     105,    15,    42,     3,     4,     5,     6,    43,    44,    45,
      46,    47,    48,   105,    15,    15,   108,    17,    15,    39,
      40,    21,     7,     8,     9,    10,    11,    12,    28,    29,
      67,    68,    69,   135,    28,    29,   128,   129,     3,     4,
       5,     6,    32,    14,    34,    35,    15,   152,    30,    31,
      15,    17,    17,   145,    17,   147,   161,    21,   105,   151,
     165,    65,    66,    28,    29,    76,    77,   159,     3,     4,
       5,     6,    18,     7,    22,     9,    10,    11,    12,    15,
      15,    18,    17,    78,    79,    24,    16,    19,    15,    22,
      18,    16,    18,    28,    29,    17,    25,    21,    21,    15,
      17,    15,    21,    21,     9,    26,    21,    17,    21,    21,
      18,    22,    18,    12,    23,    64,    89,    24,   156,   134,
      -1,    -1,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    12,    50,    51,    52,
      57,    61,    62,    15,    54,     0,    51,    14,    15,    53,
      54,    55,    56,    17,    17,    16,    21,     7,     9,    10,
      11,    12,    58,    59,    60,    62,    58,     3,     4,     5,
       6,    15,    17,    28,    29,    76,    77,    78,    79,    82,
      83,    84,    85,    86,    18,    22,    15,    18,    24,    87,
      76,    15,    84,    84,    22,    39,    40,    32,    34,    35,
      43,    44,    45,    46,    47,    48,    80,    81,    28,    29,
      30,    31,    19,    63,    60,    87,    63,     6,    25,    16,
      18,    87,    15,    56,    78,    78,    79,    79,    79,    82,
      82,    83,    83,    84,    84,    64,    25,    77,    13,    15,
      20,    21,    27,    36,    37,    38,    42,    62,    63,    65,
      66,    68,    70,    73,    74,    76,    21,    76,    17,    17,
      21,    21,    15,    67,    17,    15,    71,    21,    21,    21,
      21,    21,    75,    76,    76,    17,    85,    16,    72,    87,
      18,    22,    18,    76,    18,    76,    22,    76,    63,    23,
      71,    26,    69,    76,    63,    18,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      63,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    68,    69,    69,
      70,    71,    71,    72,    72,    73,    74,    75,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    79,
      79,    79,    80,    80,    80,    81,    81,    81,    82,    82,
      82,    83,    83,    83,    84,    84,    84,    84,    85,    85,
      86,    86,    86,    86,    87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     1,     5,
       2,     5,     3,     6,     1,     0,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     0,     1,     1,     2,     1,     2,     2,     2,
       2,     3,     2,     2,     1,     8,     1,     6,     2,     0,
       2,     4,     2,     2,     1,     4,     4,     3,     1,     0,
       4,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     2,     2,     1,     1,     2,
       1,     1,     1,     1,     0,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 89 "test2.y"
                                    { strcpy((yyval.eVal).preOrder,(string("Program ")+string((yyvsp[0].eVal).preOrder)).c_str()); cout<<(yyval.eVal).preOrder<<endl;
                                        int flag=0;
                                        for(int i=tableFunc.size()-1;i>=0;i--){ if(strcmp(tableFunc[i].first.c_str(),"main")==0) {flag=1;}}
                                        if(flag==0) {yyerror("main");}
                    }
#line 1543 "test2.tab.c"
    break;

  case 3:
#line 95 "test2.y"
                                                     {strcpy((yyval.eVal).preOrder,(string("DeclarationList ")+string((yyvsp[-1].eVal).preOrder)+string((yyvsp[0].eVal).preOrder)).c_str()); }
#line 1549 "test2.tab.c"
    break;

  case 4:
#line 96 "test2.y"
                                    { strcpy((yyval.eVal).preOrder,(string("DeclarationList ")+string((yyvsp[0].eVal).preOrder)).c_str());  strcpy((yyval.eVal).type , (yyvsp[0].eVal).type); }
#line 1555 "test2.tab.c"
    break;

  case 5:
#line 98 "test2.y"
                                          {
			                                strcpy((yyval.eVal).preOrder,(string("Type_Declaration ")+string((yyvsp[-1].eVal).preOrder)+string((yyvsp[0].eVal).preOrder)).c_str());
                                      vector<string> tokens = split((yyvsp[0].eVal).code, ',');
                                      for( int i=0; i<tokens.size() ;i++ ) {
				                                      if((yyvsp[0].eVal).typeD ==0) {tableVar.push_back(pair<string,string>(tokens[i],(yyvsp[-1].eVal).type)); }
                        	            else   {tableFunc.push_back(pair<string,string>(tokens[i],(yyvsp[-1].eVal).type));}
				 }
}
#line 1568 "test2.tab.c"
    break;

  case 6:
#line 108 "test2.y"
                                               {
				                              strcpy((yyval.eVal).preOrder,(string("Type_Declaration VOIDTYPE ")+string((yyvsp[0].eVal).preOrder)).c_str());
				                              tableFunc.push_back(pair<string,string>((yyvsp[0].eVal).code,"void"));
                                                }
#line 1577 "test2.tab.c"
    break;

  case 7:
#line 114 "test2.y"
                                   {
                              				strcpy((yyval.eVal).preOrder,(string("Declaration ")+string((yyvsp[0].eVal).preOrder)).c_str());
                              				strcpy((yyval.eVal).code , (yyvsp[0].eVal).code) ; (yyval.eVal).typeD = 0; }
#line 1585 "test2.tab.c"
    break;

  case 8:
#line 117 "test2.y"
                                                                   {
                              				strcpy((yyval.eVal).preOrder,(string("Declaration ")+string((yyvsp[0].eVal).preOrder)).c_str());
                              				strcpy((yyval.eVal).type , (yyvsp[0].eVal).code); (yyval.eVal).typeD = 1;
                                    }
#line 1594 "test2.tab.c"
    break;

  case 9:
#line 122 "test2.y"
                                                                 {
                                      strcpy((yyval.eVal).code , (yyvsp[-4].eVal).name);
                                      if ((yyvsp[-2].eVal).count>4) yyerror("error! more than 4 arg");
                                      strcpy((yyval.eVal).preOrder,(string("FuncDeclaration ID ( ")+string((yyvsp[-2].eVal).preOrder) + string(" ) ")+string((yyvsp[0].eVal).preOrder)).c_str());
                                    }
#line 1604 "test2.tab.c"
    break;

  case 10:
#line 128 "test2.y"
                                           { strcpy((yyval.eVal).code, (yyvsp[-1].eVal).code) ;
					                            strcpy((yyval.eVal).preOrder,(string("VarDeclaration ")+string((yyvsp[-1].eVal).preOrder) + string(" ;")).c_str());
                                    }
#line 1612 "test2.tab.c"
    break;

  case 11:
#line 133 "test2.y"
                                                           {
                            					strcpy((yyval.eVal).preOrder,(string("IdentList_Dec ID = ")+string((yyvsp[-2].eVal).preOrder) + string(" , ")+string((yyvsp[0].eVal).preOrder)).c_str());
                            					strcpy((yyval.eVal).code ,(string((yyvsp[-4].eVal).name)+","+string( (yyvsp[0].eVal).code)).c_str());
                                    }
#line 1621 "test2.tab.c"
    break;

  case 12:
#line 137 "test2.y"
                                                   {
                            					strcpy((yyval.eVal).preOrder,(string("IdentList_Dec ID = ")+string((yyvsp[0].eVal).preOrder)).c_str());
                            					strcpy((yyval.eVal).code, (yyvsp[-2].eVal).name) ;
                                    }
#line 1630 "test2.tab.c"
    break;

  case 13:
#line 143 "test2.y"
                                                                                   {
                                      strcpy((yyval.eVal).type , (yyvsp[-5].eVal).type);
                            					strcpy((yyval.eVal).preOrder,(string("Main_Function ")+string((yyvsp[-5].eVal).preOrder) +
                            						    string(" main ( ")+string((yyvsp[-2].eVal).preOrder)+ string(" ) ")+string((yyvsp[0].eVal).preOrder)).c_str());
                                      if ((yyvsp[-2].eVal).count>4)yyerror("error! more than 4 arg");
                                      tableFunc.push_back(pair<string,string>("main",(yyvsp[-5].eVal).type));
                                    }
#line 1642 "test2.tab.c"
    break;

  case 14:
#line 151 "test2.y"
                                 {
                              				strcpy((yyval.eVal).preOrder,(string("Func_Arg ")+string((yyvsp[0].eVal).preOrder)).c_str());
                              				(yyval.eVal).count =  (yyvsp[0].eVal).count;  }
#line 1650 "test2.tab.c"
    break;

  case 15:
#line 154 "test2.y"
                {
                              				strcpy((yyval.eVal).preOrder,"");
                              				(yyval.eVal).count =  0;
                                    }
#line 1659 "test2.tab.c"
    break;

  case 16:
#line 160 "test2.y"
                                                         {
                          						strcpy((yyval.eVal).preOrder,(string("Func_ArgList ")+string((yyvsp[-2].eVal).preOrder)+
                          							     string(" , ")+string((yyvsp[0].eVal).preOrder)).c_str());
                          						(yyval.eVal).count =  (yyvsp[-2].eVal).count + 1;
                                    }
#line 1669 "test2.tab.c"
    break;

  case 17:
#line 165 "test2.y"
                                        {
                          						strcpy((yyval.eVal).preOrder,(string("Func_ArgList ")+string((yyvsp[0].eVal).preOrder)).c_str());
                          						(yyval.eVal).count =   1;
                                    }
#line 1678 "test2.tab.c"
    break;

  case 18:
#line 170 "test2.y"
                                            {
                            					strcpy((yyval.eVal).preOrder,(string("Func_ArgList_Type ")+string((yyvsp[-2].eVal).preOrder)+
                            					     string(" ID ")+string((yyvsp[0].eVal).preOrder)).c_str());
                            					tableVar.push_back(pair<string,string>((yyvsp[-1].eVal).name,(yyvsp[-2].eVal).type)); (yyvsp[-1].eVal).typeD=1; (yyval.eVal).count =   1 ;}
#line 1687 "test2.tab.c"
    break;

  case 19:
#line 177 "test2.y"
                                             {strcpy((yyval.eVal).preOrder,(string("Types void")).c_str()); strcpy((yyval.eVal).type , "void" );}
#line 1693 "test2.tab.c"
    break;

  case 20:
#line 178 "test2.y"
                                             {strcpy((yyval.eVal).preOrder,(string("Types int")).c_str()); strcpy((yyval.eVal).type , "int" );}
#line 1699 "test2.tab.c"
    break;

  case 21:
#line 179 "test2.y"
                                         {strcpy((yyval.eVal).preOrder,(string("Types double")).c_str()); strcpy((yyval.eVal).type , "double" );}
#line 1705 "test2.tab.c"
    break;

  case 22:
#line 180 "test2.y"
                                           {strcpy((yyval.eVal).preOrder,(string("Types float")).c_str()); strcpy((yyval.eVal).type , "float" );}
#line 1711 "test2.tab.c"
    break;

  case 23:
#line 181 "test2.y"
                                           {strcpy((yyval.eVal).preOrder,(string("Types string")).c_str()); strcpy((yyval.eVal).type , "string" );}
#line 1717 "test2.tab.c"
    break;

  case 24:
#line 182 "test2.y"
                                         {strcpy((yyval.eVal).preOrder,(string("Types char")).c_str()); strcpy((yyval.eVal).type , "char" );}
#line 1723 "test2.tab.c"
    break;

  case 25:
#line 184 "test2.y"
                                               {strcpy((yyval.eVal).preOrder,(string("Types int")).c_str()); strcpy((yyval.eVal).type , "int" );}
#line 1729 "test2.tab.c"
    break;

  case 26:
#line 185 "test2.y"
                                         {strcpy((yyval.eVal).preOrder,(string("Types double")).c_str()); strcpy((yyval.eVal).type , "double" );}
#line 1735 "test2.tab.c"
    break;

  case 27:
#line 186 "test2.y"
                                           {strcpy((yyval.eVal).preOrder,(string("Types float")).c_str()); strcpy((yyval.eVal).type , "float" );}
#line 1741 "test2.tab.c"
    break;

  case 28:
#line 187 "test2.y"
                                           {strcpy((yyval.eVal).preOrder,(string("Types string")).c_str()); strcpy((yyval.eVal).type , "string" );}
#line 1747 "test2.tab.c"
    break;

  case 29:
#line 188 "test2.y"
                                         {strcpy((yyval.eVal).preOrder,(string("Types char")).c_str()); strcpy((yyval.eVal).type , "char" );}
#line 1753 "test2.tab.c"
    break;

  case 30:
#line 191 "test2.y"
                                        {strcpy((yyval.eVal).preOrder,(string("CompoundStmt { ")+string((yyvsp[-1].eVal).preOrder) + string(" }")).c_str());}
#line 1759 "test2.tab.c"
    break;

  case 31:
#line 195 "test2.y"
                                        {strcpy((yyval.eVal).preOrder,(string("StmtList ")+string((yyvsp[-1].eVal).preOrder) + string((yyvsp[0].eVal).preOrder)).c_str());}
#line 1765 "test2.tab.c"
    break;

  case 32:
#line 196 "test2.y"
                                        {strcpy((yyval.eVal).preOrder,"");}
#line 1771 "test2.tab.c"
    break;

  case 33:
#line 199 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt ")+string((yyvsp[0].eVal).preOrder)).c_str());}
#line 1777 "test2.tab.c"
    break;

  case 34:
#line 200 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt ")+string((yyvsp[0].eVal).preOrder)).c_str());}
#line 1783 "test2.tab.c"
    break;

  case 35:
#line 201 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt ")+string((yyvsp[-1].eVal).preOrder) + string(" ;")).c_str());}
#line 1789 "test2.tab.c"
    break;

  case 36:
#line 202 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt ")+string((yyvsp[0].eVal).preOrder)).c_str());}
#line 1795 "test2.tab.c"
    break;

  case 37:
#line 203 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt ")+string((yyvsp[-1].eVal).preOrder) + string(" ;")).c_str());}
#line 1801 "test2.tab.c"
    break;

  case 38:
#line 204 "test2.y"
                                                      {strcpy((yyval.eVal).preOrder,(string("Stmt return ") + string(" ;")).c_str());}
#line 1807 "test2.tab.c"
    break;

  case 39:
#line 205 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt break ") + string(" ;")).c_str());}
#line 1813 "test2.tab.c"
    break;

  case 40:
#line 206 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt continue ") + string(" ;")).c_str());}
#line 1819 "test2.tab.c"
    break;

  case 41:
#line 207 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt return ") + string((yyvsp[-1].eVal).preOrder) + string(" ;")).c_str());}
#line 1825 "test2.tab.c"
    break;

  case 42:
#line 208 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt ")+string((yyvsp[-1].eVal).preOrder) + string(" ;")).c_str());}
#line 1831 "test2.tab.c"
    break;

  case 43:
#line 209 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt ")+string((yyvsp[-1].eVal).preOrder) + string(" ;")).c_str());}
#line 1837 "test2.tab.c"
    break;

  case 44:
#line 210 "test2.y"
                                                {strcpy((yyval.eVal).preOrder,(string("Stmt ;")).c_str());}
#line 1843 "test2.tab.c"
    break;

  case 45:
#line 213 "test2.y"
                                                                                         {
						                                    strcpy((yyval.eVal).preOrder,(string("ForStmt foreach ID ( ")+string((yyvsp[-4].eVal).preOrder) + string(" .. ")+
							                                  string((yyvsp[-2].eVal).preOrder) + string(" ) ")+string((yyvsp[0].eVal).preOrder)).c_str());
                                              }
#line 1852 "test2.tab.c"
    break;

  case 46:
#line 218 "test2.y"
                                                           {   strcpy((yyval.eVal).preOrder,(string("IdTemp ") +string("ID ")).c_str() );
                                                                tableVar.push_back(pair<string,string>((yyvsp[0].eVal).name,"int"));}
#line 1859 "test2.tab.c"
    break;

  case 47:
#line 221 "test2.y"
                                                                            {strcpy((yyval.eVal).preOrder,(string("IfStmt ( ") + string((yyvsp[-3].eVal).preOrder) + string(" ) ")
											+ string((yyvsp[-1].eVal).preOrder)+ string((yyvsp[0].eVal).preOrder)).c_str());}
#line 1866 "test2.tab.c"
    break;

  case 48:
#line 225 "test2.y"
                                                            {   strcpy((yyval.eVal).preOrder,(string("ElsePart ") + string("ELSE ") + string((yyvsp[0].eVal).preOrder)).c_str() ); }
#line 1872 "test2.tab.c"
    break;

  case 49:
#line 226 "test2.y"
                                                            {   strcpy((yyval.eVal).preOrder,(string("")).c_str() );}
#line 1878 "test2.tab.c"
    break;

  case 50:
#line 228 "test2.y"
                                                            {   strcpy((yyval.eVal).preOrder,(string("Local_Vars ") + string((yyvsp[-1].eVal).preOrder) + string((yyvsp[0].eVal).preOrder)).c_str() );
                                                                vector<string> tokens = split((yyvsp[0].eVal).code, ',');
                                                                for( int i=0; i<tokens.size() ;i++ )
				                                                        tableVar.push_back(pair<string,string>(tokens[i],(yyvsp[-1].eVal).type));
                                                              }
#line 1888 "test2.tab.c"
    break;

  case 51:
#line 234 "test2.y"
                                                            {   strcpy((yyval.eVal).preOrder,(string("IdentList ") +string("ID ") + string((yyvsp[-2].eVal).preOrder) +string("COMMA ")+ string((yyvsp[0].eVal).preOrder) ).c_str() );  strcpy((yyval.eVal).code ,(string((yyvsp[-3].eVal).name)+","+string( (yyvsp[0].eVal).code)).c_str()); }
#line 1894 "test2.tab.c"
    break;

  case 52:
#line 235 "test2.y"
                                                            {   strcpy((yyval.eVal).preOrder,(string("IdentList ") +string("ID ") + string((yyvsp[0].eVal).preOrder)).c_str() );  strcpy((yyval.eVal).code, (yyvsp[-1].eVal).name) ;}
#line 1900 "test2.tab.c"
    break;

  case 53:
#line 237 "test2.y"
                                                            {strcpy((yyval.eVal).preOrder,(string("\naddi $s0 ,$zero  ,")+ string((yyvsp[0].eVal).preOrder) ).c_str() ); }
#line 1906 "test2.tab.c"
    break;

  case 54:
#line 238 "test2.y"
                                                            {strcpy((yyval.eVal).preOrder,(string("IdentList_DeforDec ") +string("Array_Var ") ).c_str() );}
#line 1912 "test2.tab.c"
    break;

  case 55:
#line 241 "test2.y"
                                                            {strcpy((yyval.eVal).preOrder,(string("Print ") +string("PRINTFUNC ") + string("LEFTPAREN ") + string((yyvsp[-1].eVal).preOrder) + string("RIGHTPAREN ") ).c_str() ); }
#line 1918 "test2.tab.c"
    break;

  case 56:
#line 244 "test2.y"
                                                            {
                                                                strcpy((yyval.eVal).preOrder,(string("Call ") +string("ID ") +string("LEFTPAREN ") + string((yyvsp[-1].eVal).preOrder) + string("RIGHTPAREN ") ).c_str() );
                                                              }
#line 1926 "test2.tab.c"
    break;

  case 57:
#line 248 "test2.y"
                                                            {   strcpy((yyval.eVal).preOrder,(string("Call_ArgList ") + string((yyvsp[-2].eVal).preOrder) + string("COMMA ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                                  (yyval.eVal).count =  (yyvsp[0].eVal).count + 1; }
#line 1933 "test2.tab.c"
    break;

  case 58:
#line 250 "test2.y"
                                                                        {  strcpy((yyval.eVal).preOrder,(string("Call_ArgList ") + string((yyvsp[0].eVal).preOrder)).c_str() );
                                                                  (yyval.eVal).count = 1; }
#line 1940 "test2.tab.c"
    break;

  case 59:
#line 252 "test2.y"
                                                                        { strcpy((yyval.eVal).preOrder,(string("")).c_str() );
                                                                  (yyval.eVal).count = 0; }
#line 1947 "test2.tab.c"
    break;

  case 60:
#line 255 "test2.y"
                                                                      {   strcpy( (yyval.eVal).preOrder , "3" );
                                                            if(strcmp(getType((yyvsp[-3].eVal).name,0),(yyvsp[-1].eVal).type)!=0 && !(strcmp(getType((yyvsp[-3].eVal).name,0),"char")==0 && strcmp((yyvsp[-1].eVal).type,"int")==0 )&&
                                                                !(strcmp((yyvsp[-1].eVal).type,"char")==0 && strcmp(getType((yyvsp[-3].eVal).name,0),"int")==0 )) yyerror("error! Different Type");
                                                            else strcpy((yyval.eVal).type , (yyvsp[-1].eVal).type);}
#line 1956 "test2.tab.c"
    break;

  case 61:
#line 260 "test2.y"
                                                        {    strcpy( (yyval.eVal).preOrder , "3" );
                                                            strcpy((yyval.eVal).type , (yyvsp[0].eVal).type );}
#line 1963 "test2.tab.c"
    break;

  case 62:
#line 263 "test2.y"
                                                        {   strcpy((yyval.eVal).preOrder,(string("ExprLogical ") + string((yyvsp[-2].eVal).preOrder) + string("LOGICOP_2 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                            if(strcmp((yyvsp[-2].eVal).type,"string")==0  &&  strcmp((yyvsp[0].eVal).type,"string")==0 ) yyerror("error! Different Type");
                                                            else if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                                !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type");
                                                            else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 1973 "test2.tab.c"
    break;

  case 63:
#line 269 "test2.y"
                                                        {    strcpy((yyval.eVal).preOrder,(string("ExprLogical ") + string((yyvsp[-2].eVal).preOrder) + string("LOGICOP_1 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                            if(strcmp((yyvsp[-2].eVal).type,"string")==0  &&  strcmp((yyvsp[0].eVal).type,"string")==0 ) yyerror("error! Different Type");
                                                            else if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                                !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type"); else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 1982 "test2.tab.c"
    break;

  case 64:
#line 274 "test2.y"
                                                        { strcpy((yyval.eVal).preOrder,(string("ExprLogical ") + string((yyvsp[0].eVal).preOrder) ).c_str() );
                                                           strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 1989 "test2.tab.c"
    break;

  case 65:
#line 277 "test2.y"
                                                        {   strcpy((yyval.eVal).preOrder,(string("ExprBinary ") + string((yyvsp[-2].eVal).preOrder) + string("BITWISEOP_2 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                            if(strcmp((yyvsp[-2].eVal).type,"string")==0  &&  strcmp((yyvsp[0].eVal).type,"string")==0 ) yyerror("error! Different Type");
                                                            else if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                                 !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type");
                                                            else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 1999 "test2.tab.c"
    break;

  case 66:
#line 283 "test2.y"
                                                         {   strcpy((yyval.eVal).preOrder,(string("ExprBinary ") + string((yyvsp[-2].eVal).preOrder) + string("ARITHMATICOP_5 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                            if(strcmp((yyvsp[-2].eVal).type,"string")==0  &&  strcmp((yyvsp[0].eVal).type,"string")==0 ) yyerror("error! Different Type");
                                                            else if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                                !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type");
                                                                else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2009 "test2.tab.c"
    break;

  case 67:
#line 289 "test2.y"
                                                         {  strcpy((yyval.eVal).preOrder,(string("ExprBinary ") + string((yyvsp[-2].eVal).preOrder) + string("BITWISEOP_1 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                            if(strcmp((yyvsp[-2].eVal).type,"string")==0  &&  strcmp((yyvsp[0].eVal).type,"string")==0 ) yyerror("error! Different Type");
                                                            else if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                            !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type");
                                                            else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2019 "test2.tab.c"
    break;

  case 68:
#line 295 "test2.y"
                                                         {  strcpy((yyval.eVal).preOrder,(string("ExprBinary ") + string((yyvsp[0].eVal).preOrder)).c_str() );
                                                            strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2026 "test2.tab.c"
    break;

  case 69:
#line 298 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Rvalue ") + string((yyvsp[-2].eVal).preOrder) + string("Compare_1 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                    if( strcmp((yyvsp[-2].eVal).type,"string")==0  &&  strcmp((yyvsp[0].eVal).type,"string")==0 )yyerror("error! Different Type");
                                                    else if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                        !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type");
                                                    else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2036 "test2.tab.c"
    break;

  case 70:
#line 304 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Rvalue ") + string((yyvsp[-2].eVal).preOrder) + string("Compare_2 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                    if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                        !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type");
                                                    else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2045 "test2.tab.c"
    break;

  case 71:
#line 309 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Rvalue ") + string((yyvsp[0].eVal).preOrder)).c_str() );  strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2051 "test2.tab.c"
    break;

  case 72:
#line 311 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Compare_1 ")+string("RELATIONOP_3")).c_str()); }
#line 2057 "test2.tab.c"
    break;

  case 73:
#line 312 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Compare_1 ")+string("RELATIONOP_2")).c_str()); }
#line 2063 "test2.tab.c"
    break;

  case 74:
#line 313 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Compare_1 ")+string("RELATIONOP_2")).c_str()); }
#line 2069 "test2.tab.c"
    break;

  case 75:
#line 315 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Compare_2 ")+string("RELATIONOP_5")).c_str()); }
#line 2075 "test2.tab.c"
    break;

  case 76:
#line 316 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Compare_2 ")+string("RELATIONOP_6")).c_str()); }
#line 2081 "test2.tab.c"
    break;

  case 77:
#line 317 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Compare_2 ")+string("RELATIONOP_4")).c_str()); }
#line 2087 "test2.tab.c"
    break;

  case 78:
#line 319 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Mag ") + string((yyvsp[-2].eVal).preOrder) + string("ARITHMATICOP_1 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                             if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                    !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type"); else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2095 "test2.tab.c"
    break;

  case 79:
#line 323 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Mag ") + string((yyvsp[-2].eVal).preOrder) + string("ARITHMATICOP_2 ") + string((yyvsp[0].eVal).preOrder)  ).c_str() );
                                                 if(strcmp((yyvsp[-2].eVal).type,"string")==0  &&  strcmp((yyvsp[0].eVal).type,"string")==0 ) yyerror("error! Different Type");
                                                 else if(strcmp((yyvsp[-2].eVal).type,(yyvsp[0].eVal).type)!=0 && !(strcmp((yyvsp[-2].eVal).type,"char")==0 && strcmp((yyvsp[0].eVal).type,"int")==0 )&&
                                                     !(strcmp((yyvsp[0].eVal).type,"char")==0 && strcmp((yyvsp[-2].eVal).type,"int")==0 )) yyerror("error! Different Type"); else strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2104 "test2.tab.c"
    break;

  case 80:
#line 328 "test2.y"
                                                {   strcpy((yyval.eVal).preOrder,(string("Mag ")+string((yyvsp[0].eVal).preOrder)).c_str()); strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);}
#line 2110 "test2.tab.c"
    break;

  case 81:
#line 331 "test2.y"
                                                {
                                                    string tmp= (yyvsp[-2].eVal).preOrder + (yyvsp[-1].eVal).preOrder;
                                                    string tmptmp;
                                                    if((yyvsp[-1].eVal).feature == 1){ //cont
                                                      string cnt=stack.pop_back();
                                                      tmptmp = cnt;
                                                    }
                                                    else if((yyvsp[-1].eVal).feature == 4){ //var
                                                      string var=stack.pop_back();
                                                      tmptmp = var;
                                                    }
                                                    else if((yyvsp[-1].eVal).feature == 6){ //tmp_ent
                                                      string tm=stack.pop_back();
                                                      temp_num--;
                                                      tmptmp = tm;
                                                    }
                                                    else
                                                      cout<<"\nerror!\n";
                                                    tmptmp = " , " + tmptmp;
                                                    if((yyvsp[-2].eVal).feature == 1){ //cont
                                                      string cnt=stack.pop_back();
                                                      tmptmp = cnt + tmptmp;
                                                    }
                                                    else if((yyvsp[-2].eVal).feature == 4){ //var
                                                      string var=stack.pop_back();
                                                      tmptmp = var + tmptmp;
                                                    }
                                                    else if((yyvsp[-2].eVal).feature == 6){ //tmp_ent
                                                      string tm=stack.pop_back();
                                                      temp_num--;
                                                      tmptmp = tm + tmptmp;
                                                    }
                                                    else
                                                      cout<<"\nerror!\n";

                                                    temp_num++;
                                                    string tm=stack.push_back("$t"+to_string(temp_num));
                                                    tmptmp = "\n\tmul\t$t"+to_string(temp_num)+" , "+tmptmp;
                                                    tmp = tmp + tmptmp;

                                                    /*if(strcmp($1.type,"string")==0  &&  strcmp($3.type,"string")==0 )yyerror("error! Different Type");
                                                        else if(strcmp($1.type,$3.type)!=0 && !(strcmp($1.type,"char")==0 && strcmp($3.type,"int")==0 )&&
                                                         !(strcmp($3.type,"char")==0 && strcmp($1.type,"int")==0 )) yyerror("error! Different Type"); else */

                                                    strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);
                                                    strcpy((yyval.eVal).preOrder,tmp.c_str() );
                                                }
#line 2162 "test2.tab.c"
    break;

  case 82:
#line 380 "test2.y"
                                                {// //////////////////////////
                                                    string tmp= (yyvsp[-2].eVal).preOrder + (yyvsp[-1].eVal).preOrder;
                                                    string tmptmp;
                                                    if((yyvsp[-1].eVal).feature == 1){ //cont
                                                      string cnt=stack.pop_back();
                                                      tmptmp = cnt;
                                                    }
                                                    else if((yyvsp[-1].eVal).feature == 4){ //var
                                                      string var=stack.pop_back();
                                                      tmptmp = var;
                                                    }
                                                    else if((yyvsp[-1].eVal).feature == 6){ //tmp_ent
                                                      string tm=stack.pop_back();
                                                      temp_num--;
                                                      tmptmp = tm;
                                                    }
                                                    else
                                                      cout<<"\nerror!\n";
                                                    tmptmp = " , " + tmptmp;
                                                    if((yyvsp[-2].eVal).feature == 1){ //cont
                                                      string cnt=stack.pop_back();
                                                      tmptmp = cnt + tmptmp;
                                                    }
                                                    else if((yyvsp[-2].eVal).feature == 4){ //var
                                                      string var=stack.pop_back();
                                                      tmptmp = var + tmptmp;
                                                    }
                                                    else if((yyvsp[-2].eVal).feature == 6){ //tmp_ent
                                                      string tm=stack.pop_back();
                                                      temp_num--;
                                                      tmptmp = tm + tmptmp;
                                                    }
                                                    else
                                                      cout<<"\nerror!\n";

                                                    temp_num++;
                                                    string tm=stack.push_back("$t"+to_string(temp_num));
                                                    tmptmp = "\n\tdiv\t"+tmptmp;
                                                    tmptmp = "\n\tmov\t$t"+to_string(temp_num)+" , $low";
                                                    tmp = tmp + tmptmp;

                                                    /*if(strcmp($1.type,"string")==0  &&  strcmp($3.type,"string")==0 )yyerror("error! Different Type");
                                                        else if(strcmp($1.type,$3.type)!=0 && !(strcmp($1.type,"char")==0 && strcmp($3.type,"int")==0 )&&
                                                         !(strcmp($3.type,"char")==0 && strcmp($1.type,"int")==0 )) yyerror("error! Different Type"); else */

                                                    strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);
                                                    strcpy((yyval.eVal).preOrder,tmp.c_str() );
                                                }
#line 2215 "test2.tab.c"
    break;

  case 83:
#line 429 "test2.y"
                                                {
                                                    (yyval.eVal).feature=(yyvsp[0].eVal).feature;
                                                    strcpy((yyval.eVal).preOrder,(yyvsp[0].eVal).preOrder.c_str() );
                                                    strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);
                                                }
#line 2225 "test2.tab.c"
    break;

  case 84:
#line 437 "test2.y"
                                                {
                                                    (yyval.eVal).feature=(yyvsp[-1].eVal).feature;
                                                    strcpy((yyval.eVal).preOrder,(yyvsp[-1].eVal).preOrder.c_str() );
                                                    strcpy((yyval.eVal).type , (yyvsp[-1].eVal).type);
                                                }
#line 2235 "test2.tab.c"
    break;

  case 85:
#line 443 "test2.y"
                                                {   // --------------------
                                                    string tmp = (yyvsp[0].eVal).preOrder;
                                                    (yyval.eVal).feature=6;
                                                    if((yyvsp[0].eVal).feature==1){//const
                                                      string cnt=stack.pop_back();
                                                      temp_num++;
                                                      stack.push_back("$t"+to_string(temp_num));
                                                      tmp = tmp + "\n\tmovl\t"+cnt+" , %eax";
                                                      tmp = tmp + "\n\tneg\t%eax";
                                                      tmp = tmp + "\n\tmovl\t"+"%eax , "+"$t"+to_string(temp_num);
                                                    }
                                                    else if((yyvsp[0].eVal).feature==4){//variable
                                                      string var=stack.pop_back();
                                                      temp_num++;
                                                      stack.push_back("$t"+to_string(temp_num));
                                                      tmp = tmp + "\n\tmovl\t"+var+" , %eax";
                                                      tmp = tmp + "\n\tneg\t%eax";
                                                      tmp = tmp + "\n\tmovl\t"+"%eax , "+to_string(temp_num);
                                                    }
                                                    else if((yyvsp[0].eVal).feature==6){//tmp_ent
                                                      string tm=stack.pop_back();
                                                      stack.push_back("$t"+to_string(temp_num));
                                                      tmp = tmp + "\n\tmovl\t"+tm+" , %eax";
                                                      tmp = tmp + "\n\tneg\t%eax";
                                                      tmp = tmp + "\n\tmovl\t"+"%eax , "+to_string(temp_num);
                                                    }
                                                    else
                                                      cout<<"\nerror!\n";

                                                    /*if(strcmp($2.type,"string")==0)
                                                      yyerror("error! Different Type");
                                                    else*/

                                                    strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);
                                                    strcpy((yyval.eVal).preOrder,tmp.c_str() );
                                                }
#line 2276 "test2.tab.c"
    break;

  case 86:
#line 480 "test2.y"
                                                {   //     +++++++++++++
                                                  string tmp = (yyvsp[0].eVal).preOrder;
                                                  if((yyvsp[0].eVal).feature==1){//const
                                                    (yyval.eVal).feature=1;

                                                  }
                                                  else if((yyvsp[0].eVal).feature==4){//variable
                                                    (yyval.eVal).feature=4;

                                                  }
                                                  else if((yyvsp[0].eVal).feature==6){//tmp_ent
                                                    (yyval.eVal).feature=6;
                                                  }
                                                  else
                                                    cout<<"\nerror!\n";


                                                  /*if(strcmp($2.type,"string")==0)
                                                    yyerror("error! Different Type");
                                                  else*/

                                                  strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);
                                                  strcpy((yyval.eVal).preOrder,tmp.c_str() );

                                                }
#line 2306 "test2.tab.c"
    break;

  case 87:
#line 505 "test2.y"
                                                {
                                                  (yyval.eVal).feature=(yyvsp[0].eVal).feature;
                                                  strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);
                                                  (yyval.eVal).preOrder=(yyvsp[0].eVal).preOrder;
                                                }
#line 2316 "test2.tab.c"
    break;

  case 88:
#line 513 "test2.y"
                                                {
                                                  (yyval.eVal).feature=(yyvsp[0].eVal).feature;
                                                  strcpy((yyval.eVal).type , (yyvsp[0].eVal).type);
                                                  (yyval.eVal).preOrder="";
                                                }
#line 2326 "test2.tab.c"
    break;

  case 89:
#line 519 "test2.y"
                                                {
                                                   string tmp = "";
                                                   vector<pair<string,string>>tmpTable = tableVar[tableVar.size()-1];
                                                   int i=0;
                                                   for(i=0;i<tmpTable.size();i++)
                                                      if(tmpTable[i].first==(yyvsp[-1].eVal).name)
                                                          break;

                                                  if ((yyvsp[0].eVal).feature==2){
                                                    (yyval.eVal).feature = 6;
                                                    int indx = atoi(stack.pop_back())*4;
                                                    temp_num++;
                                                    tmp = "\n\tlw\t$t"+to_string(temp_num)+" , "+to_string(indx)+"($s"+to_string(i)+")";
                                                    stack.push_back("$t"+to_string(temp_num));

                                                  }
                                                  else if((yyvsp[0].eVal).feature==0){
                                                    stack.push_back("$s"+to_string(i));
                                                    (yyval.eVal).feature = 4;
                                                  }
                                                  else if((yyvsp[0].eVal).feature==3){
                                                    cout<<"\nerror!\n";


                                                  }

                                                   strcpy((yyval.eVal).type , getType((yyvsp[-1].eVal).name,0));
                                                   strcpy((yyval.eVal).preOrder,tmp.c_str());

                                                 }
#line 2361 "test2.tab.c"
    break;

  case 90:
#line 553 "test2.y"
                                              { /*  strcpy($$.preOrder,"Const FLOATCONST"); strcpy($$.type , "float");*/}
#line 2367 "test2.tab.c"
    break;

  case 91:
#line 554 "test2.y"
                                                    {  /* strcpy($$.preOrder,"Const STRINGCONST"); strcpy($$.type , "string");*/}
#line 2373 "test2.tab.c"
    break;

  case 92:
#line 555 "test2.y"
                                                    {  /* strcpy($$.preOrder,"Const CHARCONST"); strcpy($$.type , "char");*/}
#line 2379 "test2.tab.c"
    break;

  case 93:
#line 556 "test2.y"
                                                    {    stack.push_back(to_string((yyvsp[0].eVal).value)); strcpy((yyval.eVal).type , "int"); (yyval.eVal).feature=1;  (yyval.eVal).preOrder=""}
#line 2385 "test2.tab.c"
    break;

  case 94:
#line 560 "test2.y"
                                                {   cout<<"arr1\n"; (yyval.eVal).feature=0; }
#line 2391 "test2.tab.c"
    break;

  case 95:
#line 561 "test2.y"
                                                {   cout<<"arr2\n"; (yyval.eVal).feature=2; stack.push_back(to_string((yyvsp[-1].eVal).value)); }
#line 2397 "test2.tab.c"
    break;

  case 96:
#line 562 "test2.y"
                                                {   cout<<"arr3\n"; (yyval.eVal).feature=3; }
#line 2403 "test2.tab.c"
    break;


#line 2407 "test2.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 565 "test2.y"



int main(int argc,char *argv[])
{
    yyparse();

}

int yyerror(const char* m){

    fprintf(stderr, " line %d: %s\n", line_counter, m);


}
