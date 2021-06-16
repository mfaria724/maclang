#include <map>
#include <deque>
#include <vector>
#include <iostream>

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
    // Variable type
    string type;
  
    Entry(string id, int scope, string type);

    // Prints the variable information
    virtual void print(void);
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

    // Add a new scope
    int newScope(void);

    // Delete the last scope
    void exitScope(void);

    // Prints representation of the symbols table
    void printTable(void);

    // Prints representation of the scope stack 
    void printScopeStack(void);
};

