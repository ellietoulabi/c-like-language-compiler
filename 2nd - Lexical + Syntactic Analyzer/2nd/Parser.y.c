/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Parser.y"

          
     #include <stdio.h>
     #include <iostream>
     #include <stdlib.h>
     #include <math.h>
     #include <string.h>
     #include <string>
     #include <unordered_map> 
     #include <algorithm>
     #include <fstream>
     #include<stack>


     using namespace std;

     int current_dtype;
     int is_declaration = 0;
     int is_loop = 0;
     int is_func = 0;
     int func_type;
     int out = 0;
     int rhs = 0;
     int scopeNo=0; 
     struct perScope{
          int type;
          int scope;
          int cnt;

     };
     unordered_map<string, struct perScope> umap; 

     ofstream MyFile("output.out");


     extern int yylex();
     extern FILE* yyin;
     void yyerror(const char* s);
     void type_check(int,int,int);
     int yyparse();


#line 113 "Parser.tab.c"

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
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 216 "Parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

#define YYUNDEFTOK  2
#define YYMAXUTOK   304

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   120,   140,   145,   152,   145,   174,   179,
     185,   174,   207,   213,   216,   227,   230,   239,   260,   267,
     270,   276,   284,   284,   298,   304,   310,   316,   325,   334,
     349,   357,   365,   386,   404,   418,   441,   441,   465,   477,
     491,   501,   506,   515,   527,   538,   548,   556,   562,   568,
     581,   592,   600,   612,   622,   632,   642,   652,   662,   672,
     682,   690,   697,   705,   707,   718,   729,   740,   749,   750,
     753,   784,   808,   830,   852,   874,   893,   914,   935,   936,
     937,   938,   941,   942,   945,   949,   987,   988,   989,   990,
     991,   992,   995,   996,   997,   998
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
  "TOKEN_RELATIONOP", "UMINUS", "$accept", "program", "globalVars",
  "function", "$@1", "$@2", "$@3", "$@4", "$@5", "argumentList",
  "arguments", "arg", "statements", "stmt", "compoundStmt", "$@6",
  "singleStmt", "printFunc", "conditionStmt", "loopStmt", "$@7",
  "functionCall", "parameter_list", "parameter", "declaration",
  "declaration_list", "sub_decl", "expression", "sub_expr", "assgn",
  "assignment_expr", "lhs", "identifier", "arithmetic_expr",
  "array_init_vars", "array_init", "array_access", "typeSpecifier",
  "constants", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     215,   -79,   -79,   -79,   -79,   -79,   -79,    19,   -79,   -79,
       9,   -79,   -79,   -79,    24,     7,     6,    29,    61,   -79,
     -79,   -79,   -79,    63,   215,   -79,   215,    82,    86,   -79,
     105,    87,   -79,   -79,   215,   107,   -79,   -79,    87,   -79,
       6,   -79,   -79,   109,   171,   215,   -79,   106,   113,   105,
     119,   116,   118,   -79,   -79,   -79,   -79,   124,   -79,   -79,
     130,   -79,    47,   -79,   -79,   132,    -7,   139,   105,   -79,
       9,    84,   -79,    84,   123,   126,   -79,   -12,    34,   -79,
     -79,   123,   140,   123,   -79,   -79,   -79,   -79,   -79,   105,
     -79,   127,     1,     6,    60,   -12,   -79,   -79,   168,   -79,
     -79,   -79,   123,   123,   123,   123,   123,   123,   123,   123,
      84,    84,    84,    84,    84,    84,    84,    17,   169,   123,
      20,   -79,     6,   -79,   -11,    34,   -79,   -79,   -79,    58,
     -79,   169,   147,   -79,   -79,   192,   180,   152,   152,   -79,
     -79,   -79,   -79,   131,   131,   141,   141,   -79,   208,   208,
     -79,   123,    74,    87,     3,   -79,   -79,   123,   -79,   169,
     123,   182,   -79,     6,   -79,    76,    87,   -79,   -79,   -79,
      87,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    86,    87,    88,    89,    90,    91,     0,     2,     4,
       0,     1,    70,     5,     8,     0,     0,     0,     0,    95,
      93,    92,    94,     0,    13,     6,     0,     0,    12,    15,
       0,     0,     3,     9,     0,    16,    22,     7,     0,    14,
       0,    19,    10,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,    23,    18,    20,    21,     0,    24,    25,
       0,    26,     0,    46,    47,     0,    48,    49,     0,    11,
       0,     0,    29,     0,     0,     0,    62,    80,    61,    69,
      81,     0,     0,     0,    30,    31,    28,    27,    44,     0,
      63,     0,     0,     0,     0,    48,     8,    80,     0,    79,
      60,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,    45,     0,    66,    80,    64,    67,    65,    39,     0,
      41,    42,     0,    43,    78,    58,    59,    54,    55,    52,
      53,    56,    57,    71,    72,    73,    74,    75,    76,    77,
      33,     0,     0,     0,     0,    83,    38,     0,    85,    50,
       0,    34,    84,     0,    40,     0,     0,    82,    36,    35,
       0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   154,   148,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   158,   -79,   -79,   -37,   -79,   -79,   -79,   -79,   -79,
     -79,   114,   -79,    53,   -79,   150,   156,   -78,   -44,   -79,
     -35,   -79,     8,   -20,   -79,   -79,   -42,    11,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    15,    31,    17,    38,    45,    27,
      28,    29,    44,    54,    37,    41,    56,    57,    58,    59,
     170,    60,   129,   130,    61,    62,    63,   117,   118,    91,
      76,    65,    77,    78,   154,   126,    79,    10,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    42,    67,    75,    12,   120,    19,    55,   -68,    64,
      92,    19,    12,   -68,    92,    13,    93,    93,    14,    11,
      20,    93,    71,   128,    43,    20,    67,   162,    18,   163,
     100,    21,    22,    64,    73,    30,    21,    22,    35,   150,
      74,   152,   153,   151,    16,    30,   151,    67,   131,   127,
      24,    98,    66,    99,    64,    68,    70,    82,   135,   136,
     137,   138,   139,   140,   141,   142,   110,   111,   112,   113,
     114,   125,    88,    89,   115,   116,    95,   132,    96,    97,
     156,    97,   165,    25,   157,   133,    89,    12,    26,    19,
     143,   144,   145,   146,   147,   148,   149,    95,   168,   124,
     151,   160,   151,    20,    33,    71,   155,   159,    12,    12,
      36,    19,    34,   131,    21,    22,   161,    73,    97,    97,
      97,    97,    97,    97,    97,    20,    12,    71,    19,   169,
      12,    72,    19,   171,    81,    40,    21,    22,    46,    73,
      83,    84,    20,    85,    71,    74,    20,   167,    71,    86,
     122,   101,    90,    21,    22,    87,    73,    21,    22,   -69,
      73,   119,    74,   102,   103,   112,   113,   114,   104,   105,
     106,   107,   108,   109,    12,    47,   158,   114,    48,    49,
      32,    50,    51,    52,     1,     2,     3,     4,     5,     6,
     134,   166,    39,    69,    36,    53,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   123,   102,   103,   115,   116,
     164,   104,   105,   106,   107,   108,   109,   102,    94,     0,
       0,     0,   104,   105,   106,   107,   108,   109,     1,     2,
       3,     4,     5,     6,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   121
};

