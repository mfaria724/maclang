#include <map>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

class symbol_entry {
  public:
    string id;
    int scope;
    string type;
  
    symbol_entry(string id, int scope, string type);

    void print();
};

class symbols_table {
  private:
    map<string, deque<symbol_entry>> sym_table;
    vector<int> scope_stack;
    int last_scope;

  public:
    symbols_table();

    bool insert(string id);

    void print_table();
    int new_scope();
    void exit_scope();
    void printScopeStack();
};

