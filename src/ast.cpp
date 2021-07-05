#include "ast.hpp"

/* ======================= AUXILIARY FUNCTIONS =======================  */
void printIdentation(vector<bool> *identation) {
  for (bool b : *identation) {
    if (b) cout << "│";
    else cout << " ";
    cout << "   ";
  }
}

/* ======================= DATA NODES =======================  */
NodeBOOL::NodeBOOL(bool value) {
  this->value = value;
  this->type = "Bool";
}

void NodeBOOL::print(void) {
  cout << this->toString();
}

string NodeBOOL::toString() {
  return this->value ? "true" : "false";
}

void NodeBOOL::printTree(vector<bool> *identation) {
  cout << "BOOL: " << this->value << "\n";
}


NodeCHAR::NodeCHAR(char value) {
  this->value = value;
  this->type = "Char";
}

void NodeCHAR::print(void) {
  cout << this->toString();
}

string NodeCHAR::toString(void) {
  string result = "'";
  return result + this->value + result;
}

void NodeCHAR::printTree(vector<bool> *identation) {
  cout << "CHAR: " << this->value << "\n";
}

NodeINT::NodeINT(int value) {
  this->value = value;
  this->type = "Int";
}

void NodeINT::print(void) {
  cout << this->toString();
}

string NodeINT::toString(void) {
  return to_string(this->value);
}

void NodeINT::printTree(vector<bool> *identation) {
  cout << "INT: " << this->value << "\n";
}

NodeFLOAT::NodeFLOAT(float value) {
  this->value = value;
  this->type = "Float";
}

void NodeFLOAT::print(void) {
  cout << this->toString();
}

string NodeFLOAT::toString(void) {
  return to_string(this->value);
}

void NodeFLOAT::printTree(vector<bool> *identation) {
  cout << "FLOAT: " << this->value << "\n";
}

NodeSTRING::NodeSTRING(string value) {
  this->value = value;
  this->type = "String";
}

void NodeSTRING::print(void) {
  cout << this->toString();
}

string NodeSTRING::toString(void) {
  return this->value;
}

void NodeSTRING::printTree(vector<bool> *identation) {
  cout << "STRING: " << this->value << "\n";
}

/* ======================= EXPRESSION NODES =======================  */
NodeBinaryOperator::NodeBinaryOperator(
  Node *left, 
  string op, 
  Node *right, 
  string type
) {
  this->left = left;
  this->op = op;
  this->right = right;
  this->type = type;
}

void NodeBinaryOperator::print(void) {
  cout << "(";
  this->left->print();
  cout << ") " << this->op << " (";
  this->right->print();
  cout << ")";
}

string NodeBinaryOperator::toString(void) {
  return "(" + this->left->toString() + ") " + this->op +
         " (" + this->right->toString() + ")";
}

void NodeBinaryOperator::printTree(vector<bool> *identation) {
  cout << "\e[1;34mBinary Operator\e[0m\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mLeft: \e[0m";
  this->left->printTree(identation);
  identation->pop_back();

  printIdentation(identation);
  cout << "├── Operator: " << this->op << "\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── \e[1;34mRight: \e[0m";
  this->right->printTree(identation);
  identation->pop_back();
}

NodeUnaryOperator::NodeUnaryOperator(string op, Node *exp, string type) {
  this->op = op;
  this->exp = exp;
  this->type = type;
}

void NodeUnaryOperator::print(void) {
  cout << this->op << "(";
  this->exp->print();
  cout << ")";
}

string NodeUnaryOperator::toString(void) {
  return this->op + "(" + this->exp->toString() + ")";
}

void NodeUnaryOperator::printTree(vector<bool> *identation) {
  cout << "\e[1;34mUnary Operator\e[0m\n";

  printIdentation(identation);
  cout << "├── Operator: " << this->op << "\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── \e[1;34mOperating: \e[0m";
  this->exp->printTree(identation);
  identation->pop_back();
}

/* ======================= HEAP NODES =======================  */
NodeNew::NodeNew(Type *type) {
  this->type = type;
}

void NodeNew::print(void) {
  cout << "new ";
  this->type->print();
}

