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

#include "cruncher.h"
#include "ast.h"
extern int yylineno;
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylex_destroy();
extern void yyerror(const char* s);
extern void add_symbol(char *, char, char);
extern void add_table(char *, char, char);
extern void print_table();
extern void free_table();
extern symbolTable *find_symbol(char *);
struct ast* syntax_tree = NULL;

#line 83 "src/cruncher_syntax.tab.c" /* yacc.c:339  */

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
#line 28 "src/cruncher_syntax.y" /* yacc.c:355  */

  char *id;
  char *type;
  char op;
  char *str;
  struct ast *node;

#line 166 "src/cruncher_syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "src/cruncher_syntax.tab.c" /* yacc.c:358  */

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
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

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
       0,    63,    63,    67,    68,    72,    73,    77,    83,    92,
     102,   103,   104,   108,   116,   117,   121,   122,   123,   124,
     125,   126,   127,   131,   137,   146,   147,   156,   157,   161,
     171,   172,   176,   177,   181,   187,   193,   199,   205,   210,
     214,   224,   228,   232,   236,   240,   244,   248,   254,   263,
     271,   272,   276,   277,   286,   287,   294,   295,   302,   303,
     307,   314,   315,   319,   323,   327,   334,   335,   339,   346,
     347,   351,   355,   362,   363,   367,   375,   376,   379,   380
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
  "inner_declarations", "inner_declaration", "local_var_definition",
  "selection_statement", "return_statement", "crunch_statement", "file",
  "options", "term", "pathconst", "while_statement", "for_statement",
  "for_expression", "simple_expression", "sub_expression", "identifier",
  "expression", "assignment_expression", "conditional_expression",
  "and_expression", "eq_expression", "relational_expression",
  "add_expression", "mul_expression", "exp_statement", "call", "args",
  "args_list", YY_NULLPTR
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

#define YYPACT_NINF -119

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-119)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,    23,    47,   -13,  -119,  -119,  -119,  -119,    29,  -119,
    -119,  -119,    64,    39,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    44,   -19,  -119,    93,    76,    77,     2,    65,    38,
      23,    21,  -119,    64,  -119,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,  -119,
      73,    39,  -119,  -119,  -119,    93,    76,     2,     2,    65,
      65,    65,    65,    38,    38,  -119,  -119,  -119,   212,  -119,
      95,   110,   111,   112,    -4,    23,     9,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,    70,    11,  -119,   117,    64,    24,
      64,    31,  -119,   121,    78,  -119,  -119,    64,  -119,  -119,
      32,    23,    87,    88,   153,  -119,    40,   127,  -119,  -119,
    -119,  -119,    64,  -119,   124,   122,   125,  -119,   126,    64,
      64,    31,   128,   129,    19,  -119,    64,   212,   212,    20,
    -119,  -119,   212,   139,    31,  -119,  -119,   113,   151,    64,
     165,   134,   137,  -119,  -119,   135,   170,  -119,   150,   147,
    -119,   212,   198,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     5,     6,    49,     0,     1,
       3,     7,     0,    12,    35,    36,    37,    38,    40,    69,
      39,    34,     0,    51,    52,    54,    56,    58,    61,    66,
       0,     0,    11,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,    53,    50,    34,    55,    57,    60,    59,    63,
      65,    62,    64,    67,    68,    70,    71,    72,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    15,    22,    18,
      16,    20,    17,    19,    34,     0,    21,     0,     0,     0,
       0,     0,    28,     0,     0,     9,    14,    77,    73,    74,
       0,     0,     0,     0,    46,    48,     0,     0,    30,    31,
      27,    23,     0,    79,     0,    76,     0,    47,     0,     0,
       0,     0,     0,    33,     0,    75,     0,     0,     0,     0,
      45,    44,     0,     0,     0,    24,    78,     0,     0,     0,
       0,     0,     0,    41,    42,    43,    25,    32,     0,     0,
      29,     0,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,   184,  -119,  -119,  -119,   138,  -118,   -69,
    -119,  -119,  -119,  -119,   -78,  -119,   -44,   -86,  -119,  -119,
    -119,  -119,  -119,    -1,   -11,   -27,   152,   162,  -119,    91,
      62,    90,  -119,  -119,  -119,  -119
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    31,    32,    76,    77,
      78,    79,    80,    81,   107,   134,    19,    20,    82,    83,
     102,   103,   104,    54,    85,    23,    24,    25,    26,    27,
      28,    29,    86,    87,   114,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    22,    65,    66,    67,   108,    52,    96,    53,   137,
     138,    21,    70,    71,   140,    72,    34,    73,    74,    40,
       1,    41,    35,     7,    14,    15,    16,    17,    18,    49,
      93,    92,    21,   152,    21,   108,     7,    14,    15,    16,
      17,    18,    75,   131,    42,    43,    98,     9,   108,    95,
       7,     7,    35,   113,   135,   139,   142,   101,     7,    50,
      35,    35,    51,    18,    11,    12,    13,    84,    96,    96,
     116,    96,    30,    35,    94,    84,   130,   100,   122,   106,
      33,    35,   136,    96,    46,    47,    48,    21,   105,    21,
     109,     7,    14,    15,    16,    17,    18,    38,    39,    37,
     117,   124,    59,    60,    61,    62,    33,    97,   129,    44,
      45,    21,    68,   111,   112,    36,    70,    71,    21,    72,
     109,    73,    74,   119,   120,   118,    84,    84,   145,    57,
      58,    84,    88,   109,    63,    64,    84,    84,    21,    84,
       7,    14,    15,    16,    17,    18,    75,    89,    90,    91,
      84,    84,    99,   143,    70,    71,   110,    72,   121,    73,
      74,   123,   125,   126,   127,   128,   133,   132,    70,    71,
     141,    72,   147,    73,    74,   148,    35,   149,     7,    14,
      15,    16,    17,    18,    75,   150,   151,    10,    55,    69,
       0,   144,     7,    14,    15,    16,    17,    18,    75,    56,
       0,    70,    71,     0,    72,   146,    73,    74,     0,     0,
       0,     0,     0,     0,     0,    70,    71,     0,    72,     0,
      73,    74,     0,     0,     0,     7,    14,    15,    16,    17,
      18,    75,     0,     0,     0,     0,     0,     0,   153,     7,
      14,    15,    16,    17,    18,    75
};