static const yytype_int16 yycheck[] =
{
      16,    38,    44,    47,     3,    83,     5,    44,    20,    44,
      21,     5,     3,    20,    21,     6,    28,    28,    10,     0,
      19,    28,    21,    22,    40,    19,    68,    24,    21,    26,
      74,    30,    31,    68,    33,    24,    30,    31,    30,    22,
      39,   119,    22,    26,    20,    34,    26,    89,    92,    91,
      21,    71,    44,    73,    89,    44,    45,    49,   102,   103,
     104,   105,   106,   107,   108,   109,    32,    33,    34,    35,
      36,    91,    25,    26,    40,    41,    68,    93,    70,    71,
      22,    73,   160,    22,    26,    25,    26,     3,    25,     5,
     110,   111,   112,   113,   114,   115,   116,    89,    22,    91,
      26,    27,    26,    19,    22,    21,   122,   151,     3,     3,
      23,     5,    26,   157,    30,    31,   153,    33,   110,   111,
     112,   113,   114,   115,   116,    19,     3,    21,     5,   166,
       3,    25,     5,   170,    21,    28,    30,    31,    29,    33,
      21,    25,    19,    25,    21,    39,    19,   163,    21,    25,
      23,    25,    20,    30,    31,    25,    33,    30,    31,    20,
      33,    21,    39,    37,    38,    34,    35,    36,    42,    43,
      44,    45,    46,    47,     3,     4,    29,    36,     7,     8,
      26,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      22,     9,    34,    45,    23,    24,    44,    45,    46,    47,
      32,    33,    34,    35,    36,    91,    37,    38,    40,    41,
     157,    42,    43,    44,    45,    46,    47,    37,    68,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    13,    14,
      15,    16,    17,    18,    42,    43,    44,    45,    46,    47,
      32,    33,    34,    35,    36,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    15,    16,    17,    18,    51,    52,    53,
      87,     0,     3,     6,    82,    54,    20,    56,    21,     5,
      19,    30,    31,    88,    21,    22,    25,    59,    60,    61,
      87,    55,    52,    22,    26,    82,    23,    64,    57,    61,
      28,    65,    64,    88,    62,    58,    29,     4,     7,     8,
      10,    11,    12,    24,    63,    64,    66,    67,    68,    69,
      71,    74,    75,    76,    80,    81,    82,    86,    87,    53,
      87,    21,    25,    33,    39,    78,    80,    82,    83,    86,
      88,    21,    82,    21,    25,    25,    25,    25,    25,    26,
      20,    79,    21,    28,    75,    82,    82,    82,    83,    83,
      78,    25,    37,    38,    42,    43,    44,    45,    46,    47,
      32,    33,    34,    35,    36,    40,    41,    77,    78,    21,
      77,    76,    23,    71,    82,    83,    85,    86,    22,    72,
      73,    78,    88,    25,    22,    78,    78,    78,    78,    78,
      78,    78,    78,    83,    83,    83,    83,    83,    83,    83,
      22,    26,    77,    22,    84,    88,    22,    26,    29,    78,
      27,    64,    24,    26,    73,    77,     9,    88,    22,    64,
      70,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    54,    55,    53,    56,    57,
      58,    53,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    65,    64,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    68,    68,    70,    69,    71,    71,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    80,    80,    80,    81,    81,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    84,    85,    86,    87,    87,    87,    87,
      87,    87,    88,    88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     1,     0,     0,     7,     0,     0,
       0,    10,     1,     0,     3,     1,     2,     5,     2,     0,
       1,     1,     0,     4,     1,     1,     1,     2,     2,     2,
       2,     2,     3,     4,     5,     7,     0,     9,     4,     3,
       3,     1,     1,     3,     2,     3,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     3,     1,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  YYUSE (yytype);
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
  unsigned long yylno = yyrline[yyrule];
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
#line 105 "Parser.y"
    {strcpy((yyval.token)._byid," PROGRAM ");strcpy((yyval.token)._byname," PROGRAM ");strcat((yyval.token)._byid,(yyvsp[0].token)._byid);strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                     

                                     if (out==1)
                                        cout << "\n\n\n[+] Parse : \n\n"<<(yyval.token)._byid;
                                     else if (out == 0)
                                          cout << "\n[+] Parse : \n"<<(yyval.token)._byname;
                                     else
                                        MyFile<<"[-] ERROR IN OUTPUT TYPE : WRONG OPTION";


                                    }
#line 1468 "Parser.tab.c"
    break;

  case 3:
#line 120 "Parser.y"
    {  
                                                                                                                   strcpy((yyval.token)._byid," globalVars ");
                                                                                                                   strcat((yyval.token)._byid,(yyvsp[-5].token)._byid);
                                                                                                                   strcat((yyval.token)._byid,(yyvsp[-4].token)._byid);
                                                                                                                   strcat((yyval.token)._byid," = ");
                                                                                                                   strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                                   strcat((yyval.token)._byid," ; ");
                                                                                                                   strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                                                                   strcpy((yyval.token)._byname," globalVars ");
                                                                                                                   strcat((yyval.token)._byname,(yyvsp[-5].token)._byname);
                                                                                                                   strcat((yyval.token)._byname,(yyvsp[-4].token)._byname);
                                                                                                                   strcat((yyval.token)._byname," TOKEN_ASSIGNOP ");
                                                                                                                   strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                                                                   strcat((yyval.token)._byname," TOKEN_SEMICOLON ");
                                                                                                                   strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                                                                   
                                                                                                                   if ( (yyvsp[-5].token)._datatype == 5) 
                                                                                                                        yyerror("variable cant be of type VOID"); }
#line 1492 "Parser.tab.c"
    break;

  case 4:
#line 141 "Parser.y"
    {strcpy((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                                                                   strcpy((yyval.token)._byname,(yyvsp[0].token)._byname);}
#line 1499 "Parser.tab.c"
    break;

  case 5:
#line 145 "Parser.y"
    { 

                            func_type = current_dtype;
                            is_declaration = 0;
                            

                        }
#line 1511 "Parser.tab.c"
    break;

  case 6:
#line 152 "Parser.y"
    {
                          
                                            is_declaration = 0;
							          is_func = 1;

                        }
#line 1522 "Parser.tab.c"
    break;

  case 7:
#line 157 "Parser.y"
    {is_func = 0; if ((yyvsp[-6].token)._datatype != 1 )yyerror("main function must be of type INT");
                        
                                             strcpy((yyval.token)._byid," main_function ");
                                             strcat((yyval.token)._byid,(yyvsp[-6].token)._byid);
                                             strcat((yyval.token)._byid," main ");
                                             strcat((yyval.token)._byid," ( ");
                                             strcat((yyval.token)._byid," ) ");
                                             strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                             
                                             strcpy((yyval.token)._byname," main_function ");
                                             strcat((yyval.token)._byname,(yyvsp[-6].token)._byname);
                                             strcat((yyval.token)._byname," TOKEN_MAINFINC  ");
                                             strcat((yyval.token)._byname," TOKEN_LEFTPARAN ");
                                             strcat((yyval.token)._byname," TOKEN_RIGHTPARAN ");
                                             strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                        
                                         }
#line 1544 "Parser.tab.c"
    break;

  case 8:
#line 174 "Parser.y"
    {

                            func_type = current_dtype;
                            is_declaration = 0;

                        }
#line 1555 "Parser.tab.c"
    break;

  case 9:
#line 179 "Parser.y"
    {
                          
                                            is_declaration = 0;
									is_func = 1;

                        }
#line 1566 "Parser.tab.c"
    break;

  case 10:
#line 185 "Parser.y"
    {is_func = 0;}
#line 1572 "Parser.tab.c"
    break;

  case 11:
#line 185 "Parser.y"
    {

                                            strcpy((yyval.token)._byid," function ");
                                             strcat((yyval.token)._byid,(yyvsp[-9].token)._byid);
                                             strcat((yyval.token)._byid,(yyvsp[-8].token)._byid);
                                             strcat((yyval.token)._byid," ( ");
                                             strcat((yyval.token)._byid,(yyvsp[-5].token)._byid);
                                             strcat((yyval.token)._byid," ) ");
                                             strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                             strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                             
                                             strcpy((yyval.token)._byname," function ");
                                             strcat((yyval.token)._byname,(yyvsp[-9].token)._byname);
                                             strcat((yyval.token)._byname,(yyvsp[-8].token)._byname);
                                             strcat((yyval.token)._byname," TOKEN_LEFTPARAN ");
                                             strcat((yyval.token)._byname,(yyvsp[-5].token)._byname);
                                             strcat((yyval.token)._byname," TOKEN_RIGHTPARAN ");
                                             strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                             strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                      }
#line 1597 "Parser.tab.c"
    break;

  case 12:
#line 207 "Parser.y"
    {if((yyval.token)._cnt > 4) yyerror("too many arguments");
                                                              strcpy((yyval.token)._byid," argumentList "); 
                                                              strcpy((yyval.token)._byname," argumentList "); 
                                                              strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                              strcat((yyval.token)._byid, (yyvsp[0].token)._byid);
                                                             }
#line 1608 "Parser.tab.c"
    break;

  case 14:
#line 216 "Parser.y"
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
#line 1624 "Parser.tab.c"
    break;

  case 16:
#line 230 "Parser.y"
    { (yyval.token)._cnt=1;
                                                              strcpy((yyval.token)._byid," arg "); 
                                                              strcpy((yyval.token)._byname," arg "); 
                                                              strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                              strcat((yyval.token)._byid, (yyvsp[-1].token)._byid); 
                                                              strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                              strcat((yyval.token)._byid, (yyvsp[0].token)._byid);

                                                            }
#line 1638 "Parser.tab.c"
    break;

  case 17:
#line 239 "Parser.y"
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
#line 1661 "Parser.tab.c"
    break;

  case 18:
#line 260 "Parser.y"
    { strcpy((yyvsp[-1].token)._byid," statements "); 
                                            strcpy((yyvsp[-1].token)._byname," statements "); 
                                            strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                            strcat((yyval.token)._byid, (yyvsp[-1].token)._byid); 
                                            strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                            strcat((yyval.token)._byid, (yyvsp[0].token)._byid);
                                          }
#line 1673 "Parser.tab.c"
    break;

  case 20:
#line 270 "Parser.y"
    {
                                        strcpy((yyval.token)._byid," stmt "); 
                                        strcpy((yyval.token)._byname," stmt "); 
                                        strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                        strcat((yyval.token)._byid, (yyvsp[0].token)._byid);   
                                     }
#line 1684 "Parser.tab.c"
    break;

  case 21:
#line 276 "Parser.y"
    {
                                        strcpy((yyval.token)._byid," stmt "); 
                                        strcpy((yyval.token)._byname," stmt "); 
                                        strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                        strcat((yyval.token)._byid, (yyvsp[0].token)._byid);   
                                     }
#line 1695 "Parser.tab.c"
    break;

  case 22:
#line 284 "Parser.y"
    {scopeNo++;}
#line 1701 "Parser.tab.c"
    break;

  case 23:
#line 284 "Parser.y"
    {
                                                                      strcpy((yyval.token)._byid," compoundStmt "); 
                                                                      strcpy((yyval.token)._byname," compoundStmt "); 
                                                                      strcat((yyval.token)._byname," TOKEN_LCB ");
                                                                      strcat((yyval.token)._byid," { ");
                                                                      strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                                      strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);                                                                           
                                                                      strcat((yyval.token)._byid," } "); 
                                                                      strcat((yyval.token)._byname," TOKEN_RCB "); 
                                                                    }
#line 1716 "Parser.tab.c"
    break;

  case 24:
#line 298 "Parser.y"
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[0].token)._byid);   
                                                       }
