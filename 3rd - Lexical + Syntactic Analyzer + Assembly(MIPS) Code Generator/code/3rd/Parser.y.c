/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */

          
     #include <stdio.h>
     #include <iostream>
     #include <stdlib.h>
     #include<time.h>
     #include <math.h>
     #include <string.h>
     #include <string>
     #include <unordered_map> 
     #include <algorithm>
     #include <fstream>
     #include<stack>
     #include<vector>



     using namespace std;

     int current_dtype;
     int is_declaration = 0;
     int is_loop = 0;
     int is_func = 0;
     int func_type;
     int out = 0;
     int rhs = 0;
     int scopeNo=0;
     int prevscopeNo=0;
     int clacStart=0;
     int conditionNo=0;
     int loopNo=0;

     struct perScope{
          int type;
          int scope;
          int cnt;
          int stack;
          int stackPlace;
     };
     unordered_map<string, struct perScope> umap; 
     unordered_map<int, int> scopeVars; 
     

     ofstream MyFile("output.out");

     vector<pair<int,int>> scopeVector;

     extern int yylex();
     extern FILE* yyin;
     void yyerror(const char* s);
     void type_check(int,int,int);
     int yyparse();


#line 121 "Parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.tab.h".  */
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
    UMINUS = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "Parser.y" /* yacc.c:355  */

     struct t {
          char*  _val;
          int    _cnt;
          int _datatype; //1:int 2:float 3:char 4:string :void 6:double
          char _byname [2056] ;
          char _byid [2056];
          int _typ; //1:const
          char _asm[2056];
          int _scopeNo;
          int _numVal;
          int _stackPlace;
          int _isVar;
          int _isSingle;
          int _arrParam;
          int _arrVar;
     }token;

#line 229 "Parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "Parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   150,   178,   183,   190,   190,   183,   231,
     237,   237,   245,   231,   297,   303,   306,   317,   320,   329,
     350,   360,   363,   369,   380,   399,   409,   418,   427,   436,
     446,   461,   469,   477,   508,   532,   552,   587,   587,   639,
     661,   681,   716,   736,   746,   760,   774,   784,   795,   802,
     808,   821,   832,   842,   882,   920,   957,   994,  1031,  1068,
    1078,  1088,  1096,  1105,  1115,  1117,  1165,  1180,  1189,  1190,
    1193,  1231,  1338,  1433,  1532,  1554,  1573,  1594,  1615,  1616,
    1617,  1618,  1619,  1622,  1623,  1626,  1630,  1675,  1676,  1677,
    1678,  1679,  1680,  1683,  1684,  1685,  1686
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_ID", "TOKEN_RETURN",
  "TOKEN_STRINGCONST", "TOKEN_MAINFUNC", "TOKEN_PRFUNC", "TOKEN_LOOP",
  "TOKEN_ELSECONDITION", "TOKEN_IFCONDITION", "TOKEN_CONTINUESTMT",
  "TOKEN_BREAKSTMT", "TOKEN_INTTYPE", "TOKEN_FLOATTYPE",
  "TOKEN_DOUBLETYPE", "TOKEN_CHARTYPE", "TOKEN_STRINGTYPE",
  "TOKEN_VOIDTYPE", "TOKEN_CHARCONST", "TOKEN_ASSIGNOP", "TOKEN_LEFTPAREN",
  "TOKEN_RIGHTPAREN", "TOKEN_LCB", "TOKEN_RCB", "TOKEN_SEMICOLON",
  "TOKEN_COMMA", "TOKEN_UNTIL", "TOKEN_LB", "TOKEN_RB", "TOKEN_INTCONST",
  "TOKEN_FLOATCONST", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MUL",
  "TOKEN_DIV", "TOKEN_POW", "TOKEN_LOGICAND", "TOKEN_LOGICOR",
  "TOKEN_LOGICNOT", "TOKEN_BITWISEAND", "TOKEN_BITWISEOR", "TOKEN_EQ",
  "TOKEN_NOTEQ", "TOKEN_GR", "TOKEN_LS", "TOKEN_LSEQ", "TOKEN_GREQ",
  "UMINUS", "$accept", "program", "globalVars", "function", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "argumentList", "arguments", "arg",
  "statements", "stmt", "compoundStmt", "singleStmt", "printFunc",
  "conditionStmt", "loopStmt", "$@8", "functionCall", "parameter_list",
  "parameter", "declaration", "declaration_list", "sub_decl", "expression",
  "sub_expr", "assgn", "assignment_expr", "lhs", "identifier",
  "arithmetic_expr", "array_init_vars", "array_init", "array_access",
  "typeSpecifier", "constants", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     171,  -115,  -115,  -115,  -115,  -115,  -115,    10,  -115,  -115,
      41,  -115,  -115,  -115,   -14,     8,     3,    14,  -115,  -115,
    -115,  -115,  -115,    -6,  -115,    23,   171,   171,  -115,  -115,
      27,    25,  -115,    53,    35,  -115,   171,    44,  -115,  -115,
      35,  -115,     3,   217,  -115,    46,   122,    57,    53,    67,
      65,    71,  -115,  -115,  -115,  -115,    75,  -115,  -115,    77,
    -115,    28,  -115,  -115,    73,    -7,    86,    53,   171,  -115,
     160,  -115,   160,   141,   172,  -115,    -5,   242,    86,  -115,
     141,    89,   141,  -115,  -115,  -115,  -115,  -115,    53,  -115,
      68,   137,     3,    79,    -5,  -115,    41,    85,   214,  -115,
    -115,  -115,  -115,   141,   141,   141,   141,   141,   141,   141,
     141,   160,   160,   160,   160,   160,   160,   160,   161,   141,
      -2,   215,  -115,     3,  -115,   -12,   242,  -115,  -115,     6,
    -115,   215,    87,  -115,  -115,  -115,   243,   226,   198,   198,
    -115,  -115,  -115,  -115,    34,    34,    81,    81,  -115,   259,
     259,  -115,    82,    35,   141,     1,  -115,  -115,   141,  -115,
     141,   117,   215,  -115,     3,  -115,    16,    35,  -115,  -115,
    -115,    35,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    87,    88,    89,    90,    91,    92,     0,     2,     4,
       0,     1,    70,     5,     9,     0,     0,     0,     6,    96,
      94,    93,    95,     0,    10,     0,     0,    15,     7,     3,
       0,    14,    17,     0,     0,    11,     0,    18,    21,     8,
       0,    16,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,    24,    20,    22,    23,     0,    25,    26,     0,
      27,     0,    47,    48,     0,    49,    50,     0,     0,    19,
       0,    30,     0,     0,     0,    63,    80,    62,    82,    81,
       0,     0,     0,    31,    32,    29,    28,    45,     0,    64,
       0,     0,     0,     0,    49,    13,     0,    80,     0,    82,
      79,    61,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    46,     0,    66,    80,    65,    67,    40,     0,
      42,    43,     0,    44,     9,    78,    59,    60,    55,    56,
      53,    54,    57,    58,    71,    72,    73,    74,    75,    76,
      77,    34,     0,     0,     0,     0,    84,    39,     0,    86,
       0,    35,    51,    85,     0,    41,     0,     0,    83,    37,
      36,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -115,  -115,   103,    62,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,    95,  -115,  -115,   -39,  -115,  -115,  -115,
    -115,  -115,    55,  -115,    -9,  -115,    83,    63,  -114,   -43,
    -115,   -36,  -115,     7,    22,  -115,  -115,   -31,   -25,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    15,    25,    34,    17,    27,    40,
      68,    30,    31,    32,    43,    53,    39,    55,    56,    57,
      58,   171,    59,   129,   130,    60,    61,    62,   120,   121,
      90,    75,    64,    76,    77,   155,   127,    78,    10,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    44,    33,    74,    54,   152,    16,    63,    19,    91,
      11,    33,    66,   -68,    91,   -68,    92,    14,    67,    26,
     153,    92,    20,    92,   154,   163,    45,   164,   157,    18,
     101,    63,   158,    21,    22,    24,    66,   118,   169,    99,
      37,    99,   154,    96,    12,    28,   166,    13,   131,    35,
      65,    36,    63,    87,    88,    81,    12,    66,    38,    99,
     136,   137,   138,   139,   140,   141,   142,   143,   113,   114,
     115,    12,    42,    19,    94,    69,   132,    97,    80,    97,
      99,    99,    99,    99,    99,    99,    99,    20,    82,    70,
      83,   123,    98,    89,   100,    94,    84,   125,    21,    22,
      85,    72,    86,   134,   133,    88,   -69,   156,   154,   160,
     119,   162,   126,    92,   161,   131,   159,   115,    97,    97,
      97,    97,    97,    97,    97,    12,   167,    19,   170,    29,
      95,    41,   172,   144,   145,   146,   147,   148,   149,   150,
      12,    20,    19,    70,    12,   124,    19,    71,   168,   165,
      93,   122,    21,    22,     0,    72,    20,     0,    70,   128,
      20,    73,    70,    12,     0,    19,     0,    21,    22,     0,
      72,    21,    22,     0,    72,     0,    73,     0,     0,    20,
      73,    70,     0,   151,     1,     2,     3,     4,     5,     6,
      21,    22,     0,    72,     0,     0,     0,   102,   103,   104,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   103,
     104,     0,     0,     0,   105,   106,   107,   108,   109,   110,
      12,    46,     0,     0,    47,    48,     0,    49,    50,    51,
       1,     2,     3,     4,     5,     6,   135,     0,     0,     0,
      38,    52,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   103,   104,   116,   117,     0,   105,   106,   107,
     108,   109,   110,   103,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,     0,   116,   117,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
      16,    40,    27,    46,    43,   119,    20,    43,     5,    21,
       0,    36,    43,    20,    21,    20,    28,    10,    43,    25,
      22,    28,    19,    28,    26,    24,    42,    26,    22,    21,
      73,    67,    26,    30,    31,    21,    67,    80,    22,    70,
      33,    72,    26,    68,     3,    22,   160,     6,    91,    22,
      43,    26,    88,    25,    26,    48,     3,    88,    23,    90,
     103,   104,   105,   106,   107,   108,   109,   110,    34,    35,
      36,     3,    28,     5,    67,    29,    92,    70,    21,    72,
     111,   112,   113,   114,   115,   116,   117,    19,    21,    21,
      25,    23,    70,    20,    72,    88,    25,    90,    30,    31,
      25,    33,    25,    96,    25,    26,    20,   123,    26,    27,
      21,   154,    90,    28,   153,   158,    29,    36,   111,   112,
     113,   114,   115,   116,   117,     3,     9,     5,   167,    26,
      68,    36,   171,   111,   112,   113,   114,   115,   116,   117,
       3,    19,     5,    21,     3,    90,     5,    25,   164,   158,
      67,    88,    30,    31,    -1,    33,    19,    -1,    21,    22,
      19,    39,    21,     3,    -1,     5,    -1,    30,    31,    -1,
      33,    30,    31,    -1,    33,    -1,    39,    -1,    -1,    19,
      39,    21,    -1,    22,    13,    14,    15,    16,    17,    18,
      30,    31,    -1,    33,    -1,    -1,    -1,    25,    37,    38,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    37,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
       3,     4,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    22,    -1,    -1,    -1,
      23,    24,    44,    45,    46,    47,    32,    33,    34,    35,
      36,    -1,    37,    38,    40,    41,    -1,    42,    43,    44,
      45,    46,    47,    37,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    -1,    42,    43,    44,    45,    46,
      47,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    15,    16,    17,    18,    50,    51,    52,
      87,     0,     3,     6,    82,    53,    20,    56,    21,     5,
      19,    30,    31,    88,    21,    54,    25,    57,    22,    51,
      60,    61,    62,    87,    55,    22,    26,    82,    23,    65,
      58,    62,    28,    63,    65,    88,     4,     7,     8,    10,
      11,    12,    24,    64,    65,    66,    67,    68,    69,    71,
      74,    75,    76,    80,    81,    82,    86,    87,    59,    29,
      21,    25,    33,    39,    78,    80,    82,    83,    86,    88,
      21,    82,    21,    25,    25,    25,    25,    25,    26,    20,
      79,    21,    28,    75,    82,    52,    87,    82,    83,    86,
      83,    78,    25,    37,    38,    42,    43,    44,    45,    46,
      47,    32,    33,    34,    35,    36,    40,    41,    78,    21,
      77,    78,    76,    23,    71,    82,    83,    85,    22,    72,
      73,    78,    88,    25,    82,    22,    78,    78,    78,    78,
      78,    78,    78,    78,    83,    83,    83,    83,    83,    83,
      83,    22,    77,    22,    26,    84,    88,    22,    26,    29,
      27,    65,    78,    24,    26,    73,    77,     9,    88,    22,
      65,    70,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    53,    54,    55,    52,    56,
      57,    58,    59,    52,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    68,    68,    70,    69,    71,
      71,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    80,    80,    80,    81,    81,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     1,     0,     0,     0,     8,     0,
       0,     0,     0,    11,     1,     0,     3,     1,     2,     5,
       2,     0,     1,     1,     3,     1,     1,     1,     2,     2,
       2,     2,     2,     3,     4,     5,     7,     0,     9,     4,
       3,     3,     1,     1,     3,     2,     3,     1,     1,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     3,     3,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     3,     1,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 125 "Parser.y" /* yacc.c:1646  */
    {strcpy((yyval.token)._byid," PROGRAM ");strcpy((yyval.token)._byname," PROGRAM ");strcat((yyval.token)._byid,(yyvsp[0].token)._byid);strcat((yyval.token)._byname,(yyvsp[0].token)._byname);

                                   strcpy((yyval.token)._asm,"\n.data");
                                   strcat((yyval.token)._asm,"\n\tbackn: .asciiz \"\\n\"");
                                   strcat((yyval.token)._asm,"\n.text");
                                   strcat((yyval.token)._asm,"\n.globl main");
                                   strcat((yyval.token)._asm,(yyvsp[0].token)._asm);

                                                                     
                                     if (out==1) {
                                        cout << "\n\n\n[+] Parse : \n\n"<<(yyval.token)._byid;
                                        cout << endl << endl << endl << "[+] ASM :" << (yyval.token)._asm << endl;
                                     }
                                     else if (out == 0)
                                          cout << "\n[+] Parse : \n"<<(yyval.token)._byname;
                                     else
                                        MyFile<<"[-] ERROR IN OUTPUT TYPE : WRONG OPTION";

                                   


                                    }
