# **MACLang**

*MACLang* is a programming languages developed for course **CI4721 - Programing** 
**Languages II** dictated at Universidad Simón Bolívar (Caracas, Venezuela) in the 
term April-July 2021, by professor Ricardo Monascal.

## Dependencies
* flex *(2.6.4)*
* bison *(3.3.2)*
* g++ *(8.3.0)*

## How to use it

**WIP:** Parsing and Lexing
The project contains a *Makefile*, thus you just need to run `make` and i1t
will compile the source code. After that, you can execute the program with:

```
&> ./bin/parser.out METHOD FILE
```

Where `FILE` represents the path to the file to be parsed and `MEHTOD` could 
have the following values:
  
  * `lex`: prints just the lexical analysis with all tokens recognized by the 
    lexer if there isn't any errors. In case of errors will print the exact 
    position in the input file where there's an invalid token.
  * `parse`: prints the Abstract Syntax tree created by the parser in a readable
    way. If there're errors, it will print the first one.

## Developers
* Amin Arriaga *(16-10072)*
* Manuel Faria *(15-10463)*
* Orlando Chaparro *(12-11499)*   