#line 1727 "Parser.tab.c"
    break;

  case 25:
#line 304 "Parser.y"
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[0].token)._byid);   
                                                       }
#line 1738 "Parser.tab.c"
    break;

  case 26:
#line 310 "Parser.y"
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[0].token)._byid);   
                                                       }
#line 1749 "Parser.tab.c"
    break;

  case 27:
#line 316 "Parser.y"
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[-1].token)._byid);                                                                           
                                                            strcat((yyval.token)._byid," ; "); 
                                                            strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");  

                                                       }
#line 1763 "Parser.tab.c"
    break;

  case 28:
#line 325 "Parser.y"
    {
                                                            strcpy((yyval.token)._byid," singleStmt "); 
                                                            strcpy((yyval.token)._byname," singleStmt "); 
                                                            strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                            strcat((yyval.token)._byid, (yyvsp[-1].token)._byid);                                                                           
                                                            strcat((yyval.token)._byid," ; "); 
                                                            strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");  

                                                       }
#line 1777 "Parser.tab.c"
    break;

  case 29:
#line 334 "Parser.y"
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
#line 1797 "Parser.tab.c"
    break;

  case 30:
#line 349 "Parser.y"
    {if(!is_loop)    { yyerror("Illegal use of continue");}
                                                                                strcpy((yyval.token)._byid," singleStmt "); 
                                                                                strcpy((yyval.token)._byname," singleStmt "); 
                                                                                strcat((yyval.token)._byname," TOKEN_CONTINUESTMT ");
                                                                                strcat((yyval.token)._byid," continue ");                                                                           
                                                                                strcat((yyval.token)._byid," ; "); 
                                                                                strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");
                                                                              }