#line 1501 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "Parser.y" /* yacc.c:1646  */
    {  
                                                                                                                   
                                                                                                                   strcpy((yyval.token)._byid," globalVars ");
                                                                                                                   //strcat($$._byid,to_string(scopeNo).c_str());
                                                                                                                   strcat((yyval.token)._byid,(yyvsp[-5].token)._byid);
                                                                                                                   strcat((yyval.token)._byid,(yyvsp[-4].token)._byid);
                                                                                                                   strcat((yyval.token)._byid," = ");
                                                                                                                   strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                                   strcat((yyval.token)._byid," ; ");
                                                                                                                   strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                                                                     string tmp;
                                                                                                                   tmp ="\n" + string((yyvsp[-4].token)._val) +":\t .long \t" + string((yyvsp[-2].token)._val);
                                                                                                                   strcat((yyval.token)._asm,tmp.c_str());

                                                                                                                   strcat((yyval.token)._asm,(yyvsp[0].token)._asm);

                                                                                                                   strcpy((yyval.token)._byname," globalVars ");
                                                                                                                   strcat((yyval.token)._byname,(yyvsp[-5].token)._byname);
                                                                                                                   strcat((yyval.token)._byname,(yyvsp[-4].token)._byname);
                                                                                                                   strcat((yyval.token)._byname," TOKEN_ASSIGNOP ");
                                                                                                                   strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                                                                   strcat((yyval.token)._byname," TOKEN_SEMICOLON ");
                                                                                                                   strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                                                                   
                                                                                                                   if ( (yyvsp[-5].token)._datatype == 5) 
                                                                                                                        yyerror("variable cant be of type VOID"); }
