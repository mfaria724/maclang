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
  cout << "'" << this->value << "'";
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
node_BinaryOperator::node_BinaryOperator(node *left, string op, node *right) {
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

/* ======================= HEAP NODES =======================  */
node_New::node_New(node *type) {
  this->type = type;
}

void node_New::print(void) {
  cout << "new ";
  this->type->print();
}

node_Forget::node_Forget(node *lvalue) {
  this->lvalue = lvalue;
}

void node_Forget::print(void) {
  cout << "forget ";
  this->lvalue->print();
  cout << ";\n";
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
  cout << "let ";
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

void node_FunctionCall::set_end_inst(void) {
  this->end_inst = true;
}

node_FunctionCallArgs::node_FunctionCallArgs(node *head, node *rvalue) {
  this->head = head;
  this->rvalue = rvalue;
}

void node_FunctionCallArgs::print(void) {
  if (this->head != NULL) {
    this->head->print();
    cout << ", ";
  }
  this->rvalue->print();
}

/* ======================= UNION DEF NODES ======================= */
node_UnionDef::node_UnionDef(string id, node *fields) {
  this->id = id;
  this->fields = fields;
}

void node_UnionDef::print(void) {
  cout << this->id << " {\n";
  this->fields->print();
  cout << "}\n";
}

node_UnionFields::node_UnionFields(node *head, node *field) {
  this->head = head;
  this->field = field;
}

void node_UnionFields::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  cout << "  ";
  this->field->print();
}

/* ======================= REGISTER DEF NODES ======================= */
node_RegDef::node_RegDef(string id, node *fields) {
  this->id = id;
  this->fields = fields;
}

void node_RegDef::print(void) {
  cout << "register " << this->id << " {\n";
  this->fields->print();
  cout << "}\n";
}

node_RegFields::node_RegFields(node *head, node *type, string id, node *rvalue) {
  this->head = head;
  this->type = type;
  this->id = id;
  this->rvalue = rvalue;
}

void node_RegFields::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  cout << "  ";
  this->type->print();
  cout << " " << this->id;
  if (this->rvalue != NULL) {
    cout << " = ";
    this->rvalue->print();
  }
  cout << ";\n";
}

/* ======================= CONDITIONAL DEF NODES ======================= */
node_Conditional::node_Conditional(node *cond, node *body, node *elsifs, node *else_def) {
  this->cond = cond;
  this->body = body;
  this->elsifs = elsifs;
  this->else_def = else_def;
}

void node_Conditional::print(void) {
  cout << "if ";
  this->cond->print();
  cout << " then \n";
  if (this->body != NULL) {
    this->body->print();
  }
  if (this->elsifs != NULL) {
    this->elsifs->print();
  }
  if (this->else_def != NULL) {
    this->else_def->print();
  }
  cout << "done\n";
}

node_Elsif::node_Elsif(node *head, node *cond, node *body) {
  this->head = head;
  this->cond = cond;
  this->body = body;
}

void node_Elsif::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  cout << "elsif ";
  this->cond->print();
  cout << " then \n";
  if (this->body != NULL) {
    this->body->print();
  }
}

node_Else::node_Else(node *body) {
  this->body = body;
}

void node_Else::print(void) {
  cout << "else \n";
  if (this->body != NULL) {
    this->body->print();
  }
}

/* ======================= LOOP NODES =======================  */
node_While::node_While(node *cond, node *body) {
  this->cond = cond;
  this->body = body;
}

void node_While::print(void) {
  cout << "while ";
  this->cond->print();
  cout << " do\n";
  if (this->body != NULL) {
    this->body->print();
  }
  cout << "done\n";
}

node_For::node_For(string iter, node *begin, node *end, node *step, node *body) {
  this->iter = iter;
  this->begin = begin;
  this->end = end;
  this->step = step;
  this->body = body;
}

void node_For::print(void) {
  cout << "for (" << this->iter << "; ";
  this->begin->print();
  cout << "; ";
  this->end->print();
  if (this->step != NULL) {
    cout << "; ";
    this->step->print();
  }
  cout <<") do\n";
  if (this->body != NULL) {
    this->body->print();
  }
  cout << "done\n";
}

/* ======================= SUBROUTINE DEF NODES =======================  */
node_RoutineDef::node_RoutineDef(string id, node *args, node *ret, node *body) {
  this->id = id;
  this->args = args;
  this->ret = ret;
  this->body = body;
}

void node_RoutineDef::print(void) {
  cout << this->id << " (";
  if (this->args != NULL) {
    this->args->print();
  }
  cout << ") ";
  if (this->ret != NULL) {
    cout << "=> ";
    this->ret->print();
  }
  cout << " {\n";
  if (this->body != NULL) {
    this->body->print();
  }
  cout << "}\n";
}

node_RoutArgsDef::node_RoutArgsDef(node *head, node *type, bool ref, string id, node *rvalue) {
  this->head = head;
  this->type = type;
  this->ref = ref;
  this->id = id;
  this->rvalue = rvalue;
}

void node_RoutArgsDef::print(void) {
  if (this->head != NULL) {
    this->head->print();
    cout << ", ";
  }
  this->type->print();
  cout << " ";
  if (this->ref) {
    cout << "@";
  }
  cout << this->id;
  if (this->rvalue) {
    cout << " = ";
    this->rvalue->print();
  }
}

node_Actions::node_Actions(node *head, node *inst) {
  this->head = head;
  this->inst = inst;
}

void node_Actions::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  this->inst->print();
}

/* ======================= INSTRUCTION NODES =======================  */
node_Assign::node_Assign(node *lvalue, node *rvalue) {
  this->lvalue = lvalue;
  this->rvalue = rvalue;
}

void node_Assign::print(void) {
  this->lvalue->print();
  cout << " = ";
  this->rvalue->print();
  cout << ";\n";
}

node_I::node_I(node *head, node *inst) {
  this->head = head;
  this->inst = inst;
}

void node_I::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  this->inst->print();
}

node_S::node_S(node *inst) {
  this->inst = inst;
}

void node_S::print(void) {
  if (this->inst != NULL) {
    this->inst->print();
  }
}
