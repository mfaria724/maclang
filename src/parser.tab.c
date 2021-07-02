/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y" /* yacc.c:337  */

  #ifndef AST
  #include "ast.hpp" 
  #endif
  
  #include <iostream>
  #include <queue>
  #include <string>
  #include <cstring>

  #include "table.hpp"

  using namespace std;

  extern int yylex(void);
  extern int yylineno;
  extern int yycolumn;
  extern char *yytext;
  extern char *filename;

  // queues for tokens and errors
  extern queue<string> errors;
  NodeS *ast;

  // queues for tokens and errors
  queue<string> tokens;
  extern queue<string> errors;

  // Leblanc-Cook's Symbols Table
  SymbolsTable table;

  // Prints error;
  void yyerror(string s);

  // Prints the queue to std.
  void printQueue(queue<string> queueToPrint);

  // add a error.
  void addError(string id, string error);

  // token names for readability on lexer
  string tokenNames [] = {
    "SEMICOLON",
    "OPEN_PAR",
    "CLOSE_PAR",
    "ASSIGNMENT",
    "OPEN_BRACKET",
    "CLOSE_BRACKET",
    "OPEN_C_BRACE",
    "CLOSE_C_BRACE",
    "COMMA",
    "REGISTER",
    "DOT",
    "UNION",
    "POINTER",
    "NEW",
    "FORGET",
    "IF",
    "THEN",
    "ELSIF",
    "ELSE",
    "WHILE",
    "DO",
    "DONE",
    "FOR",
    "LET",
    "DEF",
    "AT",
    "RIGHT_ARROW",
    "INT",
    "FLOAT",
    "CHAR",
    "STRING",
    "ID",
    "TRUE", 
    "FALSE",
    "T_UNIT",
    "T_BOOL",
    "T_CHAR",
    "T_INT",
    "T_FLOAT",
    "T_STRING",
    "POWER",
    "AND",
    "OR",
    "NOT_EQUIV",
    "NOT",
    "EQUIV",
    "GREATER_EQUAL_THAN",
    "LESS_EQUAL_THAN",
    "GREATER_THAN",
    "LESS_THAN",
    "PLUS",
    "MINUS",
    "MODULE", 
    "DIV",
    "ASTERISK"
  };

  Node *global;

#line 172 "parser.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
   by #include "parser.tab.h".  */
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
#line 106 "parser.y" /* yacc.c:352  */
	
  int   integer;
  float flot;
  bool  boolean;
  char  *str;
  char  ch;
  Node  *ast;
  NodeS *nS;

#line 283 "parser.tab.c" /* yacc.c:352  */
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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   583

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

