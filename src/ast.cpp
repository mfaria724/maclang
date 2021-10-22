#include "ast.hpp"

/* ======================= AUXILIARY FUNCTIONS ======================= */
  void printIdentation(vector<bool> *identation) {
    for (bool b : *identation) {
      if (b) cout << "│";
      else cout << " ";
      cout << "   ";
    }
  }

  map<string, int> primitiveWidths = {
    {"Unit",    1},
    {"Bool",    1},
    {"Char",    8},   // Unicode use 8 bits
    {"Int",     8},
    {"Float",   8},
    {"Pointer", 8},
    {"$Error",  0}
  };

  // Predefined Types 
  map<string, Type*> predefinedTypes = {
    {"Unit",    new PrimitiveType("Unit")},
    {"Bool",    new PrimitiveType("Bool")},
    {"Char",    new PrimitiveType("Char")},
    {"Int",     new PrimitiveType("Int")},
    {"Float",   new PrimitiveType("Float")},
    {"$Error",  new PrimitiveType("$Error")}
  };


/* ======================= TYPES ===================================== */
  PrimitiveType::PrimitiveType(string id) {
    this->id = id;
    this->width = primitiveWidths[id];
    this->category = "Primitive";
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
    this->width = primitiveWidths["Pointer"];
    this->category = "Pointer";
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


  ArrayType::ArrayType(Type *type, ExpressionNode *size) {
    this->type = type;
    this->size = size;
    string t_size = type->toString();
    // Si size es un literal, podemos calcular directamente el desplazamiento.
    if (size->is_lit) {
      this->width = type->width * ((NodeINT*) size)->value;
    }
    // En caso contrario, se tomara como un puntero.
    else {
      this->width = primitiveWidths["Pointer"];
    }
    this->category = "Array";
  }
  void ArrayType::print(void) {
    cout << "(";
    this->type->print();
    cout << ")[";
    this->size->print();
    cout << "]";
  }
  string ArrayType::toString(void) {
    return "(" + this->type->toString() + ")[]";
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


/* ======================= BASIC NODES =============================== */
  NodeAssign::NodeAssign(Node *lvalue, Node *rvalue) {
    this->lvalue = lvalue;
    this->rvalue = rvalue;
    this->is_lvalue = false;
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


  NodeAssignList::NodeAssignList(Node *head, Node *assign) {
    this->head = head;
    this->assign = assign;
  }
  void NodeAssignList::print(void) {
    if (this->head != NULL) {
      this->head->print();
    }
    this->assign->print();
  }
  string NodeAssignList::toString(void) {
    
    string result = "";
    
    if (this->head != NULL) {
      result += this->head->toString();
    }
    return result + this->assign->toString();
  }
  void NodeAssignList::printTree(vector<bool> *identation) {
    cout << "\e[1;34mAssignment List\e[0m\n";
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
    this->assign->printTree(identation);
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


/* ======================= DATA NODES ================================ */
  NodeBOOL::NodeBOOL(bool value) {
    this->value = value;
    this->type = predefinedTypes["Bool"];
    this->is_lvalue = false;
    this->is_lit = true;
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
    this->type = predefinedTypes["Char"];
    this->is_lvalue = false;
    this->is_lit = true;
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


  NodeINT::NodeINT(int value, bool defineType) {
    this->value = value;
    this->type = predefinedTypes["Int"];
    this->is_lvalue = false;
    this->is_lit = true;
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
    this->type = predefinedTypes["Float"];
    this->is_lvalue = false;
    this->is_lit = true;
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
    this->type = new PointerType(predefinedTypes["Char"]);
    this->is_lvalue = false;
    this->is_lit = false;
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


/* ======================= OPERATTION NODES ========================== */
  NodeBinaryOperator::NodeBinaryOperator(
    Node *left, 
    string op, 
    Node *right, 
    Type *type
  ) {
    this->left = left;
    this->op = op;
    this->right = right;
    this->type = type;
    this->is_lvalue = false;
    this->is_lit = false;
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


  NodeUnaryOperator::NodeUnaryOperator(string op, Node *exp, Type *type) {
    this->op = op;
    this->exp = exp;
    this->type = type;
    this->is_lvalue = false;
    this->is_lit = false;
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


  NodeID::NodeID(string id, Type *type) {
    this->id = id;
    this->type = type;
    this->is_lvalue = true;
    this->is_lit = false;
  }
  void NodeID::print(void) {
    cout << this->id;
  }
  string NodeID::toString(void) {
    return this->id;
  }
  void NodeID::printTree(vector<bool> *identation) {
    cout << "ID: " << this->id << "\n";
  }


  NodeDot::NodeDot(Node *structure, string id, Type *type) {
    this->structure = structure;
    this->id = id;
    this->type = type;
    this->is_lvalue = true;
    this->is_lit = false;
  }
  void NodeDot::print(void) {
    cout << "(";
    this->structure->print();
    cout << ")." << this->id;
  }
  string NodeDot::toString(void) {
    return "(" + this->structure->toString() + ")." + this->id;
  }
  void NodeDot::printTree(vector<bool> *identation) {
    cout << "\e[1;34mField Access\e[0m\n";

    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->structure->printTree(identation);
    identation->pop_back();

    printIdentation(identation);
    cout << "└── Field: " << this->id << "\n"; 
  }


  NodePointer::NodePointer(Node *pointer, Type *type) {
    this->pointer = pointer;
    this->type = type;
    this->is_lvalue = true;
    this->is_lit = false;
  }
  void NodePointer::print(void) {
    cout << "^(";
    this->pointer->print();
    cout << ")";
  }
  string NodePointer::toString(void) {
    return "^(" + this->pointer->toString() + ")";
  }
  void NodePointer::printTree(vector<bool> *identation) {
    cout << "\e[1;34mDesreferentation\e[0m\n";

    printIdentation(identation);
    cout << "├── ^\n";

    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->pointer->printTree(identation);
    identation->pop_back();
  }


  NodeArrayAccess::NodeArrayAccess(Node *array, Node *index, Type *type) {
    this->array = array;
    this->index = index;
    this->type = type;
    this->is_lvalue = true;
    this->is_lit = false;
  }
  void NodeArrayAccess::print(void) {
    cout << "(";
    this->array->print();
    cout << ")[";
    this->index->print();
    cout << "]";
  }
  string NodeArrayAccess::toString(void) {
    return "(" + this->array->toString() + ")[" + this->index->toString() + "]";
  }
  void NodeArrayAccess::printTree(vector<bool> *identation) {
    cout << "\e[1;34mArray Access\e[0m\n";

    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->array->printTree(identation);
    identation->pop_back();

    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->index->printTree(identation);
    identation->pop_back();
  }


/* ======================= HEAP NODES ================================ */
  NodeNew::NodeNew(Type *type_pointer) {
    this->type_pointer = type_pointer;
    this->type = new PointerType(type_pointer);
    this->is_lvalue = false;
    this->is_lit = false;
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


/* ======================= ARRAY NODES =============================== */
  NodeArray::NodeArray(Node *elems, Type *type) {
    this->elems = elems;
    this->type = type;
    this->is_lvalue = false;
    this->is_lit = false;
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


  NodeArrayElems::NodeArrayElems(Node *head, Type *type, Node *rvalue, int current_size) {
    this->head = head;
    this->rvalue = rvalue;
    this->type = type;
    this->current_size = current_size;
    this->is_lit = false;
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
    Type *type
  ) {
    this->id = id;
    this->args = args;
    this->bEndInst = bEndInst;
    this->type = type;
    this->is_lvalue = true;
    this->is_lit = false;
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


  NodeFunctionCallArgs::NodeFunctionCallArgs(Node* positional, Node* named) {
    this->positional = positional;
    this->named = named;
  }
  void NodeFunctionCallArgs::print(void) {
    if (this->positional != NULL) {
      this->positional->print();
      if (this->named != NULL) {
        cout << ", ";
        this->named->print();
      }
    } else if (this->named != NULL) {
      this->named->print();
    }
  }
  string NodeFunctionCallArgs::toString(void) {
    string result = "";

    if (this->positional != NULL) {
      result += this->positional->toString();
      if (this->named != NULL) {
        result += ", " + this->named->toString();
      }
    } else if (this->named != NULL) {
      result += this->named->toString();
    }

    return result;
  }
  void NodeFunctionCallArgs::printTree(vector<bool> *identation) {
    cout << "\e[1;34mRoutine Parameters\e[0m\n";

    if ((this->positional != NULL) && (this->named != NULL)) {
      printIdentation(identation);
      identation->push_back(true);
      cout << "├── ";
      this->positional->printTree(identation);
      identation->pop_back();

      printIdentation(identation);
      identation->push_back(false);
      cout << "└── ";
      this->named->printTree(identation);
      identation->pop_back();

    } else if (this->positional != NULL){
      printIdentation(identation);
      identation->push_back(false);
      cout << "└── ";
      this->positional->printTree(identation);
      identation->pop_back(); 

    } else if (this->named != NULL){
      printIdentation(identation);
      identation->push_back(false);
      cout << "└── ";
      this->named->printTree(identation);
      identation->pop_back(); 

    }
  }


  NodeFunctionCallPositionalArgs::NodeFunctionCallPositionalArgs(Node *head, Node *rvalue) {
    this->head = head;
    this->rvalue = rvalue;
  }
  void NodeFunctionCallPositionalArgs::print(void) {
    if (this->head != NULL) {
      this->head->print();
      cout << ", ";
    }
    this->rvalue->print();
  }
  string NodeFunctionCallPositionalArgs::toString(void) {
    string result = "";

    if (this->head != NULL) {
      result += this->head->toString() + ", ";
    }
    return result + this->rvalue->toString();
  }
  void NodeFunctionCallPositionalArgs::printTree(vector<bool> *identation) {
    cout << "\e[1;34mPositional Parameter\e[0m\n";

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


  NodeFunctionCallNamedArgs::NodeFunctionCallNamedArgs(
    Node *head, 
    string id, 
    Node *rvalue
  ) {
    this->head = head;
    this->id = id;
    this->rvalue = rvalue;
  }
  void NodeFunctionCallNamedArgs::print(void) {
    if (this->head != NULL) {
      this->head->print();
      cout << ", ";
    }
    cout << this->id + " = ";
    this->rvalue->print();
  }
  string NodeFunctionCallNamedArgs::toString(void) {
    string result = "";

    if (this->head != NULL) {
      result += this->head->toString() + ", ";
    }
    result = this->id + " = ";
    return result + this->rvalue->toString();
  }
  void NodeFunctionCallNamedArgs::printTree(vector<bool> *identation) {
    cout << "\e[1;34mNamed Parameter\e[0m\n";

    if (this->head != NULL) {
      printIdentation(identation);
      identation->push_back(true);
      cout << "├── ";
      this->head->printTree(identation);
      identation->pop_back();
    }

    printIdentation(identation);
    cout << "├── ID: " + this->id + "\n";

    printIdentation(identation);
    identation->push_back(false);
    cout << "└── ";
    this->rvalue->printTree(identation);
    identation->pop_back();
  }


/* ======================= STRUCTURE DEF NODES ======================= */
  NodeUnionFields::NodeUnionFields(Node *head, Type *type, string id) {
    this->head = head;
    this->type = type;
    this->id = id;
  }

  NodeRegFields::NodeRegFields(Node *head, Type *type, string id, Node *rvalue) {
    this->head = head;
    this->type = type;
    this->id = id;
    this->rvalue = rvalue;
  }


/* ======================= CONDITIONAL DEF NODES ===================== */
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


/* ======================= LOOP NODES ================================ */
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


/* ======================= SUBROUTINE DEF NODES ====================== */
  NodeRoutineDef::NodeRoutineDef(Node *sign, Node *body) {
    this->sign = sign;
    this->body = body;
  }
  void NodeRoutineDef::print(void) {
    this->sign->print();
    cout << " {\n";
    if (this->body != NULL) {
      this->body->print();
    }
    cout << "}\n";
  }
  string NodeRoutineDef::toString(void) {
    string result = this->sign->toString();
    result += " { ";
    if (this->body != NULL) {
      result += this->body->toString();
    }
    return result + "}";
  }
  void NodeRoutineDef::printTree(vector<bool> *identation) {
    cout << "\e[1;34mRoutine Definition\e[0m\n";

    printIdentation(identation);
    identation->push_back(true);
    cout << "├── ";
    this->sign->printTree(identation);
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


  NodeRoutineSign::NodeRoutineSign(string id, Node *args, Type *ret) {
    this->id = id;
    this->args = args;
    this->ret = ret;
  }
  void NodeRoutineSign::print(void) {
    cout << this->id << " (";
    if (this->args != NULL) {
      this->args->print();
    }
    cout << ") ";
    if (this->ret != NULL) {
      cout << "=> ";
      this->ret->print();
    }
  }
  string NodeRoutineSign::toString(void) {
    string result = this->id + " (";
    if (this->args != NULL) {
      result += this->args->toString();
    }
    result += ") ";
    if (this->ret != NULL) {
      result += "=> " + this->ret->toString();
    }

    return result;
  }
  void NodeRoutineSign::printTree(vector<bool> *identation) {
    cout << "\e[1;34mRoutine Sign \e[0m\n";

    printIdentation(identation);
    cout << "├── ID: " << this->id << "\n";

    if (this->args != NULL) {
      printIdentation(identation);
      identation->push_back(true);
      cout << "├── ";
      this->args->printTree(identation);
      identation->pop_back();
    } else {
      printIdentation(identation);
      cout << "├── \e[1;34mParameters: \e[0mNULL\n";
    }

    if (this->ret != NULL) {
      printIdentation(identation);
      identation->push_back(false);
      cout << "└── \e[1;34mReturn Type: \e[0m";
      this->ret->printTree(identation);
      identation->pop_back();
    } else {
      printIdentation(identation);
      cout << "└── \e[1;34mReturn Type: \e[0mNULL\n";
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

    } else if (this->optArgs != NULL){
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


  NodeReturn::NodeReturn(Node *rvalue) {
    this->rvalue = rvalue;
  }
  void NodeReturn::print(void) {
    cout << "return ";
    if (this->rvalue != NULL) {
      this->rvalue->print();
    }
    cout << ";\n";
  }
  string NodeReturn::toString(void) {
    string result = "return ";
    
    if (this->rvalue != NULL) {
      result += this->rvalue->toString();
    }
    return result;
  }
  void NodeReturn::printTree(vector<bool> *identation) {
    cout << "\e[1;34mReturn\e[0m\n";

    if (this->rvalue != NULL) {
      printIdentation(identation);
      identation->push_back(true);
      cout << "├── ";
      this->rvalue->printTree(identation);
      identation->pop_back();
    } else {
      printIdentation(identation);
      cout << "├── Unit\n";
    }
  }
