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
#line 11 "src/cruncher_syntax.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"
#include "ast.h"
extern int yylineno;
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern char* strdup(const char*);
extern int yylex_destroy();
extern void yyerror(const char* s);
extern void add_table(char *, char *);
extern void print_table();
extern void free_table();
struct ast* syntax_tree = NULL;

#line 85 "src/cruncher_syntax.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cruncher_syntax.tab.h".  */
#ifndef YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED
# define YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED
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
    WHILE = 258,
    FOR = 259,
    IN = 260,
    IF = 261,
    ELSE = 262,
    CRUNCH = 263,
    RETURN = 264,
    ADD_OP = 265,
    SUB_OP = 266,
    MULT_OP = 267,
    DIV_OP = 268,
    REM_OP = 269,
    NOT_OP = 270,
    LESSTHAN_OP = 271,
    LESSEQUAL_OP = 272,
    GREATERTHAN_OP = 273,
    GREATEREQUAl_OP = 274,
    NOTEQUAL_OP = 275,
    COMPARISON_OP = 276,
    OR_OP = 277,
    AND_OP = 278,
    COLON = 279,
    DEF_EQ = 280,
    PIPE = 281,
    IDENTIFIER = 282,
    INTCONST = 283,
    FLOATCONST = 284,
    CHARCONST = 285,
    STRINGCONST = 286,
    PATHCONST = 287,
    TYPE = 288,
    CRUNCH_OP = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "src/cruncher_syntax.y" /* yacc.c:355  */

  char *id;
  char *type;
  char op;
  char *str;
  struct ast *node;

