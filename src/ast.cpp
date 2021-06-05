#include "ast.hpp"

/* ======================= DATATYPES NODES =======================  */
node_INT::node_INT(int value) {
  this->value;
}

void node_INT::print(void) {
  cout << this->value;
}

/* ======================= TYPEDEF NODES =======================  */
node_TypePrimitiveDef::node_TypePrimitiveDef(string id) {
  this->id = id;
}

void node_TypePrimitiveDef::print(void) {
  cout << this->id;
}

node_TypePointerDef::node_TypePointerDef(node *type) {
  this->type = type;
}

void node_TypePointerDef::print(void) {
  cout << "^(";
  this->type->print();
  cout << ")";
}

node_TypeArrayDef::node_TypeArrayDef(node *type, node *size) {
  this->type = type;
  this->size = size;
}

void node_TypeArrayDef::print(void) {
  cout << "(";
  this->type->print();
  cout << "[";
  this->size->print();
  cout << "]";
}

node_VarDef::node_VarDef(node *type, string id, node *rvalue) {
  this->type = type;
  this->id = id;
  this->rvalue = rvalue;
}

void node_VarDef::print(void) {
  this->type->print();
  cout << " " << id;
  if (this->rvalue != NULL) {
    cout << " = ";
    this->rvalue->print();
  } 
  cout << ";\n";
}

/* ======================= GENERIC INSTRUCTIONS NODES =======================  */
node_I::node_I(node *inst, node *next) {
  this->inst = inst;
  this->next = next;
}

void node_I::print(void) {
  this->inst->print();
  if (this->next != NULL) {
    this->next->print();
  }
}

node_S::node_S(node *inst) {
  this->inst = inst;
}

void node_S::print(void) {
  if (this->inst != NULL) {
    this->inst->print();
  }
}
