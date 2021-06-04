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
    PLUS = 258,
    MINUS = 259,
    ASTERISK = 260,
    DIV = 261,
    MODULE = 262,
    POWER = 263,
    SEMICOLON = 264,
    OPEN_PAR = 265,
    CLOSE_PAR = 266,
    AND = 267,
    OR = 268,
    NOT_EQUIV = 269,
    NOT = 270,
    EQUIV = 271,
    GREATER_EQUAL_THAN = 272,
    LESS_EQUAL_THAN = 273,
    GREATER_THAN = 274,
    LESS_THAN = 275,
    ASSIGNMENT = 276,
    T_INT = 277,
    T_CHAR = 278,
    T_BOOL = 279,
    T_FLOAT = 280,
    T_UNIT = 281,
    T_STRING = 282,
    OPEN_BRACKET = 283,
    CLOSE_BRACKET = 284,
    OPEN_C_BRACE = 285,
    CLOSE_C_BRACE = 286,
    COMMA = 287,
    REGISTER = 288,
    DOT = 289,
    UNION = 290,
    POINTER = 291,
    NEW = 292,
    FORGET = 293,
    IF = 294,
    THEN = 295,
    ELSIF = 296,
    ELSE = 297,
    END = 298,
    WHILE = 299,
    DO = 300,
    DONE = 301,
    FOR = 302,
    LET = 303,
    AT = 304,
    RIGHT_ARROW = 305,
    EOL = 306,
    INT = 307,
    FLOAT = 308,
    ID = 309,
    CHAR = 310,
    STRING = 311,
    TRUE = 312,
    FALSE = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 80 "parser.y" /* yacc.c:1921  */
	
  int   integer;
  float flot;
  bool  boolean;
  char  *str;
  char  ch;

#line 125 "parser.tab.h" /* yacc.c:1921  */
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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