string NodeNew::toString(void) {
  return "new " + this->type->toString();
}

void NodeNew::printTree(vector<bool> *identation) {
  cout << "\e[1;34mNew\e[0m\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->type->printTree(identation);
  identation->pop_back();
}

NodeForget::NodeForget(Node *lvalue) {
  this->lvalue = lvalue;
}

void NodeForget::print(void) {
  cout << "forget ";
  this->lvalue->print();
  cout << ";\n";
}

string NodeForget::toString(void) {
  return "forget " + this->lvalue->toString() + ";\n";
}

void NodeForget::printTree(vector<bool> *identation) {
  cout << "\e[1;34mForget\e[0m\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->lvalue->printTree(identation);
  identation->pop_back();
}

/* ======================= TYPEDEF NODES =======================  */
NodeVarDef::NodeVarDef(Type *type, string id, Node *rvalue) {
  this->type = type;
  this->id = id;
  this->rvalue = rvalue;
}

void NodeVarDef::print(void) {
  cout << "let ";
  this->type->print();
  cout << " " << this->id;
  if (this->rvalue != NULL) {
    cout << " = ";
    this->rvalue->print();
  } 
  cout << ";\n";
}

string NodeVarDef::toString(void) {
  string result = "let " + this->type->toString() + " " + this->id;
  if (this->rvalue != NULL) {
    result += " = " + this->rvalue->toString();
  } 
  return result + ";";
}

void NodeVarDef::printTree(vector<bool> *identation) {
  cout << "\e[1;34mVariable Definition\e[0m\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->printTree(identation);
  identation->pop_back();

  if (this->rvalue != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ID: " << this->id << "\n";
    identation->pop_back();

    printIdentation(identation);
    cout << "├── = \n";

    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->rvalue->printTree(identation);
    identation->pop_back();

  } else {
    printIdentation(identation);
    identation->push_back(true);
    cout << "└── ID: " << this->id << "\n";
    identation->pop_back();
  }
}

/* ======================= LVALUE NODES =======================  */
NodeIDLValue::NodeIDLValue(string id, string type) {
  this->id = id;
  this->type = type;
}

void NodeIDLValue::print(void) {
  cout << this->id;
}

string NodeIDLValue::toString(void) {
  return this->id;
}

void NodeIDLValue::printTree(vector<bool> *identation) {
  cout << "ID: " << this->id << "\n";
}

NodeDotLValue::NodeDotLValue(Node *lvalue, string id, string type) {
  this->lvalue = lvalue;
  this->id = id;
  this->type = type;
}

void NodeDotLValue::print(void) {
  cout << "(";
  this->lvalue->print();
  cout << ")." << this->id;
}

string NodeDotLValue::toString(void) {
  return "(" + this->lvalue->toString() + ")." + this->id;
}

void NodeDotLValue::printTree(vector<bool> *identation) {
  cout << "\e[1;34mField Access\e[0m\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->lvalue->printTree(identation);
  identation->pop_back();

  printIdentation(identation);
  cout << "└── Field: " << this->id << "\n"; 
}

NodePointerLValue::NodePointerLValue(Node *lvalue, string type) {
  this->lvalue = lvalue;
  this->type = type;
}

void NodePointerLValue::print(void) {
  cout << "^(";
  this->lvalue->print();
  cout << ")";
}

string NodePointerLValue::toString(void) {
  return "^(" + this->lvalue->toString() + ")";
}

void NodePointerLValue::printTree(vector<bool> *identation) {
  cout << "\e[1;34mDesreferentation\e[0m\n";

  printIdentation(identation);
  cout << "├── ^\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->lvalue->printTree(identation);
  identation->pop_back();
}

NodeArrayLValue::NodeArrayLValue(Node *lvalue, Node *size, string type) {
  this->lvalue = lvalue;
  this->size = size;
  this->type = type;
}

void NodeArrayLValue::print(void) {
  cout << "(";
  this->lvalue->print();
  cout << ")[";
  this->size->print();
  cout << "]";
}

string NodeArrayLValue::toString(void) {
  return "(" + this->lvalue->toString() + ")[" + this->size->toString() + "]";
}

