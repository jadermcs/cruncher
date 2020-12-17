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
#line 14 "src/cruncher_syntax.y" /* yacc.c:339  */

#include "cruncher.h"
#include "ast.h"
#define utstring_fromint(value) \
    UT_string * tmp; \
    utstring_new(tmp); \
    utstring_printf(tmp, "%d", value);

extern int yylineno;
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylex_destroy();
extern void yyerror(const char* s);
extern labelStack *lhead;
int addr_counter;
int label_counter;
int param_counter;
struct ast* syntax_tree = NULL;

#line 87 "src/cruncher_syntax.tab.c" /* yacc.c:339  */

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
   by #include "cruncher_syntax.tab.h".  */
#ifndef YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED
# define YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHILE = 258,
    FOR = 259,
    IN = 260,
    IF = 261,
    ELSE = 262,
    CRUNCH = 263,
    RETURN = 264,
    NOTEQUAL_OP = 265,
    COMPARISON_OP = 266,
    LESSEQUAL_OP = 267,
    GREATEREQUAl_OP = 268,
    OR_OP = 269,
    AND_OP = 270,
    IDENTIFIER = 271,
    INTCONST = 272,
    FLOATCONST = 273,
    CHARCONST = 274,
    STRINGCONST = 275,
    PATHCONST = 276,
    TYPE = 277,
    CRUNCH_OP = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "src/cruncher_syntax.y" /* yacc.c:355  */

  char *id;
  char *type;
  char op;
  char *str;
  struct ast *node;

