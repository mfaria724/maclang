#include "ast.hpp"

/* ======================= AUXILIARY FUNCTIONS =======================  */
void print_identation(vector<bool> *identation) {
  for (bool b : *identation) {
    if (b) cout << "│";
    else cout << " ";
    cout << "   ";
  }
}

/* ======================= DATA NODES =======================  */
node_BOOL::node_BOOL(bool value) {
  this->value = value;
}

void node_BOOL::print(void) {
  cout << this->value;
}

void node_BOOL::print_tree(vector<bool> *identation) {
  cout << "BOOL: " << this->value << "\n";
}

node_CHAR::node_CHAR(char value) {
  this->value = value;
}

void node_CHAR::print(void) {
  cout << "'" << this->value << "'";
}

void node_CHAR::print_tree(vector<bool> *identation) {
  cout << "CHAR: " << this->value << "\n";
}

node_INT::node_INT(int value) {
  this->value = value;
}

void node_INT::print(void) {
  cout << this->value;
}

void node_INT::print_tree(vector<bool> *identation) {
  cout << "INT: " << this->value << "\n";
}

node_FLOAT::node_FLOAT(float value) {
  this->value = value;
}

void node_FLOAT::print(void) {
  cout << this->value;
}

void node_FLOAT::print_tree(vector<bool> *identation) {
  cout << "FLOAT: " << this->value << "\n";
}

node_STRING::node_STRING(string value) {
  this->value = value;
}

void node_STRING::print(void) {
  cout << this->value;
}