void NodeArrayLValue::printTree(vector<bool> *identation) {
  cout << "\e[1;34mArray Access\e[0m\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->lvalue->printTree(identation);
  identation->pop_back();

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->size->printTree(identation);
  identation->pop_back();
}

/* ======================= ARRAY NODES =======================  */
NodeArray::NodeArray(Node *elems) {
  this->elems = elems;
}

void NodeArray::print(void) {
  cout << "[";
  if (this->elems != NULL) {
    this->elems->print();
  } 
  cout << "]";
}

string NodeArray::toString(void) {
  string result = "[";
  if (this->elems != NULL) {
    result += this->elems->toString();
  } 
  return result + "]";
}

void NodeArray::printTree(vector<bool> *identation) {
  cout << "\e[1;34mArray\e[0m\n";

  if (this->elems != NULL) {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->elems->printTree(identation);
    identation->pop_back();
  }
}

NodeArrayElems::NodeArrayElems(Node *head, Node *rvalue) {
  this->head = head;
  this->rvalue = rvalue;
}

void NodeArrayElems::print(void) {
  if (this->head != NULL) {
    this->head->print();
    cout << ", ";
  }
  this->rvalue->print();
}

string NodeArrayElems::toString(void) {
  string result = "";
  if (this->head != NULL) {
    result += this->head->toString() + ", ";
  }
  return result + this->rvalue->toString();
}

void NodeArrayElems::printTree(vector<bool> *identation) {
  cout << "\e[1;34mArray Element\e[0m\n";

  if (this->head != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->printTree(identation);
    identation->pop_back();
  }

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->rvalue->printTree(identation);
  identation->pop_back();
}

/* ======================= FUNCTION CALL NODES ======================= */
NodeFunctionCall::NodeFunctionCall(
  string id, 
  Node *args, 
  bool bEndInst, 
  string type
) {
  this->id = id;
  this->args = args;
  this->bEndInst = bEndInst;
  this->type = type;
}

void NodeFunctionCall::print(void) {
  cout << this->id << "(";
  if (this->args != NULL) {
    this->args->print();
  }
  cout << ")";
  if (this->bEndInst) {
    cout << ";\n";
  }
}

string NodeFunctionCall::toString(void) {
  string result = this->id + "(";
  if (this->args != NULL) {
    result += this->args->toString();
  }
  result += ")";
  if (this->bEndInst) {
    result += ";";
  }

  return result;
}

void NodeFunctionCall::setEndInst(void) {
  this->bEndInst = true;
}

void NodeFunctionCall::printTree(vector<bool> *identation) {
  cout << "\e[1;34mFunction Call\e[0m\n";

  printIdentation(identation);
  cout << "├── ID: " << this->id << "\n";

  if (this->args != NULL) {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->args->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "└── \e[1;34mFunction Call Arguments: \e[0mNULL\n";
  }
}

NodeFunctionCallArgs::NodeFunctionCallArgs(Node *head, Node *rvalue) {
  this->head = head;
  this->rvalue = rvalue;
}

void NodeFunctionCallArgs::print(void) {
  if (this->head != NULL) {
    this->head->print();
    cout << ", ";
  }
  this->rvalue->print();
}

string NodeFunctionCallArgs::toString(void) {
  string result = "";

  if (this->head != NULL) {
    result += this->head->toString() + ", ";
  }
  return result + this->rvalue->toString();
}

void NodeFunctionCallArgs::printTree(vector<bool> *identation) {
  cout << "\e[1;34mFunction Call Argument\e[0m\n";

  if (this->head != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->printTree(identation);
    identation->pop_back();
  }

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->rvalue->printTree(identation);
  identation->pop_back();
}

/* ======================= UNION DEF NODES ======================= */
NodeUnionDef::NodeUnionDef(string id, Node *fields) {
  this->id = id;
  this->fields = fields;
}

void NodeUnionDef::print(void) {
  cout << this->id << " {\n";
  this->fields->print();
  cout << "}\n";
}

string NodeUnionDef::toString(void) {
  return this->id + " { " + this->fields->toString() + " }";
}