#line 159 "src/cruncher_syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "src/cruncher_syntax.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      26,    27,    35,    33,    30,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
      31,    25,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    71,    72,    76,    77,    81,    87,    96,
     103,    96,   112,   113,   114,   118,   126,   127,   131,   132,
     133,   134,   135,   136,   137,   141,   147,   156,   163,   163,
     186,   195,   200,   208,   219,   220,   224,   225,   229,   230,
     236,   242,   248,   255,   262,   263,   267,   277,   277,   306,
     306,   335,   338,   342,   347,   351,   357,   366,   374,   375,
     379,   380,   389,   390,   400,   401,   411,   412,   421,   433,
     434,   443,   452,   461,   473,   474,   481,   491,   492,   499,
     506,   516,   517,   521,   538,   539,   542,   547
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "FOR", "IN", "IF", "ELSE",
  "CRUNCH", "RETURN", "NOTEQUAL_OP", "COMPARISON_OP", "LESSEQUAL_OP",
  "GREATEREQUAl_OP", "OR_OP", "AND_OP", "IDENTIFIER", "INTCONST",
  "FLOATCONST", "CHARCONST", "STRINGCONST", "PATHCONST", "TYPE",
  "CRUNCH_OP", "';'", "'='", "'('", "')'", "'{'", "'}'", "','", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "program",
  "declarations", "declaration", "var_definition", "func_definition",
  "$@1", "$@2", "params", "param", "inner_declarations",
  "inner_declaration", "local_var_definition", "selection_statement",
  "$@3", "if_block", "return_statement", "crunch_statement", "file",
  "options", "term", "pathconst", "while_statement", "$@4",
  "for_statement", "$@5", "for_expression", "simple_expression",
  "sub_expression", "identifier", "expression", "assignment_expression",
  "conditional_expression", "and_expression", "eq_expression",
  "relational_expression", "add_expression", "mul_expression",
  "exp_statement", "call", "args", "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    59,    61,    40,    41,   123,   125,
      44,    60,    62,    43,    45,    42,    47,    37
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,    38,    58,    -4,  -136,  -136,  -136,  -136,    77,  -136,
    -136,  -136,    99,    55,  -136,  -136,  -136,  -136,  -136,    99,
    -136,  -136,    80,   -17,  -136,    83,    54,   136,    43,   124,
      74,  -136,    69,    72,    99,    99,  -136,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    38,   -19,  -136,  -136,  -136,  -136,    86,    76,    84,
    -136,  -136,  -136,    43,    43,   124,   124,   124,   124,    74,
      74,  -136,  -136,  -136,  -136,  -136,    69,  -136,    99,    95,
    -136,  -136,    11,   104,  -136,  -136,  -136,   107,    66,    38,
     123,  -136,  -136,  -136,   110,  -136,  -136,  -136,  -136,   -14,
    -136,  -136,   128,   152,     5,  -136,   106,   135,  -136,  -136,
      99,  -136,    99,    41,   158,  -136,  -136,  -136,  -136,    99,
      49,    50,    38,   155,   137,   178,  -136,   160,    40,   166,
     167,  -136,   174,    99,    99,     5,   185,     5,  -136,    11,
      11,    11,    42,  -136,  -136,   179,   180,   147,   171,   195,
      99,  -136,   184,   202,  -136,  -136,   188,  -136,   203,   191,
      11,   219,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     5,     6,    57,     9,     1,
       3,     7,     0,     0,    40,    41,    42,    43,    46,     0,
      77,    44,    39,     0,    59,    60,    62,    64,    66,    69,
      74,    45,    14,     0,     0,    85,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    38,    61,    87,    39,     0,    84,
      58,    63,    65,    68,    67,    71,    73,    70,    72,    75,
      76,    78,    79,    80,    15,    10,     0,    83,     0,     0,
      12,    86,     0,     0,    47,    49,    30,     0,     0,     0,
       0,    17,    24,    20,     0,    18,    22,    19,    21,     0,
      23,    82,     0,     0,     0,    32,     0,     0,    11,    16,
       0,    81,     0,     0,     0,    34,    35,    31,    25,     0,
       0,     0,     0,     0,     0,    54,    56,    37,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,    53,    52,     0,     0,     0,     0,     0,
       0,    36,     0,    27,    48,    50,    51,    33,     0,     0,
       0,     0,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   223,  -136,  -136,  -136,  -136,  -136,   153,
    -135,   -88,  -136,  -136,  -136,  -136,  -136,  -136,   -70,  -136,
     -26,  -101,  -136,  -136,  -136,  -136,  -136,  -136,  -136,     0,
     -12,    34,   192,   193,  -136,   130,    51,   138,  -136,  -136,
    -136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    13,    79,    52,    53,
      90,    91,    92,    93,   158,    94,    95,    96,   114,   137,
      20,    21,    97,   102,    98,   103,   123,   124,   125,    22,
      99,    24,    25,    26,    27,    28,    29,    30,   100,    31,
      58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,     8,   109,   115,   147,   148,   149,    36,    75,    56,
     111,    76,    83,    37,    84,    85,    37,    86,     1,    87,
      88,     7,    71,    72,    73,   161,    18,     7,    14,    15,
      16,    17,    18,    89,   115,    57,   115,    19,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    74,    81,    33,     7,    42,    43,     7,     9,   109,
     109,   109,   106,   122,   138,   144,   150,   146,    55,    39,
      37,    60,    37,   109,    44,    45,   129,   130,    57,    37,
      37,    32,     7,    14,    15,    16,    17,    18,    57,   107,
     105,    51,    19,    65,    66,    67,    68,    38,   120,    54,
     121,    11,    12,    77,   116,    34,    35,   128,   143,    48,
      49,    50,    35,   126,    78,     7,    14,    15,    16,    17,
      18,   142,   131,    82,    83,    19,    84,    85,   101,    86,
     117,    87,    88,   104,    57,   116,   110,   116,   156,     7,
      14,    15,    16,    17,    18,    89,    40,    41,    83,    19,
      84,    85,   108,    86,   112,    87,    88,    46,    47,   118,
     119,   133,   134,     7,    14,    15,    16,    17,    18,    89,
      63,    64,    83,    19,    84,    85,   153,    86,   113,    87,
      88,   127,   132,   135,    69,    70,   136,     7,    14,    15,
      16,    17,    18,    89,   139,   140,    83,    19,    84,    85,
     154,    86,   141,    87,    88,   145,   151,   152,   157,   -28,
     159,     7,    14,    15,    16,    17,    18,    89,    37,   160,
      83,    19,    84,    85,   155,    86,    10,    87,    88,    80,
      61,     0,    62,     0,     0,     7,    14,    15,    16,    17,
      18,    89,     0,     0,     0,    19,     0,     0,   162
};