void node_STRING::print_tree(vector<bool> *identation) {
  cout << "STRING: " << this->value << "\n";
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

void node_BinaryOperator::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mBinary Operator\e[0m\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mLeft: \e[0m";
  this->left->print_tree(identation);
  identation->pop_back();

  print_identation(identation);
  cout << "├── Operator: " << this->op << "\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── \e[1;34mRight: \e[0m";
  this->right->print_tree(identation);
  identation->pop_back();
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

void node_UnaryOperator::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mUnary Operator\e[0m\n";

  print_identation(identation);
  cout << "├── Operator: " << this->op << "\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── \e[1;34mOperating: \e[0m";
  this->exp->print_tree(identation);
  identation->pop_back();
}

/* ======================= HEAP NODES =======================  */
node_New::node_New(node *type) {
  this->type = type;
}

void node_New::print(void) {
  cout << "new ";
  this->type->print();
}

void node_New::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mNew\e[0m\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->type->print_tree(identation);
  identation->pop_back();
}

node_Forget::node_Forget(node *lvalue) {
  this->lvalue = lvalue;
}

void node_Forget::print(void) {
  cout << "forget ";
  this->lvalue->print();
  cout << ";\n";
}

void node_Forget::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mForget\e[0m\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->lvalue->print_tree(identation);
  identation->pop_back();
}

/* ======================= TYPEDEF NODES =======================  */
node_TypePrimitiveDef::node_TypePrimitiveDef(string id) {
  this->id = id;
}

void node_TypePrimitiveDef::print(void) {
  cout << this->id;
}

void node_TypePrimitiveDef::print_tree(vector<bool> *identation) {
  cout << "Primitive Type: " << this->id << "\n";
}

node_TypePointerDef::node_TypePointerDef(node *type) {
  this->type = type;
}

void node_TypePointerDef::print(void) {
  cout << "^(";
  this->type->print();
  cout << ")";
}

void node_TypePointerDef::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mType Pointer\e[0m\n";

  print_identation(identation);
  cout << "├── ^\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->type->print_tree(identation);
  identation->pop_back();
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

void node_TypeArrayDef::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mType Array\e[0m\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->print_tree(identation);
  identation->pop_back();

  print_identation(identation);
  identation->push_back(false);
  cout << "└── \e[1;34mSize: \e[0m";
  this->size->print_tree(identation);
  identation->pop_back();
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

void node_VarDef::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mVariable Definition\e[0m\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->print_tree(identation);
  identation->pop_back();

  if (this->rvalue != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ID: " << this->id << "\n";
    identation->pop_back();

    print_identation(identation);
    cout << "├── = \n";

    print_identation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->rvalue->print_tree(identation);
    identation->pop_back();

  } else {
    print_identation(identation);
    identation->push_back(true);
    cout << "└── ID: " << this->id << "\n";
    identation->pop_back();
  }
}



/* ======================= LVALUE NODES =======================  */
node_IDLValue::node_IDLValue(string id) {
  this->id = id;
}

void node_IDLValue::print(void) {
  cout << this->id;
}

void node_IDLValue::print_tree(vector<bool> *identation) {
  cout << "ID: " << this->id << "\n";
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

void node_DotLValue::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mField Access\e[0m\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->lvalue->print_tree(identation);
  identation->pop_back();

  print_identation(identation);
  cout << "└── Field: " << this->id << "\n"; 
}

node_PointerLValue::node_PointerLValue(node *lvalue) {
  this->lvalue = lvalue;
}

void node_PointerLValue::print(void) {
  cout << "^(";
  this->lvalue->print();
  cout << ")";
}

void node_PointerLValue::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mDesreferentation\e[0m\n";

  print_identation(identation);
  cout << "├── ^\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->lvalue->print_tree(identation);
  identation->pop_back();
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

void node_ArrayLValue::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mArray Access\e[0m\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->lvalue->print_tree(identation);
  identation->pop_back();

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->size->print_tree(identation);
  identation->pop_back();
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

void node_Array::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mArray\e[0m\n";

  if (this->elems != NULL) {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->elems->print_tree(identation);
    identation->pop_back();
  }
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

void node_ArrayElems::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mArray Element\e[0m\n";

  if (this->head != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->print_tree(identation);
    identation->pop_back();
  }

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->rvalue->print_tree(identation);
  identation->pop_back();
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

void node_FunctionCall::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mFunction Call\e[0m\n";

  print_identation(identation);
  cout << "├── ID: " << this->id << "\n";

  if (this->args != NULL) {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->args->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "└── \e[1;34mFunction Call Arguments: \e[0mNULL\n";
  }
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

void node_FunctionCallArgs::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mFunction Call Argument\e[0m\n";

  if (this->head != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->print_tree(identation);
    identation->pop_back();
  }

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->rvalue->print_tree(identation);
  identation->pop_back();
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

void node_UnionDef::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mUnion Definition\e[0m\n";

  print_identation(identation);
  cout << "├── ID: " << this->id << "\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->fields->print_tree(identation);
  identation->pop_back();
}

node_UnionFields::node_UnionFields(node *head, node *type, string id) {
  this->head = head;
  this->type = type;
  this->id = id;
}

void node_UnionFields::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  cout << "  ";
  this->type->print();
  cout << " " << this->id << ";\n";
}

void node_UnionFields::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mUnion Field\e[0m\n";

  if (this->head != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->print_tree(identation);
    identation->pop_back();
  }

  print_identation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->print_tree(identation);
  identation->pop_back();

  print_identation(identation);
  cout << "└── ID: " << this->id << "\n";
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

void node_RegDef::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mRegister Definition\e[0m\n";

  print_identation(identation);
  cout << "├── ID: " << this->id << "\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->fields->print_tree(identation);
  identation->pop_back();
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

void node_RegFields::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mRegister Field\e[0m\n";

  if (this->head != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->print_tree(identation);
    identation->pop_back();
  }

  print_identation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->print_tree(identation);
  identation->pop_back();

  if (this->rvalue != NULL) {
    print_identation(identation);
    cout << "├── ID: " << this->id << "\n";

    print_identation(identation);
    cout << "├── = \n";

    print_identation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->rvalue->print_tree(identation);
    identation->pop_back();
  
  } else {
    print_identation(identation);
    cout << "└── ID: " << this->id << "\n";
  }
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

void node_Conditional::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mIf\e[0m\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mCondition: \e[0m";
  this->cond->print_tree(identation);
  identation->pop_back();

  if (this->body != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mBody: \e[0m";
    this->body->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "├── \e[1;34mBody: \e[0mNULL\n";
  }

  if (this->elsifs != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->elsifs->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "├── \e[1;34mElsif: \e[0mNULL\n";
  }

  if (this->else_def != NULL) {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->else_def->print_tree(identation);
    identation->pop_back();
  }  else {
    print_identation(identation);
    cout << "└── \e[1;34mElse: \e[0mNULL\n";
  }
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

void node_Elsif::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mElsif\e[0m\n";

  if (this->head != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->print_tree(identation);
    identation->pop_back();
  }

  print_identation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mCondition: \e[0m";
  this->cond->print_tree(identation);
  identation->pop_back();

  if (this->body != NULL) {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
    this->cond->print_tree(identation);
    identation->pop_back();
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

void node_Else::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mElse\e[0m\n";

  if (this->body != NULL) {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
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

void node_While::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mWhile\e[0m\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mCondition: \e[0m";
  this->cond->print_tree(identation);
  identation->pop_back();

  if (this->body != NULL) {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
  }
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

void node_For::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mFor\e[0m\n";

  print_identation(identation);
  cout << "├── ITERATOR: " << this->iter << "\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mBegin: \e[0m";
  this->begin->print_tree(identation);
  identation->pop_back();

  print_identation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mEnd: \e[0m";
  this->end->print_tree(identation);
  identation->pop_back();

  if (this->step != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mStep: \e[0m";
    this->step->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "├── \e[1;34mStep: \e[0mNULL\n";
  }

  if (this->body != NULL) {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
  }

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

void node_RoutineDef::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mRoutine Definition\e[0m\n";

  print_identation(identation);
  cout << "├── ID: " << this->id << "\n";

  if (this->args != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mParameters: \e[0m";
    this->args->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "├── \e[1;34mParameters: \e[0mNULL\n";
  }

  if (this->ret != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mReturn Type: \e[0m";
    this->ret->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "├── \e[1;34mReturn Type: \e[0mNULL\n";
  }

  if (this->body != NULL) {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->print_tree(identation);
    identation->pop_back();
  } else {
    print_identation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
  }
}

node_RoutArgs::node_RoutArgs(node *obl_args, node *opt_args) {
  this->obl_args = obl_args;
  this->opt_args = opt_args;
}

void node_RoutArgs::print(void) {
  if (this->obl_args != NULL) {
    this->obl_args->print();
    if (this->opt_args != NULL) {
      cout << ", ";
      this->opt_args->print();
    }
  } else if (this->opt_args != NULL) {
    this->opt_args->print();
  }
}

void node_RoutArgs::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mRoutine Parameters\e[0m\n";

  if ((this->obl_args != NULL) && (this->opt_args != NULL)) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mObligatory Parameters: \e[0m";
    this->obl_args->print_tree(identation);
    identation->pop_back();

    print_identation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mOptional Parameters: \e[0m";
    this->opt_args->print_tree(identation);
    identation->pop_back();

  } else if (this->obl_args != NULL){
    print_identation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mObligatory Parameters: \e[0m";
    this->obl_args->print_tree(identation);
    identation->pop_back(); 

  } else {
    print_identation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mOptional Parameters: \e[0m";
    this->opt_args->print_tree(identation);
    identation->pop_back(); 
  }
}

node_RoutArgDef::node_RoutArgDef(node *head, node *type, bool ref, string id, node *rvalue) {
  this->head = head;
  this->type = type;
  this->ref = ref;
  this->id = id;
  this->rvalue = rvalue;
}

void node_RoutArgDef::print(void) {
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
  if (this->rvalue != NULL) {
    cout << " = ";
    this->rvalue->print();
  }
}

void node_RoutArgDef::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mParameter Definition\e[0m\n";

  if (this->head != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->print_tree(identation);
    identation->pop_back();
  } 

  print_identation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->print_tree(identation);
  identation->pop_back();

  if (this->ref) {
    print_identation(identation);
    cout << "├── @\n";
  }

  if (this->rvalue != NULL) {
    print_identation(identation);
    cout << "├── ID: " << this->id << "\n";

    print_identation(identation);
    cout << "├── =\n";

    print_identation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->rvalue->print_tree(identation);
    identation->pop_back();

  } else {
    print_identation(identation);
    cout << "└── ID: " << this->id << "\n"; 
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

void node_Actions::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mAction\e[0m\n";

  if (this->head != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->print_tree(identation);
    identation->pop_back();
  }

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->inst->print_tree(identation);
  identation->pop_back();
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

void node_Assign::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mAssignment\e[0m\n";

  print_identation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->lvalue->print_tree(identation);
  identation->pop_back();

  print_identation(identation);
  cout << "├── =\n";

  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->rvalue->print_tree(identation);
  identation->pop_back();
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

void node_I::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mI\e[0m\n";
  if (this->head != NULL) {
    print_identation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->print_tree(identation);
    identation->pop_back();
  }
  print_identation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->inst->print_tree(identation);
  identation->pop_back();
}

node_S::node_S(node *inst) {
  this->inst = inst;
}

void node_S::print(void) {
  if (this->inst != NULL) {
    this->inst->print();
  }
}

void node_S::print_tree(vector<bool> *identation) {
  cout << "\e[1;34mS\e[0m\n";
  vector<bool> *new_identation = new vector<bool>;
  new_identation->push_back(false);
  if (this->inst != NULL) {
    cout << "└── ";
    this->inst->print_tree(new_identation);
  }
}
