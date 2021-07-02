#ifndef AST
#define AST

#include <string>
#include <vector>
#include "ast.hpp"

using namespace std;

/*
  "Abstract" class that is parent of all type classes.
*/
class Type {
  public:
    Type(void) {};

    virtual void print(void);

    virtual void printTree(vector<bool> *identation);
};

/* Class for defined types. */
class Primitive : public Type {
  protected:
    string id;

  public:
    Primitive(string id);

    void print(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> ^ Type. */
class Pointer : public Type {
  protected:
    Type *type;

  public:
    Pointer(Type *type);

    void print(void);

    void printTree(vector<bool> *identation);
};

/* Representation of  -> Type [ Exp ]. */
class Array : public Type {
  protected:
    Type *type;
    Node *size;

  public: 
    Array(Type *type, Node *size);

  void print(void);

  void printTree(vector<bool> *identation);
};

#endif
