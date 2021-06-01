/* recognizes the tokens and prints them out */
%option noyywrap

%{
  #include <iostream>
  #include <queue>
  #include <string>

  using namespace std;

  enum yytokentype {
    SEMICOLON = 1,
    OPEN_PAR,
    CLOSE_PAR,
    POWER,
    AND,
    OR,
    NOT,
    EQUIV,
    PLUS,
    MINUS,
    MODULE,
    DIV,
    ASTERISK,
    OPEN_COMMENT,
    CLOSE_COMMENT,
    ASSIGNMENT,
    INT,
    CHAR,
    BOOL,
    FLOAT,
    UNIT,
    FALSE,
    TRUE,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    OPEN_C_BRACE,
    CLOSE_C_BRACE,
    COMMA,
    REGISTER,
    DOT,
    UNION,
    POINTER,
    NEW,
    FORGET,
    IF,
    THEN,
    ELSIF,
    ELSE,
    END,
    WHILE,
    DO,
    DONE,
    FOR,
    LET,
    AT,
    RIGHT_ARROW,
    NUMBER,
    ID,
    SINGLE_QUOTE,
    DOUBLE_QUOTE
  };

  string yylval;
  
  // count rows and columns to identify errors
  int row = 1; 
  int col = 1;

  // queues for tokens and errors
  queue<string> tokens;
  queue<string> errors;

  string temp;

  void setMultiLineOffset(char* text);
%}

%%
\$\{[^(\$\})]*\}\$        {  
                            /* ignore multiline line comment */

                            // count the lines of the comment 
                            setMultiLineOffset(yytext);
                          }
#.*\n                     { 
                            /* ignore single line comment */ 
                            
                            // reset the counters for rows and cols
                            row++;
                            col = 1;
                          }
";"      		              { return SEMICOLON; }
"("                       { return OPEN_PAR; }
")"                       { return CLOSE_PAR; }
"**"                      { return POWER; }
"&&"                      { return AND; }
"||"                      { return OR; }
"!"                       { return NOT; }
"=="                      { return EQUIV; }
"+"                       { return PLUS; }
"-"                       { return MINUS; }
"%"                       { return MODULE; }
"/"                       { return DIV; }
"*"                       { return ASTERISK; }
"${"                      { return OPEN_COMMENT; } 
"}$"                      { return CLOSE_COMMENT; } 
"="                       { return ASSIGNMENT; } 
"Int"                     { return INT; }
"Char"                    { return CHAR; }
"Bool"                    { return BOOL; }
"Float"                   { return FLOAT; }
"Unit"                    { return UNIT; }
"False"                   { return FALSE; }
"True"                    { return TRUE; }
"["                       { return OPEN_BRACKET; }
"]"                       { return CLOSE_BRACKET; }
"{"                       { return OPEN_C_BRACE; }  
"}"                       { return CLOSE_C_BRACE; }
","                       { return COMMA; }
"register"                { return REGISTER; }
"."                       { return DOT; }
"union"                   { return UNION; }
"^"                       { return POINTER; }
"new"                     { return NEW; }
"forget"                  { return FORGET; }
"if"                      { return IF; }
"then"                    { return THEN; }
"elsif"                   { return ELSIF; }
"else"                    { return ELSE; }
"end"                     { return END; }
"while"                   { return WHILE; }
"do"                      { return DO; }
"done"                    { return DONE; }
"for"                     { return FOR; }
"let"                     { return LET; }
"@"                       { return AT; }
"=>"                      { return RIGHT_ARROW; }
[0-9]+                    { yylval = strdup(yytext); return NUMBER; }
[ \t]                     { col++; /* ignore whitespace */ }
[[:alpha:]_][[:alnum:]_]* { yylval = strdup(yytext); return ID; }
\'.\'                     { yylval = strdup(yytext); return SINGLE_QUOTE; }
\"(?:[^"\\\n]|\\.)*\"     { yylval = strdup(yytext); return DOUBLE_QUOTE; }
\n                        { 
                            /* ignore new line characters */
                            
                            // reset the counter for colums
                            col = 1; 
                            row++;
                            cout << row << endl;
                          } 
.                         { 
                            // duplicate the value of yytext
                            temp = strdup(yytext);
                            errors.push("Unexpected character " + temp + 
                                        " at position " + "[" + to_string(row) 
                                        + "," + to_string(col) + "]. \n");
                          }

%%

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
      row++;
      col = 0;
    } else {
      col++;
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

/*
  Starts lexer execution
*/
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
    if(tok == NUMBER || tok == ID || tok == SINGLE_QUOTE || tok == DOUBLE_QUOTE)
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