#define YYUNDEFTOK  2
#define YYMAXUTOK   257

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,    24,    23,    25,    26,    18,    19,    27,    28,    29,
      30,    21,    31,    20,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    22,    50,    51,    52,    53,    54,    55,    56,
      57,    17,     6,     5,     4,    11,     3,    10,     8,     9,
       7,    12,    13,    16,    15,    14,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   205,   205,   206,   208,   209,   211,   212,   214,   215,
     216,   217,   218,   220,   221,   222,   226,   227,   228,   230,
     237,   243,   244,   246,   248,   249,   250,   251,   255,   256,
     257,   258,   267,   268,   269,   270,   271,   272,   276,   277,
     278,   279,   280,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   320,   322,
     323,   325,   326,   330,   340,   341,   343,   344,   348,   356,
     358,   364,   373,   381,   383,   389,   400,   405,   407,   408,
     410,   411,   413,   418,   419,   421,   428,   433,   435,   441,
     448,   450,   451,   455,   463,   471,   472,   473,   474,   476,
     484,   493,   501,   511,   512,   514,   515,   517,   518
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQUIV", "NOT_EQUIV", "OR", "AND",
  "LESS_THAN", "LESS_EQUAL_THAN", "GREATER_THAN", "GREATER_EQUAL_THAN",
  "NOT", "PLUS", "MINUS", "ASTERISK", "DIV", "MODULE", "POWER",
  "OPEN_BRACKET", "CLOSE_BRACKET", "POINTER", "DOT", "ID", "OPEN_PAR",
  "SEMICOLON", "CLOSE_PAR", "ASSIGNMENT", "OPEN_C_BRACE", "CLOSE_C_BRACE",
  "COMMA", "REGISTER", "UNION", "NEW", "FORGET", "IF", "THEN", "ELSIF",
  "ELSE", "WHILE", "DO", "DONE", "FOR", "LET", "DEF", "AT", "RIGHT_ARROW",
  "INT", "FLOAT", "CHAR", "STRING", "TRUE", "FALSE", "T_UNIT", "T_BOOL",
  "T_CHAR", "T_INT", "T_FLOAT", "T_STRING", "$accept", "S", "I", "Inst",
  "Action", "Def", "VarInst", "VarDef", "IdDef", "OptAssign", "Assign",
  "RValue", "Type", "LValue", "Exp", "Array", "ArrExp", "ArrElems",
  "FuncCall", "ArgsExp", "Args", "UnionDef", "UnionId", "UnionBody",
  "RegDef", "RegId", "RegBody", "Conditional", "If", "OptElsif", "Elsifs",
  "Elsif", "OptElse", "Else", "LoopWhile", "While", "LoopFor", "IdFor",
  "For", "OptStep", "RoutDef", "RoutId", "RoutArgs", "OblArgs", "OptArgs",
  "OptRef", "OptReturn", "Actions", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    46,    44,    43,    42,    50,    48,    49,
      47,    45,    51,    52,    55,    54,    53,    41,     5,     6,
      13,    11,    32,     2,     1,     3,     4,     7,     8,     9,
      10,    12,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      33,    34,    35,    36,    37,    38,    39,    40
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -75

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-75)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     215,    40,     8,    40,   -13,   -13,    40,  -158,  -158,  -158,
      57,   -13,    33,   215,  -158,  -158,  -158,    11,  -158,  -158,
      -7,    15,  -158,    13,  -158,    17,  -158,    74,  -158,    74,
    -158,    27,  -158,    29,  -158,    35,    39,    -1,  -158,  -158,
    -158,    28,    57,  -158,    57,  -158,  -158,  -158,  -158,  -158,
    -158,    10,  -158,  -158,  -158,  -158,    74,    32,    25,  -158,
      57,    57,    74,    74,    74,    74,  -158,  -158,  -158,  -158,
    -158,    28,   287,  -158,   154,   -13,    57,    45,    25,  -158,
    -158,     4,    74,    55,   508,  -158,    59,    57,  -158,  -158,
     542,  -158,    10,   128,    10,   232,   116,    52,    52,    -1,
     426,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,   215,   215,  -158,    60,   -14,
      58,    61,    62,  -158,    63,  -158,   525,    25,  -158,  -158,
      69,    25,    75,    71,  -158,    10,    55,  -158,    10,  -158,
     555,   555,   319,   319,   566,   566,   566,   566,    52,    52,
      81,    81,    81,    81,   344,   361,    74,  -158,   -13,    73,
      57,    57,  -158,  -158,  -158,  -158,    76,  -158,    79,    80,
      55,  -158,    70,    64,    74,  -158,   464,    97,    57,   107,
     -14,    62,   -14,  -158,  -158,  -158,    82,  -158,    95,   215,
      74,   302,    74,    25,    75,  -158,   -13,   -13,  -158,  -158,
     215,   341,   215,   486,  -158,   424,    97,   113,   215,   215,
      74,   115,  -158,  -158,    25,   215,   542,   102,  -158,   215,
     385,  -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    42,     0,     0,     0,     0,    87,    97,   100,
       0,     0,     0,     2,     4,     6,     7,     0,    16,    17,
       0,     0,    13,     0,    14,     0,    10,     0,    11,     0,
      12,     0,    15,     0,    42,    39,    76,     0,    20,    83,
      79,    18,     0,    31,     0,    32,    33,    34,    35,    36,
      37,     0,   104,     1,     5,     8,     0,     0,     0,     9,
       0,     0,     0,     0,     0,     0,    66,    67,    65,    63,
      64,    61,     0,    62,     0,     0,   105,     0,     0,    41,
      29,     0,     0,    21,     0,    40,    71,     0,    26,    23,
      24,    25,     0,     0,     0,     0,    47,    58,    57,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,   113,
       0,   106,   107,    73,    75,    30,     0,     0,    19,    38,
       0,     0,    27,     0,    78,     0,    21,    82,     0,    60,
      43,    44,    45,    46,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    59,    88,     0,     0,   114,     0,   115,
       0,     0,    77,    28,    22,    68,    70,    80,     0,     0,
      21,    92,    93,    89,     0,    96,     0,   109,     0,     0,
     113,   108,   113,    72,    81,    84,     0,    95,     0,     0,
       0,     0,     0,     0,   116,   117,     0,     0,    85,    86,
      94,     0,     0,   101,   111,     0,   110,     0,     0,    90,
       0,     0,   103,   118,     0,    91,   102,     0,   112,     0,
       0,    98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -100,    -8,   -62,  -158,  -158,  -158,     7,  -129,
    -158,   -76,   -34,     0,   169,  -158,  -158,  -158,    21,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,   -24,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,    12,  -157,  -158,  -158
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    39,   128,
      19,    89,    51,    71,    90,    91,   130,   131,    73,    77,
      78,    22,    23,    93,    24,    25,    95,    26,    27,   172,
     173,   174,   188,   189,    28,    29,    30,   118,    31,   211,
      32,    33,   120,   121,   122,   158,   179,   205
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    35,   124,    37,    82,    54,    41,   169,    80,    38,
      81,    56,    40,    20,    57,   154,   155,    56,    52,    58,
      57,    21,    82,   196,    79,   197,    92,    94,    82,   125,
     157,    36,    38,    53,    21,    55,    62,    63,    64,    59,
      60,   186,   119,    86,    61,     1,    56,     2,    65,    57,
      75,   164,    76,   132,    85,   166,    57,    87,    83,   135,
       1,   138,    34,     3,   -74,    99,   111,   112,   113,   114,
     123,    66,    67,    68,    88,    69,    70,    42,   -69,    43,
      44,   127,   117,   159,   156,    62,    63,    64,   165,   200,
     160,   161,   162,    82,     1,   167,     2,    65,   114,   133,
     171,   136,   209,   184,   185,   183,   198,   187,   215,    45,
      46,    47,    48,    49,    50,    20,    20,   204,   178,   220,
      66,    67,    68,   193,    69,    70,   180,   182,   109,   110,
     111,   112,   113,   114,   195,   199,    21,    21,   218,   214,
     217,   219,   168,   213,   194,   170,    54,    54,    42,   190,
      43,    44,     0,     0,    20,    20,   134,   101,   102,   103,
     104,   105,   106,   107,   108,   177,   109,   110,   111,   112,
     113,   114,   181,     0,     0,    21,    21,     0,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    20,
       0,     0,    54,   116,     0,     0,    72,     0,    74,     0,
      20,    54,    20,   206,   207,    20,     0,    54,    20,    20,
      21,     0,    54,     0,     0,    20,     0,     0,     0,    20,
      20,    21,     0,    21,     0,    84,    21,     0,     0,    21,
      21,    96,    97,    98,   100,     1,    21,     2,     3,     0,
      21,    21,     0,     0,     0,     4,     5,     0,     6,     7,
       0,   126,    42,     8,    43,    44,     9,    10,    11,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    45,    46,    47,    48,    49,    50,
     101,   102,   103,   104,   105,   106,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   101,   102,   103,   104,   105,
     106,   107,   108,     0,   109,   110,   111,   112,   113,   114,
       0,     0,   115,     0,     0,   176,   105,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   202,     0,     0,
       0,     0,     0,   191,   101,   102,   103,   104,   105,   106,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   201,
       0,   203,     0,     0,     1,     0,     2,     3,     0,     0,
       0,     0,     0,     0,     4,     5,   208,     6,     7,   216,
     171,     1,     8,     2,     3,     9,    10,    11,     0,     0,
       0,     4,     5,     0,     6,     7,     0,     0,     0,     8,
       0,   175,     9,    10,    11,     1,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     6,     7,
       0,     0,     0,     8,     0,   221,     9,    10,    11,   101,
     102,   103,   104,   105,   106,   107,   108,     0,   109,   110,
     111,   112,   113,   114,     1,     0,     2,     3,     0,     0,
       0,   139,   212,     0,     0,     0,     0,     6,     7,     0,
       0,     0,     8,     0,     0,     9,    10,   101,   102,   103,
     104,   105,   106,   107,   108,     0,   109,   110,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,   192,   101,
     102,   103,   104,   105,   106,   107,   108,     0,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
     210,   101,   102,   103,   104,   105,   106,   107,   108,     0,
     109,   110,   111,   112,   113,   114,     0,   129,   101,   102,
     103,   104,   105,   106,   107,   108,     0,   109,   110,   111,
     112,   113,   114,     0,   163,   101,   102,   103,   104,   105,
     106,   107,   108,     0,   109,   110,   111,   112,   113,   114,
     103,   104,   105,   106,   107,   108,     0,   109,   110,   111,
     112,   113,   114,   -75,   -75,   -75,   -75,     0,   109,   110,
     111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
       0,     1,    78,     3,    18,    13,     6,   136,    42,    22,
      44,    18,     5,    13,    21,   115,   116,    18,    11,    26,
      21,     0,    18,   180,    25,   182,    60,    61,    18,    25,
      44,    23,    22,     0,    13,    24,    11,    12,    13,    24,
      27,   170,    76,    18,    27,    20,    18,    22,    23,    21,
      23,   127,    23,    87,    22,   131,    21,    32,    51,    93,
      20,    95,    22,    23,    25,    65,    14,    15,    16,    17,
      25,    46,    47,    48,    49,    50,    51,    20,    19,    22,
      23,    26,    75,    25,    24,    11,    12,    13,    19,   189,
      29,    29,    29,    18,    20,    24,    22,    23,    17,    92,
      36,    94,   202,    24,    24,    29,    24,    37,   208,    52,
      53,    54,    55,    56,    57,   115,   116,   193,    45,   219,
      46,    47,    48,    26,    50,    51,   160,   161,    12,    13,
      14,    15,    16,    17,    27,    40,   115,   116,   214,    26,
      25,    39,   135,   205,   178,   138,   154,   155,    20,   173,
      22,    23,    -1,    -1,   154,   155,    28,     3,     4,     5,
       6,     7,     8,     9,    10,   158,    12,    13,    14,    15,
      16,    17,   160,    -1,    -1,   154,   155,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,   189,
      -1,    -1,   200,    39,    -1,    -1,    27,    -1,    29,    -1,
     200,   209,   202,   196,   197,   205,    -1,   215,   208,   209,
     189,    -1,   220,    -1,    -1,   215,    -1,    -1,    -1,   219,
     220,   200,    -1,   202,    -1,    56,   205,    -1,    -1,   208,
     209,    62,    63,    64,    65,    20,   215,    22,    23,    -1,
     219,   220,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    82,    20,    38,    22,    23,    41,    42,    43,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    52,    53,    54,    55,    56,    57,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      -1,    -1,    35,    -1,    -1,   156,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    35,    -1,    -1,
      -1,    -1,    -1,   174,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,   190,
      -1,   192,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    35,    33,    34,   210,
      36,    20,    38,    22,    23,    41,    42,    43,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    20,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    20,    -1,    22,    23,    -1,    -1,
      -1,    25,    28,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    -1,    19,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    -1,    19,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    22,    23,    30,    31,    33,    34,    38,    41,
      42,    43,    59,    60,    61,    62,    63,    64,    65,    68,
      71,    76,    79,    80,    82,    83,    85,    86,    92,    93,
      94,    96,    98,    99,    22,    71,    23,    71,    22,    66,
      66,    71,    20,    22,    23,    52,    53,    54,    55,    56,
      57,    70,    66,     0,    61,    24,    18,    21,    26,    24,
      27,    27,    11,    12,    13,    23,    46,    47,    48,    50,
      51,    71,    72,    76,    72,    23,    23,    77,    78,    25,
      70,    70,    18,    66,    72,    22,    18,    32,    49,    69,
      72,    73,    70,    81,    70,    84,    72,    72,    72,    71,
      72,     3,     4,     5,     6,     7,     8,     9,    10,    12,
      13,    14,    15,    16,    17,    35,    39,    66,    95,    70,
     100,   101,   102,    25,    69,    25,    72,    26,    67,    19,
      74,    75,    70,    66,    28,    70,    66,    28,    70,    25,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    60,    60,    24,    44,   103,    25,
      29,    29,    29,    19,    69,    19,    69,    24,    66,    67,
      66,    36,    87,    88,    89,    40,    72,    66,    45,   104,
      70,   102,    70,    29,    24,    24,    67,    37,    90,    91,
      89,    72,    24,    26,    70,    27,   103,   103,    24,    40,
      60,    72,    35,    72,    69,   105,    66,    66,    35,    60,
      24,    97,    28,    62,    26,    60,    72,    25,    69,    39,
      60,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    63,    63,    63,    64,    64,    64,    65,
      66,    67,    67,    68,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    74,
      74,    75,    75,    76,    77,    77,    78,    78,    79,    80,
      81,    81,    82,    83,    84,    84,    85,    86,    87,    87,
      88,    88,    89,    90,    90,    91,    92,    93,    94,    95,
      96,    97,    97,    98,    99,   100,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     0,     2,     3,     1,     1,     1,     2,     4,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     2,
       3,     3,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       2,     0,     3,     4,     0,     2,     0,     3,     4,     2,
       3,     4,     4,     2,     4,     5,     7,     1,     0,     1,
       4,     5,     1,     0,     2,     1,     5,     1,    12,     1,
       1,     0,     2,     8,     2,     0,     1,     1,     3,     3,
       5,     5,     7,     0,     1,     0,     2,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    (YYSIZE_T) (*yytop == yytop_empty ? 0 : *yytop - *yybottom + 1);
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = (YYSIZE_T) (yyesp - *yyes + 1);
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        yytype_int16 yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = ((yytype_int16)
                     (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                      ? yytable[yyi]
                      : yydefgoto[yylhs]));
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", (int) yystate));
      }
    }
}


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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
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

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2:
#line 205 "parser.y" /* yacc.c:1652  */
    { (yyval.nS) = new NodeS((yyvsp[0].ast)); ast = (yyval.nS);  }
