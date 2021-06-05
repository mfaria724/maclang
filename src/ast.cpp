#include "ast.hpp"

/* ======================= DATA NODES =======================  */
node_BOOL::node_BOOL(bool value) {
  this->value = value;
}

void node_BOOL::print(void) {
  cout << this->value;
}

node_CHAR::node_CHAR(char value) {
  this->value = value;
}

void node_CHAR::print(void) {
  cout << this->value;
}

node_INT::node_INT(int value) {
  this->value = value;
}

void node_INT::print(void) {
  cout << this->value;
}

node_FLOAT::node_FLOAT(float value) {
  this->value = value;
}

void node_FLOAT::print(void) {
  cout << this->value;
}

node_STRING::node_STRING(string value) {
  this->value = value;
}

void node_STRING::print(void) {
  cout << this->value;
}

/* ======================= EXPRESSION NODES =======================  */
node_BinaryOperator::node_BinaryOperator(node *left, string op, node *rigth) {
  this->left = left;
  this->op = op;
  this->right = right;
}

void node_BinaryOperator::print(void) {
  cout << "(";
  this->left->print();
  cout << ") " << this->op << " (";
  this->right->print();
  cout << ")";
}

node_UnaryOperator::node_UnaryOperator(string op, node *exp) {
  this->op = op;
  this->exp = exp;
}

void node_UnaryOperator::print(void) {
  cout << this->op << "(";
  this->exp->print();
  cout << ")";
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
  cout << ")[";
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
  cout << " " << this->id;
  if (this->rvalue != NULL) {
    cout << " = ";
    this->rvalue->print();
  } 
  cout << ";\n";
}

/* ======================= LVALUE NODES =======================  */
node_IDLValue::node_IDLValue(string id) {
  this->id = id;
}

void node_IDLValue::print(void) {
  cout << this->id;
}

node_DotLValue::node_DotLValue(node *lvalue, string id) {
  this->lvalue = lvalue;
  this->id = id;
}

void node_DotLValue::print(void) {
  cout << "(";
  this->lvalue->print();
  cout << ")." << this->id;
}

node_PointerLValue::node_PointerLValue(node *lvalue) {
  this->lvalue = lvalue;
}

void node_PointerLValue::print(void) {
  cout << "^(";
  this->lvalue->print();
  cout << ")";
}

node_ArrayLValue::node_ArrayLValue(node *lvalue, node *size) {
  this->lvalue = lvalue;
  this->size = size;
}

void node_ArrayLValue::print(void) {
  cout << "(";
  this->lvalue->print();
  cout << ")[";
  this->size->print();
  cout << "]";
}

/* ======================= ARRAY NODES =======================  */
node_Array::node_Array(node *elems) {
  this->elems = elems;
}

void node_Array::print(void) {
  cout << "[";
  if (this->elems != NULL) {
    this->elems->print();
  } 
  cout << "]";
}

node_ArrayElems::node_ArrayElems(node *head, node *rvalue) {
  this->head = head;
  this->rvalue = rvalue;
}

void node_ArrayElems::print(void) {
  if (this->head != NULL) {
    this->head->print();
    cout << ", ";
  }
  this->rvalue->print();
}

/* ======================= FUNCTION CALL NODES ======================= */
node_FunctionCall::node_FunctionCall(string id, node *args, bool end_inst) {
  this->id = id;
  this->args = args;
  this->end_inst = end_inst;
}

void node_FunctionCall::print(void) {
  cout << this->id << "(";
  if (this->args != NULL) {
    this->args->print();
  }
  cout << ")";
  if (this->end_inst) {
    cout << ";\n";
  }
}

/* ======================= INSTRUCTIONS NODES =======================  */
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