#line 168 "src/cruncher_syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "src/cruncher_syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    48,     2,     2,
      37,    38,    46,    44,    41,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      42,    36,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    71,    72,    76,    77,    81,    82,    86,
      94,    95,    96,   100,   104,   105,   109,   110,   111,   112,
     113,   114,   115,   116,   120,   121,   130,   131,   135,   145,
     146,   150,   151,   155,   156,   157,   158,   159,   160,   164,
     173,   177,   181,   185,   189,   190,   194,   195,   199,   203,
     204,   208,   209,   213,   214,   218,   219,   223,   224,   225,
     229,   230,   231,   232,   233,   237,   238,   239,   243,   244,
     245,   246,   250,   251,   255,   259,   260,   263,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "FOR", "IN", "IF", "ELSE",
  "CRUNCH", "RETURN", "ADD_OP", "SUB_OP", "MULT_OP", "DIV_OP", "REM_OP",
  "NOT_OP", "LESSTHAN_OP", "LESSEQUAL_OP", "GREATERTHAN_OP",
  "GREATEREQUAl_OP", "NOTEQUAL_OP", "COMPARISON_OP", "OR_OP", "AND_OP",
  "COLON", "DEF_EQ", "PIPE", "IDENTIFIER", "INTCONST", "FLOATCONST",
  "CHARCONST", "STRINGCONST", "PATHCONST", "TYPE", "CRUNCH_OP", "';'",
  "'='", "'('", "')'", "'{'", "'}'", "','", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "$accept", "program", "declarations", "declaration",
  "var_definition", "func_definition", "params", "param",
  "inner_declarations", "inner_declaration", "selection_statement",
  "return_statement", "crunch_statement", "file", "options", "term",
  "pathconst", "while_statement", "for_statement", "for_expression",
  "simple_expression", "sub_expression", "identifier", "expression",
  "assignment_expression", "conditional_expression", "and_expression",
  "eq_expression", "relational_expression", "add_expression",
  "mul_expression", "exp_statement", "call", "args", "args_list", YY_NULLPTR
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
     285,   286,   287,   288,   289,    59,    61,    40,    41,   123,
     125,    44,    60,    62,    43,    45,    42,    47,    37
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,    -7,    35,   -24,  -112,  -112,  -112,  -112,    60,  -112,
    -112,  -112,    54,    44,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,    89,   -27,  -112,   104,   105,    84,     4,    63,    55,
      -7,   -14,  -112,    54,  -112,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,  -112,
      91,    44,  -112,  -112,  -112,   104,   105,     4,     4,    63,
      63,    63,    63,    55,    55,  -112,  -112,  -112,   206,  -112,
      98,    99,   107,   115,    33,  -112,  -112,     9,  -112,  -112,
    -112,  -112,  -112,  -112,     7,   -25,  -112,   112,    54,    -5,
      54,    23,  -112,   120,  -112,  -112,    54,  -112,  -112,    13,
      -7,   118,    74,   152,  -112,    28,   124,  -112,  -112,  -112,
    -112,   121,   119,   122,  -112,   125,    54,    54,    23,   127,
     132,  -112,    54,   206,   206,    17,  -112,  -112,   206,   139,
      23,  -112,   110,   145,    54,   159,   133,   141,  -112,  -112,
     140,   173,  -112,   147,   144,  -112,   206,   192,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     5,     6,    48,     0,     1,
       3,     7,     0,    12,    34,    35,    36,    37,    39,    68,
      38,    33,     0,    50,    51,    53,    55,    57,    60,    65,
       0,     0,    11,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,    52,    49,    33,    54,    56,    59,    58,    62,
      64,    61,    63,    66,    67,    69,    70,    71,     0,    10,
       0,     0,     0,     0,     0,    22,    23,     0,    15,    18,
      16,    20,    17,    19,    33,     0,    21,     0,     0,     0,
       0,     0,    27,     0,     9,    14,    76,    72,    73,     0,
       0,     0,     0,    45,    47,     0,     0,    29,    30,    26,
      78,     0,    75,     0,    46,     0,     0,     0,     0,     0,
      32,    74,     0,     0,     0,     0,    44,    43,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,    40,    41,
      42,    24,    31,     0,     0,    28,     0,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,  -112,   181,    70,    72,  -112,   142,   -98,   -76,
    -112,  -112,  -112,  -111,  -112,   -43,   -85,  -112,  -112,  -112,
    -112,  -112,    -1,   -10,    65,   158,   160,  -112,    73,    51,
      76,  -112,  -112,  -112,  -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    75,    76,    31,    32,    77,    78,
      79,    80,    81,   106,   130,    19,    20,    82,    83,   101,
     102,   103,    54,    85,    23,    24,    25,    26,    27,    28,
      29,    86,    87,   111,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    95,    22,    65,    66,    67,   107,   127,    34,     1,
      97,    21,    70,    71,    35,    72,    35,    73,    74,   137,
       7,    40,     7,    41,    50,   132,   133,    51,   100,    49,
     135,    93,    21,   107,    21,     9,     7,    14,    15,    16,
      17,    18,     1,    33,    96,   107,    42,    43,   147,    94,
       7,   113,   134,   110,    35,    18,    95,    95,    35,    95,
       7,    14,    15,    16,    17,    18,   119,    84,    92,    35,
       5,    95,     6,     5,   126,     6,    84,    30,    99,   131,
     105,     7,    14,    15,    16,    17,    18,    21,   104,    21,
     108,    59,    60,    61,    62,    11,    12,    13,    52,   114,
      53,    46,    47,    48,    38,    39,   125,    44,    45,   116,
     117,    57,    58,    70,    71,    21,    72,   108,    73,    74,
      63,    64,    84,    84,   140,    33,    36,    84,    37,   108,
      68,    84,    84,    21,    84,    88,    89,     7,    14,    15,
      16,    17,    18,     1,    90,    84,    84,    98,    70,    71,
     138,    72,    91,    73,    74,   109,   115,   118,   120,   121,
     122,   123,    70,    71,   124,    72,   128,    73,    74,   129,
     136,   142,     7,    14,    15,    16,    17,    18,     1,   143,
     144,    35,   145,   146,    10,   139,     7,    14,    15,    16,
      17,    18,     1,    69,    55,    70,    71,    56,    72,   141,
      73,    74,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,    72,     0,    73,    74,     0,     0,     0,     7,
      14,    15,    16,    17,    18,     1,     0,     0,     0,     0,
       0,     0,   148,     7,    14,    15,    16,    17,    18,     1
};