#line 1533 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 179 "Parser.y" /* yacc.c:1646  */
    {strcpy((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                                                                   strcpy((yyval.token)._byname,(yyvsp[0].token)._byname);strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);}
#line 1540 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 183 "Parser.y" /* yacc.c:1646  */
    { 

                            func_type = current_dtype;
                            is_declaration = 0;
                            

                        }
#line 1552 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 190 "Parser.y" /* yacc.c:1646  */
    {prevscopeNo = scopeNo; scopeNo = rand();scopeVars[scopeNo]=0; }
#line 1558 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 190 "Parser.y" /* yacc.c:1646  */
    {
                          
                                            is_declaration = 0;
							          is_func = 1;

                        }
#line 1569 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 195 "Parser.y" /* yacc.c:1646  */
    {is_func = 0; if ((yyvsp[-7].token)._datatype != 1 )yyerror("main function must be of type INT");
                        
                                             strcpy((yyval.token)._byid," main_function ");
                                             strcat((yyval.token)._byid,(yyvsp[-7].token)._byid);
                                             strcat((yyval.token)._byid," main ");
                                             strcat((yyval.token)._byid," ( ");
                                             strcat((yyval.token)._byid," ) ");
                                             strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                             strcpy((yyval.token)._asm,"\nmain :");
                                             char tmp[200];
                                             sprintf(tmp,"\n\tdaddiu  $sp,$sp,-%d",(scopeVars[(yyvsp[0].token)._scopeNo]+2)*4);
                                             strcat((yyval.token)._asm,tmp);
                                             string s = "\n\tsd      $fp,"+to_string(scopeVars[(yyvsp[0].token)._scopeNo]*4)+"($sp)";
                                             strcat((yyval.token)._asm,s.c_str());
                                             strcat((yyval.token)._asm,"\n\tmove    $fp,$sp");

                                             strcat((yyval.token)._asm,(yyvsp[0].token)._asm);

                                             strcat((yyval.token)._asm,"\n\tmove    $v0,$0");
                                             strcat((yyval.token)._asm,"\n\tmove    $sp,$fp");
                                             s = "\n\tld      $fp,"+to_string(scopeVars[(yyvsp[0].token)._scopeNo]*4)+"($sp)";
                                             strcat((yyval.token)._asm,s.c_str());
                                             s = "\n\tdaddiu  $sp,$sp," + to_string((scopeVars[(yyvsp[0].token)._scopeNo]+2)*4);
                                             strcat((yyval.token)._asm,s.c_str());
                                             strcat((yyval.token)._asm,"\n\tj       $31");
                                             strcat((yyval.token)._asm,"\n\tnop");
                                             
                                             strcpy((yyval.token)._byname," main_function ");
                                             strcat((yyval.token)._byname,(yyvsp[-7].token)._byname);
                                             strcat((yyval.token)._byname," TOKEN_MAINFINC  ");
                                             strcat((yyval.token)._byname," TOKEN_LEFTPARAN ");
                                             strcat((yyval.token)._byname," TOKEN_RIGHTPARAN ");
                                             strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                        
                                         }
#line 1610 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 231 "Parser.y" /* yacc.c:1646  */
    {

                            func_type = current_dtype;
                            is_declaration = 0;
                            (yyvsp[0].token)._datatype=(yyvsp[-1].token)._datatype;

                        }
#line 1622 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 237 "Parser.y" /* yacc.c:1646  */
    {prevscopeNo = scopeNo; scopeNo = rand();scopeVars[scopeNo]=0;is_func = 1; }
#line 1628 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 237 "Parser.y" /* yacc.c:1646  */
    {
                          
                                            is_declaration = 0;
									
                                             (yyvsp[-5].token)._cnt=(yyvsp[-1].token)._cnt;
                                            umap[(yyvsp[-5].token)._val].cnt=(yyvsp[-5].token)._cnt;

                        }
#line 1641 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 245 "Parser.y" /* yacc.c:1646  */
    {is_func = 0;}
#line 1647 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 245 "Parser.y" /* yacc.c:1646  */
    {

                                            strcpy((yyval.token)._byid," function ");
                                             strcat((yyval.token)._byid,(yyvsp[-10].token)._byid);
                                             strcat((yyval.token)._byid,(yyvsp[-9].token)._byid);
                                             strcat((yyval.token)._byid," ( ");
                                             strcat((yyval.token)._byid,(yyvsp[-5].token)._byid);
                                             strcat((yyval.token)._byid," ) ");
                                             strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                             strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                             string s;
                                             s = "\n" + string((yyvsp[-9].token)._val) + ":";
                                             strcpy((yyval.token)._asm,s.c_str());
                                             char tmp[200];
                                             sprintf(tmp,"\n\tdaddiu  $sp,$sp,-%d",(scopeVars[(yyvsp[-2].token)._scopeNo]+2)*4);
                                             strcat((yyval.token)._asm,tmp);
                                             s = "\n\tsd      $fp,"+to_string(scopeVars[(yyvsp[-2].token)._scopeNo]*4)+"($sp)";
                                             strcat((yyval.token)._asm,s.c_str());
                                             strcat((yyval.token)._asm,"\n\tmove    $fp,$sp");
                                             cout << "debug-c->" << umap[(yyvsp[-9].token)._val].cnt << endl;
                                             for(int i=0;i<umap[(yyvsp[-9].token)._val].cnt;i++) {
                                                  string s = "\n\tsw  $a" + to_string(i) + "," + to_string(i*4) + "($fp)";
                                                  strcat((yyval.token)._asm,s.c_str());
                                             }

                                             strcat((yyval.token)._asm,(yyvsp[-2].token)._asm);

                                             strcat((yyval.token)._asm,"\n\tmove    $sp,$fp");
                                             s = "\n\tld      $fp,"+to_string(scopeVars[(yyvsp[-2].token)._scopeNo]*4)+"($sp)";
                                             strcat((yyval.token)._asm,s.c_str());
                                             s = "\n\tdaddiu  $sp,$sp," + to_string((scopeVars[(yyvsp[-2].token)._scopeNo]+2)*4);
                                             strcat((yyval.token)._asm,s.c_str());
                                             strcat((yyval.token)._asm,"\n\tj       $31");
                                             strcat((yyval.token)._asm,"\n\tnop");

                                             strcat((yyval.token)._asm,(yyvsp[0].token)._asm);

                                             
                                             
                                             
                                             strcpy((yyval.token)._byname," function ");
                                             strcat((yyval.token)._byname,(yyvsp[-10].token)._byname);
                                             strcat((yyval.token)._byname,(yyvsp[-9].token)._byname);
                                             strcat((yyval.token)._byname," TOKEN_LEFTPARAN ");
                                             strcat((yyval.token)._byname,(yyvsp[-5].token)._byname);
                                             strcat((yyval.token)._byname," TOKEN_RIGHTPARAN ");
                                             strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                             strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                      }
#line 1702 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 297 "Parser.y" /* yacc.c:1646  */
    {if((yyval.token)._cnt > 4) yyerror("too many arguments");
                                                              strcpy((yyval.token)._byid," argumentList "); 
                                                              strcpy((yyval.token)._byname," argumentList "); 
                                                              strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                              strcat((yyval.token)._byid, (yyvsp[0].token)._byid);
                                                             }
#line 1713 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 303 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._cnt=0;}
#line 1719 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 306 "Parser.y" /* yacc.c:1646  */
    { (yyval.token)._cnt=(yyval.token)._cnt+1;
                                                              strcpy((yyval.token)._byid," arguments "); 
                                                              strcpy((yyval.token)._byname," arguments "); 
                                                              strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                              strcat((yyval.token)._byid, (yyvsp[-2].token)._byid); 
                                                              strcat((yyval.token)._byname,"TOKEN_COMMA");
                                                              strcat((yyval.token)._byid," , "); 
                                                              strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                              strcat((yyval.token)._byid, (yyvsp[0].token)._byid);

                                                            }
#line 1735 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 320 "Parser.y" /* yacc.c:1646  */
    { (yyval.token)._cnt=1;
                                                              strcpy((yyval.token)._byid," arg "); 
                                                              strcpy((yyval.token)._byname," arg "); 
                                                              strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                              strcat((yyval.token)._byid, (yyvsp[-1].token)._byid); 
                                                              strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                              strcat((yyval.token)._byid, (yyvsp[0].token)._byid);

                                                            }
#line 1749 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 329 "Parser.y" /* yacc.c:1646  */
    { (yyval.token)._cnt=1;
                                                                                strcpy((yyval.token)._byname," arg ");
                                                                                strcpy((yyval.token)._byid," arg "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-4].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-4].token)._byid); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-3].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-3].token)._byid);
                                                                                strcat((yyval.token)._byname," TOKEN_LB "); 
                                                                                strcat((yyval.token)._byid," [ ");
                                                                                strcat((yyval.token)._byname,(yyvsp[-1].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                                strcat((yyval.token)._byname," TOKEN_RB "); 
                                                                                strcat((yyval.token)._byid," ] ");

                                                                                if ((yyvsp[-1].token)._datatype != 1)
                                                                                     yyerror("array index must be of type integer");
                                   
                                                                              }
#line 1772 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 350 "Parser.y" /* yacc.c:1646  */
    { strcpy((yyvsp[-1].token)._byid," statements "); 
                                            strcpy((yyvsp[-1].token)._byname," statements "); 
                                            strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                            strcat((yyval.token)._byid, (yyvsp[-1].token)._byid); 
                                            strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                            strcat((yyval.token)._byid, (yyvsp[0].token)._byid);
                                             // strcat($$._asm,$1._asm);
                                             strcat((yyval.token)._asm,(yyvsp[0].token)._asm);

                                          }
#line 1787 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 363 "Parser.y" /* yacc.c:1646  */
    {
                                        strcpy((yyval.token)._byid," stmt "); 
                                        strcpy((yyval.token)._byname," stmt "); 
                                        strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                        strcat((yyval.token)._byid, (yyvsp[0].token)._byid);   
                                     }
#line 1798 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 369 "Parser.y" /* yacc.c:1646  */
    {
                                        strcpy((yyval.token)._byid," stmt "); 
                                        strcat((yyval.token)._byid,to_string(scopeNo).c_str());
                                        strcpy((yyval.token)._byname," stmt "); 
                                        strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                        strcat((yyval.token)._byid, (yyvsp[0].token)._byid);  
                                        strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);

                                     }
#line 1812 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 380 "Parser.y" /* yacc.c:1646  */
    {
                                                                      strcpy((yyval.token)._byid," compoundStmt "); 
                                                                      strcpy((yyval.token)._byname," compoundStmt "); 
                                                                      strcat((yyval.token)._byname," TOKEN_LCB ");
                                                                      strcat((yyval.token)._byid," { ");
                                                                      
                                                                      strcat((yyval.token)._byid,to_string(scopeNo).c_str());
                                                                      strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                                      strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);                                                                           
                                                                      strcat((yyval.token)._byid," } "); 
                                                                      strcat((yyval.token)._byname," TOKEN_RCB "); 
                                                                      strcpy((yyval.token)._asm,(yyvsp[-1].token)._asm);
                                                                      (yyval.token)._scopeNo = scopeNo;
                                                                      scopeNo = prevscopeNo;
                                                                    }
#line 1832 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 399 "Parser.y" /* yacc.c:1646  */
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[0].token)._byid);   
                                                            strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                            prevscopeNo = scopeNo; scopeNo = rand();scopeVars[scopeNo]=0;
                                                            conditionNo++;

                                                       }
#line 1847 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 409 "Parser.y" /* yacc.c:1646  */
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[0].token)._byid); 
                                                            strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                            prevscopeNo = scopeNo; scopeNo = rand();scopeVars[scopeNo]=0;
                                                            loopNo++;  
                                                       }
#line 1861 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 418 "Parser.y" /* yacc.c:1646  */
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[0].token)._byid); 
                                                            strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                            

                                                       }
#line 1875 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 427 "Parser.y" /* yacc.c:1646  */
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[-1].token)._byid);                                                                           
                                                            strcat((yyval.token)._byid," ; "); 
                                                            strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");  

                                                       }
#line 1889 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 436 "Parser.y" /* yacc.c:1646  */
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[-1].token)._byid);                                                                           
                                                            strcat((yyval.token)._byid," ; "); 
                                                            strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");  
                                                            strcpy((yyval.token)._asm,(yyvsp[-1].token)._asm);

                                                       }
#line 1904 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 446 "Parser.y" /* yacc.c:1646  */
    {
                              strcpy((yyval.token)._byid," singleStmt "); 
                              strcpy((yyval.token)._byname," singleStmt "); 
                              strcat((yyval.token)._byname," TOKEN_RETURN ");
                              strcat((yyval.token)._byid," return ");                                                                           
                              strcat((yyval.token)._byid," ; "); 
                              strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");
                            if(is_func)
                            {
                              if(func_type != 5)
                                yyerror("return type (VOID) does not match function type");
                            }
                            else yyerror("return statement not inside function definition");
                          
                        }
