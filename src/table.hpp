#include <map>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

/*
  "Abstract" class that is parent of all entries classes in the 
  Symbols Table.
*/
class entry {
  public:
    // Variable identification.
    string id;
    // Scope where variable was defined.
    int scope;
    // Variable type
    string type;
  
    entry(string id, int scope, string type);

    // Prints the variable information
    virtual void print(void);
};

/*
  Symbols Table implementation.
*/
class symbols_table {
  private:
    // Dictionary:  Name -> Entries
    map<string, deque<entry*>> sym_table;
    vector<int> scope_stack;
    // Last scope added
    int last_scope;

  public:
    symbols_table(void);

    // Insert a new entry
    void insert(entry *e);

    int current_scope(void);

    // Verify if a ID can be added
    bool verify_insert(string id);

    // Find a variable
    entry* lookup(string id);

    // Add a new scope
    int new_scope(void);

    // Delete the last scope
    void exit_scope(void);

    void print_table(void);

    void print_scope_stack(void);
};

