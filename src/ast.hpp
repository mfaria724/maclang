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

/* ======================= DATATYPES NODES =======================  */
class node_INT : public node {
  protected:
    int value;

  public:
    node_INT(int value);

    void print(void);
};

class node_UNIT : public node {
  protected:
    int value;

  public:
    node_UNIT(int value);

    void print(void);
};

/* ======================= TYPEDEF NODES =======================  */
/* "Abstract" class that is parent of all type def nodes classes. */
class node_TypeDef : public node {
  public:
    node_TypeDef(void) {};
};

/* Class for defined types. */
class node_TypePrimitiveDef : public node_TypeDef {
  protected:
    string id;

  public:
    node_TypePrimitiveDef(string id);

    void print(void);
};

/* Representation of  -> ^ Type. */
class node_TypePointerDef : public node_TypeDef {
  protected:
    node *type;

  public:
    node_TypePointerDef(node *type);

    void print(void);
};

/* Representation of  -> Type [ Exp ]. */
class node_TypeArrayDef : public node_TypeDef {
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


/* ======================= GENERIC INSTRUCTIONS NODES =======================  */
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