void NodeUnionDef::printTree(vector<bool> *identation) {
  cout << "\e[1;34mUnion Definition\e[0m\n";

  printIdentation(identation);
  cout << "├── ID: " << this->id << "\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->fields->printTree(identation);
  identation->pop_back();
}

NodeUnionFields::NodeUnionFields(Node *head, Type *type, string id) {
  this->head = head;
  this->type = type;
  this->id = id;
}

void NodeUnionFields::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  cout << "  ";
  this->type->print();
  cout << " " << this->id << ";\n";
}

string NodeUnionFields::toString(void) {

  string result = "";
  if (this->head != NULL) {
    result += this->head->toString();
  }
  return result + "  " + this->type->toString() + " " + this->id + ";";
}

void NodeUnionFields::printTree(vector<bool> *identation) {
  cout << "\e[1;34mUnion Field\e[0m\n";

  if (this->head != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->printTree(identation);
    identation->pop_back();
  }

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->printTree(identation);
  identation->pop_back();

  printIdentation(identation);
  cout << "└── ID: " << this->id << "\n";
}

/* ======================= REGISTER DEF NODES ======================= */
NodeRegDef::NodeRegDef(string id, Node *fields) {
  this->id = id;
  this->fields = fields;
}

void NodeRegDef::print(void) {
  cout << "register " << this->id << " {\n";
  this->fields->print();
  cout << "}\n";
}

string NodeRegDef::toString(void) {
  return "register " + this->id + " { " + this->fields->toString() + " }";
}

void NodeRegDef::printTree(vector<bool> *identation) {
  cout << "\e[1;34mRegister Definition\e[0m\n";

  printIdentation(identation);
  cout << "├── ID: " << this->id << "\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->fields->printTree(identation);
  identation->pop_back();
}

NodeRegFields::NodeRegFields(Node *head, Type *type, string id, Node *rvalue) {
  this->head = head;
  this->type = type;
  this->id = id;
  this->rvalue = rvalue;
}