#line 1947 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 206 "parser.y" /* yacc.c:1652  */
    { (yyval.nS) = NULL; }
#line 1953 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 208 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeI(NULL, (yyvsp[0].ast)); }
#line 1959 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 209 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeI((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1965 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 211 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1971 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 212 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1977 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 214 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1983 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 215 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[-1].ast); ((NodeFunctionCall*) (yyval.ast))->setEndInst(); }
#line 1989 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 216 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1995 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 217 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2001 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 218 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2007 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 220 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2013 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 221 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2019 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 222 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2025 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 226 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2031 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 227 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2037 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 228 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeForget((yyvsp[0].ast)); }
#line 2043 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 230 "parser.y" /* yacc.c:1652  */
    { 
                                          (yyval.ast) = new NodeVarDef((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));
                                          int s = table.currentScope();
                                          Entry *e = new Entry((yyvsp[-1].str), s, "Var");
                                          table.insert(e);
                                        }
#line 2054 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 237 "parser.y" /* yacc.c:1652  */
    {
                                          if (! table.verifyInsert((yyvsp[0].str))) {
                                            addError((yyvsp[0].str), (string) "Redefinition of \"" + (yyvsp[0].str) + "\".");
                                          }
                                          (yyval.str) = (yyvsp[0].str); 
                                        }