#line 1810 "Parser.tab.c"
    break;

  case 31:
#line 357 "Parser.y"
    {if(!is_loop) { yyerror("Illegal use of break");}
                                                                                strcpy((yyval.token)._byid," singleStmt "); 
                                                                                strcpy((yyval.token)._byname," singleStmt "); 
                                                                                strcat((yyval.token)._byname," TOKEN_BREAKSTMT ");
                                                                                strcat((yyval.token)._byid," break ");                                                                           
                                                                                strcat((yyval.token)._byid," ; "); 
                                                                                strcat((yyval.token)._byname," TOKEN_SEMOCOLON ");
                                                                }
#line 1823 "Parser.tab.c"
    break;

  case 32:
#line 365 "Parser.y"
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
                        }
#line 1846 "Parser.tab.c"
    break;

  case 33:
#line 386 "Parser.y"
    {

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
#line 1864 "Parser.tab.c"
    break;

  case 34:
#line 404 "Parser.y"
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
                                                                                                                                             }
#line 1883 "Parser.tab.c"
    break;

  case 35:
#line 418 "Parser.y"
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
                                                                                                                                            

                                                                                                                                             }
#line 1908 "Parser.tab.c"
    break;

  case 36:
#line 441 "Parser.y"
    {is_loop = 1;}
