%{
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
%}

%define parse.lac full

%union 
{	
  int   integer;
  float flot;
  bool  boolean;
  char  *str;
  char  ch;
  Node  *ast;
  NodeS *nS;
}

%locations
%start S

%left       EQUIV NOT_EQUIV
%left       OR AND 
%nonassoc   LESS_THAN LESS_EQUAL_THAN GREATER_THAN GREATER_EQUAL_THAN
%right      NOT
%left       PLUS MINUS
%left       ASTERISK DIV MODULE
%right      POWER
%left       OPEN_BRACKET CLOSE_BRACKET
%right      POINTER
%left       DOT
%nonassoc   ID
%left       OPEN_PAR


%token SEMICOLON 1
%token OPEN_PAR 2
%token CLOSE_PAR 3
%token ASSIGNMENT 4
%token OPEN_BRACKET 5
%token CLOSE_BRACKET 6
%token OPEN_C_BRACE 7
%token CLOSE_C_BRACE 8
%token COMMA 9
%token REGISTER 10
%token DOT 11
%token UNION 12
%token POINTER 13
%token NEW 14
%token FORGET 15
%token IF 16
%token THEN 17
%token ELSIF 18
%token ELSE 19
%token WHILE 20
%token DO 21
%token DONE 22
%token FOR 23
%token LET 24
%token DEF 25
%token AT 26
%token RIGHT_ARROW 27

%token <integer>  INT 28
%token <flot>     FLOAT 29
%token <ch>       CHAR 30
%token <str>      STRING 31
%token <str>      ID 32
%token <boolean>  TRUE 33 
%token <boolean>  FALSE 34
%token <str>      T_UNIT 35
%token <str>      T_BOOL 36
%token <str>      T_CHAR 37
%token <str>      T_INT 38
%token <str>      T_FLOAT 39
%token <str>      T_STRING 40
%token <str>      POWER 41
%token <str>      AND 42
%token <str>      OR 43
%token <str>      NOT_EQUIV 44
%token <str>      NOT 45
%token <str>      EQUIV 46
%token <str>      GREATER_EQUAL_THAN 47
%token <str>      LESS_EQUAL_THAN 48
%token <str>      GREATER_THAN 49
%token <str>      LESS_THAN 50
%token <str>      PLUS 51
%token <str>      MINUS 52
%token <str>      MODULE 53 
%token <str>      DIV 54
%token <str>      ASTERISK 55

%type <ast>       I Inst Action VarInst VarDef OptAssign Type OptReturn
%type <ast>       LValue Exp Array ArrExp ArrElems FuncCall ArgsExp
%type <ast>       Args RValue Assign UnionDef UnionBody Def RegDef
%type <ast>       RegBody Conditional OptElsif Elsifs OptElse 
%type <ast>       LoopWhile LoopFor OptStep RoutDef OptArgs OblArgs 
%type <ast>       RoutArgs Actions 
%type <boolean>   OptRef
%type <str>       IdDef IdFor UnionId RegId RoutId
%type <nS>        S

%expect 1

%%

/* =================== GLOBAL RULES =================== */
S       : I                   { $$ = new NodeS($1); ast = $$;  }
        | /* lambda */        { $$ = NULL; }
        ;
I       : Inst                { $$ = new NodeI(NULL, $1); }
        | I Inst              { $$ = new NodeI($1, $2); }
        ;
Inst    : Action              { $$ = $1; }
				| Def                 { $$ = $1; }
        ;
Action  : VarInst SEMICOLON   { $$ = $1; }
				| FuncCall SEMICOLON  { $$ = $1; ((NodeFunctionCall*) $$)->setEndInst(); }
				| Conditional         { $$ = $1; }
				| LoopWhile           { $$ = $1; }
				| LoopFor             { $$ = $1; }
        ;
Def     : UnionDef            { $$ = $1; }
				| RegDef              { $$ = $1; }
				| RoutDef             { $$ = $1; }
        ;

/* ============ VARIABLES DEFINITION ============ */
VarInst     : VarDef                    { $$ = $1; }
						| Assign                    { $$ = $1; }
            | FORGET LValue             { $$ = new NodeForget($2); }
            ;
