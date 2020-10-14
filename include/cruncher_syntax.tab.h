/* A Bison parser, made by GNU Bison 3.3.2.  */

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
    PARAMS = 265,
    ADD_OP = 266,
    SUB_OP = 267,
    MULT_OP = 268,
    DIV_OP = 269,
    REM_OP = 270,
    NOT_OP = 271,
    LESSTHAN_OP = 272,
    LESSEQUAL_OP = 273,
    GREATERTHAN_OP = 274,
    GREATEREQUAl_OP = 275,
    NOTEQUAL_OP = 276,
    COMPARISON_OP = 277,
    OR_OP = 278,
    AND_OP = 279,
    COLON = 280,
    DEF_EQ = 281,
    PIPE = 282,
    IDENTIFIER = 283,
    INTCONST = 284,
    FLOATCONST = 285,
    CHARCONST = 286,
    STRINGCONST = 287,
    PATHCONST = 288,
    TYPE = 289,
    SYMBOL = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "src/cruncher_syntax.y" /* yacc.c:1921  */

  char *id;
  char *type;
  char op;
  char *str;
  struct ast *node;

#line 102 "include/cruncher_syntax.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED  */
