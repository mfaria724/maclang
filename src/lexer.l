/* recognizes the tokens and prints them out */
%option noyywrap
%option yylineno

%{
  #include "parser.tab.h"

  using namespace std;

  string yylval;
  
  // count rows and columns to identify errors
  int yycolumn = 1;

  #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng; \
    yylval.str = strdup(yytext);
%}

%%
\$\{[^(\$\})]*\}\$        {  
                            /* ignore multiline line comment */

                            // count the lines of the comment 
                            setMultiLineOffset(yytext);
                          }
#.*\n                     { 
                            /* ignore single line comment */ 
                            
                            // reset the counter for cols
                            yycolumn = 1;
                          }
";"      		              { return SEMICOLON; }
"("                       { return OPEN_PAR; }
")"                       { return CLOSE_PAR; }
"**"                      { return POWER; }
"&&"                      { return AND; }
"||"                      { return OR; }
"!="                      { return NOT_EQUIV; }
"!"                       { return NOT; }
"=="                      { return EQUIV; }
">="                      { return GREATER_EQUAL_THAN; }
"<="                      { return LESS_EQUAL_THAN; }
">"                       { return GREATER_THAN; }
"<"                       { return LESS_THAN; }
"+"                       { return PLUS; }
"-"                       { return MINUS; }
"%"                       { return MODULE; }
"/"                       { return DIV; }
"*"                       { return ASTERISK; }
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
[0-9]+\.[0-9]+            { yylval =strdup(yytext); return FLOAT; }
[0-9]+                    { yylval = strdup(yytext); return INT; }
[\t]                      { yycolumn++; /* ignore tab */ }
[ ]                       { /* ignore whitespace */ }
[[:alpha:]_][[:alnum:]_]* { yylval = strdup(yytext); return ID; }
\'.\'                     { yylval = strdup(yytext); return SINGLE_QUOTE; }
\"(?:[^"\\\n]|\\.)*\"     { yylval = strdup(yytext); return DOUBLE_QUOTE; }
\n                        { /* ignore new line characters */ } 
.                         { 
                            // duplicate the value of yytext
                            temp = strdup(yytext);
                            errors.push("Unexpected character " + temp + 
                                        " at position " + "[" + to_string(yylineno) 
                                        + "," + to_string(yycolumn) + "]. \n");
                          }