#line 1914 "Parser.tab.c"
    break;

  case 37:
#line 441 "Parser.y"
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

                                                                                                                                                    }
#line 1940 "Parser.tab.c"
    break;

  case 38:
#line 465 "Parser.y"
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
                                                                                          }
#line 1957 "Parser.tab.c"
    break;

  case 39:
#line 477 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                        
                                                                                     strcpy((yyval.token)._byid," functionCall "); 
                                                                                     strcpy((yyval.token)._byname," functionCall "); 
                                                                                     strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                     strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                                     strcat((yyval.token)._byname," TOKEN_LEFTPAREN "); 
                                                                                     strcat((yyval.token)._byid," ( ");
                                                                                     strcat((yyval.token)._byname," TOKEN_RIGHTPAREN "); 
                                                                                     strcat((yyval.token)._byid," ) ");
                                                                                     
                                                                                     }
#line 1974 "Parser.tab.c"
    break;

  case 40:
#line 491 "Parser.y"
    {
                                                                           strcpy((yyval.token)._byid," parameter_list "); 
                                                                           strcpy((yyval.token)._byname," parameter_list "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                           strcat((yyval.token)._byname," TOKEN_COMMA "); 
                                                                           strcat((yyval.token)._byid," , ");
                                                                           strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                           strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                        }
#line 1989 "Parser.tab.c"
    break;

  case 41:
#line 501 "Parser.y"
    {  strcpy((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                           strcpy((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                        }
#line 1997 "Parser.tab.c"
    break;

  case 42:
#line 506 "Parser.y"
    {
                                                                           strcpy((yyval.token)._byid," parameter "); 
                                                                           strcpy((yyval.token)._byname," parameter "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                        }
#line 2008 "Parser.tab.c"
    break;

  case 43:
#line 515 "Parser.y"
    {  is_declaration = 0;
                                                                           strcpy((yyval.token)._byid," declaration "); 
                                                                           strcpy((yyval.token)._byname," declaration "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                           strcat((yyval.token)._byname,(yyvsp[-1].token)._byname); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                           strcat((yyval.token)._byname,"TOKEN_SEMICOLON"); 
                                                                           strcat((yyval.token)._byid," ; ");


                                                                        }
#line 2025 "Parser.tab.c"
    break;

  case 44:
#line 527 "Parser.y"
    {
                                                                           is_declaration = 0;
                                                                           strcpy((yyval.token)._byid," declaration "); 
                                                                           strcpy((yyval.token)._byname," declaration "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[-1].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);
                                                                           strcat((yyval.token)._byname,"TOKEN_SEMICOLON"); 
                                                                           strcat((yyval.token)._byid," ; ");
                                                                        }
#line 2039 "Parser.tab.c"
    break;

  case 45:
#line 538 "Parser.y"
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
#line 2054 "Parser.tab.c"
    break;

  case 46:
#line 548 "Parser.y"
    {  (yyvsp[0].token)._datatype=(yyval.token)._datatype;
                                                                           strcpy((yyval.token)._byid," declaration_list "); 
                                                                           strcpy((yyval.token)._byname," declaration_list "); 
                                                                           strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                           strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                        }
#line 2065 "Parser.tab.c"
    break;

  case 47:
#line 556 "Parser.y"
    {
                                                                 strcpy((yyval.token)._byid," sub_decl "); 
                                                                 strcpy((yyval.token)._byname," sub_decl "); 
                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            }
#line 2076 "Parser.tab.c"
    break;

  case 48:
#line 562 "Parser.y"
    {
                                                                 strcpy((yyval.token)._byid," sub_decl "); 
                                                                 strcpy((yyval.token)._byname," sub_decl "); 
                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                            }
#line 2087 "Parser.tab.c"
    break;

  case 49:
#line 568 "Parser.y"
    {
                                                                 is_declaration = 1;
                                                                 
                                                                 strcpy((yyval.token)._byid," sub_decl "); 
                                                                 strcpy((yyval.token)._byname," sub_decl "); 
                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname);

                                                            }
#line 2101 "Parser.tab.c"
    break;

  case 50:
#line 581 "Parser.y"
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
#line 2117 "Parser.tab.c"
    break;

  case 51:
#line 592 "Parser.y"
    {strcpy((yyval.token)._byid," expression ");
                                                             strcpy((yyval.token)._byname," sub_expr ");
                                                             strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                             strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                             
                                                            }
#line 2128 "Parser.tab.c"
    break;

  case 52:
#line 600 "Parser.y"
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_GR "); 
                                                                      strcat((yyval.token)._byid," > ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);


                                                                    }
#line 2145 "Parser.tab.c"
    break;

  case 53:
#line 612 "Parser.y"
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_LS "); 
                                                                      strcat((yyval.token)._byid," < ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                    }
#line 2160 "Parser.tab.c"
    break;

  case 54:
#line 622 "Parser.y"
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_EQ "); 
                                                                      strcat((yyval.token)._byid," = ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                    }
#line 2175 "Parser.tab.c"
    break;

  case 55:
#line 632 "Parser.y"
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_NOTEQ "); 
                                                                      strcat((yyval.token)._byid," != ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                    }
#line 2190 "Parser.tab.c"
    break;

  case 56:
#line 642 "Parser.y"
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_LSEQ "); 
                                                                      strcat((yyval.token)._byid," <= ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                    }
#line 2205 "Parser.tab.c"
    break;

  case 57:
#line 652 "Parser.y"
    {type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,2); (yyval.token)._datatype = (yyvsp[-2].token)._datatype;
                                                                      strcpy((yyval.token)._byid," sub_expr "); 
                                                                      strcpy((yyval.token)._byname," sub_expr "); 
                                                                      strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                      strcat((yyval.token)._byname,(yyvsp[-2].token)._byname);
                                                                      strcat((yyval.token)._byname," TOKEN_GREQ "); 
                                                                      strcat((yyval.token)._byid," >= ");
                                                                      strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                      strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                    }
#line 2220 "Parser.tab.c"
    break;

  case 58:
#line 662 "Parser.y"
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
#line 2235 "Parser.tab.c"
    break;

  case 59:
#line 672 "Parser.y"
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
#line 2250 "Parser.tab.c"
    break;

  case 60:
#line 682 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;
                                                                     strcpy((yyval.token)._byid," sub_expr ");
                                                                     strcpy((yyval.token)._byid," TOKEN_LOGICNOT ");
                                                                     strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                     strcat((yyval.token)._byname," sub_expr ");
                                                                     strcat((yyval.token)._byname," ! ");
                                                                     strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                    }
#line 2263 "Parser.tab.c"
    break;

  case 61:
#line 690 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;
                                                                     strcpy((yyval.token)._byname," sub_expr ");
                                                                     strcpy((yyval.token)._byid," sub_expr ");
                                                                     strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                     strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                        
                                                                    }
#line 2275 "Parser.tab.c"
    break;

  case 62:
#line 697 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;
                                                                     strcpy((yyval.token)._byname," sub_expr ");
                                                                     strcpy((yyval.token)._byid," sub_expr ");
                                                                     strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                     strcat((yyval.token)._byname,(yyvsp[0].token)._byname);
                                                                    }
#line 2286 "Parser.tab.c"
    break;

  case 63:
#line 705 "Parser.y"
    {rhs=1;}
#line 2292 "Parser.tab.c"
    break;

  case 64:
#line 707 "Parser.y"
    { type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,1); (yyval.token)._datatype = (yyvsp[0].token)._datatype;rhs=0;
                                                                                                 strcpy((yyval.token)._byname," assignment_expr ");
                                                                                                 strcpy((yyval.token)._byid," assignment_expr "); 
                                                                                                 strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                 strcat((yyval.token)._byname,"TOKEN_ASSIGNOP"); 
                                                                                                 strcat((yyval.token)._byid,"=");
                                                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                                               }
#line 2308 "Parser.tab.c"
    break;

  case 65:
#line 718 "Parser.y"
    { type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,1); (yyval.token)._datatype = (yyvsp[0].token)._datatype;rhs=0;
                                                                                                 strcpy((yyval.token)._byname," assignment_expr ");
                                                                                                 strcpy((yyval.token)._byid," assignment_expr "); 
                                                                                                 strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                 strcat((yyval.token)._byname,"TOKEN_ASSIGNOP"); 
                                                                                                 strcat((yyval.token)._byid,"=");
                                                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                                                 
                                                                                               }
#line 2324 "Parser.tab.c"
    break;

  case 66:
#line 729 "Parser.y"
    { type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,1); (yyval.token)._datatype = (yyvsp[0].token)._datatype;rhs=0;
                                                                                                 strcpy((yyval.token)._byname," assignment_expr ");
                                                                                                 strcpy((yyval.token)._byid," assignment_expr "); 
                                                                                                 strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[-2].token)._byid);
                                                                                                 strcat((yyval.token)._byname,"TOKEN_ASSIGNOP"); 
                                                                                                 strcat((yyval.token)._byid,"=");
                                                                                                 strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                                 strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

                                                                                               }
#line 2340 "Parser.tab.c"
    break;

  case 67:
#line 740 "Parser.y"
    {
                              type_check((yyvsp[-2].token)._datatype,(yyvsp[0].token)._datatype,1);
                              yyerror("cant be initialized");
                                                       
                                                  }
#line 2350 "Parser.tab.c"
    break;

  case 68:
#line 749 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;strcpy((yyval.token)._byid,(yyvsp[0].token)._byid);strcat((yyval.token)._byid,(yyvsp[0].token)._byname);}
#line 2356 "Parser.tab.c"
    break;

  case 69:
#line 750 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype;strcpy((yyval.token)._byid,(yyvsp[0].token)._byid);strcat((yyval.token)._byid,(yyvsp[0].token)._byname);}
#line 2362 "Parser.tab.c"
    break;

  case 70:
#line 753 "Parser.y"
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
                                                                      temp.type=current_dtype;
                                                                      temp.scope=scopeNo;
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

                                                  }