static const yytype_int16 yycheck[] =
{
       1,    77,    12,    46,    47,    48,    91,   118,    35,    33,
      35,    12,     3,     4,    41,     6,    41,     8,     9,   130,
      27,    17,    27,    19,    38,   123,   124,    41,    33,    30,
     128,    74,    33,   118,    35,     0,    27,    28,    29,    30,
      31,    32,    33,    36,    37,   130,    42,    43,   146,    40,
      27,    38,    35,    96,    41,    32,   132,   133,    41,   135,
      27,    28,    29,    30,    31,    32,    38,    68,    35,    41,
       0,   147,     0,     3,   117,     3,    77,    33,    88,   122,
      90,    27,    28,    29,    30,    31,    32,    88,    89,    90,
      91,    40,    41,    42,    43,    35,    36,    37,    33,   100,
      35,    46,    47,    48,    20,    21,   116,    44,    45,    35,
      36,    38,    39,     3,     4,   116,     6,   118,     8,     9,
      44,    45,   123,   124,   134,    36,    22,   128,    23,   130,
      39,   132,   133,   134,   135,    37,    37,    27,    28,    29,
      30,    31,    32,    33,    37,   146,   147,    35,     3,     4,
      40,     6,    37,     8,     9,    35,    38,     5,    34,    38,
      41,    39,     3,     4,    39,     6,    39,     8,     9,    37,
      31,    38,    27,    28,    29,    30,    31,    32,    33,    38,
       7,    41,    35,    39,     3,    40,    27,    28,    29,    30,
      31,    32,    33,    51,    36,     3,     4,    37,     6,    40,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,     6,    -1,     8,     9,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    27,    28,    29,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    50,    51,    52,    53,    54,    27,    71,     0,
      52,    35,    36,    37,    28,    29,    30,    31,    32,    64,
      65,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      33,    55,    56,    36,    35,    41,    22,    23,    20,    21,
      17,    19,    42,    43,    44,    45,    46,    47,    48,    71,
      38,    41,    73,    73,    71,    74,    75,    77,    77,    78,
      78,    78,    78,    79,    79,    64,    64,    64,    39,    56,
       3,     4,     6,     8,     9,    53,    54,    57,    58,    59,
      60,    61,    66,    67,    71,    72,    80,    81,    37,    37,
      37,    37,    35,    64,    40,    58,    37,    35,    35,    72,
      33,    68,    69,    70,    71,    72,    62,    65,    71,    35,
      64,    82,    83,    38,    71,    38,    35,    36,     5,    38,
      34,    38,    41,    39,    39,    72,    64,    62,    39,    37,
      63,    64,    57,    57,    35,    57,    31,    62,    40,    40,
      72,    40,    38,    38,     7,    35,    39,    57,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      55,    55,    55,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    60,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    65,
      66,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    77,    78,    78,    78,    79,    79,
      79,    79,    80,    80,    81,    82,    82,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     8,
       3,     1,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,    11,     3,     2,     8,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       7,     7,     5,     3,     3,     1,     2,     1,     1,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     2,     2,     4,     1,     0,     3,     1
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
#line 67 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { syntax_tree = (yyvsp[0].node); }
#line 1386 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 71 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('D', (yyvsp[-1].node), (yyvsp[0].node));}
#line 1392 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1398 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1404 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1410 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); add_table((yyvsp[-1].node)->addr, (yyvsp[-2].type)); free((yyvsp[-2].type)); }
#line 1416 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 82 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('V', (yyvsp[-3].node), (yyvsp[-1].node)); add_table((yyvsp[-3].node)->addr, (yyvsp[-4].type)); free((yyvsp[-4].type)); }
#line 1422 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 86 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('F', (yyvsp[-6].node), newast('F', (yyvsp[-4].node), (yyvsp[-1].node)));
    add_table((yyvsp[-6].node)->addr, (yyvsp[-7].type));
    free((yyvsp[-7].type));
  }
#line 1432 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 94 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('P', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1438 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 95 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1444 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 96 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1450 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 100 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('A', (yyvsp[0].node), NULL); add_table((yyvsp[0].node)->addr, (yyvsp[-1].type)); free((yyvsp[-1].type));}
#line 1456 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 104 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('S', (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1462 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 105 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1468 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 109 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1474 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1480 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1486 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 112 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1492 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 113 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1498 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 114 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1504 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1510 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 116 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1516 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = newast('E', (yyvsp[-4].node), (yyvsp[-1].node)); (yyval.node)->dtype = 'i'; }
#line 1522 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    struct ast *tmp = newast('E', (yyvsp[-8].node), (yyvsp[-5].node));
    tmp->dtype = 'i';
    (yyval.node) = newast('E', tmp, (yyvsp[-1].node));
    (yyval.node)->dtype = 'e';
  }
