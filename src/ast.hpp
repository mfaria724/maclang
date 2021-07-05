#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
  "Abstract" class that is parent of all nodes classes in the 
  Abstract Syntax Tree.
*/
class Node {
  public:
    Node(void) {};
    // Print a node representation.
    virtual void print(void) {};
    // Returns a string representation of the sub-ast.
    virtual string toString(void) { return ""; };
    // Print a tree representation of the sub-ast.
    virtual void printTree(vector<bool> *identation) {};
};

/*
  "Abstract" class that is parent of all type classes.
*/
class Type {
  public:
    Type(void) {};
    // Print a node representation.
    virtual void print(void) {};
    // Returns a string representation of the sub ast.
    virtual string toString(void) { return ""; };
    // Print a tree representation of the sub-ast.
    virtual void printTree(vector<bool> *identation) {};
};

class ExpressionNode : public Node {

  public: 
    string type;

    ExpressionNode(void) {};

    virtual void print(void) {};

    virtual string toString(void) { return ""; };
    
    virtual void printTree(vector<bool> *identation) {};
};

/* ======================= DATA NODES =======================  */
class NodeBOOL : public ExpressionNode {
  protected:
    bool value;

  public:
    NodeBOOL(bool value);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

class NodeCHAR : public ExpressionNode {
  protected:
    char value;

  public:
    NodeCHAR(char value);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

class NodeINT : public ExpressionNode {
  protected:
    int value;

  public:
    NodeINT(int value);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

class NodeFLOAT : public ExpressionNode {
  protected:
    float value;

  public:
    NodeFLOAT(float value);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

class NodeSTRING : public ExpressionNode {
  protected:
    string value;

  public:
    NodeSTRING(string value);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= EXPRESSION NODES =======================  */
/* Representation o binary operators. */
class NodeBinaryOperator : public ExpressionNode {
  protected:
    Node *left;
    string op;
    Node *right;

  public:
    NodeBinaryOperator(Node *left, string op, Node *rigth, string type);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of unary operations. */
class NodeUnaryOperator : public ExpressionNode {
  protected:
    string op;
    Node *exp;

  public:
    NodeUnaryOperator(string op, Node *exp, string type);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= HEAP NODES =======================  */
/* Representation of  -> new Type. */
class NodeNew : public Node {
  protected:
    Type *type;

  public:
    NodeNew(Type *type);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> forget Type. */
class NodeForget : public Node {
  protected:
    Node *lvalue;

  public:
    NodeForget(Node *lvalue);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= TYPEDEF NODES =======================  */
/* Representation of  -> Type ID = RValue. */
class NodeVarDef : public Node {
  protected:
    Type *type;
    string id;
    Node *rvalue;

  public:
    NodeVarDef(Type *type, string id, Node *rvalue = NULL);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= LVALUE NODES =======================  */
/* Class for defined id lvalues. */
class NodeIDLValue : public ExpressionNode {
  protected:
    string id;

  public:
    NodeIDLValue(string id, string type);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> LValue . ID. */
class NodeDotLValue : public ExpressionNode {
  protected:
    Node *lvalue;
    string id;

  public:
    NodeDotLValue(Node *lvalue, string id, string type);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> ^ LValue. */
class NodePointerLValue : public ExpressionNode {
  protected:
    Node *lvalue;

  public:
    NodePointerLValue(Node *lvalue, string type);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> LValue [ Exp ]. */
class NodeArrayLValue : public ExpressionNode {
  protected:
    Node *lvalue;
    Node *size;

  public:
    NodeArrayLValue(Node *lvalue, Node *size, string type);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= ARRAY NODES =======================  */
/* Representation of arrays. */
class NodeArray : public Node {
  protected:
    Node *elems;

  public:
    NodeArray(Node *elems);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  ->  RValue , ArrElems. */
class NodeArrayElems : public Node {
  protected:
    Node *rvalue;
    Node *head;

  public:
    NodeArrayElems(Node *rvalue, Node *head = NULL);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= FUNCTION CALL NODES ======================= */
/* Representation of function calls. */
class NodeFunctionCall : public ExpressionNode {
  protected:
    string id;
    Node *args;
    bool bEndInst;

  public:
    NodeFunctionCall(string id, Node *args, bool bEndInst, string type);

    void print(void);

    void printTree(vector<bool> *identation);

