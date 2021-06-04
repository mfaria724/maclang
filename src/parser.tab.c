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

  #include <iostream>
  #include <queue>
  #include <cstring>
  #include <string>

  using namespace std;

  extern int yylex(void);
  extern int yylineno;
  extern int yycolumn;
  extern char *yytext;

  // queues for tokens and errors
  extern queue<string> errors;

  // offsets the columns and the rows for multiline comments, as could be the case
  void setMultiLineOffset(char* text);

  // Prints error;
  void yyerror(char *s);

  // Prints the queue to std.
  void printQueue(queue<string> queueToPrint);

  /*
    Starts lexer execution
  int main(int argc, char **argv)
  {
    // Look for input line
    if(argc < 2) 
    {
      cout << "No input file" << endl;
      return -1;
    }

    // open file to extract the tokens
    FILE *file = fopen(argv[1], "r");
      
    // check if file was succesfully opened.
    if (!file) 
    {
      cout << "There was an error opening the file" << endl;
      return -1;
    }

    // insert tokens into the lexer
    yyin = file;

    // iterate while there are new tokens
    int tok;
    while(tok = yylex()) 
    {
      // if token can have multiple values, also print the value of the token
      if(tok == INT || tok == ID || tok == SINGLE_QUOTE || tok == DOUBLE_QUOTE
        || tok == FLOAT)
      {
        tokens.push(to_string(tok) + " = " + yylval + "\n");
      }
      else 
        tokens.push(to_string(tok) + "\n");
      col += strlen(yytext);
    }

    fclose(file);

    if(errors.empty())
      printQueue(tokens);
    else
      printQueue(errors);

    return 0;
  }
  */

#line 146 "parser.tab.c" /* yacc.c:337  */
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
    EQUIV = 258,
    NOT_EQUIV = 259,
    OR = 260,
    AND = 261,
    LESS_THAN = 262,
    LESS_EQUAL_THAN = 263,
    GREATER_THAN = 264,
    GREATER_EQUAL_THAN = 265,
    NOT = 266,
    PLUS = 267,
    MINUS = 268,
    ASTERISK = 269,
    DIV = 270,
    MODULE = 271,
    POWER = 272,
    OPEN_BRACKET = 273,
    CLOSE_BRACKET = 274,
    POINTER = 275,
    DOT = 276,
    OPEN_PAR = 277,
    SEMICOLON = 278,
    CLOSE_PAR = 279,
    ASSIGNMENT = 280,
    T_INT = 281,
    T_CHAR = 282,
    T_BOOL = 283,
    T_FLOAT = 284,
    T_UNIT = 285,
    T_STRING = 286,
    OPEN_C_BRACE = 287,
    CLOSE_C_BRACE = 288,
    COMMA = 289,
    REGISTER = 290,
    UNION = 291,
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
    DEF = 304,
    AT = 305,
    RIGHT_ARROW = 306,
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
#line 80 "parser.y" /* yacc.c:352  */
	
  int   integer;
  float flot;
  bool  boolean;
  char  *str;
  char  ch;

#line 256 "parser.tab.c" /* yacc.c:352  */
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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