#line 2397 "Parser.tab.c"
    break;

  case 71:
#line 784 "Parser.y"
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_PLUS "); 
                                                                                strcat((yyval.token)._byid," + ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

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

                                                                           }
#line 2426 "Parser.tab.c"
    break;

  case 72:
#line 808 "Parser.y"
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_MINUS "); 
                                                                                strcat((yyval.token)._byid," - ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

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
#line 2453 "Parser.tab.c"
    break;

  case 73:
#line 830 "Parser.y"
    {    
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_MUL "); 
                                                                                strcat((yyval.token)._byid," * ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);

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
#line 2480 "Parser.tab.c"
    break;

  case 74:
#line 852 "Parser.y"
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_DIV "); 
                                                                                strcat((yyval.token)._byid," / ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                               

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
#line 2507 "Parser.tab.c"
    break;

  case 75:
#line 874 "Parser.y"
    {
                                                                                strcpy((yyval.token)._byname," arithmetic_expr ");
                                                                                strcpy((yyval.token)._byid," arithmetic_expr "); 
                                                                                strcat((yyval.token)._byname,(yyvsp[-2].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[-2].token)._byid); 
                                                                                strcat((yyval.token)._byname," TOKEN_POW "); 
                                                                                strcat((yyval.token)._byid," ^ ");
                                                                                strcat((yyval.token)._byname,(yyvsp[0].token)._byname); 
                                                                                strcat((yyval.token)._byid,(yyvsp[0].token)._byid);
                                                                               

                                                                                if(((yyvsp[-2].token)._datatype==1 && (yyvsp[0].token)._datatype==1))
                                                                                     (yyval.token)._datatype = 1;
     
                                                                                else if(((yyvsp[-2].token)._datatype==2 && (yyvsp[0].token)._datatype==2))
                                                                                     (yyval.token)._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
#line 2531 "Parser.tab.c"
    break;

  case 76:
#line 893 "Parser.y"
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
#line 2557 "Parser.tab.c"
    break;

  case 77:
#line 914 "Parser.y"
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
#line 2583 "Parser.tab.c"
    break;

  case 78:
#line 935 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[-1].token)._datatype; strcpy((yyval.token)._byid," TOKEN_LEFTPAREN");strcat((yyval.token)._byname,"(");strcat((yyval.token)._byid,(yyvsp[-1].token)._byid); strcat((yyval.token)._byname,(yyvsp[-1].token)._byname);strcat((yyval.token)._byid," ) ");strcat((yyval.token)._byname," TOKEN_RIGHTPAREN ");}
#line 2589 "Parser.tab.c"
    break;

  case 79:
#line 936 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype; strcpy((yyval.token)._byid,"  - ");strcat((yyval.token)._byname," TOKEN_MINUS ");strcat((yyval.token)._byid,(yyvsp[0].token)._byid); strcat((yyval.token)._byname,(yyvsp[0].token)._byname);}
#line 2595 "Parser.tab.c"
    break;

  case 80:
#line 937 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype; strcpy((yyval.token)._byid,(yyvsp[0].token)._byid); strcpy((yyval.token)._byname,(yyvsp[0].token)._byname);}
#line 2601 "Parser.tab.c"
    break;

  case 81:
#line 938 "Parser.y"
    {(yyval.token)._datatype = (yyvsp[0].token)._datatype; strcpy((yyval.token)._byid,(yyvsp[0].token)._byid); strcpy((yyval.token)._byname,(yyvsp[0].token)._byname);}
#line 2607 "Parser.tab.c"
    break;

  case 84:
#line 945 "Parser.y"
    { (yyval.token)._datatype = 7;}
#line 2613 "Parser.tab.c"
    break;

  case 85:
#line 949 "Parser.y"
    { 
                                                                 if((yyvsp[-1].token)._datatype != 1) {yyerror("array count should be integer");}
                                                                 string s ((yyvsp[-3].token)._val);
                                                                 if(is_declaration){
                                                                      if ((umap.find(s) == umap.end())||((umap.find(s) != umap.end())&&(umap[s].scope!=scopeNo))) {
                                                                      }
                                                                      else  if ((umap.find(s) != umap.end())&&(umap[s].scope==scopeNo)){
                                                                           umap[s].cnt = atoi((yyvsp[-1].token)._val);
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

                                                                }
#line 2652 "Parser.tab.c"
    break;

  case 86:
#line 987 "Parser.y"
    { is_declaration = 1;current_dtype=1; (yyval.token)._datatype=1; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_INTTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);   }
#line 2658 "Parser.tab.c"
    break;

  case 87:
#line 988 "Parser.y"
    { is_declaration = 1; current_dtype=2; (yyval.token)._datatype=2; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_FLOATTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val); }
#line 2664 "Parser.tab.c"
    break;

  case 88:
#line 989 "Parser.y"
    { is_declaration = 1; current_dtype=6; (yyval.token)._datatype=6; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_DOUBLETYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);}
#line 2670 "Parser.tab.c"
    break;

  case 89:
#line 990 "Parser.y"
    { is_declaration = 1; current_dtype=3; (yyval.token)._datatype=3; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_CHARTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);  }
#line 2676 "Parser.tab.c"
    break;

  case 90:
#line 991 "Parser.y"
    { is_declaration = 1; current_dtype=4; (yyval.token)._datatype=4; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_STRINGTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);}
#line 2682 "Parser.tab.c"
    break;

  case 91:
#line 992 "Parser.y"
    { is_declaration = 1; current_dtype=5; (yyval.token)._datatype=5; strcpy((yyval.token)._byname," typeSpecifier "); strcpy((yyval.token)._byid," typeSpecifier "); strcat((yyval.token)._byname," TOKEN_VOIDTYPE "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);  }
#line 2688 "Parser.tab.c"
    break;

  case 92:
#line 995 "Parser.y"
    {(yyval.token)._datatype = 1; strcpy((yyval.token)._byname," constants "); strcpy((yyval.token)._byid," constants "); strcat((yyval.token)._byname," TOKEN_INTCONST "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);   }
#line 2694 "Parser.tab.c"
    break;

  case 93:
#line 996 "Parser.y"
    {(yyval.token)._datatype = 3; strcpy((yyval.token)._byname," constants "); strcpy((yyval.token)._byid," constants "); strcat((yyval.token)._byname," TOKEN_CHARCONST "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);  }
#line 2700 "Parser.tab.c"
    break;

  case 94:
#line 997 "Parser.y"
    {(yyval.token)._datatype = 2; strcpy((yyval.token)._byname," constants "); strcpy((yyval.token)._byid," constants "); strcat((yyval.token)._byname," TOKEN_FLOATCONST "); strcat((yyval.token)._byid,(yyvsp[0].token)._val); }
#line 2706 "Parser.tab.c"
    break;

  case 95:
#line 998 "Parser.y"
    {(yyval.token)._datatype = 4; strcpy((yyval.token)._byname," constants "); strcpy((yyval.token)._byid," constants "); strcat((yyval.token)._byname," TOKEN_STRINGCONST "); strcat((yyval.token)._byid,(yyvsp[0].token)._val);}
#line 2712 "Parser.tab.c"
    break;


#line 2716 "Parser.tab.c"

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
#line 1003 "Parser.y"

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
