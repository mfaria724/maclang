#include "table.hpp"

extern map<string, Type*> predefinedTypes;

SymbolsTable::SymbolsTable() {
  this->lastScope = 1;
  this->offsets = {0};
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
  Verify if it is possible to insert a new entry in the table.
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
  Gets an entry on the Symbols Table that matches the specified id and scope.
  If that entry doesn't exists, returns NULL.
*/
Entry* SymbolsTable::lookup(string id, int scope) {
  // For each entry in the vector with belongs to id.
  for (Entry *entry : this->symTable[id]) {
    if (entry->id == id && entry->scope == scope) {
      return entry;
    }
  }

  return NULL;
}

/*
  Erase an entry on the Symbols Table that matches the specified id and scope.
*/
void SymbolsTable::erase(string id, int scope) {
  deque<Entry*> newQueue;

  while (! this->symTable[id].empty()) {
    Entry *e = this->symTable[id].back();
    this->symTable[id].pop_back();

    if ((e->id != id) || (e->scope != scope)) {
      newQueue.push_front(e);
    } else {
      cout << e->id << " " << e->scope << "\n";
    }
  }

  this->symTable[id] = newQueue;
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
  cout << "\n\e[1;32m***Imprimiendo la tabla de s??mbolos***\e[0m" << endl;

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



PrimitiveEntry::PrimitiveEntry(string id) {
  this->id = id;
  this->scope = 0;
  this->category = "Primitive";
  if (id != "String") this->type = predefinedTypes[id];
}

void PrimitiveEntry::print(void) {
  cout << "\e[1;31m(\e[1;34mScope:\e[0m " << this->scope;
  cout << ", \e[1;34mID:\e[0m " << this->id;
  cout << ", \e[1;34mCategory:\e[0m " << this->category;
  if (this->id != "String") {
    cout << ", \e[1;34mWidth:\e[0m " << this->type->width;
  }
  cout << "\e[1;31m)\e[0m";
}

VarEntry::VarEntry(string id, int scope, string category, Type *type, int offset) {
  this->id = id;
  this->type = type;
  this->scope = scope;
  this->category = category;
  this->offset = offset;
}

/*
  Prints a representation of the table entry.
*/
void VarEntry::print(void) {
  cout << "\e[1;31m(\e[1;34mScope:\e[0m " << this->scope;
  cout << ", \e[1;34mID:\e[0m " << this->id;
  cout << ", \e[1;34mCategory:\e[0m " << this->category;
  cout << ", \e[1;34mType: \e[0m";
  cout << this->type->toString(); 
  cout << ", \e[1;34mOffset: \e[0m" << this->offset; 
  cout << "\e[1;31m)\e[0m";
}

StructureEntry::StructureEntry(
  string id, 
  int scope, 
  string category, 
  int def_scope,
  int width
) {
  this->id = id;
  this->scope = scope;
  this->category = category;
  this->def_scope = def_scope;
  this->width = width;
}

/*
  Prints a representation of the table entry.
*/
void StructureEntry::print(void) {
  cout << "\e[1;31m(\e[1;34mScope:\e[0m " << this->scope;
  cout << ", \e[1;34mID:\e[0m " << this->id;
  cout << ", \e[1;34mCategory:\e[0m " << this->category;
  cout << ", \e[1;34mDef Scope:\e[0m " << this->def_scope; 
  cout << ", \e[1;34mWidth: \e[0m" << this->width; 
  cout << "\e[1;31m)\e[0m";
}

FunctionEntry::FunctionEntry(
  string id, 
  int scope, 
  string category
) {
  this->id = id;
  this->scope = scope;
  this->category = category;
}

/*
  Prints a representation of the table entry.
*/
void FunctionEntry::print(void) {
  cout << "\e[1;31m(\e[1;34mScope:\e[0m " << this->scope;
  cout << ", \e[1;34mID:\e[0m " << this->id;
  cout << ", \e[1;34mCategory:\e[0m " << this->category;
  if (this->return_type) {
    cout << ", \e[1;34mReturn Type:\e[0m " << this->return_type->toString();
  }
  cout << "\e[1;31m)\e[0m";
}

FunctionDeclarationEntry::FunctionDeclarationEntry(
  string id, 
  int scope,
  string category, 
  vector<tuple<string, string, bool, bool>> args, 
  Type *return_type
) {
  this->id = id;
  this->scope = scope;
  this->category = category;
  this->args = args;
  this->return_type = return_type;
}

/*
  Prints a representation of the table entry.
*/
void FunctionDeclarationEntry::print(void) {
  cout << "\e[1;31m(\e[1;34mScope:\e[0m " << this->scope;
  cout << ", \e[1;34mID:\e[0m " << this->id;
  cout << ", \e[1;34mCategory:\e[0m " << this->category;
  if (this->return_type) {
    cout << ", \e[1;34mReturn Type:\e[0m " << this->return_type->toString();
  }
  cout << "\e[1;31m)\e[0m";
}