#line 2065 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 243 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2071 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 244 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2077 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 246 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeAssign((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2083 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 248 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2089 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 249 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2095 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 250 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeSTRING((yyvsp[0].str)); }
#line 2101 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 251 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeNew((yyvsp[0].ast)); }
#line 2107 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 255 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeTypeArrayDef((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2113 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 256 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeTypePointerDef((yyvsp[0].ast)); }
#line 2119 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 257 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2125 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 258 "parser.y" /* yacc.c:1652  */
    {
                                              Entry *e;
                                              if ((e = table.lookup((yyvsp[0].str))) == NULL) {
                                                addError((yyvsp[0].str), (string) "\"" + (yyvsp[0].str) + "\" was not declared.");
                                              } else if (e->category != "Type") {
                                                addError((yyvsp[0].str), (string) "\"" + (yyvsp[0].str) + "\" is not a type.");
                                              }
                                              (yyval.ast) = new Type((yyvsp[0].str));
                                            }
#line 2139 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 267 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new Type((yyvsp[0].str)); }
#line 2145 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 268 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new Type((yyvsp[0].str)); }
#line 2151 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 269 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new Type((yyvsp[0].str)); }
#line 2157 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 270 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new Type((yyvsp[0].str)); }
#line 2163 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 271 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new Type((yyvsp[0].str)); }
#line 2169 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 272 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new Type((yyvsp[0].str)); }
#line 2175 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 276 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeArrayLValue((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2181 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 277 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodePointerLValue((yyvsp[0].ast)); }
#line 2187 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 278 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeDotLValue((yyvsp[-2].ast), (yyvsp[0].str)); }
#line 2193 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 279 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2199 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 280 "parser.y" /* yacc.c:1652  */
    { 
                                                    Entry *e;
                                                    if ((e = table.lookup((yyvsp[0].str))) == NULL) {
                                                      addError((yyvsp[0].str), (string) "\"" + (yyvsp[0].str) + "\" was not declared.");
                                                    } else if (e->category != "Var") {
                                                      addError((yyvsp[0].str), (string) "\"" + (yyvsp[0].str) + "\" is not a variable.");
                                                    }
                                                    (yyval.ast) = new NodeIDLValue((yyvsp[0].str)); 
                                                  }
