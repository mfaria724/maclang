#include <iostream>

using namespace std;

Primitive::Primitive(string id) {
  this->id = id;
}

void Primitive::print(void) {
  cout << this->id;
}

void Primitive::print(void) {
  cout << this->id;
}

void Primitive::printTree(vector<bool> *identation) {
  cout << "Primitive Type: " << this->id << "\n";
}

Pointer::Pointer(Type *type) {
  this->type = type;
}

void Pointer::print(void) {
  cout << "^(";
  this->type->print();
  cout << ")";
}

void Pointer::printTree(vector<bool> *identation) {
  cout << "\e[1;34mType Pointer\e[0m\n";

  printIdentation(identation);
  cout << "├── ^\n";

  printIdentation(identation);
  identation->push_back(false);
  cout << "└── ";
  this->type->printTree(identation);
  identation->pop_back();
}

Array::Array(Type *type, Node *size) {
  this->type = type;
  this->size = size;
}

void Array::print(void) {
  cout << "(";
  this->type->print();
  cout << ")[";
  this->size->print();
  cout << "]";
}

void Array::printTree(vector<bool> *identation) {
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