#line 1924 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 461 "Parser.y" /* yacc.c:1646  */
    {if(!is_loop)    { yyerror("Illegal use of continue");}
                                                                                strcpy((yyval.token)._byid," singleStmt "); 
                                                                                strcpy((yyval.token)._byname," singleStmt "); 
                                                                                strcat((yyval.token)._byname," TOKEN_CONTINUESTMT ");
                                                                                strcat((yyval.token)._byid," continue ");                                                                           
                                                                                strcat((yyval.token)._byid," ; "); 
                                                                                strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");
                                                                              }
#line 1937 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 469 "Parser.y" /* yacc.c:1646  */
    {if(!is_loop) { yyerror("Illegal use of break");}
                                                                                strcpy((yyval.token)._byid," singleStmt "); 
                                                                                strcpy((yyval.token)._byname," singleStmt "); 
                                                                                strcat((yyval.token)._byname," TOKEN_BREAKSTMT ");
                                                                                strcat((yyval.token)._byid," break ");                                                                           
                                                                                strcat((yyval.token)._byid," ; "); 
                                                                                strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");
                                                                }
#line 1950 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 477 "Parser.y" /* yacc.c:1646  */
    {                   
                                                                           strcpy((yyval.token)._byid," singleStmt "); 
                                                                           strcpy((yyval.token)._byname," singleStmt "); 
                                                                           strcat((yyval.token)._byname,"TOKEN_RETURN");
                                                                           strcat((yyval.token)._byid,"return");
                                                                           strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                                           strcat((yyval.token)._byid," ; "); 
                                                                           strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");


                                                                           if(is_func)
                                                                           {
                                                                                if(func_type != (yyvsp[-1].token)._datatype)
                                                                                     yyerror("return type does not match function type");
                                                                           }
                                                                           else yyerror("return statement not in function definition");
                                                                           if((yyvsp[-1].token)._isVar == 2) {
                                                                                string tmp = "\n\tlw     $t0,"+to_string((yyvsp[-1].token)._stackPlace*4) + "($fp)";
                                                                                strcpy((yyval.token)._asm,tmp.c_str());
                                                                           } else {
                                                                                strcpy((yyval.token)._asm,(yyvsp[-1].token)._asm);

                                                                           }
                                                                           strcat((yyval.token)._asm,"\n\tmove $t0,$v0");

                                                                           
                        }
#line 1983 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 508 "Parser.y" /* yacc.c:1646  */
    {

                                                                                     string tmp = "\n\tlw     $a0,"+to_string((yyvsp[-1].token)._stackPlace*4) + "($fp)";
                                                                                     
                                                                                     strcpy((yyval.token)._asm,(yyvsp[-1].token)._asm);
                                                                                     strcpy((yyval.token)._asm,tmp.c_str());
                                                                                     strcat((yyval.token)._asm,"\n\tli   $v0,1");
                                                                                     strcat((yyval.token)._asm,"\n\tsyscall");
                                                                                     strcpy((yyval.token)._byid," printFunc "); 
                                                                                     strcpy((yyval.token)._byname," printFunc "); 
                                                                                     strcat((yyval.token)._byid,(yyvsp[-3].token)._byid);
                                                                                     strcat((yyval.token)._byname,(yyvsp[-3].token)._byname);
                                                                                     strcat((yyval.token)._byname," TOKEN_LEFTPAREN "); 
                                                                                     strcat((yyval.token)._byid," ( ");
                                                                                     strcat((yyval.token)._byname,(yyvsp[-1].token)._byname); 
                                                                                     strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                                     strcat((yyval.token)._byname," TOKEN_RIGHTPAREN "); 
                                                                                     strcat((yyval.token)._byid," ) ");                                                           
                                                                                    }
#line 2007 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 532 "Parser.y" /* yacc.c:1646  */
    {
                                                                                                                                                  strcpy((yyval.token)._byid," conditionStmt "); 
                                                                                                                                                 strcpy((yyval.token)._byname," conditionStmt "); 
                                                                                                                                                 strcat((yyval.token)._byid," if "); 
                                                                                                                                                 strcat((yyval.token)._byname," TOKEN_IFCONDITION ");
                                                                                                                                                 strcat((yyval.token)._byname," TOKEN_LEFTPAREN "); 
                                                                                                                                                 strcat((yyval.token)._byid," ( ");
                                                                                                                                                 strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                                                                 strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                                                                                                 strcat((yyval.token)._byname," TOKEN_RIGHTPAREN "); 
                                                                                                                                                 strcat((yyval.token)._byid," ) ");
                                                                                                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                                                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                                                                                                 
                                                                                                                                                 string s;
                                                                                                                                                 s = "\nC" + to_string(conditionNo) + ":";
                                                                                                                                                 strcpy((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                                                                                                 strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                                                                                                 strcat((yyval.token)._asm,s.c_str());
                                                                                                                                             }
#line 2032 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 552 "Parser.y" /* yacc.c:1646  */
    {
                                                                                                                                                 strcpy((yyval.token)._byid," conditionStmt "); 
                                                                                                                                                 strcpy((yyval.token)._byname," conditionStmt "); 
                                                                                                                                                 strcat((yyval.token)._byid," if "); 
                                                                                                                                                 strcat((yyval.token)._byname," TOKEN_IFCONDITION ");
                                                                                                                                                 strcat((yyval.token)._byname," TOKEN_LEFTPAREN "); 
                                                                                                                                                 strcat((yyval.token)._byid," ( ");
                                                                                                                                                 strcat((yyval.token)._byid,(yyvsp[-4].token)._byid);
                                                                                                                                                 strcat((yyval.token)._byname,(yyvsp[-4].token)._byname);
                                                                                                                                                 strcat((yyval.token)._byname," TOKEN_RIGHTPAREN "); 
                                                                                                                                                 strcat((yyval.token)._byid," ) ");
                                                                                                                                                 strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                                                                 strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                                                                                                 strcat((yyval.token)._byname," TOKEN_ELSECONDITION "); 
                                                                                                                                                 strcat((yyval.token)._byid," else ");
                                                                                                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                                                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                                                                                                 
                                                                                                                                                 string s;
                                                                                                                                                 strcpy((yyval.token)._asm,(yyvsp[-4].token)._asm);
                                                                                                                                                 strcat((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                                                                                                 s = "\n\tb     C"+to_string(++conditionNo);
                                                                                                                                                 strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                 strcat((yyval.token)._asm,"\n\tnop");
                                                                                                                                                 s = "\nC"+to_string(conditionNo-1);
                                                                                                                                                 strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                 strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                                                                                                 s = "\nC" + to_string(conditionNo) + ":";
                                                                                                                                                 strcat((yyval.token)._asm,s.c_str());
                                                                                                                                            

                                                                                                                                             }
#line 2069 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 587 "Parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 2075 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 587 "Parser.y" /* yacc.c:1646  */
    {is_loop = 0;
                                                                                                                                                      strcpy((yyval.token)._byid," loopStmt "); 
                                                                                                                                                      strcpy((yyval.token)._byname," loopStmt "); 
                                                                                                                                                      strcat((yyval.token)._byid," foreach "); 
                                                                                                                                                      strcat((yyval.token)._byname," TOKEN_LOOP ");
                                                                                                                                                      strcat((yyval.token)._byid,(yyvsp[-7].token)._byid);
                                                                                                                                                      strcat((yyval.token)._byname,(yyvsp[-7].token)._byname);
                                                                                                                                                      strcat((yyval.token)._byname," TOKEN_LEFTPAREN "); 
                                                                                                                                                      strcat((yyval.token)._byid," ( ");
                                                                                                                                                      strcat((yyval.token)._byid,(yyvsp[-5].token)._byid);
                                                                                                                                                      strcat((yyval.token)._byname,(yyvsp[-5].token)._byname);
                                                                                                                                                      strcat((yyval.token)._byname," TOKEN_UNTIL "); 
                                                                                                                                                      strcat((yyval.token)._byid," .. ");
                                                                                                                                                      strcat((yyval.token)._byid,(yyvsp[-3].token)._byid);
                                                                                                                                                      strcat((yyval.token)._byname,(yyvsp[-3].token)._byname);
                                                                                                                                                      strcat((yyval.token)._byname," TOKEN_RIGHTPAREN "); 
                                                                                                                                                      strcat((yyval.token)._byid," ) ");
                                                                                                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                                                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname);

                                                                                                                                                      string s;
                                                                                                                                                      s = "\nL" + to_string(++loopNo) + ":";
                                                                                                                                                      strcpy((yyval.token)._asm,s.c_str());
                                                                                                                                                      s = "\n\tli    $s0," + to_string((yyvsp[-5].token)._numVal);
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                      s = "\n\tli    $s1," + to_string((yyvsp[-3].token)._numVal);
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                      s = "\n\tbgt   $s0,$s1,L" + to_string(loopNo-1);
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                      s = "\n\tnop";
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());

                                                                                                                                                      s = "\n\tsw    $s0," + to_string((yyvsp[-7].token)._stackPlace*4) + "($fp)";
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                      strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                                                                                                      
                                                                                                                                                      s = "\n\taddiu $s0,$s0,1";
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                      s = "\n\tsw    $s0," + to_string((yyvsp[-7].token)._stackPlace*4) + "($fp)";
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                      s = "\n\tb     L" + to_string(loopNo);
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                      s = "\n\tnop";
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());
                                                                                                                                                      s = "\nL" + to_string(loopNo-1);
                                                                                                                                                      strcat((yyval.token)._asm,s.c_str());


                                                                                                                                                    }
#line 2129 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 639 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[-3].token)._datatype;
                                                                                               strcpy((yyval.token)._byid," functionCall "); 
                                                                                               strcpy((yyval.token)._byname," functionCall "); 
                                                                                               strcat((yyval.token)._byid,(yyvsp[-3].token)._byid);
                                                                                               strcat((yyval.token)._byname,(yyvsp[-3].token)._byname);
                                                                                               strcat((yyval.token)._byname," TOKEN_LEFTPAREN "); 
                                                                                               strcat((yyval.token)._byid," ( ");
                                                                                               strcat((yyval.token)._byname,(yyvsp[-1].token)._byname); 
                                                                                               strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                                               strcat((yyval.token)._byname," TOKEN_RIGHTPAREN "); 
                                                                                               strcat((yyval.token)._byid," ) ");
                                                                                               string s ((yyvsp[-3].token)._val);
                                                                                     
                                                                                               if(umap[s].cnt!=(yyvsp[-1].token)._cnt)
                                                                                                     yyerror("function arguments count mismatch");
                                                                                               
                                                                                               // cout << "debug-p->" << $3._asm << endl;
                                                                                               strcpy((yyval.token)._asm,(yyvsp[-1].token)._asm);
                                                                                               s = "\n\tjal " + string((yyvsp[-3].token)._val);
                                                                                               strcat((yyval.token)._asm,s.c_str());

                                                                                          }
