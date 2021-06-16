#include "table.hpp"

using namespace std;

entry::entry(string id, int scope, string type) {
  this->id = id;
  this->scope = scope;
  this->type = type;
}

/*
  Print a entry representation.
*/
void entry::print(void) {
  cout << "\e[1;31m(\e[1;34mScope:\e[0m " << this->scope;
  cout << ", \e[1;34mID:\e[0m " << this->id <<"\e[1;31m)\e[0m";
}

symbols_table::symbols_table() {
  this->last_scope = 1;
  this->scope_stack.push_back(this->last_scope);
}

/*
  Agregamos una entrada a la tabla de simbolos.
*/
void symbols_table::insert(entry *e) {
  // Si el id no se encuentra en la tabla, inicializamos su cola correspondiente.
  if (this->sym_table.find(e->id) == this->sym_table.end()) {
    this->sym_table[e->id];
  }

  // Agregamos el entry a la tabla.
  this->sym_table[e->id].push_front(e); 
}

/*
  Retorna el scope en el tope de la pila.
*/
int symbols_table::current_scope(void) {
  return this->scope_stack.back();
}

/*
  Verificamos si podemos insertar una nueva tabla en la entrada.
*/
bool symbols_table::verify_insert(string id) {
  entry *look = this->lookup(id);
  // Si obtenemos una entrada con el mismo id en el mismo scope, no podemos
  // agregar el entry.
  if ((look != NULL) && (look->scope == this->scope_stack.back())) { 
    return false; 
  }
  // En caso contrario, si se puede.
  return true;
}

/*
  Obtenemos la entrada correspondiente a un id dado el scope actual utilizando
  el algoritmo de Leblanc Cook.
*/
entry* symbols_table::lookup(string id) {
  entry *pervasive = NULL;
  entry *best = NULL;

  // Por cada entrada en el vector correspondiente al id.
  for (entry *entry : this->sym_table[id]) {
    if (entry->id == id) {
      
      // Si el scope es 0, significa que estamos en el scope penetrante.
      if (entry->scope == 0) { 
        pervasive = entry; 

      } else {
        // Si no, recorremos el scope comenzando desde el ultimo agregado.
        vector<int>::reverse_iterator begin = this->scope_stack.rbegin();
        vector<int>::reverse_iterator end = this->scope_stack.rend();
        for (vector<int>::reverse_iterator it = begin; it != end; it++) {

          // Si es igual al scope del entry. Lo asignamos como el mejor scope.
          if (*it == entry->scope) {
            best = entry;
            break;

          // Si ya tenemos un scope best y es igual al scope de esta iteracion,
          // ya no podremos encontrar un scope mejor.
          } else if (best != NULL && *it == best->scope) {
            break;
          }
        }
      }
    }
  }

  // Retornamos el scope que encontremos. Si se retorna NULL es que no se 
  // consiguo ninguno.
  if (best != NULL) { return best; }
  return pervasive;
}

/*
  Agregamos un nuevo scope a la tabla de simbolos.
*/
int symbols_table::new_scope() {
  this->last_scope++;
  this->scope_stack.push_back(this->last_scope);
  return this->last_scope;
}

/*
  Eliminamos el ultimo scope agregado a la tabla de simbolos.
*/
void symbols_table::exit_scope() {
  if (! this->scope_stack.empty())  {
    this->scope_stack.pop_back();
  }
}

/*
  Imprime una representacion de la tabla de simbolos.
*/
void symbols_table::print_table() {
  cout << "\n\e[1;32m***Imprimiendo la tabla de símbolos***\e[0m" << endl;

  // Recorremos cada para de id -> cola de entradas en la tabla de simbolos.
  map<string, deque<entry*>>::iterator begin = this->sym_table.begin();
  map<string, deque<entry*>>::iterator end = this->sym_table.end();
  for (map<string, deque<entry*>>::iterator i = begin; i != end; i++) {

    cout << "\e[1;33mVariable:\e[0m " << i->first << " \n => [";

    // Recorremos cada entrada en la cola de entrada.
    deque<entry*>::iterator qbegin = i->second.begin();
    deque<entry*>::iterator qend = i->second.end();
    for (deque<entry*>::iterator qi = qbegin; qi < qend; qi++) {

      // Imprimimos la representacion de la tabla.
      (*qi)->print();
      if (qi+1 != i->second.end()) 
        cout << ", ";
    }

    cout << "]" << endl;
  }

}

/*
  Imprime una representacion de la cola de scopes.
*/
void symbols_table::print_scope_stack() {
  cout << "\e[1;32mBottom ==> \e[0m";
  
  // Recorremos la cola e imprimimos cada elemento.
  vector<int>::const_iterator begin = this->scope_stack.begin();
  vector<int>::const_iterator end = this->scope_stack.end();
  for (vector<int>::const_iterator i = begin; i != end; i++) {
    cout << *i << ' ';
  }
  
  cout << "\e[1;31m<== Top\e[0m\n";
}