static const yytype_int16 yycheck[] =
{
      12,     1,    90,   104,   139,   140,   141,    24,    27,    35,
      24,    30,     1,    30,     3,     4,    30,     6,    22,     8,
       9,    16,    48,    49,    50,   160,    21,    16,    17,    18,
      19,    20,    21,    22,   135,    35,   137,    26,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    78,    19,    16,    12,    13,    16,     0,   147,
     148,   149,    88,    22,    24,   135,    24,   137,    34,    15,
      30,    37,    30,   161,    31,    32,    27,    27,    78,    30,
      30,    26,    16,    17,    18,    19,    20,    21,    88,    89,
      24,    22,    26,    42,    43,    44,    45,    14,   110,    27,
     112,    24,    25,    27,   104,    25,    26,   119,   134,    35,
      36,    37,    26,   113,    30,    16,    17,    18,    19,    20,
      21,   133,   122,    28,     1,    26,     3,     4,    24,     6,
      24,     8,     9,    26,   134,   135,    26,   137,   150,    16,
      17,    18,    19,    20,    21,    22,    10,    11,     1,    26,
       3,     4,    29,     6,    26,     8,     9,    33,    34,    24,
      25,    24,    25,    16,    17,    18,    19,    20,    21,    22,
      40,    41,     1,    26,     3,     4,    29,     6,    26,     8,
       9,    23,    27,     5,    46,    47,    26,    16,    17,    18,
      19,    20,    21,    22,    28,    28,     1,    26,     3,     4,
      29,     6,    28,     8,     9,    20,    27,    27,    24,     7,
       7,    16,    17,    18,    19,    20,    21,    22,    30,    28,
       1,    26,     3,     4,    29,     6,     3,     8,     9,    76,
      38,    -1,    39,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    39,    40,    41,    42,    43,    16,    67,     0,
      41,    24,    25,    44,    17,    18,    19,    20,    21,    26,
      58,    59,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    77,    26,    69,    25,    26,    24,    30,    14,    15,
      10,    11,    12,    13,    31,    32,    33,    34,    35,    36,
      37,    22,    46,    47,    27,    69,    58,    67,    78,    79,
      69,    70,    71,    73,    73,    74,    74,    74,    74,    75,
      75,    58,    58,    58,    67,    27,    30,    27,    30,    45,
      47,    58,    28,     1,     3,     4,     6,     8,     9,    22,
      48,    49,    50,    51,    53,    54,    55,    60,    62,    68,
      76,    24,    61,    63,    26,    24,    58,    67,    29,    49,
      26,    24,    26,    26,    56,    59,    67,    24,    24,    25,
      68,    68,    22,    64,    65,    66,    67,    23,    68,    27,
      27,    67,    27,    24,    25,     5,    26,    57,    24,    28,
      28,    28,    68,    58,    56,    20,    56,    48,    48,    48,
      24,    27,    27,    29,    29,    29,    68,    24,    52,     7,
      28,    48,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    44,
      45,    43,    46,    46,    46,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    52,    51,
      53,    54,    54,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    61,    60,    63,
      62,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    77,    78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     0,
       0,    10,     3,     1,     0,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     7,     0,    12,
       1,     3,     2,     8,     1,     1,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     8,     0,
       8,     5,     3,     3,     1,     2,     1,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     2,     2,     4,     1,     0,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 67 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { syntax_tree = (yyvsp[0].node); }
#line 1497 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 71 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('D', (yyvsp[-1].node), (yyvsp[0].node));}
#line 1503 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1509 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1515 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1521 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
    (yyval.node)->dtype = (yyvsp[-2].type)[0];
    add_table((yyvsp[-1].node)->addr, 'V', (yyvsp[-2].type)[0]);
    free((yyvsp[-2].type));
  }
#line 1532 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 87 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('V', (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->dtype = (yyvsp[-4].type)[0];
    add_table((yyvsp[-3].node)->addr, 'V', (yyvsp[-4].type)[0]);
    free((yyvsp[-4].type));
  }
#line 1543 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    addr_counter = 0;
    label_counter = 0;
    param_counter = 0;
    gen_fmt("\n");
    gen_label((yyvsp[0].node)->addr);
  }
#line 1555 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 103 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {;}
#line 1561 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 104 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('F', NULL, (yyvsp[-1].node));
    add_table((yyvsp[-8].node)->addr, 'F', (yyvsp[-9].type)[0]);
    free((yyvsp[-9].type));
  }
#line 1571 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 112 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('P', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1577 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 113 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1583 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 114 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1589 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 118 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('A', (yyvsp[0].node), NULL);
    add_symbol((yyvsp[0].node)->addr, 'P', (yyvsp[-1].type)[0]);
    free((yyvsp[-1].type));
  }
#line 1599 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('S', (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1605 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1611 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1617 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1623 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 133 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1629 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 134 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1635 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 135 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1641 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 136 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1647 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 137 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1653 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 141 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
    (yyval.node)->dtype = (yyvsp[-2].type)[0];
    add_symbol((yyvsp[-1].node)->addr, 'V', (yyvsp[-2].type)[0]);
    free((yyvsp[-2].type));
  }