#define YYUNDEFTOK  2
#define YYMAXUTOK   313

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   165,   167,   168,   170,   171,   173,   174,
     175,   176,   177,   179,   180,   181,   185,   186,   188,   190,
     192,   193,   195,   197,   198,   199,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   215,   216,   217,   218,   219,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   251,   253,   254,   256,   257,
     261,   263,   264,   266,   267,   271,   273,   274,   278,   280,
     281,   285,   287,   288,   290,   291,   293,   294,   298,   300,
     302,   303,   307,   309,   310,   312,   313,   315,   316,   318,
     319,   321,   322
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
  "OPEN_BRACKET", "CLOSE_BRACKET", "POINTER", "DOT", "OPEN_PAR",
  "SEMICOLON", "CLOSE_PAR", "ASSIGNMENT", "T_INT", "T_CHAR", "T_BOOL",
  "T_FLOAT", "T_UNIT", "T_STRING", "OPEN_C_BRACE", "CLOSE_C_BRACE",
  "COMMA", "REGISTER", "UNION", "NEW", "FORGET", "IF", "THEN", "ELSIF",
  "ELSE", "END", "WHILE", "DO", "DONE", "FOR", "LET", "DEF", "AT",
  "RIGHT_ARROW", "INT", "FLOAT", "ID", "CHAR", "STRING", "TRUE", "FALSE",
  "$accept", "S", "I", "Inst", "Action", "Def", "VarInst", "VarDef",
  "VarDefBody", "OptAssign", "Assign", "RValue", "Type", "LValue", "Exp",
  "Array", "ArrExp", "ArrElems", "FuncCall", "ArgsExp", "Args", "UnionDef",
  "UnionBody", "RegisterDef", "RegisterBody", "Conditional", "OptElsif",
  "Elsifs", "OptElse", "LoopWhile", "LoopFor", "OptStep", "RutineDef",
  "RutineArgs", "ArgsDef", "OptRef", "OptReturn", "Actions", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF -148

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-148)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-72)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,    12,    12,   -33,   -13,    16,    16,    21,   188,    -8,
      39,    79,    28,  -148,  -148,  -148,    61,  -148,  -148,    19,
      71,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    41,    83,
      60,    84,    16,    16,    16,    16,  -148,  -148,  -148,  -148,
    -148,     5,   123,  -148,   140,    63,   188,   188,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,   -15,    93,    97,  -148,  -148,
    -148,    16,    66,     2,  -148,  -148,    74,   188,    96,   144,
     144,    83,   400,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    28,    28,   111,
    -148,    62,    16,   126,   188,   141,     2,   464,  -148,   145,
    -148,  -148,   498,  -148,   143,   -17,    -7,    69,  -148,   511,
     511,   294,   294,   329,   329,   329,   329,   144,   144,   150,
     150,   150,   150,   278,   313,    16,  -148,   481,     2,  -148,
      31,   146,   188,  -148,   135,  -148,   152,     2,  -148,  -148,
     151,   154,  -148,    -1,    16,   133,   137,  -148,   422,  -148,
    -148,  -148,   130,   136,    31,  -148,  -148,   158,  -148,  -148,
     175,   240,    28,   159,    16,    16,   126,   188,   169,   149,
    -148,  -148,    28,    28,  -148,   280,   443,  -148,   195,   348,
     126,    28,    28,    16,   181,  -148,   187,  -148,    28,   498,
     176,  -148,  -148,    28,   336,  -148
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     2,     4,     6,     7,     0,    16,    17,     0,
       0,    13,    14,    10,    11,    12,    15,    39,    36,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    62,    60,
      61,    58,     0,    59,     0,     0,     0,     0,    32,    31,
      30,    33,    29,    34,    18,     0,     0,    73,     1,     5,
       8,     0,     0,     0,     9,    38,     0,     0,    44,    55,
      54,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    20,    93,     0,     0,     0,    37,    68,
      25,    22,    23,    24,     0,     0,     0,     0,    57,    40,
      41,    42,    43,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    56,    82,     0,     0,    28,     0,     0,    19,
      97,     0,    94,    70,    72,    35,     0,     0,    79,    78,
       0,     0,    75,     0,     0,    86,    83,    88,     0,    26,
      21,    98,     0,    99,    97,    74,    65,    67,    80,    76,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
      69,    77,     0,    87,    81,     0,    90,    95,   100,     0,
      20,    84,     0,     0,     0,   101,     0,    96,    85,    91,
       0,    92,   102,     0,     0,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,   -79,    -5,  -101,  -148,  -148,   -60,  -148,  -147,
    -148,   -86,   -42,     0,   190,  -148,  -148,  -148,    18,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,    73,  -148,  -148
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    16,    17,    54,   129,
      18,   101,    55,    41,   102,   103,   136,   137,    43,    95,
      96,    21,   107,    22,   105,    23,   145,   146,   163,    24,
      25,   184,    26,   131,   132,   152,   168,   186
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    28,    29,    92,    90,    91,   104,    59,   123,   124,
     134,    92,    19,    32,    33,    34,   139,    92,    20,   177,
      99,    30,     1,    61,    35,   106,    62,    32,    33,    34,
      20,     8,     1,   187,     2,    71,     1,    61,    35,    93,
      62,    31,   150,    45,    63,   140,    56,   141,     1,    92,
       2,   157,   130,   160,    36,    37,    10,    38,   100,    39,
      40,    57,    62,     3,     4,   143,    27,     5,    36,    37,
      10,    38,     6,    39,    40,     7,     8,     9,   185,    58,
      92,   151,    10,   173,    60,   192,   126,    19,    19,    46,
     154,    47,    66,   181,    64,    48,    49,    50,    51,    52,
      53,    61,   142,   188,    62,    20,    20,    65,    81,    82,
      83,    84,    85,    86,   194,    94,    67,    89,    59,    59,
      98,   -71,     8,    19,    19,   178,    73,    74,    75,    76,
      77,    78,    79,    80,   125,    81,    82,    83,    84,    85,
      86,    20,    20,    73,    74,    75,    76,    77,    78,    79,
      80,   128,    81,    82,    83,    84,    85,    86,    83,    84,
      85,    86,    19,    87,   -66,   133,   138,    86,    59,   155,
     153,   156,    19,    19,   158,   162,    59,   159,   164,    19,
      20,    19,    19,    59,   166,    88,    19,   167,    19,    59,
      20,    20,   170,    19,    19,    42,    44,    20,   171,    20,
      20,   179,   174,   180,    20,   190,    20,     1,    46,     2,
      47,    20,    20,    92,    48,    49,    50,    51,    52,    53,
     191,   193,    68,    69,    70,    72,     5,   169,     0,     0,
       0,     6,     0,     0,     7,     8,     0,     0,     0,     0,
       0,    10,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    97,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
     172,     0,   127,    73,    74,    75,    76,    77,    78,    79,
      80,     0,    81,    82,    83,    84,    85,    86,     1,     0,
       2,    77,    78,    79,    80,     0,    81,    82,    83,    84,
      85,    86,     0,     3,     4,   148,     0,     5,     0,   144,
     182,     0,     6,     0,     0,     7,     8,     9,     0,     0,
       0,     0,    10,     1,   161,     2,   -72,   -72,   -72,   -72,
       0,    81,    82,    83,    84,    85,    86,     0,     3,     4,
       0,     0,     5,     0,   175,   176,     1,     6,     2,   147,
       7,     8,     9,     0,     0,     0,     0,    10,     1,     0,
       2,     3,     4,   189,     0,     5,     0,     0,     0,     0,
       6,     0,   195,     7,     8,     9,     0,     5,     0,     0,
      10,     0,     6,     0,     0,     7,     8,     0,     0,     0,
       0,     0,    10,    73,    74,    75,    76,    77,    78,    79,
      80,     0,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,   108,    73,    74,    75,    76,    77,
      78,    79,    80,     0,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,   165,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,   183,    73,    74,    75,
      76,    77,    78,    79,    80,     0,    81,    82,    83,    84,
      85,    86,     0,   135,    73,    74,    75,    76,    77,    78,
      79,    80,     0,    81,    82,    83,    84,    85,    86,     0,
     149,    73,    74,    75,    76,    77,    78,    79,    80,     0,
      81,    82,    83,    84,    85,    86,    75,    76,    77,    78,
      79,    80,     0,    81,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       0,     1,     2,    18,    46,    47,    66,    12,    87,    88,
      96,    18,    12,    11,    12,    13,    33,    18,     0,   166,
      18,    54,    20,    18,    22,    67,    21,    11,    12,    13,
      12,    48,    20,   180,    22,    35,    20,    18,    22,    54,
      21,    54,   128,    22,    25,   105,    54,    54,    20,    18,
      22,   137,    94,    54,    52,    53,    54,    55,    56,    57,
      58,    22,    21,    35,    36,   107,    54,    39,    52,    53,
      54,    55,    44,    57,    58,    47,    48,    49,   179,     0,
      18,    50,    54,   162,    23,   186,    24,    87,    88,    20,
     132,    22,    32,   172,    23,    26,    27,    28,    29,    30,
      31,    18,    33,   182,    21,    87,    88,    24,    12,    13,
      14,    15,    16,    17,   193,    22,    32,    54,   123,   124,
      54,    24,    48,   123,   124,   167,     3,     4,     5,     6,
       7,     8,     9,    10,    23,    12,    13,    14,    15,    16,
      17,   123,   124,     3,     4,     5,     6,     7,     8,     9,
      10,    25,    12,    13,    14,    15,    16,    17,    14,    15,
      16,    17,   162,    40,    19,    24,    23,    17,   173,    34,
      24,    19,   172,   173,    23,    42,   181,    23,    41,   179,
     162,   181,   182,   188,    54,    45,   186,    51,   188,   194,
     172,   173,    34,   193,   194,     5,     6,   179,    23,   181,
     182,    32,    43,    54,   186,    24,   188,    20,    20,    22,
      22,   193,   194,    18,    26,    27,    28,    29,    30,    31,
      33,    45,    32,    33,    34,    35,    39,   154,    -1,    -1,
      -1,    44,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    54,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    61,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      40,    -1,    92,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    20,    -1,
      22,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    -1,    35,    36,   125,    -1,    39,    -1,    41,
      40,    -1,    44,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    20,   144,    22,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    -1,    35,    36,
      -1,    -1,    39,    -1,   164,   165,    20,    44,    22,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    20,    -1,
      22,    35,    36,   183,    -1,    39,    -1,    -1,    -1,    -1,
      44,    -1,    46,    47,    48,    49,    -1,    39,    -1,    -1,
      54,    -1,    44,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    54,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    23,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    23,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    -1,    19,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      19,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    22,    35,    36,    39,    44,    47,    48,    49,
      54,    60,    61,    62,    63,    64,    65,    66,    69,    72,
      77,    80,    82,    84,    88,    89,    91,    54,    72,    72,
      54,    54,    11,    12,    13,    22,    52,    53,    55,    57,
      58,    72,    73,    77,    73,    22,    20,    22,    26,    27,
      28,    29,    30,    31,    67,    71,    54,    22,     0,    62,
      23,    18,    21,    25,    23,    24,    32,    32,    73,    73,
      73,    72,    73,     3,     4,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    15,    16,    17,    40,    45,    54,
      71,    71,    18,    54,    22,    78,    79,    73,    54,    18,
      56,    70,    73,    74,    66,    83,    71,    81,    24,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    61,    61,    23,    24,    73,    25,    68,
      71,    92,    93,    24,    70,    19,    75,    76,    23,    33,
      66,    54,    33,    71,    41,    85,    86,    46,    73,    19,
      70,    50,    94,    24,    71,    34,    19,    70,    23,    23,
      54,    73,    42,    87,    41,    23,    54,    51,    95,    94,
      34,    23,    40,    61,    43,    73,    73,    68,    71,    32,
      54,    61,    40,    23,    90,    63,    96,    68,    61,    73,
      24,    33,    63,    45,    61,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    66,    67,
      68,    68,    69,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    81,    81,    82,    83,
      83,    84,    85,    85,    86,    86,    87,    87,    88,    89,
      90,    90,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       0,     2,     3,     1,     1,     1,     4,     2,     3,     1,
       1,     1,     1,     1,     1,     4,     2,     3,     3,     1,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     2,     0,     3,
       4,     0,     2,     0,     3,     5,     3,     4,     5,     2,
       3,     7,     0,     1,     4,     5,     0,     2,     5,    12,
       0,     2,     9,     0,     1,     4,     5,     0,     1,     0,
       2,     1,     2
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
#line 164 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1899 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 167 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1905 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 168 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1911 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 170 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1917 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 171 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1923 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 173 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1929 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 174 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1935 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 175 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1941 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 176 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1947 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 177 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1953 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 179 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1959 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 180 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1965 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 181 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1971 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 185 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1977 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 186 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1983 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 188 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1989 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 190 "parser.y" /* yacc.c:1652  */
    { ; }