VarDef      : LET Type IdDef OptAssign  { 
                                          $$ = new NodeVarDef($2, $3, $4);
                                          int s = table.currentScope();
                                          Entry *e = new Entry($3, s, "Var");
                                          table.insert(e);
                                        }
            ;   
IdDef       : ID                        {
                                          if (! table.verifyInsert($1)) {
                                            addError($1, (string) "Redefinition of \"" + $1 + "\".");
                                          }
                                          $$ = $1; 
                                        }
OptAssign   : /* lambda */              { $$ = NULL; }
						| ASSIGNMENT RValue         { $$ = $2; }
            ;
Assign      : LValue ASSIGNMENT RValue  { $$ = new NodeAssign($1, $3); }
            ;
RValue      : Exp                       { $$ = $1; }
            | Array                     { $$ = $1; }
            | STRING                    { $$ = new NodeSTRING($1); }
            | NEW Type                  { $$ = new NodeNew($2); }
            ;

/* ======================== TYPES ======================== */
Type	: Type OPEN_BRACKET Exp CLOSE_BRACKET { $$ = new NodeTypeArrayDef($1, $3); }
			| POINTER Type 	                      { $$ = new NodeTypePointerDef($2); }
			| OPEN_PAR Type CLOSE_PAR             { $$ = $2; }
      | ID                                  {
                                              Entry *e;
                                              if ((e = table.lookup($1)) == NULL) {
                                                addError($1, (string) "\"" + $1 + "\" was not declared.");
                                              } else if (e->category != "Type") {
                                                addError($1, (string) "\"" + $1 + "\" is not a type.");
                                              }
                                              $$ = new Type($1);
                                            }
      | T_UNIT                              { $$ = new Type($1); }
			| T_BOOL                              { $$ = new Type($1); }
      | T_CHAR                              { $$ = new Type($1); }
      | T_INT                               { $$ = new Type($1); }
      | T_FLOAT                             { $$ = new Type($1); }
      | T_STRING                            { $$ = new Type($1); }
      ;

/* ======================= LVALUES ======================= */
LValue	:	LValue OPEN_BRACKET Exp CLOSE_BRACKET   { $$ = new NodeArrayLValue($1, $3); }
				|	POINTER LValue                          { $$ = new NodePointerLValue($2); }
				|	LValue DOT ID                           { $$ = new NodeDotLValue($1, $3); }
				| OPEN_PAR LValue CLOSE_PAR               { $$ = $2; }
				|	ID                                      { 
                                                    Entry *e;
                                                    if ((e = table.lookup($1)) == NULL) {
                                                      addError($1, (string) "\"" + $1 + "\" was not declared.");
                                                    } else if (e->category != "Var") {
                                                      addError($1, (string) "\"" + $1 + "\" is not a variable.");
                                                    }
                                                    $$ = new NodeIDLValue($1); 
                                                  }
        ;

