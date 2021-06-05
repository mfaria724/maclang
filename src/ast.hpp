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
/* Representation of function calls. */
class node_FunctionCall : public node {
  protected:
    string id;
    node *args;
    bool end_inst;

  public:
    node_FunctionCall(string id, node *args, bool end_inst);

    void print(void);

    void set_end_inst(void);
};

/* Representation of  ->  RValue , FuncArgs. */
class node_FunctionCallArgs : public node {
  protected:
    node *rvalue;
    node *head;

  public:
    node_FunctionCallArgs(node *rvalue, node *head = NULL);

    void print(void);
};

/* ======================= UNION DEF NODES ======================= */
/* Representation of union definitions. */
class node_UnionDef : public node {
  protected:
    string id;
    node *fields;

  public:
    node_UnionDef(string id, node *fields);

    void print(void);
};

/* Representation of  -> UnionBody Type ID ;  */
class node_UnionFields : public node {
  protected:
    node *head;
    node *field;

  public:
    node_UnionFields(node *head, node *field);

    void print(void);
};

/* ======================= REGISTER DEF NODES ======================= */
/* Representation of register definitions. */
class node_RegDef : public node {
  protected:
    string id;
    node *fields;

  public:
    node_RegDef(string id, node *fields);

    void print(void);
};

/* Representation of  -> RegisterBody VarDefBody;  */
class node_RegFields : public node {
  protected:
    node *head;
    node *type;
    string id;
    node *rvalue;

  public:
    node_RegFields(node *head, node *type, string id, node *rvalue);

    void print(void);
};

/* ======================= CONDITIONAL DEF NODES ======================= */
/* Representation of if-elsif-else blocks. */
class node_Conditional : public node {
  protected:
    node *cond;
    node *body;
    node *elsifs;
    node *else_def;

  public:
    node_Conditional(node *cond, node *body, node *elsifs, node *else_def);

    void print(void);
};

/* Representation of  -> Elsifs elsif Exp then I. */
class node_Elsif : public node {
  protected:
    node *head;
    node *cond;
    node *body;

  public:
    node_Elsif(node *head, node *cond, node *body);

    void print(void);
};

/* Representation of  -> else I. */
class node_Else : public node {
  protected:
    node *body;

  public:
    node_Else(node *body);

    void print(void);
};

/* ======================= LOOP NODES =======================  */
/* Representation of while blocks. */
class node_While : public node {
  protected:
    node *cond;
    node *body;

  public:
    node_While(node *cond, node *body);

    void print(void);
};

/* Representation of for blocks. */
class node_For : public node {
  protected:
    string iter;
    node *begin;
    node *end;
    node *step;
    node *body;

  public:
    node_For(string iter, node *begin, node *end, node *step, node *body);

    void print(void);
};

/* ======================= SUBROUTINE DEF NODES =======================  */
/* Representation of routine definitions. */
class node_RoutineDef : public node {
  protected:
    string id;
    node *args;
    node *ret;
    node *body;

  public:
    node_RoutineDef(string id, node *args, node *ret, node *body);

    void print(void);
};

class node_RoutArgsDef : public node {
  protected:
    node *head;
    node *type;
    bool ref;
    string id;
    node *rvalue;

  public:
    node_RoutArgsDef(node *head, node *type, bool ref, string id, node *rvalue);

    void print(void);
};

/* Representacion of  -> Actions Action */
class node_Actions : public node {
  protected:
    node *head;
    node *inst;

  public:
    node_Actions(node *head, node *inst);

    void print(void);
};

/* ======================= INSTRUCTION NODES =======================  */
class node_Assign : public node {
  protected:
    node *lvalue;
    node *rvalue;

  public:
    node_Assign(node *lvalue, node *rvalue);

    void print(void);
};

/* Representacion of  -> I Inst */
class node_I : public node {
  protected:
    node *head;
    node *inst;

  public:
    node_I(node *head, node *inst);

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
