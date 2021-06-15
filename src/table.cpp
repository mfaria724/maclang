#include "table.hpp"

using namespace std;

symbol_entry::symbol_entry(string id, int scope, string type) {
  this->id = id;
  this->scope = scope;
  this->type = type;
}

symbols_table::symbols_table() {
  this->last_scope = 0;
  this->scope_stack.push_back(this->last_scope);
}

bool symbols_table::insert(string id) {
  
  
  if (this->sym_table.find(id) == this->sym_table.end()) {
    this->sym_table[id];
  }

  // TODO: revisar si el elemento ya existe en la tabla

  this->sym_table[id].push_front(symbol_entry(id, this->scope_stack.back(), "")); 
  return true;
}

void symbol_entry::print() {
  cout << "\e[1;31m(\e[1;34mScope:\e[0m " << this->scope;
  cout << ", \e[1;34mID:\e[0m " << this->id <<"\e[1;31m)\e[0m";
}

void symbols_table::print_table() {
  cout << "\n\e[1;32m***Imprimiendo la tabla de símbolos***\e[0m" << endl;

  for (map<string, deque<symbol_entry>>::iterator i = this->sym_table.begin(); i != this->sym_table.end(); ++i) {
    cout << "\e[1;33mVariable:\e[0m " << i->first << " \n => [";
    for (deque<symbol_entry>::iterator qi = i->second.begin(); qi != i->second.end(); qi++) {
      qi->print();
      if (qi+1 != i->second.end()) 
        cout << ", ";
    }
    cout << "]" << endl;
  }

}

int symbols_table::new_scope() {
  this->last_scope++;
  this->scope_stack.push_back(this->last_scope);
  return this->last_scope;
}

void symbols_table::exit_scope() {
  
  if (!this->scope_stack.empty()) 
    this->scope_stack.pop_back();

}

void symbols_table::printScopeStack() {
  cout << "\e[1;32mBottom ==> \e[0m";
  
  for (vector<int>::const_iterator i = this->scope_stack.begin(); i != this->scope_stack.end(); ++i)
    cout << *i << ' ';
  
  cout << "\e[1;31m<== Top\e[0m\n";
}