#line 1664 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('V', (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->dtype = (yyvsp[-4].type)[0];
    add_symbol((yyvsp[-3].node)->addr, 'V', (yyvsp[-4].type)[0]);
    free((yyvsp[-4].type));
  }
#line 1675 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 156 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('E', newast('E', (yyvsp[-4].node), (yyvsp[-1].node)), NULL);
    
    labelStack *tmp;
    STACK_POP(lhead, tmp);
    gen_label(tmp->label);
  }
#line 1687 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 163 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {

    char tmp_label[5];
    new_label(tmp_label);
    gen1("jump", tmp_label);

    labelStack *a_tmp;
    STACK_POP(lhead, a_tmp);
    gen_label(a_tmp->label);

    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    strcpy(ltmp->label, tmp_label);
    STACK_PUSH(lhead, ltmp);
  }
#line 1706 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 177 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('E', newast('E', (yyvsp[-9].node), (yyvsp[-6].node)), (yyvsp[-1].node));
    labelStack *tmp;
    STACK_POP(lhead, tmp);
    gen_label(tmp->label);
  }
#line 1717 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    char tmp_label[5];
    new_label(tmp_label);
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    strcpy(ltmp->label, tmp_label);
    STACK_PUSH(lhead, ltmp);
  }
#line 1729 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 195 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('J', (yyvsp[-1].node), NULL);
    (yyval.node)->dtype = (yyvsp[-1].node)->dtype;
    gen1("return", (yyvsp[-1].node)->addr);
  }
#line 1739 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 200 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('J', NULL, NULL);
    (yyval.node)->dtype = 'v';
    gen0("return");
  }
#line 1749 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 208 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('C', (yyvsp[-5].node), (yyvsp[-2].node));
    (yyval.node)->dtype = (yyvsp[-4].op);
    if ((yyvsp[-3].str)) (yyval.node)->value.str_ = (char *)strdup((yyvsp[-3].str));
    else (yyval.node)->value.str_ = NULL;
    free((yyvsp[-3].str));
    gen0("nop // crunch operation here"); /*TODO: implement when possible*/
}
#line 1762 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 219 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1768 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 220 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1774 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 224 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str); }
#line 1780 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 225 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.str) = NULL; }
#line 1786 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 229 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1792 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 230 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
    symbolTable *s = find_symbol((yyvsp[0].node)->addr);
    if (s == NULL) error_scope();
    (yyval.node)->dtype = s->dtype;
  }
#line 1803 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 236 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->dtype = 'i';
    (yyval.node)->value.int_ = atoi((yyvsp[0].str));
    strcpy((yyval.node)->addr, (yyvsp[0].str));
  }
#line 1814 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->dtype = 'f';
    (yyval.node)->value.float_ = atof((yyvsp[0].str));
    strcpy((yyval.node)->addr, (yyvsp[0].str));
  }
#line 1825 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 248 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->dtype = 'c';
    (yyval.node)->value.char_ = (yyvsp[0].str)[0];
    free((yyvsp[0].str));
    new_addr((yyval.node)->addr);
  }
#line 1837 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 255 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->dtype = 's';
    (yyval.node)->value.str_ = strdup((yyvsp[0].str));
    free((yyvsp[0].str));
    new_addr((yyval.node)->addr);
  }
#line 1849 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 262 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1855 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 263 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1861 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 267 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->value.str_ = strdup((yyvsp[0].str));
    (yyval.node)->dtype = 'p';
    (yyval.node)->flag = (yyvsp[0].str)[0];
    free((yyvsp[0].str));
}
#line 1873 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 277 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    char tmp_label[5];
    new_label(tmp_label);
    gen_label(tmp_label);
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    strcpy(ltmp->label, tmp_label);
    STACK_PUSH(lhead, ltmp);

    new_label(tmp_label);
    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    strcpy(a_tmp->label, tmp_label);
    STACK_PUSH(lhead, a_tmp);
  }
#line 1891 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 290 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('L', (yyvsp[-4].node), (yyvsp[-1].node));
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    STACK_POP(lhead, ltmp);

    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    STACK_POP(lhead, a_tmp);
    gen1("jump", a_tmp->label);

    gen_label(ltmp->label);
    free(a_tmp);
    free(ltmp);
  }
#line 1909 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 306 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    char tmp_label[5];
    new_label(tmp_label);
    gen_label(tmp_label);
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    strcpy(ltmp->label, tmp_label);
    STACK_PUSH(lhead, ltmp);

    new_label(tmp_label);
    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    strcpy(a_tmp->label, tmp_label);
    STACK_PUSH(lhead, a_tmp);
  }