static const yytype_int16 yycheck[] =
{
       1,    12,    46,    47,    48,    91,    33,    76,    35,   127,
     128,    12,     3,     4,   132,     6,    35,     8,     9,    17,
      33,    19,    41,    27,    28,    29,    30,    31,    32,    30,
      74,    35,    33,   151,    35,   121,    27,    28,    29,    30,
      31,    32,    33,   121,    42,    43,    35,     0,   134,    40,
      27,    27,    41,    97,    35,    35,   134,    33,    27,    38,
      41,    41,    41,    32,    35,    36,    37,    68,   137,   138,
      38,   140,    33,    41,    75,    76,   120,    88,    38,    90,
      36,    41,   126,   152,    46,    47,    48,    88,    89,    90,
      91,    27,    28,    29,    30,    31,    32,    20,    21,    23,
     101,   112,    40,    41,    42,    43,    36,    37,   119,    44,
      45,   112,    39,    35,    36,    22,     3,     4,   119,     6,
     121,     8,     9,    35,    36,    38,   127,   128,   139,    38,
      39,   132,    37,   134,    44,    45,   137,   138,   139,   140,
      27,    28,    29,    30,    31,    32,    33,    37,    37,    37,
     151,   152,    35,    40,     3,     4,    35,     6,     5,     8,
       9,    34,    38,    41,    39,    39,    37,    39,     3,     4,
      31,     6,    38,     8,     9,    38,    41,     7,    27,    28,
      29,    30,    31,    32,    33,    35,    39,     3,    36,    51,
      -1,    40,    27,    28,    29,    30,    31,    32,    33,    37,
      -1,     3,     4,    -1,     6,    40,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,    -1,
       8,     9,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    27,
      28,    29,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    50,    51,    52,    53,    54,    27,    72,     0,
      52,    35,    36,    37,    28,    29,    30,    31,    32,    65,
      66,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      33,    55,    56,    36,    35,    41,    22,    23,    20,    21,
      17,    19,    42,    43,    44,    45,    46,    47,    48,    72,
      38,    41,    74,    74,    72,    75,    76,    78,    78,    79,
      79,    79,    79,    80,    80,    65,    65,    65,    39,    56,
       3,     4,     6,     8,     9,    33,    57,    58,    59,    60,
      61,    62,    67,    68,    72,    73,    81,    82,    37,    37,
      37,    37,    35,    65,    72,    40,    58,    37,    35,    35,
      73,    33,    69,    70,    71,    72,    73,    63,    66,    72,
      35,    35,    36,    65,    83,    84,    38,    72,    38,    35,
      36,     5,    38,    34,    73,    38,    41,    39,    39,    73,
      65,    63,    39,    37,    64,    35,    65,    57,    57,    35,
      57,    31,    63,    40,    40,    73,    40,    38,    38,     7,
      35,    39,    57,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      55,    55,    55,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      66,    67,    68,    69,    69,    70,    70,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    78,    78,    78,    78,    78,    79,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    83,    83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     5,     8,
       3,     1,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     7,    11,     3,     2,     8,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     7,     7,     5,     3,     3,     1,     2,     1,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     2,     2,     4,     1,     0,     3,     1
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
#line 63 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { syntax_tree = (yyvsp[0].node); }
#line 1390 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('D', (yyvsp[-1].node), (yyvsp[0].node));}
#line 1396 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1402 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1408 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1414 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
    (yyval.node)->dtype = (yyvsp[-2].type)[0];
    add_table((yyvsp[-1].node)->addr, 'V', (yyvsp[-2].type)[0]);
    free((yyvsp[-2].type));
  }