void NodeRegFields::print(void) {
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

string NodeRegFields::toString(void) {
  
  string result = "";
  
  if (this->head != NULL) {
    result += this->head->toString();
  }
  result += "  " + this->type->toString() + " " + this->id;
  if (this->rvalue != NULL) {
    result += " = " + this->rvalue->toString();
  }
  return result + ";";
}

void NodeRegFields::printTree(vector<bool> *identation) {
  cout << "\e[1;34mRegister Field\e[0m\n";

  if (this->head != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->printTree(identation);
    identation->pop_back();
  }

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->printTree(identation);
  identation->pop_back();

  if (this->rvalue != NULL) {
    printIdentation(identation);
    cout << "├── ID: " << this->id << "\n";

    printIdentation(identation);
    cout << "├── = \n";

    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->rvalue->printTree(identation);
    identation->pop_back();
  
  } else {
    printIdentation(identation);
    cout << "└── ID: " << this->id << "\n";
  }
}

/* ======================= CONDITIONAL DEF NODES ======================= */
NodeConditional::NodeConditional(Node *cond, Node *body, Node *elsifs, Node *elseDef) {
  this->cond = cond;
  this->body = body;
  this->elsifs = elsifs;
  this->elseDef = elseDef;
}

void NodeConditional::print(void) {
  cout << "if ";
  this->cond->print();
  cout << " then \n";
  if (this->body != NULL) {
    this->body->print();
  }
  if (this->elsifs != NULL) {
    this->elsifs->print();
  }
  if (this->elseDef != NULL) {
    this->elseDef->print();
  }
  cout << "done\n";
}

string NodeConditional::toString(void) {

  string result = "";
  result += "if " + this->cond->toString() + " then ";
  if (this->body != NULL) {
    result += this->body->toString();
  }
  if (this->elsifs != NULL) {
    result += this->elsifs->toString();
  }
  if (this->elseDef != NULL) {
    result += this->elseDef->toString();
  }
  return result + " done";
}

void NodeConditional::printTree(vector<bool> *identation) {
  cout << "\e[1;34mIf\e[0m\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mCondition: \e[0m";
  this->cond->printTree(identation);
  identation->pop_back();

  if (this->body != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mBody: \e[0m";
    this->body->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "├── \e[1;34mBody: \e[0mNULL\n";
  }

  if (this->elsifs != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->elsifs->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "├── \e[1;34mElsif: \e[0mNULL\n";
  }

  if (this->elseDef != NULL) {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->elseDef->printTree(identation);
    identation->pop_back();
  }  else {
    printIdentation(identation);
    cout << "└── \e[1;34mElse: \e[0mNULL\n";
  }
}

NodeElsif::NodeElsif(Node *head, Node *cond, Node *body) {
  this->head = head;
  this->cond = cond;
  this->body = body;
}

void NodeElsif::print(void) {
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

string NodeElsif::toString(void) {

  string result = "";

  if (this->head != NULL) {
    result += this->head->toString();
  }
  result += "elsif " + this->cond->toString() + " then ";
  if (this->body != NULL) {
    result += this->body->toString();
  }

  return result;
}

void NodeElsif::printTree(vector<bool> *identation) {
  cout << "\e[1;34mElsif\e[0m\n";

  if (this->head != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->printTree(identation);
    identation->pop_back();
  }

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mCondition: \e[0m";
  this->cond->printTree(identation);
  identation->pop_back();

  if (this->body != NULL) {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
    this->cond->printTree(identation);
    identation->pop_back();
  }
}

NodeElse::NodeElse(Node *body) {
  this->body = body;
}

void NodeElse::print(void) {
  cout << "else \n";
  if (this->body != NULL) {
    this->body->print();
  }
}

string NodeElse::toString(void) {
  string result = " else ";
  if (this->body != NULL) {
    result += this->body->toString();
  }

  return result;
}

void NodeElse::printTree(vector<bool> *identation) {
  cout << "\e[1;34mElse\e[0m\n";

  if (this->body != NULL) {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
  }
}

/* ======================= LOOP NODES =======================  */
NodeWhile::NodeWhile(Node *cond, Node *body) {
  this->cond = cond;
  this->body = body;
}

void NodeWhile::print(void) {
  cout << "while ";
  this->cond->print();
  cout << " do\n";
  if (this->body != NULL) {
    this->body->print();
  }
  cout << "done\n";
}

string NodeWhile::toString(void) {
  string result = "while " + this->cond->toString() + " do ";
  if (this->body != NULL) {
    result += this->body->toString();
  }
  return result + " done";
}

void NodeWhile::printTree(vector<bool> *identation) {
  cout << "\e[1;34mWhile\e[0m\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mCondition: \e[0m";
  this->cond->printTree(identation);
  identation->pop_back();

  if (this->body != NULL) {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
  }
}

NodeFor::NodeFor(string iter, Node *begin, Node *end, Node *step, Node *body) {
  this->iter = iter;
  this->begin = begin;
  this->end = end;
  this->step = step;
  this->body = body;
}

void NodeFor::print(void) {
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

string NodeFor::toString(void) {
  string result = "for (" + this->iter + "; " + this->begin->toString() + "; " 
                  + this->end->toString();
  if (this->step != NULL) {
    result += "; " + this->step->toString();
  }
  result += ") do ";
  if (this->body != NULL) {
    result += this->body->toString();
  }
  return result + "done";
}

void NodeFor::printTree(vector<bool> *identation) {
  cout << "\e[1;34mFor\e[0m\n";

  printIdentation(identation);
  cout << "├── ITERATOR: " << this->iter << "\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mBegin: \e[0m";
  this->begin->printTree(identation);
  identation->pop_back();

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── \e[1;34mEnd: \e[0m";
  this->end->printTree(identation);
  identation->pop_back();

  if (this->step != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mStep: \e[0m";
    this->step->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "├── \e[1;34mStep: \e[0mNULL\n";
  }

  if (this->body != NULL) {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
  }

}

/* ======================= SUBROUTINE DEF NODES =======================  */
NodeRoutineDef::NodeRoutineDef(string id, Node *args, Type *ret, Node *body) {
  this->id = id;
  this->args = args;
  this->ret = ret;
  this->body = body;
}

void NodeRoutineDef::print(void) {
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

string NodeRoutineDef::toString(void) {
  string result = this->id + " (";
  if (this->args != NULL) {
    result += this->args->toString();
  }
  result += ") ";
  if (this->ret != NULL) {
    result += "=> " + this->ret->toString();
  }
  result += " { ";
  if (this->body != NULL) {
    result += this->body->toString();
  }
  return result + "}";
}

void NodeRoutineDef::printTree(vector<bool> *identation) {
  cout << "\e[1;34mRoutine Definition\e[0m\n";

  printIdentation(identation);
  cout << "├── ID: " << this->id << "\n";

  if (this->args != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mParameters: \e[0m";
    this->args->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "├── \e[1;34mParameters: \e[0mNULL\n";
  }

  if (this->ret != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mReturn Type: \e[0m";
    this->ret->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "├── \e[1;34mReturn Type: \e[0mNULL\n";
  }

  if (this->body != NULL) {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mBody: \e[0m";
    this->body->printTree(identation);
    identation->pop_back();
  } else {
    printIdentation(identation);
    cout << "└── \e[1;34mBody: \e[0mNULL\n";
  }
}

NodeRoutArgs::NodeRoutArgs(Node *oblArgs, Node *optArgs) {
  this->oblArgs = oblArgs;
  this->optArgs = optArgs;
}

void NodeRoutArgs::print(void) {
  if (this->oblArgs != NULL) {
    this->oblArgs->print();
    if (this->optArgs != NULL) {
      cout << ", ";
      this->optArgs->print();
    }
  } else if (this->optArgs != NULL) {
    this->optArgs->print();
  }
}

string NodeRoutArgs::toString(void) {

  string result = "";

  if (this->oblArgs != NULL) {
    result += this->oblArgs->toString();
    if (this->optArgs != NULL) {
      result += ", " + this->optArgs->toString();
    }
  } else if (this->optArgs != NULL) {
    result += this->optArgs->toString();
  }

  return result;
}

void NodeRoutArgs::printTree(vector<bool> *identation) {
  cout << "\e[1;34mRoutine Parameters\e[0m\n";

  if ((this->oblArgs != NULL) && (this->optArgs != NULL)) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── \e[1;34mMandatory Parameters: \e[0m";
    this->oblArgs->printTree(identation);
    identation->pop_back();

    printIdentation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mOptional Parameters: \e[0m";
    this->optArgs->printTree(identation);
    identation->pop_back();

  } else if (this->oblArgs != NULL){
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mMandatory Parameters: \e[0m";
    this->oblArgs->printTree(identation);
    identation->pop_back(); 

  } else {
    printIdentation(identation);
    identation->push_back(false);
    cout << "└── \e[1;34mOptional Parameters: \e[0m";
    this->optArgs->printTree(identation);
    identation->pop_back(); 
  }
}

NodeRoutArgDef::NodeRoutArgDef(Node *head, Type *type, bool ref, string id, Node *rvalue) {
  this->head = head;
  this->type = type;
  this->ref = ref;
  this->id = id;
  this->rvalue = rvalue;
}

void NodeRoutArgDef::print(void) {
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

string NodeRoutArgDef::toString(void) {
  
  string result = "";

  if (this->head != NULL) {
    result += this->head->toString() + ", ";
  }
  result += this->type->toString() + " ";
  if (this->ref) {
    result += "@";
  }
  result += this->id;
  if (this->rvalue != NULL) {
    result += " = " + this->rvalue->toString();
  }

  return result;
}

void NodeRoutArgDef::printTree(vector<bool> *identation) {
  cout << "\e[1;34mParameter Definition\e[0m\n";

  if (this->head != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->printTree(identation);
    identation->pop_back();
  } 

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->printTree(identation);
  identation->pop_back();

  if (this->ref) {
    printIdentation(identation);
    cout << "├── @\n";
  }

  if (this->rvalue != NULL) {
    printIdentation(identation);
    cout << "├── ID: " << this->id << "\n";

    printIdentation(identation);
    cout << "├── =\n";

    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->rvalue->printTree(identation);
    identation->pop_back();

  } else {
    printIdentation(identation);
    cout << "└── ID: " << this->id << "\n"; 
  }
}

NodeActions::NodeActions(Node *head, Node *inst) {
  this->head = head;
  this->inst = inst;
}

void NodeActions::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  this->inst->print();
}

string NodeActions::toString(void) {
  
  string result = "";
  
  if (this->head != NULL) {
    result += this->head->toString();
  }
  return result + this->inst->toString();
}

void NodeActions::printTree(vector<bool> *identation) {
  cout << "\e[1;34mAction\e[0m\n";

  if (this->head != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->printTree(identation);
    identation->pop_back();
  }

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->inst->printTree(identation);
  identation->pop_back();
}

/* ======================= INSTRUCTION NODES =======================  */
NodeAssign::NodeAssign(Node *lvalue, Node *rvalue) {
  this->lvalue = lvalue;
  this->rvalue = rvalue;
}

void NodeAssign::print(void) {
  this->lvalue->print();
  cout << " = ";
  this->rvalue->print();
  cout << ";\n";
}

string NodeAssign::toString(void) {
  return this->lvalue->toString() + " = " +this->rvalue->toString() + ";";
}

void NodeAssign::printTree(vector<bool> *identation) {
  cout << "\e[1;34mAssignment\e[0m\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->lvalue->printTree(identation);
  identation->pop_back();

  printIdentation(identation);
  cout << "├── =\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->rvalue->printTree(identation);
  identation->pop_back();
}

NodeI::NodeI(Node *head, Node *inst) {
  this->head = head;
  this->inst = inst;
}

void NodeI::print(void) {
  if (this->head != NULL) {
    this->head->print();
  }
  this->inst->print();
}

string NodeI::toString(void) {
  
  string result = "";
  
  if (this->head != NULL) {
    result += this->head->toString();
  }
  return result + this->inst->toString();
}

void NodeI::printTree(vector<bool> *identation) {
  cout << "\e[1;34mI\e[0m\n";
  if (this->head != NULL) {
    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->head->printTree(identation);
    identation->pop_back();
  }
  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->inst->printTree(identation);
  identation->pop_back();
}

NodeS::NodeS(Node *inst) {
  this->inst = inst;
}

void NodeS::print(void) {
  if (this->inst != NULL) {
    this->inst->print();
  }
}

string NodeS::toString(void) {
  
  string result = "";

  if (this->inst != NULL) {
    result += this->inst->toString();
  }

  return result;
}

void NodeS::printTree(vector<bool> *identation) {
  cout << "\e[1;34mS\e[0m\n";
  vector<bool> *new_identation = new vector<bool>;
  new_identation->push_back(false);
  if (this->inst != NULL) {
    cout << "└── ";
    this->inst->printTree(new_identation);
  }
}

/* ======================= TYPE NODES =======================  */
PrimitiveType::PrimitiveType(string id) {
  this->id = id;
}

void PrimitiveType::print(void) {
  cout << this->toString();
}

string PrimitiveType::toString(void) {
  return this->id;
}

void PrimitiveType::printTree(vector<bool> *identation) {
  cout << "Primitive Type: " << this->id << "\n";
}

PointerType::PointerType(Type *type) {
  this->type = type;
}

void PointerType::print(void) {
  cout << "^(";
  this->type->print();
  cout << ")";
}

string PointerType::toString(void) {
  return "^(" + this->type->toString() + ")";
}

void PointerType::printTree(vector<bool> *identation) {
  cout << "\e[1;34mType Pointer\e[0m\n";

  printIdentation(identation);
  cout << "├── ^\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->type->printTree(identation);
  identation->pop_back();
}

ArrayType::ArrayType(Type *type, Node *size) {
  this->type = type;
  this->size = size;
}

void ArrayType::print(void) {
  cout << "(";
  this->type->print();
  cout << ")[";
  this->size->print();
  cout << "]";
}

string ArrayType::toString(void) {
  return "(" + this->type->toString() + ")[" + this->size->toString() + "]";
}

void ArrayType::printTree(vector<bool> *identation) {
  cout << "\e[1;34mType Array\e[0m\n";

  printIdentation(identation);
  identation->push_back(true);
  cout << "├── ";
  this->type->printTree(identation);
  identation->pop_back();

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── \e[1;34mSize: \e[0m";
  this->size->printTree(identation);
  identation->pop_back();
}
