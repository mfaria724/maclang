#include <string>

using namespace std;

class node {

  public:
    node() {};
    virtual void inOrder(void);

};

class node_INT : public node {

  protected:
    int value;

  public:
    node_INT(int value);

};

class node_TypeDef : public node {

  public:
    node_TypeDef(void) {};

};

class node_TypePrimitiveDef : public node_TypeDef {

  protected:
    string id;

  public:
    node_TypePrimitiveDef(string id);

};

class node_TypePointerDef : public node_TypeDef {

  protected:
    node *type;

  public:
    node_TypePointerDef(node *type);

};

class node_TypeArrayDef : public node_TypeDef {

  protected:
    node *type;
    node *size;

  public:
    node_TypeArrayDef(node *type, node *size);

};

class node_VarDef : public node {

  protected:
    node *type;
    string id;
    node *rvalue;

  public:
    node_VarDef(node *type, string id, node *rvalue = NULL);

};

class node_I : public node {

  protected:
    node *inst;
    node *next;

  public:
    node_I(node *inst, node *next = NULL);

};

class node_S {

  protected:
    node *inst;

  public:
    node_S(node *inst);

};
