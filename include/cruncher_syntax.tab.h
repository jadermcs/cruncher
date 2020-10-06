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
    SYMBOL = 258,
    IDENTIFIER = 259,
    INTCONST = 260,
    FLOATCONST = 261,
    CHARCONST = 262,
    STRINGCONST = 263,
    PATHCONST = 264,
    WHILE_KW = 265,
    FOR_KW = 266,
    IN_KW = 267,
    IF_KW = 268,
    ELSE_KW = 269,
    CRUNCH_KW = 270,
    RETURN_KW = 271,
    CHAR_TYPE = 272,
    INT_TYPE = 273,
    FLOAT_TYPE = 274,
    STRING_TYPE = 275,
    PATH_TYPE = 276,
    VOID_TYPE = 277,
    ADD_OP = 278,
    SUB_OP = 279,
    MULT_OP = 280,
    DIV_OP = 281,
    REM_OP = 282,
    NOT_OP = 283,
    LESSTHAN_OP = 284,
    LESSEQUAL_OP = 285,
    GREATERTHAN_OP = 286,
    GREATEREQUAl_OP = 287,
    NOTEQUAL_OP = 288,
    COMPARISON_OP = 289,
    OR_OP = 290,
    AND_OP = 291,
    LBRACE = 292,
    RBRACE = 293,
    LBRACKET = 294,
    RBRACKET = 295,
    LPARENTHESES = 296,
    RPARENTHESES = 297,
    COLON = 298,
    SEMICOLON = 299,
    DEF_EQ = 300,
    COMMA = 301,
    PIPE = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_CRUNCHER_SYNTAX_TAB_H_INCLUDED  */
