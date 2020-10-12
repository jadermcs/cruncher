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
    WHILE = 265,
    FOR = 266,
    IN = 267,
    IF = 268,
    ELSE = 269,
    CRUNCH = 270,
    RETURN = 271,
    TYPE = 272,
    PARAMS = 273,
    ADD_OP = 274,
    SUB_OP = 275,
    MULT_OP = 276,
    DIV_OP = 277,
    REM_OP = 278,
    NOT_OP = 279,
    LESSTHAN_OP = 280,
    LESSEQUAL_OP = 281,
    GREATERTHAN_OP = 282,
    GREATEREQUAl_OP = 283,
    NOTEQUAL_OP = 284,
    COMPARISON_OP = 285,
    OR_OP = 286,
    AND_OP = 287,
    LBRACE = 288,
    RBRACE = 289,
    LBRACKET = 290,
    RBRACKET = 291,
    LPARENTHESES = 292,
    RPARENTHESES = 293,
    COLON = 294,
    SEMICOLON = 295,
    DEF_EQ = 296,
    COMMA = 297,
    PIPE = 298
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
