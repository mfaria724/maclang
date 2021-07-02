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
    EQUIV = 46,
    NOT_EQUIV = 44,
    OR = 43,
    AND = 42,
    LESS_THAN = 50,
    LESS_EQUAL_THAN = 48,
    GREATER_THAN = 49,
    GREATER_EQUAL_THAN = 47,
    NOT = 45,
    PLUS = 51,
    MINUS = 52,
    ASTERISK = 55,
    DIV = 54,
    MODULE = 53,
    POWER = 41,
    OPEN_BRACKET = 5,
    CLOSE_BRACKET = 6,
    POINTER = 13,
    DOT = 11,
    ID = 32,
    OPEN_PAR = 2,
    SEMICOLON = 1,
    CLOSE_PAR = 3,
    ASSIGNMENT = 4,
    OPEN_C_BRACE = 7,
    CLOSE_C_BRACE = 8,
    COMMA = 9,
    REGISTER = 10,
    UNION = 12,
    NEW = 14,
    FORGET = 15,
    IF = 16,
    THEN = 17,
    ELSIF = 18,
    ELSE = 19,
    WHILE = 20,
    DO = 21,
    DONE = 22,
    FOR = 23,
    LET = 24,
    DEF = 25,
    AT = 26,
    RIGHT_ARROW = 27,
    INT = 28,
    FLOAT = 29,
    CHAR = 30,
    STRING = 31,
    TRUE = 33,
    FALSE = 34,
    T_UNIT = 35,
    T_BOOL = 36,
    T_CHAR = 37,
    T_INT = 38,
    T_FLOAT = 39,
    T_STRING = 40
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 106 "parser.y" /* yacc.c:1921  */
	
  int   integer;
  float flot;
  bool  boolean;
  char  *str;
  char  ch;
  Node  *ast;
  NodeS *nS;

#line 126 "parser.tab.h" /* yacc.c:1921  */
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
