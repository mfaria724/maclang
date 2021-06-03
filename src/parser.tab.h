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
    UNIT = 277,
    OPEN_BRACKET = 278,
    CLOSE_BRACKET = 279,
    OPEN_C_BRACE = 280,
    CLOSE_C_BRACE = 281,
    COMMA = 282,
    REGISTER = 283,
    DOT = 284,
    UNION = 285,
    POINTER = 286,
    NEW = 287,
    FORGET = 288,
    IF = 289,
    THEN = 290,
    ELSIF = 291,
    ELSE = 292,
    END = 293,
    WHILE = 294,
    DO = 295,
    DONE = 296,
    FOR = 297,
    LET = 298,
    AT = 299,
    RIGHT_ARROW = 300,
    INT = 301,
    FLOAT = 302,
    ID = 303,
    SINGLE_QUOTE = 304,
    DOUBLE_QUOTE = 305,
    TRUE = 306,
    FALSE = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 102 "parser.y" /* yacc.c:1921  */
	
			int num; 
			float flot;
			bool boolean;
			char * str;
			char ch;
			ArbolSintactico * arb;
		

#line 121 "parser.tab.h" /* yacc.c:1921  */
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
