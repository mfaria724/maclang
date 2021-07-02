#include "table.hpp"

using namespace std;

Entry::Entry(string id, int scope, Type *type, string category) {
  this->id = id;
  this->scope = scope;
  this->type = type;
  this->category = category;
}

/*
  Print a entry representation.
*/
void Entry::print(void) {
  cout << "\e[1;31m(\e[1;34mScope:\e[0m " << this->scope;
  cout << ", \e[1;34mID:\e[0m " << this->id;
  cout << ", \e[1;34mType:\e[0m " << this->type->print(); 
  cout << "\e[1;31m)\e[0m";
}

SymbolsTable::SymbolsTable() {
  this->lastScope = 1;
  this->scopeStack.push_back(this->lastScope);
}

/*
  Add an entry to symbols table
*/
void SymbolsTable::insert(Entry *e) {
  // If the id isn't in the table, start the list for that id.
  if (this->symTable.find(e->id) == this->symTable.end()) {
    this->symTable[e->id];
  }

  // Add entry to the list
  this->symTable[e->id].push_front(e); 
}

/*
  Returns the scope in the top of the stack. 
*/
int SymbolsTable::currentScope(void) {
  return this->scopeStack.back();
}

/*
  Verify if it is possibke to insert a new entry in the table.
*/
bool SymbolsTable::verifyInsert(string id) {
  Entry *look = this->lookup(id);
  // If we get an entru with the same id, we can't add the entry
  if ((look != NULL) && (look->scope == this->scopeStack.back())) { 
    return false; 
  }

  // Otherwise, we can add it.
  return true;
}

/*
  Gets an entry for the given id in the current scope using Leblanc-Cook's 
  algorithm.
*/
Entry* SymbolsTable::lookup(string id) {
  Entry *pervasive = NULL;
  Entry *best = NULL;

  // For each entry in the vector with belongs to id.
  for (Entry *entry : this->symTable[id]) {
    if (entry->id == id) {
      
      // If scope is 0, means that we're in the perversive scope.
      if (entry->scope == 0) { 
        pervasive = entry; 

      } else {
        // Otherwise, we go through the scope using the las entry added.
        vector<int>::reverse_iterator begin = this->scopeStack.rbegin();
        vector<int>::reverse_iterator end = this->scopeStack.rend();
        for (vector<int>::reverse_iterator it = begin; it != end; it++) {

          // If it is the same as the scope of the entry, we assign it as best
          // scope.
          if (*it == entry->scope) {
            best = entry;
            break;

          // If we already have a best scope and it is the same as the scope
          // of the iterarion, we can't get any better.
          } else if (best != NULL && *it == best->scope) {
            break;
          }
        }
      }
    }
  }

  // Return the scope founded. If it is null, is because there isn't one.
  if (best != NULL) { return best; }
  return pervasive;
}

/*
  Add new scope to the symbols table.
*/
int SymbolsTable::newScope() {
  this->lastScope++;
  this->scopeStack.push_back(this->lastScope);
  return this->lastScope;
}

/*
  Deletes the last scope added to the symbols table.
*/
void SymbolsTable::exitScope() {
  if (! this->scopeStack.empty())  {
    this->scopeStack.pop_back();
  }
}

/*
  Prints a representation of the symbols table.
*/
void SymbolsTable::printTable() {
  cout << "\n\e[1;32m            =< MACLANG >=             \e[0m" << endl;
  cout << "\n\e[1;32m***Imprimiendo la tabla de símbolos***\e[0m" << endl;

  // Iterate over each entry of the table.
  map<string, deque<Entry*>>::iterator begin = this->symTable.begin();
  map<string, deque<Entry*>>::iterator end = this->symTable.end();
  for (map<string, deque<Entry*>>::iterator i = begin; i != end; i++) {

    cout << "\e[1;33mName:\e[0m " << i->first << " \n   =====> [";

    // Iterates over each element of a list in a table entry.
    deque<Entry*>::iterator qbegin = i->second.begin();
    deque<Entry*>::iterator qend = i->second.end();
    for (deque<Entry*>::iterator qi = qbegin; qi < qend; qi++) {

      // Prints the representation of the table.
      (*qi)->print();
      if (qi+1 != i->second.end()) 
        cout << ",\n           ";
    }

    cout << "]" << endl;
  }

}

/*
  Prints a representation of the scope stack.
*/
void SymbolsTable::printScopeStack() {
  cout << "\e[1;32mBottom ==> \e[0m";
  
  // Iterates over the stack to print each element.
  vector<int>::const_iterator begin = this->scopeStack.begin();
  vector<int>::const_iterator end = this->scopeStack.end();
  for (vector<int>::const_iterator i = begin; i != end; i++) {
    cout << *i << ' ';
  }
  
  cout << "\e[1;31m<== Top\e[0m\n";
}