#line 1533 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('J', (yyvsp[-1].node), NULL); (yyval.node)->dtype = 'r'; }
#line 1539 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 131 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('J', NULL, NULL); (yyval.node)->dtype = 'r'; }
#line 1545 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 135 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('C', (yyvsp[-5].node), (yyvsp[-2].node));
    (yyval.node)->dtype = (yyvsp[-4].op);
    if ((yyvsp[-3].str)) (yyval.node)->value.str_ = (char *)strdup((yyvsp[-3].str));
    else (yyval.node)->value.str_ = NULL;
    free((yyvsp[-3].str));
}
#line 1557 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1563 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 146 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1569 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 150 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str); }
#line 1575 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 151 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.str) = NULL; }
#line 1581 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 155 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1587 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 156 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = newast('i', NULL, NULL); (yyval.node)->value.int_ = atoi((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1593 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 157 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = newast('f', NULL, NULL); (yyval.node)->value.float_ = atof((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1599 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 158 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = newast('c', NULL, NULL); (yyval.node)->value.char_ = (yyvsp[0].str)[0]; free((yyvsp[0].str)); }
#line 1605 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 159 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = newast('s', NULL, NULL); (yyval.node)->value.str_ = strdup((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1611 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 160 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1617 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 164 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('p', NULL, NULL);
    (yyval.node)->value.str_ = strdup((yyvsp[0].str));
    (yyval.node)->dtype = (yyvsp[0].str)[0];
    free((yyvsp[0].str));
}
#line 1628 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 173 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('L', (yyvsp[-4].node), (yyvsp[-1].node)); (yyval.node)->dtype = 'w'; }
#line 1634 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 177 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('L', (yyvsp[-4].node), (yyvsp[-1].node)); (yyval.node)->dtype = 'f'; }
#line 1640 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 181 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('E', (yyvsp[-4].node), newast('E', (yyvsp[-2].node), (yyvsp[0].node)));
    (yyval.node)->dtype = '3';
  }
#line 1649 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 185 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('E', (yyvsp[-2].node), (yyvsp[0].node));  (yyval.node)->dtype = 'i'; }
#line 1655 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 189 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('H', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1661 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 190 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1667 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 194 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); add_table((yyvsp[0].node)->addr, (yyvsp[-1].type)); free((yyvsp[-1].type));}
#line 1673 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 195 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1679 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 199 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('I', NULL, NULL); (yyval.node)->addr = strdup((yyvsp[0].id)); free((yyvsp[0].id)); }
#line 1685 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 203 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('H', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1691 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 204 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1697 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 208 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1703 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('=', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1709 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 213 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1715 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 214 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = newast('|', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1721 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 218 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1727 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 219 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('&', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1733 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 223 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1739 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 224 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('=', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1745 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 225 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('=', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1751 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 229 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1757 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 230 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '<'; }
#line 1763 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 231 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '2'; }
#line 1769 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 232 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '>'; }
#line 1775 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 233 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '4'; }
#line 1781 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 237 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1787 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 238 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('+', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '+'; }
#line 1793 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 239 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('+', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '-'; }
#line 1799 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 243 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1805 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 244 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('*', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '*'; }
#line 1811 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 245 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('*', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '/'; }
#line 1817 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 246 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('*', (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->dtype = '%'; }
#line 1823 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 250 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1829 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 251 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); }
#line 1835 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 255 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('T', (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1841 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 259 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1847 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 260 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; }
#line 1853 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 263 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('G', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1859 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 264 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1865 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;


#line 1869 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
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
#line 267 "src/cruncher_syntax.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
    ++argv, --argc;
    if ( argc > 0 )
            yyin = fopen(argv[0], "r");
    else
            yyin = stdin;
    yyparse();
    print_ast(syntax_tree, 0);
    print_table();
    free_table();
    free_ast(syntax_tree);
    fclose(yyin);
    yylex_destroy();
    return 0;
}