    string toString(void);

    void setEndInst(void);
};

/* Representation of  ->  RValue , FuncArgs. */
class NodeFunctionCallArgs : public Node {
  protected:
    Node *head;
    Node *rvalue;

  public:
    NodeFunctionCallArgs(Node *head, Node *rvalue);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= UNION DEF NODES ======================= */
/* Representation of union definitions. */
class NodeUnionDef : public Node {
  protected:
    string id;
    Node *fields;

  public:
    NodeUnionDef(string id, Node *fields);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> UnionBody Type ID ;  */
class NodeUnionFields : public Node {
  protected:
    Node *head;
    Type *type;
    string id;

  public:
    NodeUnionFields(Node *head, Type *type, string id);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= REGISTER DEF NODES ======================= */
/* Representation of register definitions. */
class NodeRegDef : public Node {
  protected:
    string id;
    Node *fields;

  public:
    NodeRegDef(string id, Node *fields);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> RegisterBody VarDefBody;  */
class NodeRegFields : public Node {
  protected:
    Node *head;
    Type *type;
    string id;
    Node *rvalue;

  public:
    NodeRegFields(Node *head, Type *type, string id, Node *rvalue);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= CONDITIONAL DEF NODES ======================= */
/* Representation of if-elsif-else blocks. */
class NodeConditional : public Node {
  protected:
    Node *cond;
    Node *body;
    Node *elsifs;
    Node *elseDef;

  public:
    NodeConditional(Node *cond, Node *body, Node *elsifs, Node *elseDef);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> Elsifs elsif Exp then I. */
class NodeElsif : public Node {
  protected:
    Node *head;
    Node *cond;
    Node *body;

  public:
    NodeElsif(Node *head, Node *cond, Node *body);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> else I. */
class NodeElse : public Node {
  protected:
    Node *body;

  public:
    NodeElse(Node *body);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= LOOP NODES =======================  */
/* Representation of while blocks. */
class NodeWhile : public Node {
  protected:
    Node *cond;
    Node *body;

  public:
    NodeWhile(Node *cond, Node *body);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of for blocks. */
class NodeFor : public Node {
  protected:
    string iter;
    Node *begin;
    Node *end;
    Node *step;
    Node *body;

  public:
    NodeFor(string iter, Node *begin, Node *end, Node *step, Node *body);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= SUBROUTINE DEF NODES =======================  */
/* Representation of routine definitions. */
class NodeRoutineDef : public Node {
  protected:
    string id;
    Node *args;
    Type *ret;
    Node *body;

  public:
    NodeRoutineDef(string id, Node *args, Type *ret, Node *body);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

class NodeRoutArgs : public Node {
  protected:
    Node *oblArgs;
    Node *optArgs;

  public:
    NodeRoutArgs(Node *oblArgs, Node *optArgs);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

class NodeRoutArgDef : public Node {
  protected:
    Node *head; 
    Type *type; 
    bool ref; 
    string id; 
    Node *rvalue;

  public:
    NodeRoutArgDef(Node *head, Type *type, bool ref, string id, Node *rvalue);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representacion of  -> Actions Action */
class NodeActions : public Node {
  protected:
    Node *head;
    Node *inst;

  public:
    NodeActions(Node *head, Node *inst);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= INSTRUCTION NODES =======================  */
class NodeAssign : public Node {
  protected:
    Node *lvalue;
    Node *rvalue;

  public:
    NodeAssign(Node *lvalue, Node *rvalue);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representacion of  -> I Inst */
class NodeI : public Node {
  protected:
    Node *head;
    Node *inst;

  public:
    NodeI(Node *head, Node *inst);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Root node. */
class NodeS {
  protected:
    Node *inst;

  public:
    NodeS(Node *inst);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* ======================= TYPE NODES =======================  */
/* Class for defined types. */
class PrimitiveType : public Type {
  protected:
    string id;

  public:
    PrimitiveType(string id);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> ^ Type. */
class PointerType : public Type {
  protected:
    Type *type;

  public:
    PointerType(Type *type);

    void print(void);

    string toString(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> Type [ Exp ]. */
class ArrayType : public Type {
  protected:
    Type *type;
    Node *size;

  public: 
    ArrayType(Type *type, Node *size);

  void print(void);

  string toString(void);

  void printTree(vector<bool> *identation);
};
