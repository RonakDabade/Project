
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 ".\\file_operations.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_create_file(const char *filename);
void generate_delete_file(const char *filename);
void generate_add_function(const char *funcname, const char *filename);
void generate_delete_function(const char *funcname, const char *filename);
void generate_for_loop(const char *var, int limit, int step, const char *funcname, const char *filename);
void generate_if_statement(const char *var, const char *op, int value, const char *funcname, const char *filename);
void generate_if_else_statement(const char *var, const char *op, int value, const char *funcname, const char *filename);
void generate_switch_statement(const char *var, int cases, const char *funcname, const char *filename);
void generate_case_statement(int value, const char *filename);
void generate_default_case(const char *filename);
void generate_break_statement(const char *filename);
void generate_close_brace(const char *filename);
int variable_exists_in_function(const char *var, const char *funcname, const char *filename);
void generate_array(const char *array_name, int start, int end, const char *funcname, const char *filename);
void generate_array_iteration(const char *array_name, const char *index_var, const char *funcname, const char *filename);
void optimize_code(const char *filename);



extern int yylex();
extern FILE *yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}


/* Line 189 of yacc.c  */
#line 106 "file_operations.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     NUMBER = 259,
     CREATE = 260,
     DELETE = 261,
     FILE_TOKEN = 262,
     FUNCTION_TOKEN = 263,
     FOR = 264,
     LOOP = 265,
     UP = 266,
     TO = 267,
     WITH = 268,
     INCREMENT = 269,
     IN = 270,
     UP_TO = 271,
     IF = 272,
     ELSE = 273,
     SWITCH = 274,
     CASE = 275,
     DEFAULT = 276,
     BREAK = 277,
     COLON = 278,
     CONDITIONS = 279,
     ITERATE = 280,
     ARRAY = 281,
     USING = 282,
     INDEX = 283,
     FROM = 284,
     OPTIMIZE = 285,
     FUNCTIONS = 286,
     EQ = 287,
     NEQ = 288,
     LE = 289,
     GE = 290,
     LT = 291,
     GT = 292,
     CLOSE = 293,
     BRACE = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 33 ".\\file_operations.y"

    char* str;
    int num;
    char** str_array;



/* Line 214 of yacc.c  */
#line 189 "file_operations.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 201 "file_operations.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  2
/* YYNRULES -- Number of rules.  */
#define YYNRULES  27
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    11,    17,    23,    37,    41,    51,
      61,    71,    81,    91,   101,   112,   123,   134,   145,   156,
     167,   179,   185,   190,   195,   200,   212,   224
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,     5,     7,     3,    -1,     6,     7,     3,
      -1,     5,     8,     3,    15,     3,    -1,     6,     8,     3,
      15,     3,    -1,     5,     9,    10,     3,    16,     4,    13,
      14,     4,    15,     3,    15,     3,    -1,    30,     7,     3,
      -1,     5,    17,     3,    32,     4,    15,     3,    15,     3,
      -1,     5,    17,     3,    33,     4,    15,     3,    15,     3,
      -1,     5,    17,     3,    36,     4,    15,     3,    15,     3,
      -1,     5,    17,     3,    37,     4,    15,     3,    15,     3,
      -1,     5,    17,     3,    34,     4,    15,     3,    15,     3,
      -1,     5,    17,     3,    35,     4,    15,     3,    15,     3,
      -1,     5,    17,     3,    32,     4,    18,    15,     3,    15,
       3,    -1,     5,    17,     3,    33,     4,    18,    15,     3,
      15,     3,    -1,     5,    17,     3,    36,     4,    18,    15,
       3,    15,     3,    -1,     5,    17,     3,    37,     4,    18,
      15,     3,    15,     3,    -1,     5,    17,     3,    34,     4,
      18,    15,     3,    15,     3,    -1,     5,    17,     3,    35,
       4,    18,    15,     3,    15,     3,    -1,     5,    19,     3,
      24,    13,     4,    20,    15,     3,    15,     3,    -1,     5,
      20,     4,    15,     3,    -1,     5,    21,    15,     3,    -1,
       5,    22,    15,     3,    -1,    38,    39,    15,     3,    -1,
       5,    26,     3,    29,     4,    12,     4,    15,     3,    15,
       3,    -1,     5,    25,    26,     3,    27,    28,     3,    15,
       3,    15,     3,    -1,     5,     7,     3,    13,     4,    31,
       3,     3,     3,     3,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    53,    57,    62,    67,    73,    77,    83,
      89,    95,   101,   107,   113,   119,   125,   131,   137,   143,
     149,   155,   159,   163,   167,   171,   178,   185
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "NUMBER", "CREATE",
  "DELETE", "FILE_TOKEN", "FUNCTION_TOKEN", "FOR", "LOOP", "UP", "TO",
  "WITH", "INCREMENT", "IN", "UP_TO", "IF", "ELSE", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "COLON", "CONDITIONS", "ITERATE", "ARRAY", "USING",
  "INDEX", "FROM", "OPTIMIZE", "FUNCTIONS", "EQ", "NEQ", "LE", "GE", "LT",
  "GT", "CLOSE", "BRACE", "$accept", "command", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     5,     5,    13,     3,     9,     9,
       9,     9,     9,     9,    10,    10,    10,    10,    10,    10,
      11,     5,     4,     4,     4,    11,    11,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,    24,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     9,     0,    12,     0,    13,     0,    10,     0,    11,
       0,     0,     0,     0,     0,     0,    14,    15,    18,    19,
      16,    17,     0,     0,     0,    27,     0,    20,    26,    25,
       0,     6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -38
