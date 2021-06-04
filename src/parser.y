%{
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
%}

%define parse.lac full

%union 
{	
  int   integer;
  float flot;
  bool  boolean;
  char  *str;
  char  ch;
}

%locations
%start S


%left PLUS MINUS
%left ASTERISK DIV MODULE
%right POWER

%token SEMICOLON
%token OPEN_PAR
%token CLOSE_PAR
%token POWER
%token AND
%token OR
%token NOT_EQUIV
%token NOT
%token EQUIV
%token GREATER_EQUAL_THAN
%token LESS_EQUAL_THAN
%token GREATER_THAN
%token LESS_THAN
%token PLUS
%token MINUS
%token MODULE
%token DIV
%token ASTERISK
%token ASSIGNMENT
%token T_INT
%token T_CHAR 
%token T_BOOL 
%token T_FLOAT
%token T_UNIT
%token T_STRING
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
%token END
%token WHILE
%token DO
%token DONE
%token FOR
%token LET
%token AT
%token RIGHT_ARROW

%token EOL

%token <integer>  INT
%token <flot>     FLOAT
%token <id>       ID
%token <chr>      CHAR
%token <str>      STRING
%token <boolean>  TRUE FALSE

%type <integer> Integer

%%

S       : Integer EOL                 { cout << $1 << "\n"; }
        | /* lambda */ 
        ;

Integer	:	Integer PLUS Integer        { $$ = $1 + $3; }
				|	Integer MINUS Integer       { $$ = $1 - $3; }
				|	Integer ASTERISK Integer    { $$ = $1 * $3; }
				|	Integer DIV Integer         { $$ = $1 / $3; }         
				|	Integer MODULE Integer      { $$ = $1 % $3; }
				|	MINUS Integer               { $$ = -$2; }
				|	PLUS Integer                { $$ = $2; }
        | Integer POWER Integer       { $$ = $1 * $3; }
				|	OPEN_PAR Integer CLOSE_PAR  { $$ = $2; }
				|	INT                         { $$ = $1; }
        ;

%%

int main(int argc, char **argv)
{
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