#line 2213 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 292 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2219 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 293 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2225 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 294 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2231 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 295 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2237 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 296 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeUnaryOperator((yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2243 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 297 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2249 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 298 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2255 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 299 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2261 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 300 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2267 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 301 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2273 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 302 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2279 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 303 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2285 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 304 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2291 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 305 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2297 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 306 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeUnaryOperator((yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2303 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 307 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeUnaryOperator((yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2309 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 308 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2315 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 309 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2321 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 310 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2327 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 311 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2333 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 312 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBOOL(true); }
#line 2339 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 313 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeBOOL(false); }
#line 2345 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 314 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeCHAR((yyvsp[0].ch)); }
#line 2351 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 315 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeINT((yyvsp[0].integer)); }
#line 2357 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 316 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeFLOAT((yyvsp[0].flot)); }
#line 2363 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 320 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeArray((yyvsp[-1].ast)); }
#line 2369 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 322 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2375 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 323 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeArrayElems((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2381 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 325 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2387 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 326 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeArrayElems((yyvsp[-2].ast), (yyvsp[-1].ast)); }
#line 2393 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 330 "parser.y" /* yacc.c:1652  */
    { 
                                              Entry *e;
                                              if ((e = table.lookup((yyvsp[-3].str))) == NULL) {
                                                addError((yyvsp[-3].str), (string) "\"" + (yyvsp[-3].str) + "\" was not declared.");
                                              } else if (e->category != "Function") {
                                                addError((yyvsp[-3].str), (string) "\"" + (yyvsp[-3].str) + "\" is not a function.");
                                              }
                                              (yyval.ast) = new NodeFunctionCall((yyvsp[-3].str), (yyvsp[-1].ast), false); 
                                            }
