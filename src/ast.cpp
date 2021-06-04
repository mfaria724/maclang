#include "ast.hpp"

node_S::node_S(node *inst) {
  this->inst = inst;
}

node_VarDef::node_VarDef(node *type, string id, node *rvalue) {
  this->type = type;
  this->id = id;
  this->rvalue = rvalue;
}

node_TypeArrayDef::node_TypeArrayDef(node *type, node *size) {
  this->type = type;
  this->size = size;
}

node_TypePointerDef::node_TypePointerDef(node *type) {
  this->type = type;
}

node_TypePrimitiveDef::node_TypePrimitiveDef(string id) {
  this->id = id;
}

node_INT::node_INT(int value) {
  this->value;
}

node_I::node_I(node *inst, node *next) {
  this->inst = inst;
  this->next = next;
}