/* ======================= EXPRESSIONS ======================= */
Exp   : Exp EQUIV Exp               { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp NOT_EQUIV Exp           { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp OR Exp                  { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp AND Exp                 { $$ = new NodeBinaryOperator($1, $2, $3); }
      | NOT Exp                     { $$ = new NodeUnaryOperator($1, $2); }
      | Exp LESS_THAN Exp           { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp LESS_EQUAL_THAN Exp     { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp GREATER_THAN Exp        { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp GREATER_EQUAL_THAN Exp  { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp PLUS Exp                { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp MINUS Exp               { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp ASTERISK Exp            { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp DIV Exp                 { $$ = new NodeBinaryOperator($1, $2, $3); }
      | Exp MODULE Exp              { $$ = new NodeBinaryOperator($1, $2, $3); }
      | MINUS Exp                   { $$ = new NodeUnaryOperator($1, $2); }
      | PLUS Exp                    { $$ = new NodeUnaryOperator($1, $2); }
      | Exp POWER Exp               { $$ = new NodeBinaryOperator($1, $2, $3); }
      | OPEN_PAR Exp CLOSE_PAR      { $$ = $2; }
      | LValue                      { $$ = $1; }
      | FuncCall                    { $$ = $1; }
      | TRUE                        { $$ = new NodeBOOL(true); }
      | FALSE                       { $$ = new NodeBOOL(false); }
      | CHAR                        { $$ = new NodeCHAR($1); }
      | INT                         { $$ = new NodeINT($1); }
      | FLOAT                       { $$ = new NodeFLOAT($1); }
      ;

/* ====================== ARRAYS ====================== */
Array     : OPEN_BRACKET ArrExp CLOSE_BRACKET   { $$ = new NodeArray($2); }
          ;
ArrExp    : /* lambda */                        { $$ = NULL; }
					| ArrElems RValue                     { $$ = new NodeArrayElems($1, $2); }
          ;
ArrElems	: /* lambda */                        { $$ = NULL; }
					| ArrElems RValue COMMA               { $$ = new NodeArrayElems($1, $2); }
          ;

/* ================= FUNCTION CALLS ================= */
FuncCall  : ID OPEN_PAR ArgsExp CLOSE_PAR   { 
                                              Entry *e;
                                              if ((e = table.lookup($1)) == NULL) {
                                                addError($1, (string) "\"" + $1 + "\" was not declared.");
                                              } else if (e->category != "Function") {
                                                addError($1, (string) "\"" + $1 + "\" is not a function.");
                                              }
                                              $$ = new NodeFunctionCall($1, $3, false); 
                                            }
          ;
ArgsExp   : /* lambda */                    { $$ = NULL; }
					| Args RValue                     { $$ = new NodeFunctionCallArgs($1, $2); }
          ;
Args      : /* lambda */                    { $$ = NULL; }
					| Args RValue COMMA               { $$ = new NodeFunctionCallArgs($1, $2); }
          ;

/* ================= UNION DEFINITION ================= */
UnionDef  : UnionId OPEN_C_BRACE UnionBody CLOSE_C_BRACE  { 
                                                            $$ = new NodeUnionDef($1, $3);
                                                            table.exitScope(); 
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry($1, s, "Type");
                                                            table.insert(e);
                                                          }
          ;
UnionId   : UNION IdDef                                   { table.newScope(); $$ = $2; }
          ;  
UnionBody	: Type IdDef SEMICOLON                          { 
                                                            $$ = new NodeUnionFields(NULL, $1, $2); 
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry($2, s, "Field");
                                                            table.insert(e);
                                                          }
					| UnionBody Type IdDef SEMICOLON                { 
                                                            $$ = new NodeUnionFields($1, $2, $3); 
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry($3, s, "Field");
                                                            table.insert(e);
                                                          }
          ;

/* ================ REGISTER DEFINITION ================ */
RegDef    : RegId OPEN_C_BRACE RegBody CLOSE_C_BRACE  { 
                                                        $$ = new NodeRegDef($1, $3);
                                                        table.exitScope();
                                                        int s = table.currentScope();
                                                        Entry *e = new Entry($1, s, "Type");
                                                        table.insert(e);
                                                      }
          ;   
RegId     : REGISTER IdDef                            { table.newScope(); $$ = $2; }
          ; 
RegBody	  : Type IdDef OptAssign SEMICOLON            { 
                                                        $$ = new NodeRegFields(NULL, $1, $2, $3);
                                                        int s = table.currentScope();
                                                        Entry *e = new Entry($2, s, "Field");
                                                        table.insert(e);
                                                      }
				  |	RegBody Type IdDef OptAssign SEMICOLON    { 
                                                        $$ = new NodeRegFields($1, $2, $3, $4);
                                                        int s = table.currentScope();
                                                        Entry *e = new Entry($3, s, "Field");
                                                        table.insert(e);
                                                      }
          ;



/* ===================== CONDITIONALS ===================== */
Conditional : If Exp THEN I OptElsif OptElse DONE   { 
                                                      $$ = new NodeConditional($2, $4, $5, $6);
                                                      table.exitScope(); 
                                                    }
            ;
If          : IF                                    { table.newScope(); }
            ;
OptElsif    : /* lambda */                          { $$ = NULL; }
						| Elsifs                                { $$ = $1; }
            ;
Elsifs      : Elsif Exp THEN I                      { $$ = new NodeElsif(NULL, $2, $4); }
						| Elsifs Elsif Exp THEN I               { $$ = new NodeElsif($1, $3, $5); }
            ;
Elsif       : ELSIF                                 { 
                                                      table.exitScope();
                                                      table.newScope(); 
                                                    }
            ;
OptElse     : /* lambda */                          { $$ = NULL; }
						| Else I                                { $$ = new NodeElse($2); }
            ;
Else        : ELSE                                  { 
                                                      table.exitScope();
                                                      table.newScope(); 
                                                    }
            ;

/* ======================== LOOPS ======================== */
LoopWhile : While Exp DO I DONE                       { 
                                                        $$ = new NodeWhile($2, $4); 
                                                        table.exitScope();
                                                      }
          ; 
While     : WHILE                                     { table.newScope(); }
          ;
LoopFor   : For OPEN_PAR IdFor SEMICOLON Exp SEMICOLON   
            Exp OptStep CLOSE_PAR DO I DONE           { 
                                                        $$ = new NodeFor($3, $5, $7, $8, $11);
                                                        table.exitScope();
                                                      }
          ;
IdFor     : IdDef                                     { 
                                                        int s = table.currentScope();
                                                        Entry *e = new Entry($1, s, "Var");
                                                        table.insert(e); 
                                                        $$ = $1; 
                                                      }
          ;
For       : FOR                                       { table.newScope(); }
          ;
OptStep   : /* lambda */                              { $$ = NULL; }
				  | SEMICOLON Exp                             { $$ = $2; }
          ;

/* =============== SUBROUTINES DEFINITION =============== */
RoutDef   : RoutId OPEN_PAR RoutArgs CLOSE_PAR OptReturn 
            OPEN_C_BRACE Actions CLOSE_C_BRACE            { 
                                                            $$ = new NodeRoutineDef(
                                                              $1, $3, $5, $7
                                                            ); 
                                                            table.exitScope();
                                                          }
          ;  
RoutId    : DEF IdDef                                     {
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry($2, s, "Function");
                                                            table.insert(e);
                                                            table.newScope();
                                                            $$ = $2;
                                                          }
          ;    
RoutArgs  : /* lambda */                                  { $$ = NULL; }
          | OblArgs                                       { $$ = new NodeRoutArgs($1, NULL); }
          | OptArgs                                       { $$ = new NodeRoutArgs(NULL, $1); }
          | OblArgs COMMA OptArgs                         { $$ = new NodeRoutArgs($1, $3); }
          ;   
OblArgs   : Type OptRef IdDef                             { 
                                                            $$ = new NodeRoutArgDef(
                                                              NULL, $1, $2, $3, NULL
                                                            );
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry($3, s, "Var");
                                                            table.insert(e);
                                                          }
          | OblArgs COMMA Type OptRef IdDef               { 
                                                            $$ = new NodeRoutArgDef(
                                                              $1, $3, $4, $5, NULL
                                                            );
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry($5, s, "Var");
                                                            table.insert(e);
                                                          }
          ;   
OptArgs   : Type OptRef IdDef ASSIGNMENT RValue           { 
                                                            $$ = new NodeRoutArgDef(
                                                              NULL, $1, $2, $3, $5
                                                            );
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry($3, s, "Var");
                                                            table.insert(e);
                                                          }
          | OptArgs COMMA Type OptRef IdDef 
            ASSIGNMENT RValue                             { 
                                                            $$ = new NodeRoutArgDef(
                                                              $1, $3, $4, $5, $7
                                                            );
                                                            int s = table.currentScope();
                                                            Entry *e = new Entry($5, s, "Var");
                                                            table.insert(e);
                                                          }
          ;
OptRef    : /* lambda */                                  { $$ = false; }
					| AT                                            { $$ = true; }
          ; 
OptReturn : /* lambda */                                  { $$ = NULL; }
				  | RIGHT_ARROW Type                              { $$ = $2; }
          ; 
Actions   : /* lambda */                                  { $$ = NULL; }
				  | Actions Action                                { $$ = new NodeActions($1, $2); }
          ;

%%

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