#line 2407 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 340 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2413 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 341 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeFunctionCallArgs((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2419 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 343 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2425 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 344 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeFunctionCallArgs((yyvsp[-2].ast), (yyvsp[-1].ast)); }
#line 2431 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 348 "parser.y" /* yacc.c:1652  */
    { 
                                                            (yyval.ast) = new NodeUnionDef((yyvsp[-3].str), (yyvsp[-1].ast));
                                                            table.exitScope(); 
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry((yyvsp[-3].str), s, "Type");
                                                            table.insert(e);
                                                          }
#line 2443 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 356 "parser.y" /* yacc.c:1652  */
    { table.newScope(); (yyval.str) = (yyvsp[0].str); }
#line 2449 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 358 "parser.y" /* yacc.c:1652  */
    { 
                                                            (yyval.ast) = new NodeUnionFields(NULL, (yyvsp[-2].ast), (yyvsp[-1].str)); 
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry((yyvsp[-1].str), s, "Field");
                                                            table.insert(e);
                                                          }
#line 2460 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 364 "parser.y" /* yacc.c:1652  */
    { 
                                                            (yyval.ast) = new NodeUnionFields((yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].str)); 
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry((yyvsp[-1].str), s, "Field");
                                                            table.insert(e);
                                                          }
#line 2471 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 373 "parser.y" /* yacc.c:1652  */
    { 
                                                        (yyval.ast) = new NodeRegDef((yyvsp[-3].str), (yyvsp[-1].ast));
                                                        table.exitScope();
                                                        int s = table.currentScope();
                                                        Entry *e = new Entry((yyvsp[-3].str), s, "Type");
                                                        table.insert(e);
                                                      }
#line 2483 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 381 "parser.y" /* yacc.c:1652  */
    { table.newScope(); (yyval.str) = (yyvsp[0].str); }
#line 2489 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 383 "parser.y" /* yacc.c:1652  */
    { 
                                                        (yyval.ast) = new NodeRegFields(NULL, (yyvsp[-3].ast), (yyvsp[-2].str), (yyvsp[-1].ast));
                                                        int s = table.currentScope();
                                                        Entry *e = new Entry((yyvsp[-2].str), s, "Field");
                                                        table.insert(e);
                                                      }
#line 2500 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 389 "parser.y" /* yacc.c:1652  */
    { 
                                                        (yyval.ast) = new NodeRegFields((yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].str), (yyvsp[-1].ast));
                                                        int s = table.currentScope();
                                                        Entry *e = new Entry((yyvsp[-2].str), s, "Field");
                                                        table.insert(e);
                                                      }