static const yytype_int16 yypact[] =
{
      -5,    -4,    31,     7,   -37,    12,    16,    27,    26,    37,
      38,    39,    29,    30,    20,    44,    45,    46,    47,    36,
     -38,    40,    41,    49,   -26,    18,    42,    51,    52,    55,
      32,   -38,    48,   -38,    56,    58,    57,    50,    60,    61,
      63,    64,    65,    66,    59,    68,   -38,   -38,    53,    69,
      71,   -38,    54,   -38,    72,     5,     9,    11,    13,    17,
      19,    73,   -38,    62,    67,   -38,    75,    70,    78,    74,
      79,    76,    81,    77,    83,    80,    84,    82,    85,    86,
      87,    90,    92,    91,    88,    89,    95,    93,    96,    94,
      97,    98,   100,    99,   102,   101,   103,   104,   105,   106,
     107,   108,   112,   109,   114,   110,   115,   111,   119,   113,
     120,   116,   124,   117,   126,   127,   130,   131,   121,   -38,
     132,   -38,   134,   -38,   135,   -38,   136,   -38,   137,   -38,
     138,   128,   129,   133,   139,   142,   -38,   -38,   -38,   -38,
     -38,   -38,   143,   144,   146,   -38,   140,   -38,   -38,   -38,
     147,   -38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       1,     2,    19,     6,     7,     8,    38,    39,    40,    41,
      42,    43,    20,     9,    18,    10,    11,    12,    13,    21,
      68,    14,    15,    69,    70,     3,    72,    71,    74,    73,
      22,    75,    76,     4,    78,    77,    23,    79,    16,    17,
      24,    25,    44,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    37,    35,    46,    47,    36,    45,    48,    51,
      53,    49,    52,    50,    55,    56,    54,    57,    58,    59,
      60,    62,    61,    64,    65,     0,    67,    80,    83,    82,
      63,    85,    87,    84,    89,    66,    91,    93,    95,    86,
      81,    88,    90,    98,   100,    92,    99,    94,   103,   105,
     107,    96,   101,   109,   102,   111,   113,    97,   104,   106,
     117,     0,   118,   108,   110,   119,   112,   121,   123,   114,
     115,   116,   125,   127,   120,   122,   124,   129,   126,   131,
     132,   128,   130,   133,   134,   136,   135,   137,   138,   139,
     140,   141,   145,   142,   143,   146,   147,   148,   144,   149,
     151,     0,     0,     0,     0,   150
};