#line 1425 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('V', (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->dtype = (yyvsp[-4].type)[0];
    add_table((yyvsp[-3].node)->addr, 'V', (yyvsp[-4].type)[0]);
    free((yyvsp[-4].type));
  }
#line 1436 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 94 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    add_table((yyvsp[-6].node)->addr, 'F', (yyvsp[-7].type)[0]);
    (yyval.node) = newast('F', (yyvsp[-6].node), newast('F', (yyvsp[-4].node), (yyvsp[-1].node)));
    free((yyvsp[-7].type));
  }
#line 1446 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('P', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1452 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1458 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1464 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 108 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('A', (yyvsp[0].node), NULL);
    add_symbol((yyvsp[0].node)->addr, 'P', (yyvsp[-1].type)[0]);
    free((yyvsp[-1].type));
  }
#line 1474 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('S', (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1480 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 117 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1486 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 121 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1492 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 122 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1498 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 123 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1504 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 124 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1510 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 125 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1516 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 126 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1522 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1528 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 131 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
    (yyval.node)->dtype = (yyvsp[-2].type)[0];
    add_symbol((yyvsp[-1].node)->addr, 'V', (yyvsp[-2].type)[0]);
    free((yyvsp[-2].type));
  }
#line 1539 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 137 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('V', (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->dtype = (yyvsp[-4].type)[0];
    add_symbol((yyvsp[-3].node)->addr, 'V', (yyvsp[-4].type)[0]);
    free((yyvsp[-4].type));
  }
#line 1550 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = newast('E', (yyvsp[-4].node), (yyvsp[-1].node)); (yyval.node)->dtype = 'i'; }
#line 1556 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    struct ast *tmp = newast('E', (yyvsp[-8].node), (yyvsp[-5].node));
    tmp->dtype = 'i';
    (yyval.node) = newast('E', tmp, (yyvsp[-1].node));
    (yyval.node)->dtype = 'e';
  }
#line 1567 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 156 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('J', (yyvsp[-1].node), NULL); (yyval.node)->dtype = 'r'; }
#line 1573 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('J', NULL, NULL); (yyval.node)->dtype = 'r'; }
#line 1579 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 161 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('C', (yyvsp[-5].node), (yyvsp[-2].node));
    (yyval.node)->dtype = (yyvsp[-4].op);
    if ((yyvsp[-3].str)) (yyval.node)->value.str_ = (char *)strdup((yyvsp[-3].str));
    else (yyval.node)->value.str_ = NULL;
    free((yyvsp[-3].str));
}
#line 1591 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 171 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1597 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 172 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1603 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str); }
#line 1609 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 177 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.str) = NULL; }
#line 1615 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 181 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
    symbolTable *s = find_symbol((yyvsp[0].node)->addr);
    if (s == NULL) error_scope();
    (yyval.node)->dtype = s->dtype;
  }