#line 2511 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 400 "parser.y" /* yacc.c:1652  */
    { 
                                                      (yyval.ast) = new NodeConditional((yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
                                                      table.exitScope(); 
                                                    }
#line 2520 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 405 "parser.y" /* yacc.c:1652  */
    { table.newScope(); }
#line 2526 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 407 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2532 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 408 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2538 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 410 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeElsif(NULL, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2544 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 411 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeElsif((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2550 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 413 "parser.y" /* yacc.c:1652  */
    { 
                                                      table.exitScope();
                                                      table.newScope(); 
                                                    }
#line 2559 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 418 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2565 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 419 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeElse((yyvsp[0].ast)); }
#line 2571 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 421 "parser.y" /* yacc.c:1652  */
    { 
                                                      table.exitScope();
                                                      table.newScope(); 
                                                    }
#line 2580 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 428 "parser.y" /* yacc.c:1652  */
    { 
                                                        (yyval.ast) = new NodeWhile((yyvsp[-3].ast), (yyvsp[-1].ast)); 
                                                        table.exitScope();
                                                      }
#line 2589 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 433 "parser.y" /* yacc.c:1652  */
    { table.newScope(); }
#line 2595 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 436 "parser.y" /* yacc.c:1652  */
    { 
                                                        (yyval.ast) = new NodeFor((yyvsp[-9].str), (yyvsp[-7].ast), (yyvsp[-5].ast), (yyvsp[-4].ast), (yyvsp[-1].ast));
                                                        table.exitScope();
                                                      }
#line 2604 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 441 "parser.y" /* yacc.c:1652  */
    { 
                                                        int s = table.currentScope();
                                                        Entry *e = new Entry((yyvsp[0].str), s, "Var");
                                                        table.insert(e); 
                                                        (yyval.str) = (yyvsp[0].str); 
                                                      }
#line 2615 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 448 "parser.y" /* yacc.c:1652  */
    { table.newScope(); }
#line 2621 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 450 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2627 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 451 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2633 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 456 "parser.y" /* yacc.c:1652  */
    { 
                                                            (yyval.ast) = new NodeRoutineDef(
                                                              (yyvsp[-7].str), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)
                                                            ); 
                                                            table.exitScope();
                                                          }
#line 2644 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 463 "parser.y" /* yacc.c:1652  */
    {
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry((yyvsp[0].str), s, "Function");
                                                            table.insert(e);
                                                            table.newScope();
                                                            (yyval.str) = (yyvsp[0].str);
                                                          }
#line 2656 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 471 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2662 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 472 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeRoutArgs((yyvsp[0].ast), NULL); }
#line 2668 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 473 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeRoutArgs(NULL, (yyvsp[0].ast)); }
#line 2674 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 474 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeRoutArgs((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2680 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 476 "parser.y" /* yacc.c:1652  */
    { 
                                                            (yyval.ast) = new NodeRoutArgDef(
                                                              NULL, (yyvsp[-2].ast), (yyvsp[-1].boolean), (yyvsp[0].str), NULL
                                                            );
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry((yyvsp[0].str), s, "Var");
                                                            table.insert(e);
                                                          }
#line 2693 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 484 "parser.y" /* yacc.c:1652  */
    { 
                                                            (yyval.ast) = new NodeRoutArgDef(
                                                              (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].boolean), (yyvsp[0].str), NULL
                                                            );
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry((yyvsp[0].str), s, "Var");
                                                            table.insert(e);
                                                          }
#line 2706 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 493 "parser.y" /* yacc.c:1652  */
    { 
                                                            (yyval.ast) = new NodeRoutArgDef(
                                                              NULL, (yyvsp[-4].ast), (yyvsp[-3].boolean), (yyvsp[-2].str), (yyvsp[0].ast)
                                                            );
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry((yyvsp[-2].str), s, "Var");
                                                            table.insert(e);
                                                          }
#line 2719 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 502 "parser.y" /* yacc.c:1652  */
    { 
                                                            (yyval.ast) = new NodeRoutArgDef(
                                                              (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-3].boolean), (yyvsp[-2].str), (yyvsp[0].ast)
                                                            );
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry((yyvsp[-2].str), s, "Var");
                                                            table.insert(e);
                                                          }
#line 2732 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 511 "parser.y" /* yacc.c:1652  */
    { (yyval.boolean) = false; }
#line 2738 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 512 "parser.y" /* yacc.c:1652  */
    { (yyval.boolean) = true; }
