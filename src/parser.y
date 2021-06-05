%{
  #include <iostream>
  #include <queue>
  #include <cstring>
  #include <string>
  #include "ast.hpp"

  using namespace std;

  extern int yylex(void);
  extern int yylineno;
  extern int yycolumn;
  extern char *yytext;

  // queues for tokens and errors
  extern queue<string> errors;

  // offsets the columns and the rows for multiline comments
  void setMultiLineOffset(char* text);

  // Prints error;
  void yyerror(char *s);

  // Prints the queue to std.
  void printQueue(queue<string> queueToPrint);

  node* global;
%}

%define parse.lac full

%union 
{	
  int   integer;
  float flot;
  bool  boolean;
  char  *str;
  char  ch;
  node  *ast;
  node_S *nS;
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


%token SEMICOLON
%token OPEN_PAR
%token CLOSE_PAR
%token ASSIGNMENT
%token OPEN_BRACKET
%token CLOSE_BRACKET
%token OPEN_C_BRACE
%token CLOSE_C_BRACE
%token COMMA
%token REGISTER
%token DOT
%token UNION
%token POINTER
%token NEW
%token FORGET
%token IF
%token THEN
%token ELSIF
%token ELSE
%token WHILE
%token DO
%token DONE
%token FOR
%token LET
%token DEF
%token AT
%token RIGHT_ARROW
%token ERROR

%token <integer>  INT
%token <flot>     FLOAT
%token <ch>       CHAR
%token <str>      STRING ID
%token <boolean>  TRUE FALSE
%token <str>      T_UNIT T_BOOL T_CHAR T_INT T_FLOAT T_STRING
%token <str>      POWER AND OR NOT_EQUIV NOT EQUIV GREATER_EQUAL_THAN 
%token <str>      LESS_EQUAL_THAN GREATER_THAN LESS_THAN PLUS MINUS 
%token <str>      MODULE DIV ASTERISK

%type <ast>     I Inst Action VarInst VarDef OptAssign Type OptReturn
%type <ast>     LValue Exp Array ArrExp ArrElems FuncCall ArgsExp
%type <ast>     Args RValue Assign UnionDef UnionBody Def RegDef
%type <ast>     RegBody Conditional OptElsif Elsifs OptElse 
%type <ast>     LoopWhile LoopFor OptStep RutineDef RutineArgs ArgsDef 
%type <ast>     Actions 
%type <boolean> OptRef
%type <nS>      S

%% 

/* =================== GLOBAL RULES =================== */
S       : I                   { $$ = new node_S($1); $$->print();  }
        | /* lambda */        { $$ = NULL; }
        ;
I       : Inst                { $$ = new node_I(NULL, $1); }
        | I Inst              { $$ = new node_I($1, $2); }
        ;
Inst    : Action              { $$ = $1; }
				| Def                 { $$ = $1; }
        ;
Action  : VarInst SEMICOLON   { $$ = $1; }
				| FuncCall SEMICOLON  { $$ = $1; ((node_FunctionCall*) $$)->set_end_inst(); }
				| Conditional         { $$ = $1; }
				| LoopWhile           { $$ = $1; }
				| LoopFor             { $$ = $1; }
        ;
Def     : UnionDef            { $$ = $1; }
				| RegDef         { $$ = $1; }
				| RutineDef           { $$ = $1; }
        ;

/* ============ VARIABLES DEFINITION ============ */
VarInst     : VarDef                    { $$ = $1; }
						| Assign                    { $$ = $1; }
            ;
VarDef      : LET Type ID OptAssign     { $$ = new node_VarDef($2, $3, $4); }
            ;   
OptAssign   : /* lambda */              { $$ = NULL; }
						| ASSIGNMENT RValue         { $$ = $2; }
            ;
Assign      : LValue ASSIGNMENT RValue  { $$ = new node_Assign($1, $3); }
            ;
RValue      : Exp                       { $$ = $1; }
            | Array                     { $$ = $1; }
            | STRING                    { $$ = new node_STRING($1); }
            ;

/* ======================== TYPES ======================== */
Type	: Type OPEN_BRACKET Exp CLOSE_BRACKET { $$ = new node_TypeArrayDef($1, $3); }
			| POINTER Type 	                      { $$ = new node_TypePointerDef($2); }
			| OPEN_PAR Type CLOSE_PAR             { $$ = $2; }
      | T_UNIT                              { $$ = new node_TypePrimitiveDef($1); }
			| T_BOOL                              { $$ = new node_TypePrimitiveDef($1); }
      | T_CHAR                              { $$ = new node_TypePrimitiveDef($1); }
      | T_INT                               { $$ = new node_TypePrimitiveDef($1); }
      | T_FLOAT                             { $$ = new node_TypePrimitiveDef($1); }
      | T_STRING                            { $$ = new node_TypePrimitiveDef($1); }
      ;

/* ======================= LVALUES ======================= */
LValue	:	LValue OPEN_BRACKET Exp CLOSE_BRACKET   { $$ = new node_ArrayLValue($1, $3); }
				|	POINTER LValue                          { $$ = new node_PointerLValue($2); }
				|	LValue DOT ID                           { $$ = new node_DotLValue($1, $3); }
				| OPEN_PAR LValue CLOSE_PAR               { $$ = $2; }
				|	ID                                      { $$ = new node_IDLValue($1); }
        ;

/* ======================= EXPRESSIONS ======================= */
Exp   : Exp EQUIV Exp               { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp NOT_EQUIV Exp           { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp OR Exp                  { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp AND Exp                 { $$ = new node_BinaryOperator($1, $2, $3); }
      | NOT Exp                     { $$ = new node_UnaryOperator($1, $2); }
      | Exp LESS_THAN Exp           { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp LESS_EQUAL_THAN Exp     { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp GREATER_THAN Exp        { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp GREATER_EQUAL_THAN Exp  { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp PLUS Exp                { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp MINUS Exp               { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp ASTERISK Exp            { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp DIV Exp                 { $$ = new node_BinaryOperator($1, $2, $3); }
      | Exp MODULE Exp              { $$ = new node_BinaryOperator($1, $2, $3); }
      | MINUS Exp                   { $$ = new node_UnaryOperator($1, $2); }
      | PLUS Exp                    { $$ = new node_UnaryOperator($1, $2); }
      | Exp POWER Exp               { $$ = new node_BinaryOperator($1, $2, $3); }
      | OPEN_PAR Exp CLOSE_PAR      { $$ = $2; }
      | LValue                      { $$ = $1; }
      | FuncCall                    { $$ = $1; }
      | TRUE                        { $$ = new node_BOOL(true); }
      | FALSE                       { $$ = new node_BOOL(false); }
      | CHAR                        { $$ = new node_CHAR($1); }
      | INT                         { $$ = new node_INT($1); }
      | FLOAT                       { $$ = new node_FLOAT($1); }
      ;

/* ====================== ARRAYS ====================== */
Array     : OPEN_BRACKET ArrExp CLOSE_BRACKET   { $$ = new node_Array($2); }
          ;
ArrExp    : /* lambda */                        { $$ = NULL; }
					| ArrElems RValue                     { $$ = new node_ArrayElems($1, $2); }
          ;
ArrElems	: /* lambda */                        { $$ = NULL; }
					| ArrElems RValue COMMA               { $$ = new node_ArrayElems($1, $2); }
          ;

/* ================= FUNCTION CALLS ================= */
FuncCall  : ID OPEN_PAR ArgsExp CLOSE_PAR   { $$ = new node_FunctionCall($1, $3, false); }
          ;
ArgsExp   : /* lambda */                    { $$ = NULL; }
					| Args RValue                     { $$ = new node_FunctionCallArgs($1, $2); }
          ;
Args      : /* lambda */                    { $$ = NULL; }
					| Args RValue COMMA               { $$ = new node_FunctionCallArgs($1, $2); }
          ;

/* ================= UNION DEFINITION ================= */
UnionDef  : UNION ID OPEN_C_BRACE UnionBody CLOSE_C_BRACE   { $$ = new node_UnionDef($2, $4); }
          ; 
UnionBody	: Type ID SEMICOLON                               { 
                                                              $$ = new node_UnionFields(
                                                                NULL,
                                                                new node_VarDef($1, $2, NULL)
                                                              ); 
                                                            }
					| UnionBody Type ID SEMICOLON                     { 
                                                              $$ = new node_UnionFields(
                                                                $1,
                                                                new node_VarDef($2, $3, NULL)
                                                              ); 
                                                            }
          ;

/* ================ REGISTER DEFINITION ================ */
RegDef  : REGISTER ID OPEN_C_BRACE RegBody 
          CLOSE_C_BRACE                        { $$ = new node_RegDef($2, $4); }
        ;
RegBody	: Type ID OptAssign SEMICOLON          { $$ = new node_RegFields(NULL, $1, $2, $3); }
				|	RegBody Type ID OptAssign SEMICOLON  { $$ = new node_RegFields($1, $2, $3, $4); }
        ;



/* ===================== CONDITIONALS ===================== */
Conditional : IF Exp THEN I OptElsif OptElse DONE   { $$ = new node_Conditional($2, $4, $5, $6); }
            ;
OptElsif    : /* lambda */                          { $$ = NULL; }
						| Elsifs                                { $$ = $1; }
            ;
Elsifs      : ELSIF Exp THEN I                      { $$ = new node_Elsif(NULL, $2, $4); }
						| Elsifs ELSIF Exp THEN I               { $$ = new node_Elsif($1, $3, $5); }
            ;
OptElse     : /* lambda */                          { $$ = NULL; }
						| ELSE I                                { $$ = new node_Else($2); }
            ;

/* ======================== LOOPS ======================== */
LoopWhile : WHILE Exp DO I DONE                       { $$ = new node_While($2, $4); }
          ; 
LoopFor   : FOR OPEN_PAR ID SEMICOLON Exp SEMICOLON   
            Exp OptStep CLOSE_PAR DO I DONE           { $$ = new node_For($3, $5, $7, $8, $11); }
          ;
OptStep   : /* lambda */                              { $$ = NULL; }
				  | SEMICOLON Exp                             { $$ = $2; }
          ;

/* =============== SUBROUTINES DEFINITION =============== */
RutineDef   : DEF ID OPEN_PAR RutineArgs CLOSE_PAR OptReturn 
              OPEN_C_BRACE Actions CLOSE_C_BRACE            { 
                                                              $$ = new node_RoutineDef(
                                                                $2, $4, $6, $8
                                                              ); 
                                                            }
            ; 
RutineArgs  : /* lambda */                                  { $$ = NULL; }
						| ArgsDef                                       { $$ = $1; }
            ;
ArgsDef     : Type OptRef ID OptAssign                      { 
                                                              $$ = new node_RoutArgsDef(
                                                                NULL, $1, $2, $3, $4
                                                              ); 
                                                            }
						| ArgsDef COMMA Type OptRef ID OptAssign        { 
                                                              $$ = new node_RoutArgsDef(
                                                                $1, $3, $4, $5, $6
                                                              ); 
                                                            }
            ;
OptRef      : /* lambda */                                  { $$ = false; }
						| AT                                            { $$ = true; }
            ;
OptReturn   : /* lambda */                                  { $$ = NULL; }
						| RIGHT_ARROW Type                              { $$ = $2; }
            ;
Actions     : /* lambda */                                  { $$ = NULL; }
						| Actions Action                                { $$ = new node_Actions($1, $2); }
            ;

%%

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

  // apply lexing
  int tok;
  while(tok = yylex());

  fclose(yyin);
  yyin = fopen(argv[1], "r");

  // if there are no errors, apply parsing
  if (errors.empty()) {
    
    // reset lines and columns
    yylineno = 1; 
    yycolumn = 1;

    // start parsing
    yyparse();
  } else {
    printQueue(errors);
  }
  return 0;
}

/*
  Prints error.
*/
void yyerror(char *s)
{
  fprintf(stderr, "error: %s (%d,%d)\n", s, yylineno, yycolumn);
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