#line 1995 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 193 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2001 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 195 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2007 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 197 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2013 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 198 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2019 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 199 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2025 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 203 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2031 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 204 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2037 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 205 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2043 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 206 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2049 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 207 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2055 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 208 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2061 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 209 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2067 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 210 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2073 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 211 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2079 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 215 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2085 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 216 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2091 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 217 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2097 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 218 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2103 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 219 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2109 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 223 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2115 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 224 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2121 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 225 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2127 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 226 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2133 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 227 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2139 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 228 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2145 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 229 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2151 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 230 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2157 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 231 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2163 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 232 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2169 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 233 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2175 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 234 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2181 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 235 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2187 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 236 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2193 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 237 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2199 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 238 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2205 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 239 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2211 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 240 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2217 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 241 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2223 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 242 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2229 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 243 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2235 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 244 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2241 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 245 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2247 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 246 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2253 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 247 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2259 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 261 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2265 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 264 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2271 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 267 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2277 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 271 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2283 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 273 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2289 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 274 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2295 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 278 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2301 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 280 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2307 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 281 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2313 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 285 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2319 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 288 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2325 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 290 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2331 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 291 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2337 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 294 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2343 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 298 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2349 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 300 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2355 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 303 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2361 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 307 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2367 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 310 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2373 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 312 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2379 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 313 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2385 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 316 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2391 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 319 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2397 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 321 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2403 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 322 "parser.y" /* yacc.c:1652  */
    { ; }
#line 2409 "parser.tab.c" /* yacc.c:1652  */
    break;


#line 2413 "parser.tab.c" /* yacc.c:1652  */
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
#line 325 "parser.y" /* yacc.c:1918  */


int main(int argc, char **argv)
{
  // Look for input line
  if(argc != 2) 
  {
    cout << "No input file" << endl;
    return -1;
  }

  // open file to extract the tokens
  extern FILE *yyin;
  yyin = fopen(argv[1], "r");
    
  // check if file was succesfully opened.
  if (!yyin) 
  {
    cout << "There was an error opening the file" << endl;
    return -1;
  }

  yyparse();
  return 0;
}

/*
  Prints error.
*/
void yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

/*
  offsets the columns and the rows for multiline comments, as could be the case
  that after a multiline comment could be a valid code statement.
*/
void setMultiLineOffset(char* text)
{ 
  for (int i=0; i < strlen(text); i++)
  {
    char x = text[i];

    // If there is a line break, reset the column and increment the row.
    if(x == '\n')
    {
      yylineno++;
      yycolumn = 0;
    } else {
      yycolumn++;
    }
  }
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