#line 2744 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 115:
#line 514 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2750 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 515 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2756 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 117:
#line 517 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = NULL; }
#line 2762 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 118:
#line 518 "parser.y" /* yacc.c:1652  */
    { (yyval.ast) = new NodeActions((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2768 "parser.tab.c" /* yacc.c:1652  */
    break;


#line 2772 "parser.tab.c" /* yacc.c:1652  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 521 "parser.y" /* yacc.c:1918  */


int main(int argc, char **argv)
{
  // Booleans for options
  bool bLexOpt = false;
  bool bParseOpt = false;
  bool bSymbolsOpt = false;
  bool bTreeOpt = false;
  bool bRepOpt = false;

  // Verify all arguments has been passed
  if (argc < 3 || argc > 4) {
    cout << "\e[1mSYNOPSIS\n"
      "\t\e[1mmaclang\e[0m lex \e[4mFILE\e[0m\n"
      "\t\e[1mmaclang\e[0m parse -t \e[4mFILE\e[0m\n"
      "\t\e[1mmaclang\e[0m parse -c \e[4mFILE\e[0m\n"
      "\t\e[1mmaclang\e[0m symbols \e[4mFILE\e[0m\n";
    return 1;
  } 
  
  // Check if provided method is valid
  if (strcmp(argv[1], "lex") && strcmp(argv[1], "parse") && strcmp(argv[1], "symbols")) {
    cout << "Invalid action: " << argv[1] << endl;
    return 1;

  } else if (strcmp(argv[1], "parse") == 0) {
    // Parsing.

    bParseOpt = true;
    // Print tree
    if (strcmp(argv[2], "-t") == 0) { bTreeOpt = true; }
    // Print code representation
    else if (strcmp(argv[2], "-c") == 0) { bRepOpt = true; }
    else {
      cout << "Invalid flag: " << argv[2] << endl;
      return 1;
    }
    filename = argv[3];

  } else if (strcmp(argv[1], "lex") == 0) {
    // Lexing.

    bLexOpt = true;
    filename = argv[2];

  } else {
    // Sumbols table 

    bSymbolsOpt = true;
    filename = argv[2];
  }
  
  // open file to extract the tokens
  extern FILE *yyin;
  yyin = fopen(filename, "r");
    
  // check if file was succesfully opened.
  if (!yyin) 
  {
    cout << "There was an error opening the file" << endl;
    return -1;
  }

  // apply lexing if lexing option is passed
  // if not, yyparse will call yylex.
  int tok;
  while(bLexOpt && (tok = yylex()))
  {
    // if token can have multiple values, also print the value of the token
    switch(tok) {
      case INT:
        tokens.push("\e[0;33m" + to_string(tok) + ":\t\e[0m\e[1;34m " + 
                    tokenNames[tok-1] + "\e[0m = \e[1;36m" + 
                    to_string(yylval.integer) + "\n");
        break;
      case FLOAT:
        tokens.push("\e[0;33m" + to_string(tok) + ":\t\e[0m\e[1;32m " + 
                    tokenNames[tok-1] + "\e[0m = \e[1;36m" + 
                    to_string(yylval.flot) + "\n");
        break;
      case CHAR:
        tokens.push("\e[0;33m" + to_string(tok) + ":\t\e[0m\e[1;35m " + 
                    tokenNames[tok-1] + "\e[0m = \e[1;36m" + yylval.ch + "\n");
        break;
      case STRING:
      case ID:
        tokens.push("\e[0;33m" + to_string(tok) + ":\t\e[0m\e[1;31m " + 
                    tokenNames[tok-1] + "\e[0m = \e[1;36m" + yylval.str + "\n");
        break;
      default:
        tokens.push("\e[0;33m" + to_string(tok) + ":\t\e[0m\e[1;37m " + 
                    tokenNames[tok-1] + "\e[0m\n");
    }
  }

  fclose(yyin);

  // if were asked just for lexing print the results of it and return
  if (bLexOpt) {
    if(errors.empty())
      printQueue(tokens);
    else
      printQueue(errors);

    return 0;
  }

  // parsing
  yyin = fopen(filename, "r");

  // reset lines and columns
  yylineno = 1; 
  yycolumn = 1;

  // start parsing
  yyparse();

  if (errors.empty()) {
    if (bParseOpt) {
      if (bTreeOpt) {
        ast->printTree(NULL);
      } else {
        ast->print();
      }
    } else {
      table.printTable();
    }
  } else {
    // print all errors
    printQueue(errors);

    return 1;
  }

  return 0;
}

/*
  Prints error.
*/
void yyerror(string s)
{
  string file = strdup(filename);
    
  // Add syntax error
  string error = "\e[1m" + file + " (" + to_string(yylineno) + ", " + 
    to_string(yycolumn) + "): \e[31mSyntax error:\e[0m Unexpected " +
    "token \"" + yytext + "\".\n\n";

  errors.push(error);

  // read the remaining file for more lexical errors.
  while(yylex());
}

/*
  Prints the queue to std.
*/
void printQueue(queue<string> queueToPrint)
{
  while (!queueToPrint.empty()) {
    cout << queueToPrint.front();
    queueToPrint.pop();
  }
}

/*
  Add a error to vector errors.
*/
void addError(string id, string error) {
  string file = strdup(filename);

  string err = "\e[1m" + file + " (" + to_string(yylineno) + ", " + 
    to_string(yycolumn) + "): \e[31mError:\e[0m " + error + "\n\n";

  // add the error to the queue
  errors.push(err);
}