#line 2156 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 661 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                                     string s ((yyvsp[-2].token)._val);
                                                                                     if(umap[s].cnt != 0)
                                                                                          yyerror("function arguments missing");
                        
                                                                                     strcpy((yyval.token)._byid," functionCall "); 
                                                                                     strcpy((yyval.token)._byname," functionCall "); 
                                                                                     strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                     strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                                     strcat((yyval.token)._byname," TOKEN_LEFTPAREN "); 
                                                                                     strcat((yyval.token)._byid," ( ");
                                                                                     strcat((yyval.token)._byname," TOKEN_RIGHTPAREN "); 
                                                                                     strcat((yyval.token)._byid," ) ");

                                                                                     s = "\n\tjal " + string((yyvsp[-2].token)._val);
                                                                                     strcpy((yyval.token)._asm,s.c_str());
                                                                                     
                                                                                     }
#line 2179 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 681 "Parser.y" /* yacc.c:1646  */
    {
                                                                           strcpy((yyval.token)._byid," parameter_list "); 
                                                                           strcpy((yyval.token)._byname," parameter_list "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                           strcat((yyval.token)._byname," TOKEN_COMMA "); 
                                                                           strcat((yyval.token)._byid," , ");
                                                                           strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                           strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                           (yyval.token)._cnt++;
                                                                           cout<<"::::"<<(yyval.token)._cnt<<"::::";

                                                                           strcpy((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                           // strcat($$._asm,$3._asm);
                                                                           string s;
                                                                           if((yyvsp[0].token)._isVar == 1) {
                                                                                s = "\n\tli  $t0," + to_string((yyvsp[0].token)._numVal);
                                                                                strcat((yyval.token)._asm,s.c_str());
                                                                                
                                                                           } else if((yyvsp[0].token)._isVar == 2) {
                                                                                 s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                                strcat((yyval.token)._asm,s.c_str());
                                                                                
                                                                           } else {
                                                                                strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                           }
                                                                           s = "\n\tmove $t0,a" + to_string((yyval.token)._cnt);
                                                                                strcat((yyval.token)._asm,s.c_str());
                                                                           // if($3._isVar == 1) {
                                                                           //      string s = "\n\tli  $4," + to_string($3._numVal);
                                                                           //      strcpy($$._asm,s.c_str());
                                                                           // } else {
                                                                           //      strcpy($$._asm,$3._asm);
                                                                           // }
                                                                        }
#line 2219 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 716 "Parser.y" /* yacc.c:1646  */
    {  strcpy((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                           strcpy((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                           (yyval.token)._cnt=1;
                                                                           string s;
                                                                           if((yyvsp[0].token)._isVar == 1) {
                                                                                 s = "\n\tli  $t0," + to_string((yyvsp[0].token)._numVal);
                                                                                strcat((yyval.token)._asm,s.c_str());
                                                                                
                                                                           } else if((yyvsp[0].token)._isVar == 2) {
                                                                                 s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                                strcat((yyval.token)._asm,s.c_str());
                                                                           } else {
                                                                                strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                           }
                                                                           s = "\n\tmove $t0,a" + to_string((yyval.token)._cnt);
                                                                           strcat((yyval.token)._asm,s.c_str());
                                                                                // strcpy($$._asm,$1._asm);
                                                                        }
#line 2242 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 736 "Parser.y" /* yacc.c:1646  */
    {
                                                                           strcpy((yyval.token)._byid," parameter "); 
                                                                           strcpy((yyval.token)._byname," parameter "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                           strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                        }
#line 2254 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 746 "Parser.y" /* yacc.c:1646  */
    {  is_declaration = 0;
                                                                           strcpy((yyval.token)._byid," declaration "); 
                                                                           strcpy((yyval.token)._byname," declaration "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                           strcat((yyval.token)._byname,(yyvsp[-1].token)._byname); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                           strcat((yyval.token)._byname,"TOKEN_SEMICOLON"); 
                                                                           strcat((yyval.token)._byid," ; ");
                                                                 strcpy((yyval.token)._asm,(yyvsp[-1].token)._asm);



                                                                        }
#line 2273 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 760 "Parser.y" /* yacc.c:1646  */
    {
                                                                           is_declaration = 0;
                                                                           strcpy((yyval.token)._byid," declaration "); 
                                                                           strcpy((yyval.token)._byname," declaration "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                                           strcat((yyval.token)._byname,"TOKEN_SEMICOLON"); 
                                                                           strcat((yyval.token)._byid," ; ");
                                                                 strcpy((yyval.token)._asm,(yyvsp[-1].token)._asm);


                                                                        }
#line 2290 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 774 "Parser.y" /* yacc.c:1646  */
    {  (yyvsp[0].token)._datatype=(yyval.token)._datatype;
                                                                           strcpy((yyval.token)._byid," declaration_list "); 
                                                                           strcpy((yyval.token)._byname," declaration_list "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                           strcat((yyval.token)._byname," TOKEN_COMMA "); 
                                                                           strcat((yyval.token)._byid," , ");
                                                                           strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                           strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                        }
#line 2305 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 784 "Parser.y" /* yacc.c:1646  */
    {  (yyvsp[0].token)._datatype=(yyval.token)._datatype;
                                                                           strcpy((yyval.token)._byid," declaration_list "); 
                                                                           strcpy((yyval.token)._byname," declaration_list "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                           strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);


                                                                        }
#line 2319 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 795 "Parser.y" /* yacc.c:1646  */
    {
                                                                 strcpy((yyval.token)._byid," sub_decl "); 
                                                                 strcpy((yyval.token)._byname," sub_decl "); 
                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                 strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                            }
#line 2331 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 802 "Parser.y" /* yacc.c:1646  */
    {
                                                                 strcpy((yyval.token)._byid," sub_decl "); 
                                                                 strcpy((yyval.token)._byname," sub_decl "); 
                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            }
#line 2342 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 808 "Parser.y" /* yacc.c:1646  */
    {
                                                                 is_declaration = 1;
                                                                 
                                                                 strcpy((yyval.token)._byid," sub_decl "); 
                                                                 strcpy((yyval.token)._byname," sub_decl "); 
                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname);

                                                            }
#line 2356 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 821 "Parser.y" /* yacc.c:1646  */
    {
                                                                 strcpy((yyval.token)._byid," expression "); 
                                                                 strcpy((yyval.token)._byname," expression "); 
                                                                 strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                 strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                 strcat((yyval.token)._byname," TOKEN_COMMA "); 
                                                                 strcat((yyval.token)._byid," , ");
                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                            }
#line 2372 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 832 "Parser.y" /* yacc.c:1646  */
    {strcpy((yyval.token)._byid," expression ");
                                                             strcpy((yyval.token)._byname," sub_expr ");
                                                             strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                             strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                             strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);

                                                             (yyval.token)._numVal=(yyvsp[0].token)._numVal;
                                                            }
#line 2385 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 842 "Parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_GR "); 
                                                                      strcat((yyval.token)._byid," > ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                      if((yyvsp[-2].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                           strcpy((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[-2].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[-2].token)._numVal);
                                                                           strcpy((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcpy((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                      }
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t6");

                                                                      if((yyvsp[0].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                           strcat((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[0].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[0].token)._numVal);
                                                                           strcat((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                      }
                                                                      
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat((yyval.token)._asm,"\n\tble  $t6,$7,C");
                                                                      strcat((yyval.token)._asm,to_string(conditionNo).c_str());
                                                                      strcat((yyval.token)._asm,"\n\tnop");
                                                                      


                                                                    }
#line 2430 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 882 "Parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_LS "); 
                                                                      strcat((yyval.token)._byid," < ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                      if((yyvsp[-2].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                           strcpy((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[-2].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[-2].token)._numVal);
                                                                           strcpy((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcpy((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                      }
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t6");

                                                                      if((yyvsp[0].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                           strcat((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[0].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[0].token)._numVal);
                                                                           strcat((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                      }
                                                                      
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat((yyval.token)._asm,"\n\tbge  $t6,$7,C");
                                                                      strcat((yyval.token)._asm,to_string(conditionNo).c_str());
                                                                      strcat((yyval.token)._asm,"\n\tnop");
                                                                      
                                                                    }
#line 2473 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 920 "Parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_EQ "); 
                                                                      strcat((yyval.token)._byid," = ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                      if((yyvsp[-2].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                           strcpy((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[-2].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[-2].token)._numVal);
                                                                           strcpy((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcpy((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                      }
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t6");

                                                                      if((yyvsp[0].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                           strcat((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[0].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[0].token)._numVal);
                                                                           strcat((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                      }
                                                                      
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat((yyval.token)._asm,"\n\tbne  $t6,$7,C");
                                                                      strcat((yyval.token)._asm,to_string(conditionNo).c_str());
                                                                      strcat((yyval.token)._asm,"\n\tnop");
                                                                    }
#line 2515 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 957 "Parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_NOTEQ "); 
                                                                      strcat((yyval.token)._byid," != ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                      if((yyvsp[-2].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                           strcpy((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[-2].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[-2].token)._numVal);
                                                                           strcpy((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcpy((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                      }
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t6");

                                                                      if((yyvsp[0].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                           strcat((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[0].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[0].token)._numVal);
                                                                           strcat((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                      }
                                                                      
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat((yyval.token)._asm,"\n\tbeq  $t6,$7,C");
                                                                      strcat((yyval.token)._asm,to_string(conditionNo).c_str());
                                                                      strcat((yyval.token)._asm,"\n\tnop");
                                                                    }
#line 2557 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 994 "Parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_LSEQ "); 
                                                                      strcat((yyval.token)._byid," <= ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                      if((yyvsp[-2].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                           strcpy((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[-2].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[-2].token)._numVal);
                                                                           strcpy((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcpy((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                      }
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t6");

                                                                      if((yyvsp[0].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                           strcat((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[0].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[0].token)._numVal);
                                                                           strcat((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                      }
                                                                      
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat((yyval.token)._asm,"\n\tbgt  $t6,$7,C");
                                                                      strcat((yyval.token)._asm,to_string(conditionNo).c_str());
                                                                      strcat((yyval.token)._asm,"\n\tnop");
                                                                    }
#line 2599 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1031 "Parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_GREQ "); 
                                                                      strcat((yyval.token)._byid," >= ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                      if((yyvsp[-2].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                           strcpy((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[-2].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[-2].token)._numVal);
                                                                           strcpy((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcpy((yyval.token)._asm,(yyvsp[-2].token)._asm);
                                                                      }
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t6");

                                                                      if((yyvsp[0].token)._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                           strcat((yyval.token)._asm,s.c_str());     
                                                                      } else if((yyvsp[0].token)._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string((yyvsp[0].token)._numVal);
                                                                           strcat((yyval.token)._asm,s.c_str());
                                                                      } else {
                                                                           strcat((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                      }
                                                                      
                                                                      strcat((yyval.token)._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat((yyval.token)._asm,"\n\tblt  $t6,$7,C");
                                                                      strcat((yyval.token)._asm,to_string(conditionNo).c_str());
                                                                      strcat((yyval.token)._asm,"\n\tnop");
                                                                    }
#line 2641 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1068 "Parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname,"TOKEN_LOGICAND"); 
                                                                      strcat((yyval.token)._byid," && ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                    }
#line 2656 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1078 "Parser.y" /* yacc.c:1646  */
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_LOGICOR "); 
                                                                      strcat((yyval.token)._byid," || ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                    }
#line 2671 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1088 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;
                                                                     strcpy((yyval.token)._byid," sub_expr ");
                                                                     strcpy((yyval.token)._byid," TOKEN_LOGICNOT ");
                                                                     strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                     strcat((yyval.token)._byname," sub_expr ");
                                                                     strcat((yyval.token)._byname," ! ");
                                                                     strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                    }
#line 2684 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1096 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;
                                                                     strcpy((yyval.token)._byname," sub_expr ");
                                                                     strcpy((yyval.token)._byid," sub_expr ");
                                                                     strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                     strcat((yyval.token)._byname,(yyvsp[0].token)._byname);

                                                                     (yyval.token)._numVal=(yyvsp[0].token)._numVal;
                        
                                                                    }
#line 2698 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1105 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;
                                                                     strcpy((yyval.token)._byname," sub_expr ");
                                                                     strcpy((yyval.token)._byid," sub_expr ");
                                                                     strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                     strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                     strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                    }
#line 2710 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1115 "Parser.y" /* yacc.c:1646  */
    {rhs=1;}
#line 2716 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1117 "Parser.y" /* yacc.c:1646  */
    { type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,1); (yyval.token)._datatype = (yyvsp[0].token)._datatype;rhs=0;
                                                                                                 strcpy((yyval.token)._byname," assignment_expr ");
                                                                                                 strcpy((yyval.token)._byid," assignment_expr "); 
                                                                                                 strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                 strcat((yyval.token)._byname,"TOKEN_ASSIGNOP"); 
                                                                                                 strcat((yyval.token)._byid,"=");
                                                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                                                 (yyvsp[-2].token)._numVal = (int)((yyvsp[0].token)._numVal);

                                                                                                 cout<<"***"<<(yyvsp[-2].token)._numVal<<"**";

                                                                                               char tmp2[200];
                                                                                               char tmp[200];
                                                                                               
                                                                                                    if((yyvsp[0].token)._isSingle) {
                                                                                                    if((yyvsp[0].token)._isVar == 1) {
                                                                                                         sprintf(tmp,"\n\tli      $t0,%d",(yyvsp[0].token)._numVal);
                                                                                                         strcpy((yyval.token)._asm,tmp);
                                                                                                         char tmp2[200];
                                                                                                         sprintf(tmp2,"\n\tsw      $t0,%d($fp)",((yyvsp[-2].token)._stackPlace)*4);
                                                                                                         strcat((yyval.token)._asm,tmp2);
                                                                                                    }
                                                                                                    if((yyvsp[0].token)._isVar == 2) {
                                                                                                          string s = "\n\tlw  $t0," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                                                          strcpy((yyval.token)._asm,s.c_str());
                                                                                                          s = "\n\tsw   $t0," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                                                          strcat((yyval.token)._asm,s.c_str());
                                                                                                    }
                                                                                                    } else {
                                                                                                         strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                                                         sprintf(tmp2,"\n\tsw     $t0,%d($fp)",((yyvsp[-2].token)._stackPlace)*4);
                                                                                                         strcat((yyval.token)._asm,tmp2);
                                                                                                         clacStart = 0;
                                                                                                    }
                                                                                               
                                                                                               
                                                                                               
                                                                                               // char tmp[200];
                                                                                               // sprintf(tmp,"\n\tli      $2,%d",$1._numVal);
                                                                                               // strcpy($$._asm,tmp);
                                                                                               // char tmp2[200];
                                                                                               // sprintf(tmp2,"\n\tsw      $2,%d($fp)",($1._stackPlace-1)*4);
                                                                                               // strcat($$._asm,tmp2);
                                                                                               }
#line 2768 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1165 "Parser.y" /* yacc.c:1646  */
    { type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,1); (yyval.token)._datatype = (yyvsp[0].token)._datatype;rhs=0;
                                                                                                 strcpy((yyval.token)._byname," assignment_expr ");
                                                                                                 strcpy((yyval.token)._byid," assignment_expr "); 
                                                                                                 strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                 strcat((yyval.token)._byname,"TOKEN_ASSIGNOP"); 
                                                                                                 strcat((yyval.token)._byid,"=");
                                                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                                                 strcpy((yyval.token)._asm,(yyvsp[0].token)._asm);
                                                                                                 string s = "\n\tsw   $v0," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                                                 strcat((yyval.token)._asm,s.c_str());

                                                                                               }
#line 2788 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1180 "Parser.y" /* yacc.c:1646  */
    {
                              type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,1);
                              yyerror("cant be initialized");
                                                       
                                                  }
#line 2798 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1189 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;strcpy((yyval.token)._byid,(yyvsp[0].token)._byid);strcat((yyval.token)._byid,(yyvsp[0].token)._byname);(yyval.token)._stackPlace=(yyvsp[0].token)._stackPlace;}
#line 2804 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1190 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;strcpy((yyval.token)._byid,(yyvsp[0].token)._byid);strcat((yyval.token)._byid,(yyvsp[0].token)._byname);(yyval.token)._stackPlace=(yyvsp[0].token)._stackPlace;(yyval.token)._arrParam = (yyvsp[0].token)._arrParam;(yyval.token)._arrVar=(yyvsp[0].token)._arrVar;}
#line 2810 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1193 "Parser.y" /* yacc.c:1646  */
    {   
                                                       strcpy((yyval.token)._byname," identifier ");
                                                       strcpy((yyval.token)._byid," identifier "); 
                                                       strcat((yyval.token)._byname," TOKEN_ID "); 
                                                       strcat((yyval.token)._byid,(yyvsp[0].token)._val);
                                                       string s ((yyvsp[0].token)._val);
                                                       struct perScope temp;
                                                            if(is_declaration && !rhs)
                                                            {
                                                                 
                                                                 if ((umap.find(s) == umap.end())||((umap.find(s) != umap.end())&&(umap[s].scope!=scopeNo))) {
                                                                      if(is_func==1)
                                                                           scopeVars[scopeNo]=scopeVars[scopeNo]+1;
                                                                      temp.type=current_dtype;
                                                                      temp.scope=scopeNo;
                                                                      // temp.cnt=0;
                                                                      temp.stackPlace=scopeVars[scopeNo]-1;
                                                                      umap[s]= temp;
                                                                      (yyval.token)._datatype = umap[s].type;}
                                                                 else if ((umap.find(s) != umap.end())&&(umap[s].scope==scopeNo)){
                                                                      (yyval.token)._datatype = umap[s].type;
                                                                      yyerror("Redeclaration of variable");}
                                                                 

                                                                      
                                                            }
                                                            else
                                                            {
                                                                 (yyval.token)._datatype = umap[s].type;
                                                                 if((yyval.token)._datatype == 0) 
                                                                      yyerror("Variable not declared");
                                                            }
                                                            (yyval.token)._val = (yyvsp[0].token)._val;
                                                            (yyval.token)._stackPlace=umap[s].stackPlace;
                                                            

                                                  }
#line 2852 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1231 "Parser.y" /* yacc.c:1646  */
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_PLUS "); 
                                                                                strcat((yyval.token)._byid," + ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                                
                                                                                
                                                                                (yyval.token)._numVal = (int)((yyvsp[-2].token)._numVal+(yyvsp[0].token)._numVal);
                                                                                // cout<<"^^"<<$$._numVal<<"="<<$1._numVal<<"^^"<<$3._numVal<<"^^";


                                                                                if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
                                                                                else if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==3) || ((yyvsp[-2].token)._datatype==3 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 0;
                                                                                else if(((yyvsp[-2].token)._datatype==4 && (yyvsp[0].token)._datatype==4))
                                                                                     (yyval.token)._datatype = 4;
                                                                                else if(((yyvsp[-2].token)._datatype==6 && (yyvsp[0].token)._datatype==6))
                                                                                     (yyval.token)._datatype = 6;
                                                                                else if(((yyvsp[-2].token)._datatype==2 && (yyvsp[0].token)._datatype==2))
                                                                                     (yyval.token)._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                                
                                                                                (yyval.token)._isSingle = 0;
                                                                                string s;
                                                                                if(!clacStart) 
                                                                                     {cout << "li    $t0,0" << endl;clacStart = 1;
                                                                                          strcat((yyval.token)._asm,"\n\tli    $t0,0");
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 2) {

                                                                                          cout << "lw $2," << (yyvsp[-2].token)._stackPlace << "($fp)" << endl;
                                                                                          s = "\n\tlw    $t1," + to_string((yyvsp[-2].token)._stackPlace * 4) + "($fp)";
                                                                                          strcat((yyval.token)._asm,s.c_str());
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t2," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw   $t2," + to_string((yyvsp[0].token)._stackPlace * 4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               cout << "addu    $t0,$t2,$t1" << endl;
                                                                                               s = "\n\taddu    $t0,$t2,$t1";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               cout << "addiu   $4,$2," << (yyvsp[0].token)._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t1," + to_string((yyvsp[0].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          (yyval.token)._isVar = 3;
                                                                                          
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 1) {
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t1," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string((yyvsp[0].token)._stackPlace * 4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               
                                                                                               cout << "addiu   $t0,$t1," << (yyvsp[-2].token)._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t1," + to_string((yyvsp[-2].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               (yyval.token)._isVar = 3;
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               cout << "addiu   $t0,$0," << (yyval.token)._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$0," + to_string((yyval.token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               (yyval.token)._isVar = 1;
                                                                                          }
                                                                                          
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 3) {
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t1," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               
                                                                                               cout << "addu    $t0,$t1,$t0" << endl;
                                                                                               s = "\n\taddu    $t0,$t1,$t0";
                                                                                               strcat((yyval.token)._asm,s.c_str());

                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               cout << "addiu   $t0,$t0," << (yyvsp[0].token)._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t0," + to_string((yyvsp[0].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 3) {
                                                                                               cout << "addu   $t0,$t0,$t3" << endl;
                                                                                               s = "\n\taddu   $t0,$t0,$t3";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          (yyval.token)._isVar = 3;
                                                                                     }
                                                                                
                                                                                
                                                                                
                                                                                

                                                                                

                                                                            

                                                                           }
#line 2964 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1338 "Parser.y" /* yacc.c:1646  */
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_MINUS "); 
                                                                                strcat((yyval.token)._byid," - ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                                (yyval.token)._numVal = (int)((yyvsp[-2].token)._numVal-(yyvsp[0].token)._numVal);

                                                                                if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
                                                                                else if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==3) || ((yyvsp[-2].token)._datatype==3 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
                                                                                else if(((yyvsp[-2].token)._datatype==6 && (yyvsp[0].token)._datatype==6))
                                                                                     (yyval.token)._datatype = 6;
                                                                                else if(((yyvsp[-2].token)._datatype==2 && (yyvsp[0].token)._datatype==2))
                                                                                     (yyval.token)._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");

                                                                                (yyval.token)._isSingle = 0;
                                                                                string s;
                                                                                if(!clacStart) 
                                                                                     {cout << "li    $t0,0" << endl;clacStart = 1;
                                                                                          strcat((yyval.token)._asm,"\n\tli    $t0,0");
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 2) {

                                                                                          cout << "lw $2," << (yyvsp[-2].token)._stackPlace << "($fp)" << endl;
                                                                                          s = "\n\tlw    $t1," + to_string((yyvsp[-2].token)._stackPlace * 4) + "($fp)";
                                                                                          strcat((yyval.token)._asm,s.c_str());
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t2," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw   $t2," + to_string((yyvsp[0].token)._stackPlace * 4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               cout << "subu    $t0,$t2,$t1" << endl;
                                                                                               s = "\n\tsubu    $t0,$t2,$t1";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               cout << "addiu   $t0,$t1,-" << (yyvsp[0].token)._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t1,-" + to_string((yyvsp[0].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          (yyval.token)._isVar = 3;
                                                                                          
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 1) {
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t1," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string((yyvsp[0].token)._stackPlace * 4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               
                                                                                               cout << "addiu   $t0,$t1,-" << (yyvsp[-2].token)._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t1,-" + to_string((yyvsp[-2].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               (yyval.token)._isVar = 3;
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               cout << "addiu   $t0,$zero," << (yyval.token)._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$zero," + to_string((yyval.token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               (yyval.token)._isVar = 1;
                                                                                          }
                                                                                          
                                                                                          
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 3) {
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t1," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               
                                                                                               cout << "subu    $t0,$t1,$t0" << endl;
                                                                                               s = "\n\tsubu    $t0,$t1,$t0";
                                                                                               strcat((yyval.token)._asm,s.c_str());

                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               cout << "addiu   $t0,$t0,-" << (yyvsp[0].token)._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t0,-" + to_string((yyvsp[0].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 3) {
                                                                                               cout << "subu   $t0,$t0,$t3" << endl;
                                                                                               s = "\n\tsubu   $t0,$t0,$t3";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          (yyval.token)._isVar = 3;
                                                                                     }

                                                                           }
#line 3064 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1433 "Parser.y" /* yacc.c:1646  */
    {    
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_MUL "); 
                                                                                strcat((yyval.token)._byid," * ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                                (yyval.token)._numVal = (int)((yyvsp[-2].token)._numVal*(yyvsp[0].token)._numVal);

                                                                                if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
                                                                                else if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==3) || ((yyvsp[-2].token)._datatype==3 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
                                                                                else if(((yyvsp[-2].token)._datatype==6 && (yyvsp[0].token)._datatype==6))
                                                                                     (yyval.token)._datatype = 6;
                                                                                else if(((yyvsp[-2].token)._datatype==2 && (yyvsp[0].token)._datatype==2))
                                                                                     (yyval.token)._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");

                                                                                (yyval.token)._isSingle = 0;
                                                                                string s;
                                                                                if(!clacStart) 
                                                                                     {cout << "li    $t0,0" << endl;clacStart = 1;
                                                                                     s = "\n\tli    $t0,0";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 2) {
                                                                                          cout << "lw $t1," << (yyvsp[-2].token)._stackPlace << "($fp)" << endl;
                                                                                          s = "\n\tlw    $t1," + to_string((yyvsp[-2].token)._stackPlace*4) + "($fp)";
                                                                                          strcat((yyval.token)._asm,s.c_str());
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t2," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t2," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               cout << "mul    $t3,$t2,$t1" << endl;
                                                                                               s = "\n\tmul    $t3,$t2,$t1";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               cout << "li   $t4," << (yyvsp[0].token)._numVal << endl;
                                                                                               s = "\n\tli   $t4," + to_string((yyvsp[0].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               cout << "mul   $t3,$t1,$t4" << endl;
                                                                                               s = "\n\tmul   $t3,$t1,$t4";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          (yyval.token)._isVar = 3;
                                                                                          
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 1) {
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t1," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               
                                                                                               cout << "li   $t4," << (yyvsp[-2].token)._numVal << endl;
                                                                                               s = "\n\tli   $t4," + to_string((yyvsp[-2].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());

                                                                                               cout << "mul   $t3,$t1,$t4" << endl;
                                                                                               s = "\n\tmul   $t3,$t1,$t4";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               (yyval.token)._isVar = 3;
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               // cout << "li   $6," << $$._numVal << endl;
                                                                                               // cout << "li   $7,1" << endl;
                                                                                               // cout << "mul   $5,$7,$6" << endl;
                                                                                               (yyval.token)._isVar = 1;
                                                                                          }
                                                                                          
                                                                                     }
                                                                                     if((yyvsp[-2].token)._isVar == 3) {
                                                                                          if((yyvsp[0].token)._isVar == 2) {
                                                                                               cout << "lw $t1," << (yyvsp[0].token)._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string((yyvsp[0].token)._stackPlace*4) + "($fp)";
                                                                                               strcat((yyval.token)._asm,s.c_str());

                                                                                               cout << "mul    $t0,$t1,$0" << endl;
                                                                                               s = "\n\tmul    $t0,$t1,$t0";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          if((yyvsp[0].token)._isVar == 1) {
                                                                                               cout << "li   $t4," << (yyvsp[0].token)._numVal << endl;
                                                                                               s = "\n\tli   $t4," + to_string((yyvsp[0].token)._numVal);
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                               
                                                                                               cout << "mul   $t0,$t0,$t4" << endl;
                                                                                               s = "\n\tmul   $t0,$t0,$t4";
                                                                                               strcat((yyval.token)._asm,s.c_str());
                                                                                          }
                                                                                          (yyval.token)._isVar = 3;
                                                                                     }

                                                                           }
#line 3168 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1532 "Parser.y" /* yacc.c:1646  */
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_DIV "); 
                                                                                strcat((yyval.token)._byid," / ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                                (yyval.token)._numVal = (int)((yyvsp[-2].token)._numVal/(yyvsp[0].token)._numVal);

                                                                                if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
                                                                                else if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==3) || ((yyvsp[-2].token)._datatype==3 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
                                                                                else if(((yyvsp[-2].token)._datatype==6 && (yyvsp[0].token)._datatype==6))
                                                                                     (yyval.token)._datatype = 6;
                                                                                else if(((yyvsp[-2].token)._datatype==2 && (yyvsp[0].token)._datatype==2))
                                                                                     (yyval.token)._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
#line 3195 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1554 "Parser.y" /* yacc.c:1646  */
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_POW "); 
                                                                                strcat((yyval.token)._byid," ^ ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                               (yyval.token)._numVal=(int)(pow(double((yyvsp[-2].token)._numVal),double((yyvsp[0].token)._numVal)));

                                                                                if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
     
                                                                                else if(((yyvsp[-2].token)._datatype==2 && (yyvsp[0].token)._datatype==2))
                                                                                     (yyval.token)._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
#line 3219 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1573 "Parser.y" /* yacc.c:1646  */
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_BITWISEAND "); 
                                                                                strcat((yyval.token)._byid," & ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                               

                                                                                if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
     
                                                                                else if(((yyvsp[-2].token)._datatype==3 && (yyvsp[0].token)._datatype==3))
                                                                                     (yyval.token)._datatype = 3;
                                                                                else if(((yyvsp[-2].token)._datatype==4 && (yyvsp[0].token)._datatype==4))
                                                                                     (yyval.token)._datatype = 4;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
#line 3245 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1594 "Parser.y" /* yacc.c:1646  */
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_BITWISEOR "); 
                                                                                strcat((yyval.token)._byid," | ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                               

                                                                                if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
     
                                                                                else if(((yyvsp[-2].token)._datatype==3 && (yyvsp[0].token)._datatype==3))
                                                                                     (yyval.token)._datatype = 3;
                                                                                else if(((yyvsp[-2].token)._datatype==4 && (yyvsp[0].token)._datatype==4))
                                                                                     (yyval.token)._datatype = 4;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
#line 3271 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1615 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._numVal=(yyvsp[-1].token)._numVal;(yyval.token)._datatype = (yyvsp[-1].token)._datatype; strcpy((yyval.token)._byid," TOKEN_LEFTPAREN");strcat((yyval.token)._byname,"(");strcat((yyval.token)._byid,(yyvsp[-1].token)._byid); strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);strcat((yyval.token)._byid," ) ");strcat((yyval.token)._byname," TOKEN_RIGHTPAREN ");}
#line 3277 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1616 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._numVal=(-1)*(yyvsp[0].token)._numVal;(yyval.token)._datatype = (yyvsp[0].token)._datatype; strcpy((yyval.token)._byid,"  - ");strcat((yyval.token)._byname," TOKEN_MINUS ");strcat((yyval.token)._byid,(yyvsp[0].token)._byid); strcat((yyval.token)._byname,(yyvsp[0].token)._byname);}
#line 3283 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1617 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype; strcpy((yyval.token)._byid,(yyvsp[0].token)._byid); strcpy((yyval.token)._byname,(yyvsp[0].token)._byname); (yyval.token)._typ=2; (yyval.token)._val=(yyvsp[0].token)._val; (yyval.token)._isVar=2;(yyval.token)._stackPlace=(yyvsp[0].token)._stackPlace;(yyval.token)._isSingle = 1;(yyval.token)._arrVar=0;}
#line 3289 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1618 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._numVal=(yyvsp[0].token)._numVal;(yyval.token)._datatype = (yyvsp[0].token)._datatype; strcpy((yyval.token)._byid,(yyvsp[0].token)._byid); strcpy((yyval.token)._byname,(yyvsp[0].token)._byname); (yyval.token)._typ=1; (yyval.token)._val=(yyvsp[0].token)._val;(yyval.token)._isVar=1;(yyval.token)._isSingle = 1;(yyval.token)._arrVar=0;}
#line 3295 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1619 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype; strcpy((yyval.token)._byid,(yyvsp[0].token)._byid); strcpy((yyval.token)._byname,(yyvsp[0].token)._byname); (yyval.token)._typ=2; (yyval.token)._val=(yyvsp[0].token)._val; (yyval.token)._isVar=2;(yyval.token)._stackPlace=(yyvsp[0].token)._stackPlace;(yyval.token)._isSingle = 1;}
#line 3301 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1626 "Parser.y" /* yacc.c:1646  */
    { (yyval.token)._datatype = 7;}
#line 3307 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1630 "Parser.y" /* yacc.c:1646  */
    { 
                                                                 if((yyvsp[-1].token)._datatype != 1) {yyerror("array count should be integer");}
                                                                 string s ((yyvsp[-3].token)._val);
                                                                 if(is_declaration){
                                                                      if ((umap.find(s) == umap.end())||((umap.find(s) != umap.end())&&(umap[s].scope!=scopeNo))) {
                                                                      }
                                                                      else  if ((umap.find(s) != umap.end())&&(umap[s].scope==scopeNo)){
                                                                           umap[s].cnt = atoi((yyvsp[-1].token)._val);
                                                                           umap[s].stackPlace = scopeVars[scopeNo]-1;
                                                                           scopeVars[scopeNo] = scopeVars[scopeNo] + atoi((yyvsp[-1].token)._val) - 1;
                                                                      }
                                                                      
                                                                 } else {
                                                                      if ((umap.find(s) != umap.end())&&(umap[s].scope==scopeNo)){
                                                                           
                                                                           if(umap[s].cnt <= atoi((yyvsp[-1].token)._val) || atoi((yyvsp[-1].token)._val) < 0) {
                                                                           char errs[400];
                                                                           sprintf(errs,"cannot access element %d of array of size %d",atoi((yyvsp[-1].token)._val),umap[s].cnt);
                                                                           yyerror(errs);
                                                                           }
                                                                      }
                                                                 }
                                                                 
                                                                 (yyval.token)._datatype = (yyvsp[-3].token)._datatype; 
                                                                  strcpy((yyval.token)._byname," array_access ");
                                                                  strcpy((yyval.token)._byid," array_access "); 
                                                                  strcat((yyval.token)._byname,(yyvsp[-3].token)._byname); 
                                                                  strcat((yyval.token)._byid,(yyvsp[-3].token)._byid); 
                                                                  strcat((yyval.token)._byname," TOKEN_LB "); 
                                                                  strcat((yyval.token)._byid," [ ");
                                                                  strcat((yyval.token)._byname,(yyvsp[-1].token)._byname); 
                                                                  strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                  strcat((yyval.token)._byname," TOKEN_RB "); 
                                                                  strcat((yyval.token)._byid," ] ");

                                                                  (yyval.token)._stackPlace = umap[s].stackPlace + atoi((yyvsp[-1].token)._val);
                                                                  (yyval.token)._arrParam = -1;

                                                                }
#line 3351 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1675 "Parser.y" /* yacc.c:1646  */
    { is_declaration = 1;current_dtype=1; (yyval.token)._datatype=1; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_INTTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);   }
#line 3357 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1676 "Parser.y" /* yacc.c:1646  */
    { is_declaration = 1; current_dtype=2; (yyval.token)._datatype=2; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_FLOATTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val); }
#line 3363 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1677 "Parser.y" /* yacc.c:1646  */
    { is_declaration = 1; current_dtype=6; (yyval.token)._datatype=6; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_DOUBLETYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);}
#line 3369 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1678 "Parser.y" /* yacc.c:1646  */
    { is_declaration = 1; current_dtype=3; (yyval.token)._datatype=3; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_CHARTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);  }
#line 3375 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1679 "Parser.y" /* yacc.c:1646  */
    { is_declaration = 1; current_dtype=4; (yyval.token)._datatype=4; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_STRINGTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);}
#line 3381 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1680 "Parser.y" /* yacc.c:1646  */
    { is_declaration = 1; current_dtype=5; (yyval.token)._datatype=5; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_VOIDTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);  }
#line 3387 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1683 "Parser.y" /* yacc.c:1646  */
    {(yyval.token)._datatype = 1; strcpy((yyval.token)._byname," constants "); strcpy((yyval.token)._byid," constants "); strcat((yyval.token)._byname," TOKEN_INTCONST "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);  (yyval.token)._typ=1; (yyval.token)._val=(yyvsp[0].token)._val; (yyval.token)._numVal=atoi((yyvsp[0].token)._val);}
#line 3393 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1684 "Parser.y" /* yacc.c:1646  */
    {/*$$._datatype = 3; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_CHARCONST "); strcat($$._byid,$1._val);  */}
#line 3399 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1685 "Parser.y" /* yacc.c:1646  */
    {/*$$._datatype = 2; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_FLOATCONST "); strcat($$._byid,$1._val); */}
#line 3405 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1686 "Parser.y" /* yacc.c:1646  */
    {/*$$._datatype = 4; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_STRINGCONST "); strcat($$._byid,$1._val);*/}
#line 3411 "Parser.tab.c" /* yacc.c:1646  */
    break;


#line 3415 "Parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1691 "Parser.y" /* yacc.c:1906  */

/*==============================================================error handling===============================================================*/
void type_check(int left, int right, int flag)
{
	if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

void yyerror(const char *s) {
  extern int yylineno;
  extern int columnNo;
  MyFile<<"[-] ERROR : LINE "<<yylineno<<" COLUMN "<<columnNo<<" : "<<s<<"\n";
}


/*==============================================================main function===============================================================*/

int main(int argc , char* argv[]) {
     srand(time(0)); 
     out = atoi(argv[1]);
     yyparse();

     MyFile.close();
     cout << "\n\n\n[#] ERRORS :\n\n\n";
     std::ifstream file("output.out");
     std::string str;
     while (std::getline(file, str)) {
      std::cout << str << "\n";
     }
     file.close();

}
