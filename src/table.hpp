#include <map>
#include <deque>
#include <vector>
#include <iostream>
#include "ast.hpp"

using namespace std;

/*
  "Abstract" class that is parent of all entries classes in the Symbols Table.
*/
class Entry {
  public:
    // Variable identification.
    string id;
    // Scope where variable was defined.
    int scope;
    // Category of the entry
    string category;
  
    Entry(void) {};

    // Prints the variable information
    virtual void print(void) {};
};

/*
  Symbols Table implementation.
*/
class SymbolsTable {
  private:
    // Dictionary:  Name -> Entries
    map<string, deque<Entry*>> symTable;
    vector<int> scopeStack;
    // Last scope added
    int lastScope;

  public:
    SymbolsTable(void);

    // Insert a new entry
    void insert(Entry *e);

    int currentScope(void);

    // Verify if a ID can be added
    bool verifyInsert(string id);

    // Find a variable
    Entry* lookup(string id);

    // Find a variable in a scope
    Entry* lookup(string id, int scope);

    // Add a new scope
    int newScope(void);

    // Delete the last scope
    void exitScope(void);

    // Prints representation of the symbols table
    void printTable(void);

    // Prints representation of the scope stack 
    void printScopeStack(void);
};

class VarEntry : public Entry {
  public:
    // Variable type
    Type *type;
  
    VarEntry(string id, int scope, string category, Type *type);

    // Prints the variable information
    void print(void);
};

class StructureEntry : public Entry {
  public:
    // scope where the entry was defined.
    int def_scope;  

    StructureEntry(string id, int scope, string category, int def_scope);

    // Prints the structure information
    void print(void);
};

class FunctionEntry : public Entry {
  public:
    // return type of the function
    Type *return_type;

    FunctionEntry(string id, int scope, string category);

    // Prints the function information
    void print(void);
};
