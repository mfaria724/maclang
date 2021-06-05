#include <string>
#include <iostream>

using namespace std;

/*
  "Abstract" class that is parent of all nodes classes in the 
  Abstract Syntax Tree.
*/
class node {
  public:
    node() {};
    // Print a node representation.
    virtual void print(void) { };
};

/* ======================= DATA NODES =======================  */
class node_BOOL : public node {
  protected:
    bool value;

  public:
    node_BOOL(bool value);

    void print(void);
};

class node_CHAR : public node {
  protected:
    char value;

  public:
    node_CHAR(char value);

    void print(void);
};

class node_INT : public node {
  protected:
    int value;

  public:
    node_INT(int value);

    void print(void);
};

class node_FLOAT : public node {
  protected:
    float value;

  public:
    node_FLOAT(float value);

    void print(void);
};

class node_STRING : public node {
  protected:
    string value;

  public:
    node_STRING(string value);

    void print(void);
};

/* ======================= EXPRESSION NODES =======================  */
/* Representation o binary operators. */
class node_BinaryOperator : public node {
  protected:
    node* left;
    string op;
    node* right;

  public:
    node_BinaryOperator(node *left, string op, node *rigth);

    void print(void);
};

/* Representation of unary operations. */
class node_UnaryOperator : public node {
  protected:
    string op;
    node *exp;

  public:
    node_UnaryOperator(string op, node *exp);

    void print(void);
};

/* ======================= TYPEDEF NODES =======================  */
/* Class for defined types. */
class node_TypePrimitiveDef : public node {
  protected:
    string id;

  public:
    node_TypePrimitiveDef(string id);

    void print(void);
};

/* Representation of  -> ^ Type. */
class node_TypePointerDef : public node {
  protected:
    node *type;

  public:
    node_TypePointerDef(node *type);

    void print(void);
};

/* Representation of  -> Type [ Exp ]. */
class node_TypeArrayDef : public node {
  protected:
    node *type;
    node *size;

  public:
    node_TypeArrayDef(node *type, node *size);

    void print(void);
};

/* Representation of  -> Type ID = RValue. */
class node_VarDef : public node {
  protected:
    node *type;
    string id;
    node *rvalue;

  public:
    node_VarDef(node *type, string id, node *rvalue = NULL);

    void print(void);
};

/* ======================= LVALUE NODES =======================  */
/* Class for defined id lvalues. */
class node_IDLValue : public node {
  protected:
    string id;

  public:
    node_IDLValue(string id);

    void print(void);
};

/* Representation of  -> LValue . ID. */
class node_DotLValue : public node {
  protected:
    node *lvalue;
    string id;

  public:
    node_DotLValue(node *lvalue, string id);

    void print(void);
};

/* Representation of  -> ^ LValue. */
class node_PointerLValue : public node {
  protected:
    node *lvalue;

  public:
    node_PointerLValue(node *lvalue);

    void print(void);
};

/* Representation of  -> LValue [ Exp ]. */
class node_ArrayLValue : public node {
  protected:
    node *lvalue;
    node *size;

  public:
    node_ArrayLValue(node *lvalue, node *size);

    void print(void);
};

/* ======================= ARRAY NODES =======================  */
/* Representation of arrays. */
class node_Array : public node {
  protected:
    node *elems;

  public:
    node_Array(node *elems);

    void print(void);
};

/* Representation of  ->  RValue , ArrElems. */
class node_ArrayElems : public node {
  protected:
    node *rvalue;
    node *head;

  public:
    node_ArrayElems(node *rvalue, node *head = NULL);

    void print(void);
};

/* ======================= FUNCTION CALL NODES ======================= */
class node_FunctionCall : public node {
  protected:
    string id;
    node *args;
    bool end_inst;

  public:
    node_FunctionCall(string id, node *args, bool end_inst);

    void print(void);
};

class node_FunctionArgs : public node {
  protected:
    node *rvalue;
    node *head;

  public:
    node_FunctionArgs(node *rvalue, node *head = NULL);

    void print(void);
}

/* ======================= INSTRUCTIONS NODES =======================  */


/* Representacion of  -> I Inst */
class node_I : public node {
  protected:
    node *inst;
    node *next;

  public:
    node_I(node *inst, node *next = NULL);

    void print(void);
};

/* Root node. */
class node_S {
  protected:
    node *inst;

  public:
    node_S(node *inst);

    void print(void);
};