#line 1927 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 319 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('L', (yyvsp[-4].node), (yyvsp[-1].node));
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    STACK_POP(lhead, ltmp);

    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    STACK_POP(lhead, a_tmp);
    gen1("jump", a_tmp->label);

    gen_label(ltmp->label);
    free(a_tmp);
    free(ltmp);
  }
#line 1945 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 335 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('E', (yyvsp[-4].node), newast('E', (yyvsp[-2].node), (yyvsp[0].node)));
  }
#line 1953 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 338 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('E', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1959 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 342 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('H', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
  }
#line 1969 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 347 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1975 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 351 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
    add_symbol((yyvsp[0].node)->addr, 'E', (yyvsp[-1].type)[0]);
    (yyval.node)->dtype = (yyvsp[-1].type)[0];
    free((yyvsp[-1].type));
  }
#line 1986 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 357 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
    symbolTable *s = find_symbol((yyvsp[0].node)->addr);
    if (s == NULL) error_scope();
    else (yyval.node)->dtype = s->dtype;
  }
#line 1997 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 366 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('I', NULL, NULL);
    strcpy((yyval.node)->addr, (yyvsp[0].id));
    free((yyvsp[0].id));
  }
#line 2007 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 374 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('H', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2013 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 375 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 2019 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 379 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2025 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 380 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('=', (yyvsp[-2].node), (yyvsp[0].node));
    symbolTable *s = find_symbol((yyvsp[-2].node)->addr);
    if (s == NULL) error_scope();
    else (yyval.node)->dtype = s->dtype;
  }
#line 2036 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 389 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2042 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 390 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('B', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    gen3("or", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
  }
#line 2054 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 400 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2060 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 401 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('B', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    gen3("and", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
  }
#line 2072 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 411 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2078 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 412 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("seq", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
    gen2("brz", top_label->label, (yyval.node)->addr);
  }
#line 2092 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 421 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("seq", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
    gen2("brnz", top_label->label, (yyval.node)->addr);
  }
#line 2106 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 433 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2112 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 434 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("slt", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
    gen2("brz", top_label->label, (yyval.node)->addr);
  }
#line 2126 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 443 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("sleq", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
    gen2("brz", top_label->label, (yyval.node)->addr);
  }
#line 2140 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 452 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("sleq", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
    gen2("brnz", top_label->label, (yyval.node)->addr);
  }
#line 2154 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 461 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("slt", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
    gen2("brnz", top_label->label, (yyval.node)->addr);
  }
#line 2168 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 473 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2174 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 474 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    gen3("add", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
  }
#line 2186 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 481 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    gen3("sub", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
  }
#line 2198 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 491 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2204 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 492 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    gen3("mul", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
  }
#line 2216 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 499 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    gen3("div", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
  }
#line 2228 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 506 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
    else (yyval.node)->dtype = (yyvsp[-2].node)->dtype;
    new_addr((yyval.node)->addr);
    gen3("mod", (yyval.node)->addr, (yyvsp[-2].node)->addr, (yyvsp[0].node)->addr);
  }
#line 2240 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 516 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2246 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 517 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2252 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 521 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('T', (yyvsp[-3].node), (yyvsp[-1].node));
    symbolTable *s = find_symbol((yyvsp[-3].node)->addr);
    if (s == NULL || s->type != 'F') error_scope();
    else if (param_counter > 0) {
      /*utstring_fromint(param_counter);
      gen2("call", $1->addr, utstring_body(tmp));
      utstring_free(tmp);*/
    }
    else gen1("call", (yyvsp[-3].node)->addr);
    param_counter = 0;
    new_addr((yyval.node)->addr);
    if(s->type != 'v') gen1("pop", (yyval.node)->addr);
  }
#line 2271 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 538 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 2277 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 539 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; }
#line 2283 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 542 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('G', (yyvsp[-2].node), (yyvsp[0].node));
    param_counter++;
    gen1("param", (yyvsp[0].node)->addr);
  }
#line 2293 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 547 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
    param_counter++;
    gen1("param", (yyvsp[0].node)->addr);
  }
#line 2303 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2307 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 554 "src/cruncher_syntax.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
    ++argv, --argc;
    if ( argc > 0 )
            yyin = fopen(argv[0], "r");
    else
            yyin = stdin;
    yyparse();
    annotate_ast(syntax_tree);
    print_ast(syntax_tree, 0);
    print_table();
    print_tac();
    free_tac();
    free_table();
    free_ast(syntax_tree);
    fclose(yyin);
    yylex_destroy();
    return 0;
}