static const yytype_int8 yycheck[] =
{
       5,     6,    39,     7,     8,     9,    32,    33,    34,    35,
      36,    37,     0,    17,     7,    19,    20,    21,    22,     3,
      15,    25,    26,    18,    15,    30,    15,    18,    15,    18,
       3,    18,    15,    38,    15,    18,    10,    18,     7,     8,
       3,     3,    24,     4,    15,    15,    26,     3,     3,     3,
       3,    15,     3,    13,     3,     3,    15,    15,     3,     3,
       3,    29,     4,    15,     4,     4,    16,     4,     4,     4,
       4,     3,    13,     4,     3,    -1,     4,     4,     3,    12,
      27,     3,     3,    13,     3,    31,     3,     3,     3,    15,
      28,    15,    15,     3,     3,    15,     4,    15,     3,     3,
       3,    15,    14,     3,    15,     3,     3,    20,    15,    15,
       3,    -1,     4,    15,    15,     3,    15,     3,     3,    15,
      15,    15,     3,     3,    15,    15,    15,     3,    15,     3,
       3,    15,    15,     3,     3,     3,    15,     3,     3,     3,
       3,     3,     3,    15,    15,     3,     3,     3,    15,     3,
       3,    -1,    -1,    -1,    -1,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    30,    38,    41,     7,     8,     9,    17,
      19,    20,    21,    22,    25,    26,     7,     8,     7,    39,
       0,     3,     3,    10,     3,     3,     4,    15,    15,    26,
       3,     3,     3,     3,    15,    13,    15,     3,    32,    33,
      34,    35,    36,    37,    24,    15,     3,     3,     3,    29,
      15,     3,     4,     3,    16,     4,     4,     4,     4,     4,
       4,    13,     3,    27,     4,     3,    31,     4,    15,    18,
      15,    18,    15,    18,    15,    18,    15,    18,    15,    18,
       4,    28,    12,     3,    13,     3,    15,     3,    15,     3,
      15,     3,    15,     3,    15,     3,    15,    20,     3,     4,
       3,    14,    15,     3,    15,     3,    15,     3,    15,     3,
      15,     3,    15,     3,    15,    15,    15,     3,     4,     3,
      15,     3,    15,     3,    15,     3,    15,     3,    15,     3,
      15,     3,     3,     3,     3,    15,     3,     3,     3,     3,
       3,     3,    15,    15,    15,     3,     3,     3,     3,     3,
      15,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 49 ".\\file_operations.y"
    {
        generate_create_file((yyvsp[(3) - (3)].str));
        free((yyvsp[(3) - (3)].str));
      ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 53 ".\\file_operations.y"
    {
        generate_delete_file((yyvsp[(3) - (3)].str));
        free((yyvsp[(3) - (3)].str));
      ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 57 ".\\file_operations.y"
    {
        generate_add_function((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str));
        free((yyvsp[(3) - (5)].str));
        free((yyvsp[(5) - (5)].str));
      ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 62 ".\\file_operations.y"
    {
        generate_delete_function((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str));
        free((yyvsp[(3) - (5)].str));
        free((yyvsp[(5) - (5)].str));
      ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 67 ".\\file_operations.y"
    {
        generate_for_loop((yyvsp[(4) - (13)].str), (yyvsp[(6) - (13)].num), (yyvsp[(9) - (13)].num), (yyvsp[(11) - (13)].str), (yyvsp[(13) - (13)].str));
        free((yyvsp[(4) - (13)].str));
        free((yyvsp[(11) - (13)].str));
        free((yyvsp[(13) - (13)].str));
      ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 73 ".\\file_operations.y"
    {
        optimize_code((yyvsp[(3) - (3)].str));
        free((yyvsp[(3) - (3)].str));
      ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 77 ".\\file_operations.y"
    {
        generate_if_statement((yyvsp[(3) - (9)].str), "==", (yyvsp[(5) - (9)].num), (yyvsp[(7) - (9)].str), (yyvsp[(9) - (9)].str));
        free((yyvsp[(3) - (9)].str));
        free((yyvsp[(7) - (9)].str));
        free((yyvsp[(9) - (9)].str));
      ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 83 ".\\file_operations.y"
    {
        generate_if_statement((yyvsp[(3) - (9)].str), "!=", (yyvsp[(5) - (9)].num), (yyvsp[(7) - (9)].str), (yyvsp[(9) - (9)].str));
        free((yyvsp[(3) - (9)].str));
        free((yyvsp[(7) - (9)].str));
        free((yyvsp[(9) - (9)].str));
      ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 89 ".\\file_operations.y"
    {
        generate_if_statement((yyvsp[(3) - (9)].str), "<", (yyvsp[(5) - (9)].num), (yyvsp[(7) - (9)].str), (yyvsp[(9) - (9)].str));
        free((yyvsp[(3) - (9)].str));
        free((yyvsp[(7) - (9)].str));
        free((yyvsp[(9) - (9)].str));
      ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 95 ".\\file_operations.y"
    {
        generate_if_statement((yyvsp[(3) - (9)].str), ">", (yyvsp[(5) - (9)].num), (yyvsp[(7) - (9)].str), (yyvsp[(9) - (9)].str));
        free((yyvsp[(3) - (9)].str));
        free((yyvsp[(7) - (9)].str));
        free((yyvsp[(9) - (9)].str));
      ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 101 ".\\file_operations.y"
    {
        generate_if_statement((yyvsp[(3) - (9)].str), "<=", (yyvsp[(5) - (9)].num), (yyvsp[(7) - (9)].str), (yyvsp[(9) - (9)].str));
        free((yyvsp[(3) - (9)].str));
        free((yyvsp[(7) - (9)].str));
        free((yyvsp[(9) - (9)].str));
      ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 107 ".\\file_operations.y"
    {
        generate_if_statement((yyvsp[(3) - (9)].str), ">=", (yyvsp[(5) - (9)].num), (yyvsp[(7) - (9)].str), (yyvsp[(9) - (9)].str));
        free((yyvsp[(3) - (9)].str));
        free((yyvsp[(7) - (9)].str));
        free((yyvsp[(9) - (9)].str));
      ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 113 ".\\file_operations.y"
    {
        generate_if_else_statement((yyvsp[(3) - (10)].str), "==", (yyvsp[(5) - (10)].num), (yyvsp[(8) - (10)].str), (yyvsp[(10) - (10)].str));
        free((yyvsp[(3) - (10)].str));
        free((yyvsp[(8) - (10)].str));
        free((yyvsp[(10) - (10)].str));
      ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 119 ".\\file_operations.y"
    {
        generate_if_else_statement((yyvsp[(3) - (10)].str), "!=", (yyvsp[(5) - (10)].num), (yyvsp[(8) - (10)].str), (yyvsp[(10) - (10)].str));
        free((yyvsp[(3) - (10)].str));
        free((yyvsp[(8) - (10)].str));
        free((yyvsp[(10) - (10)].str));
      ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 125 ".\\file_operations.y"
    {
        generate_if_else_statement((yyvsp[(3) - (10)].str), "<", (yyvsp[(5) - (10)].num), (yyvsp[(8) - (10)].str), (yyvsp[(10) - (10)].str));
        free((yyvsp[(3) - (10)].str));
        free((yyvsp[(8) - (10)].str));
        free((yyvsp[(10) - (10)].str));
      ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 131 ".\\file_operations.y"
    {
        generate_if_else_statement((yyvsp[(3) - (10)].str), ">", (yyvsp[(5) - (10)].num), (yyvsp[(8) - (10)].str), (yyvsp[(10) - (10)].str));
        free((yyvsp[(3) - (10)].str));
        free((yyvsp[(8) - (10)].str));
        free((yyvsp[(10) - (10)].str));
      ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 137 ".\\file_operations.y"
    {
        generate_if_else_statement((yyvsp[(3) - (10)].str), "<=", (yyvsp[(5) - (10)].num), (yyvsp[(8) - (10)].str), (yyvsp[(10) - (10)].str));
        free((yyvsp[(3) - (10)].str));
        free((yyvsp[(8) - (10)].str));
        free((yyvsp[(10) - (10)].str));
      ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 143 ".\\file_operations.y"
    {
        generate_if_else_statement((yyvsp[(3) - (10)].str), ">=", (yyvsp[(5) - (10)].num), (yyvsp[(8) - (10)].str), (yyvsp[(10) - (10)].str));
        free((yyvsp[(3) - (10)].str));
        free((yyvsp[(8) - (10)].str));
        free((yyvsp[(10) - (10)].str));
      ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 149 ".\\file_operations.y"
    {
        generate_switch_statement((yyvsp[(3) - (11)].str), (yyvsp[(6) - (11)].num), (yyvsp[(9) - (11)].str), (yyvsp[(11) - (11)].str));
        free((yyvsp[(3) - (11)].str));
        free((yyvsp[(9) - (11)].str));
        free((yyvsp[(11) - (11)].str));
      ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 155 ".\\file_operations.y"
    {
        generate_case_statement((yyvsp[(3) - (5)].num), (yyvsp[(5) - (5)].str));
        free((yyvsp[(5) - (5)].str));
      ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 159 ".\\file_operations.y"
    {
        generate_default_case((yyvsp[(4) - (4)].str));
        free((yyvsp[(4) - (4)].str));
      ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 163 ".\\file_operations.y"
    {
        generate_break_statement((yyvsp[(4) - (4)].str));
        free((yyvsp[(4) - (4)].str));
      ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 167 ".\\file_operations.y"
    {
        generate_close_brace((yyvsp[(4) - (4)].str));
        free((yyvsp[(4) - (4)].str));
      ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 171 ".\\file_operations.y"
    {
        generate_array((yyvsp[(3) - (11)].str), (yyvsp[(5) - (11)].num), (yyvsp[(7) - (11)].num), (yyvsp[(9) - (11)].str), (yyvsp[(11) - (11)].str));
        free((yyvsp[(3) - (11)].str));
        free((yyvsp[(9) - (11)].str));
        free((yyvsp[(11) - (11)].str));
      ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 178 ".\\file_operations.y"
    {
        generate_array_iteration((yyvsp[(4) - (11)].str), (yyvsp[(7) - (11)].str), (yyvsp[(9) - (11)].str), (yyvsp[(11) - (11)].str));
        free((yyvsp[(4) - (11)].str));
        free((yyvsp[(7) - (11)].str));
        free((yyvsp[(9) - (11)].str));
        free((yyvsp[(11) - (11)].str));
      ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 185 ".\\file_operations.y"
    {
        generate_create_file((yyvsp[(3) - (11)].str));
        generate_add_function((yyvsp[(7) - (11)].str), (yyvsp[(3) - (11)].str));
        generate_add_function((yyvsp[(8) - (11)].str), (yyvsp[(3) - (11)].str));
        generate_add_function((yyvsp[(9) - (11)].str), (yyvsp[(3) - (11)].str));
        generate_add_function((yyvsp[(10) - (11)].str), (yyvsp[(3) - (11)].str));
        generate_add_function((yyvsp[(11) - (11)].str), (yyvsp[(3) - (11)].str));
        free((yyvsp[(3) - (11)].str));
        free((yyvsp[(7) - (11)].str));
        free((yyvsp[(8) - (11)].str));
        free((yyvsp[(9) - (11)].str));
        free((yyvsp[(10) - (11)].str));
        free((yyvsp[(11) - (11)].str));
      ;}
    break;



/* Line 1455 of yacc.c  */
#line 1800 "file_operations.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 201 ".\\file_operations.y"


/* Check if a variable exists in a function */
int variable_exists_in_function(const char *var, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "r");
    if (!fp) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return 0;
    }

    char line[256];
    int in_function = 0;
    int var_found = 0;
    int brace_count = 0;
    char function_pattern[256];
    
    // Create pattern to search for function
    snprintf(function_pattern, sizeof(function_pattern), "%s(", funcname);
    
    while (fgets(line, sizeof(line), fp)) {
        // Check if we're entering the target function
        if (!in_function && strstr(line, function_pattern)) {
            in_function = 1;
        }
        
        // If in function, check for variable declaration or usage
        if (in_function) {
            // Count braces to track function scope
            for (char *c = line; *c; c++) {
                if (*c == '{') brace_count++;
                if (*c == '}') brace_count--;
            }
            
            // Check if we've exited the function
            if (brace_count <= 0 && strstr(line, "}")) {
                break;
            }
            
            // Check for variable in different contexts
            char var_pattern[256];
            snprintf(var_pattern, sizeof(var_pattern), "int %s", var); // Check for declaration
            
            if (strstr(line, var_pattern) || 
                (strstr(line, var) && (line[0] == ' ' || line[0] == '\t'))) {
                var_found = 1;
                break;
            }
        }
    }
    
    fclose(fp);
    return var_found;
}

void generate_create_file(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *check = fopen(full_name, "r");
    if (check) {
        fclose(check);
        printf("File '%s' already exists.\n", full_name);
        return;
    }

    FILE *fp = fopen(full_name, "w");
    if (!fp) {
        perror("Create file error");
        return;
    }

    fprintf(fp, "#include <stdio.h>\n\nint main() {\n    return 0;\n}\n");
    fclose(fp);
    printf("File '%s' created.\n", full_name);
}

void generate_delete_file(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *check = fopen(full_name, "r");
    if (!check) {
        printf("File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(check);

    if (remove(full_name) == 0)
        printf("File '%s' deleted.\n", full_name);
    else
        perror("Delete file error");
}

void generate_add_function(const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *check_fp = fopen(full_name, "r");
    if (!check_fp) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }

    char line[256];
    int exists = 0;

    while (fgets(line, sizeof(line), check_fp)) {
        if (strstr(line, funcname) && strstr(line, "void")) {
            exists = 1;
            break;
        }
    }
    fclose(check_fp);

    if (exists) {
        printf("Function '%s' already exists in %s.\n", funcname, full_name);
        return;
    }

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "\nvoid %s() {\n    // TODO: implement %s\n}\n", funcname, funcname);
    fclose(fp);
    printf("Function '%s' added to %s.\n", funcname, full_name);
}

void generate_delete_function(const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "r");
    if (!fp) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }

    FILE *temp = fopen("temp.c", "w");
    if (!temp) {
        fclose(fp);
        perror("Error creating temporary file");
        return;
    }

    char line[256];
    int found = 0, skip = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (!skip && strstr(line, funcname) && strstr(line, "void")) {
            found = 1;
            skip = 1;
            continue;
        }
        if (skip && strstr(line, "}")) {
            skip = 0;
            continue;
        }
        if (!skip) fputs(line, temp);
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        remove("temp.c");
        printf("Function '%s' not found in %s.\n", funcname, full_name);
        return;
    }

    remove(full_name);
    rename("temp.c", full_name);
    printf("Function '%s' deleted from %s.\n", funcname, full_name);
}

long find_insertion_point_in_function(const char *file_content, const char *funcname) {
    // Create pattern to search for function
    char pattern[256];
    snprintf(pattern, sizeof(pattern), "%s(", funcname);
    
    char *func_pos = strstr(file_content, pattern);
    if (!func_pos) {
        return -1; // Function not found
    }
    
    // Find the opening brace of the function
    char *brace_pos = strchr(func_pos, '{');
    if (!brace_pos) {
        return -1; // Opening brace not found
    }
    
    // Now find the right position to insert code - this should be right before the 
    // closing brace of the function, not after content at brace level 1
    char *current_pos = brace_pos + 1;
    int brace_level = 1;
    
    // Track the position until we find the closing brace of the function
    while (*current_pos && brace_level > 0) {
        if (*current_pos == '{') {
            brace_level++;
        } else if (*current_pos == '}') {
            brace_level--;
            
            // If this is the closing brace of the function, we found our spot
            if (brace_level == 0) {
                // Find the start of this line or the last newline before the brace
                char *line_start = current_pos;
                while (line_start > brace_pos && *(line_start-1) != '\n') {
                    line_start--;
                }
                
                // Return position right before the closing brace indentation
                return (line_start - file_content);
            }
        }
        
        current_pos++;
    }
    
    // If we couldn't find the closing brace for some reason, 
    // fall back to position after opening brace
    return (brace_pos - file_content) + 1;
}

// Now modify the generate_for_loop function to use the new helper function
void generate_for_loop(const char *var, int limit, int step, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    // First, let's check if the file exists
    FILE *fp = fopen(full_name, "r");
    if (!fp) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }

    // Read the entire file content into memory
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Create the for loop code with proper indentation
    char for_loop[256];
    snprintf(for_loop, sizeof(for_loop), 
             "    for (int %s = 0; %s < %d; %s += %d) {\n        // TODO: Add logic\n    }\n",
             var, var, limit, var, step);
    
    // Create a new file with the for loop inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write for loop
    fputs(for_loop, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("For loop with '%s' added to function '%s' in %s up to %d with step %d\n", 
           var, funcname, full_name, limit, step);
}

// Similarly, update generate_if_statement to use the new helper
void generate_if_statement(const char *var, const char *op, int value, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Check if function exists and variable exists in function
    if (!variable_exists_in_function(var, funcname, filename)) {
        printf("Error: Variable '%s' not found in function '%s' in file '%s'.\n", 
               var, funcname, full_name);
        return;
    }
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Create the if statement code with proper indentation
    char if_statement[256];
    snprintf(if_statement, sizeof(if_statement), 
             "    if (%s %s %d) {\n        // TODO: Add logic for if condition\n    }\n",
             var, op, value);
    
    // Create a new file with the if statement inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write if statement
    fputs(if_statement, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("If statement for '%s %s %d' added to function '%s' in %s\n", 
           var, op, value, funcname, full_name);
}

// Update generate_if_else_statement to use the new helper
void generate_if_else_statement(const char *var, const char *op, int value, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Check if function exists and variable exists in function
    if (!variable_exists_in_function(var, funcname, filename)) {
        printf("Error: Variable '%s' not found in function '%s' in file '%s'.\n", 
               var, funcname, full_name);
        return;
    }
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Create the if-else statement code with proper indentation
    char if_else_statement[256];
    snprintf(if_else_statement, sizeof(if_else_statement), 
             "    if (%s %s %d) {\n        // TODO: Add logic for if condition\n    } else {\n        // TODO: Add logic for else condition\n    }\n",
             var, op, value);
    
    // Create a new file with the if-else statement inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write if-else statement
    fputs(if_else_statement, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("If-else statement for '%s %s %d' added to function '%s' in %s\n", 
           var, op, value, funcname, full_name);
}

// Update generate_switch_statement to use the new helper
void generate_switch_statement(const char *var, int cases, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Check if function exists and variable exists in function
    if (!variable_exists_in_function(var, funcname, filename)) {
        printf("Error: Variable '%s' not found in function '%s' in file '%s'.\n", 
               var, funcname, full_name);
        return;
    }
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Create buffer for the switch statement
    char *switch_code = (char *)malloc(1024);
    if (!switch_code) {
        free(file_content);
        perror("Memory allocation error");
        return;
    }
    
    // Start the switch statement with proper indentation
    sprintf(switch_code, "    switch (%s) {\n", var);
    
    // Add the specified number of cases
    for (int i = 1; i <= cases; i++) {
        char case_code[256];
        sprintf(case_code, "        case %d:\n            // TODO: Add logic for case %d\n            break;\n", i, i);
        strcat(switch_code, case_code);
    }
    
    // Add default case and close the switch
    strcat(switch_code, "        default:\n            // TODO: Add logic for default case\n            break;\n    }\n");
    
    // Create a new file with the switch statement inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        free(switch_code);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write switch statement
    fputs(switch_code, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    free(switch_code);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("Switch statement for '%s' with %d cases added to function '%s' in %s\n", 
           var, cases, funcname, full_name);
}

void generate_case_statement(int value, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file for case statement");
        return;
    }

    fprintf(fp, "    case %d:\n        // TODO: Add logic for case %d\n", value, value);
    fclose(fp);
    printf("Case %d added to %s\n", value, full_name);
}

void generate_default_case(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file for default case");
        return;
    }

    fprintf(fp, "    default:\n        // TODO: Add logic for default case\n");
    fclose(fp);
    printf("Default case added to %s\n", full_name);
}

void generate_break_statement(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file for break statement");
        return;
    }

    fprintf(fp, "        break;\n");
    fclose(fp);
    printf("Break statement added to %s\n", full_name);
}

void generate_close_brace(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file to close brace");
        return;
    }

    fprintf(fp, "}\n");
    fclose(fp);
    printf("Closing brace added to %s\n", full_name);
}

void generate_array(const char *array_name, int start, int end, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Calculate array size
    int size = end - start + 1;
    if (size <= 0) {
        printf("Error: Invalid array range (start: %d, end: %d).\n", start, end);
        free(file_content);
        return;
    }
    
    // Create array declaration and initialization
    char *array_code = (char *)malloc(size * 20 + 256); // Allocate enough space
    if (!array_code) {
        free(file_content);
        perror("Memory allocation error");
        return;
    }
    
    // Create array declaration with proper indentation
    sprintf(array_code, "    int %s[%d] = {", array_name, size);
    
    // Initialize array with values
    for (int i = 0; i < size; i++) {
        char value[20];
        sprintf(value, "%d", start + i);
        
        // Add comma except for the last element
        if (i < size - 1) {
            strcat(value, ", ");
        }
        
        strcat(array_code, value);
        
        // Add line break every 10 elements for readability
        if ((i + 1) % 10 == 0 && i < size - 1) {
            strcat(array_code, "\n        ");
        }
    }
    
    // Close the array initialization
    strcat(array_code, "};\n");
    
    // Create a new file with the array inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        free(array_code);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write array code
    fputs(array_code, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    free(array_code);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("Array '%s' with range [%d-%d] (size: %d) added to function '%s' in %s\n", 
           array_name, start, end, size, funcname, full_name);
}

void generate_array_iteration(const char *array_name, const char *index_var, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Check if function exists and array exists in function
    if (!variable_exists_in_function(array_name, funcname, filename)) {
        printf("Error: Array '%s' not found in function '%s' in file '%s'.\n", 
               array_name, funcname, full_name);
        return;
    }
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point (at the end of the function)
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Try to determine array size
    char *array_size = NULL;
    char *array_decl_pos = strstr(file_content, array_name);
    if (array_decl_pos) {
        char *open_bracket = strchr(array_decl_pos, '[');
        if (open_bracket) {
            char *close_bracket = strchr(open_bracket, ']');
            if (close_bracket && close_bracket > open_bracket) {
                int size = close_bracket - open_bracket - 1;
                array_size = (char *)malloc(size + 1);
                strncpy(array_size, open_bracket + 1, size);
                array_size[size] = '\0';
            }
        }
    }
    
    // Create the array iteration code
    char *iteration_code = (char *)malloc(512);
    if (!iteration_code) {
        free(file_content);
        if (array_size) free(array_size);
        perror("Memory allocation error");
        return;
    }
    
    if (array_size) {
        // If we found the array size, use it
        sprintf(iteration_code, 
                "    // Iterating through array %s\n    for (int %s = 0; %s < %s; %s++) {\n"
                "        // TODO: Process %s[%s]\n"
                "        // Example: printf(\"%%d \", %s[%s]);\n"
                "    }\n",
                array_name, index_var, index_var, array_size, index_var,
                array_name, index_var, array_name, index_var);
        free(array_size);
    } else {
        // If we couldn't determine the size, add a placeholder
        sprintf(iteration_code, 
                "    // Iterating through array %s\n    for (int %s = 0; %s < ARRAY_SIZE; %s++) {\n"
                "        // TODO: Replace ARRAY_SIZE with the actual size of %s\n"
                "        // TODO: Process %s[%s]\n"
                "        // Example: printf(\"%%d \", %s[%s]);\n"
                "    }\n",
                array_name, index_var, index_var, index_var, array_name,
                array_name, index_var, array_name, index_var);
    }
    
    // Create a new file with the iteration code inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        free(iteration_code);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write iteration code
    fputs(iteration_code, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    free(iteration_code);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("Array iteration for '%s' using index '%s' added to function '%s' in %s\n", 
           array_name, index_var, funcname, full_name);
}

void optimize_code(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    
    // Read the entire file content
    fseek(fp_check, 0, SEEK_END);
    long file_size = ftell(fp_check);
    fseek(fp_check, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp_check);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp_check);
    file_content[read_size] = '\0';
    fclose(fp_check);
    
    // Create a new temporary file
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        perror("Error creating temporary file");
        return;
    }
    
    // Track changes made
    int changes = 0;
    char *optimized_content = strdup(file_content);
    if (!optimized_content) {
        free(file_content);
        fclose(out);
        perror("Memory allocation error");
        return;
    }
    
   
    char *ptr = optimized_content;
    while ((ptr = strstr(ptr, "int ")) != NULL) {
        // Check if variable is used
        char var_name[100] = {0};
        if (sscanf(ptr + 4, "%99[a-zA-Z0-9_]", var_name) == 1) {
          
            char *first_use = ptr;
            char *next_use = ptr + strlen(var_name) + 4;
            
           
            char search_pattern[150];
            snprintf(search_pattern, sizeof(search_pattern), "%s", var_name);
            
            int usage_count = 0;
            char *search_pos = optimized_content;
            while ((search_pos = strstr(search_pos, search_pattern)) != NULL) {
                // Check if this is a proper variable usage
                char prev_char = (search_pos > optimized_content) ? *(search_pos - 1) : ' ';
                char next_char = *(search_pos + strlen(search_pattern));
                
                if ((prev_char == ' ' || prev_char == '\t' || prev_char == '(' || prev_char == '=') &&
                    (next_char == ' ' || next_char == ';' || next_char == ')' || next_char == ',' || 
                     next_char == '+' || next_char == '-' || next_char == '*' || next_char == '/')) {
                    usage_count++;
                }
                search_pos += strlen(search_pattern);
            }
            
            // If used exactly once (declaration), mark for potential optimization
            if (usage_count == 1) {
                // We would normally optimize this, but for now we'll just notify
                changes++;
            }
        }
        ptr++;
    }
    
    // 2. Optimize loop conditions
    ptr = optimized_content;
    while ((ptr = strstr(ptr, "for (")) != NULL) {
        char init[100], cond[100], incr[100];
        // Try to parse the for loop components
        if (sscanf(ptr + 5, "%99[^;];%99[^;];%99[^)]", init, cond, incr) == 3) {
            // Check if we can optimize the loop
            if (strstr(cond, "<") && !strstr(cond, "=")) {
                // Convert "i < n" to "i != n" for certain loops where appropriate
                if (strstr(incr, "++") || strstr(incr, "+=1")) {
                    char *lt_pos = strstr(cond, "<");
                    if (lt_pos) {
                        // Replace < with != where it makes sense
                        // This is a heuristic optimization that works in some cases
                        memcpy(lt_pos, "!=", 2);
                        changes++;
                    }
                }
            }
        }
        ptr++;
    }
    
    // 3. Optimize redundant code
    ptr = optimized_content;
    while ((ptr = strstr(ptr, "if (")) != NULL) {
        // Look for redundant conditions like "if (x == true)" or "if (x == false)"
        char cond[100];
        if (sscanf(ptr + 4, "(%99[^)])", cond) == 1) {
            if (strstr(cond, "== true")) {
                // Replace "x == true" with "x"
                char *true_pos = strstr(cond, "== true");
                size_t prefix_len = true_pos - cond;
                
                // Ensure we have space for the string manipulation
                char *new_condition = (char *)malloc(strlen(cond) + 1);
                if (new_condition) {
                    strncpy(new_condition, cond, prefix_len);
                    new_condition[prefix_len] = '\0';
                    strcat(new_condition, true_pos + 7); // Skip "== true"
                    
                    // Replace in optimized content
                    char *start_of_condition = ptr + 4;
                    char *end_of_condition = strchr(start_of_condition, ')');
                    if (end_of_condition) {
                        size_t old_len = end_of_condition - start_of_condition;
                        size_t new_len = strlen(new_condition);
                        
                        if (new_len <= old_len) {
                            // Overwrite in place
                            memcpy(start_of_condition, new_condition, new_len);
                            // Fill rest with spaces
                            memset(start_of_condition + new_len, ' ', old_len - new_len);
                            changes++;
                        }
                    }
                    free(new_condition);
                }
            }
            else if (strstr(cond, "== false")) {
                // Replace "x == false" with "!x"
                char *false_pos = strstr(cond, "== false");
                size_t prefix_len = false_pos - cond;
                
                // Ensure we have space for the string manipulation
                char *new_condition = (char *)malloc(strlen(cond) + 2); // +2 for '!' and null terminator
                if (new_condition) {
                    new_condition[0] = '!';
                    strncpy(new_condition + 1, cond, prefix_len);
                    new_condition[prefix_len + 1] = '\0';
                    strcat(new_condition, false_pos + 8); // Skip "== false"
                    
                    // Replace in optimized content
                    char *start_of_condition = ptr + 4;
                    char *end_of_condition = strchr(start_of_condition, ')');
                    if (end_of_condition) {
                        size_t old_len = end_of_condition - start_of_condition;
                        size_t new_len = strlen(new_condition);
                        
                        if (new_len <= old_len) {
                            // Overwrite in place
                            memcpy(start_of_condition, new_condition, new_len);
                            // Fill rest with spaces
                            memset(start_of_condition + new_len, ' ', old_len - new_len);
                            changes++;
                        }
                    }
                    free(new_condition);
                }
            }
        }
        ptr++;
    }
    
    // 4. Loop unrolling optimization detection
    ptr = optimized_content;
    while ((ptr = strstr(ptr, "for (")) != NULL) {
        int loop_count = 0;
        // Check if this is a simple counting loop
        if (sscanf(ptr, "for (int %*[^=]= %*d; %*[^<]< %d; %*[^{]{", &loop_count) == 1) {
            // If the loop count is very small, consider unrolling
            if (1 <= loop_count && loop_count <= 3) {
                // For demonstration we're just marking potential unroll candidates
                changes++;
            }
        }
        ptr++;
    }
    
    // 5. Constant folding optimization
    ptr = optimized_content;
    while ((ptr = strstr(ptr, " = ")) != NULL) {
        int a, b, result;
        char op;
        
        // Match patterns like: x = 5 + 3; or x = 10 * 2;
        if (sscanf(ptr + 3, "%d %c %d;", &a, &op, &b) == 3) {
            switch (op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b != 0) result = a / b; 
                    else goto next_expr; // Skip division by zero
                    break;
                default: goto next_expr; // Skip if not a basic arithmetic operator
            }
            
            // Format the replacement expression
            char new_expr[50];
            snprintf(new_expr, sizeof(new_expr), " = %d;", result);
            
            // Find the end of the original expression
            char *expr_end = strchr(ptr + 3, ';');
            if (expr_end) {
                size_t old_len = (expr_end - ptr) - 2; // -2 to exclude " = "
                size_t new_len = strlen(new_expr) - 3;  // -3 to exclude " = "
                
                // Replace the expression
                if (new_len <= old_len) {
                    memcpy(ptr + 3, new_expr + 3, new_len);
                    // Fill rest with spaces
                    memset(ptr + 3 + new_len, ' ', old_len - new_len);
                    changes++;
                }
            }
        }
next_expr:
        ptr++;
    }
    
    // Write optimized content to the output file
    fputs(optimized_content, out);
    fclose(out);
    free(file_content);
    free(optimized_content);
    
    // Replace original file with the optimized one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("Code optimization complete for %s. %d potential optimization points identified.\n", 
           full_name, changes);
}
int main() {
    FILE *fp = fopen("command.txt", "r");
    if (!fp) {
        perror("command.txt not found");
        return 1;
    }

    yyin = fp;
    yyparse();
    fclose(fp);
    return 0;
}