#line 1626 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 187 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->dtype = 'i';
    (yyval.node)->value.int_ = atoi((yyvsp[0].str));
    free((yyvsp[0].str));
  }
#line 1637 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 193 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->dtype = 'f';
    (yyval.node)->value.float_ = atof((yyvsp[0].str));
    free((yyvsp[0].str));
  }
#line 1648 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 199 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->dtype = 'c';
    (yyval.node)->value.char_ = (yyvsp[0].str)[0];
    free((yyvsp[0].str));
  }
#line 1659 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 205 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->dtype = 's';
    (yyval.node)->value.str_ = strdup((yyvsp[0].str));
    free((yyvsp[0].str)); }
#line 1669 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 210 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1675 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 214 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('c', NULL, NULL);
    (yyval.node)->value.str_ = strdup((yyvsp[0].str));
    (yyval.node)->dtype = 'p';
    (yyval.node)->flag = (yyvsp[0].str)[0];
    free((yyvsp[0].str));
}
#line 1687 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 224 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('L', (yyvsp[-4].node), (yyvsp[-1].node)); (yyval.node)->dtype = 'w'; }
#line 1693 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 228 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('L', (yyvsp[-4].node), (yyvsp[-1].node)); (yyval.node)->dtype = 'f'; }
#line 1699 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 232 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('E', (yyvsp[-4].node), newast('E', (yyvsp[-2].node), (yyvsp[0].node)));
    (yyval.node)->dtype = '3';
  }
#line 1708 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 236 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('E', (yyvsp[-2].node), (yyvsp[0].node));  (yyval.node)->dtype = 'p'; }
#line 1714 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 240 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('H', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1723 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 244 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1729 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 248 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
    add_symbol((yyvsp[0].node)->addr, 'E', (yyvsp[-1].type)[0]);
    (yyval.node)->dtype = (yyvsp[-1].type)[0];
    free((yyvsp[-1].type));
  }
#line 1740 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 254 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
    symbolTable *s = find_symbol((yyvsp[0].node)->addr);
    if (s == NULL) error_scope();
    (yyval.node)->dtype = s->dtype;
  }
#line 1751 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 263 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('I', NULL, NULL);
    strcpy((yyval.node)->addr, (yyvsp[0].id));
    free((yyvsp[0].id));
  }
#line 1761 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 271 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('H', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1767 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 272 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1773 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 276 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1779 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 277 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('=', (yyvsp[-2].node), (yyvsp[0].node));
    symbolTable *s = find_symbol((yyvsp[-2].node)->addr);
    if (s == NULL) error_scope();
    (yyval.node)->dtype = s->dtype;
  }
#line 1790 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 286 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1796 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 287 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('B', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1805 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 294 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1811 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 295 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('B', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1820 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 302 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1826 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 303 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1835 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 307 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1844 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 314 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1850 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 315 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1859 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 319 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1868 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 323 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1877 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 327 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('R', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1886 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 334 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1892 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 335 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1901 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 339 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1910 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 346 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1916 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 347 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1925 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 351 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1934 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 355 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('Z', (yyvsp[-2].node), (yyvsp[0].node));
    if (type_match((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype)) error_type((yyvsp[-2].node)->dtype, (yyvsp[0].node)->dtype);
  }
#line 1943 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 362 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1949 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 363 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); }
#line 1955 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 367 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {
    (yyval.node) = newast('T', (yyvsp[-3].node), (yyvsp[-1].node));
    symbolTable *s = find_symbol((yyvsp[-3].node)->addr);
    if (s == NULL || s->type != 'F') error_scope();
  }
#line 1965 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 375 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1971 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 376 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; }
#line 1977 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 379 "src/cruncher_syntax.y" /* yacc.c:1646  */
    { (yyval.node) = newast('G', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1983 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 380 "src/cruncher_syntax.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1989 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
    break;


#line 1993 "src/cruncher_syntax.tab.c" /* yacc.c:1646  */
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
#line 383 "src/cruncher_syntax.y" /* yacc.c:1906  */


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
    free_table();
    free_ast(syntax_tree);
    fclose(yyin);
    yylex_destroy();
    return 0;
}
