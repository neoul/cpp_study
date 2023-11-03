#include <iostream>
#include <typeinfo>
using namespace std;

struct A { virtual ~A() { } };
struct B : A { };

struct C { };
struct D : C { };

void use_typeinfo() {
  B bobj;
  A* ap = &bobj;
  A& ar = bobj;
  cout << "ap: " << typeid(*ap).name() << endl;
  cout << "ar: " << typeid(ar).name() << endl;

  D dobj;
  C* cp = &dobj;
  C& cr = dobj;
  cout << "cp: " << typeid(*cp).name() << endl;
  cout << "cr: " << typeid(cr).name() << endl;
  cout << "typeid(uint32_t) " << typeid(uint32_t).hash_code() << endl;
  uint32_t x = 10;
  // bool y = typeid(x).hash_code() == typeid(x);
  cout << "typeid(uint32_t) " << typeid(x).hash_code() << endl;
  // cout << "typeid(uint32_t) " << y << endl;
  cout << "typeid(const char *) " << typeid(const char *).hash_code() << endl;
  cout << "typeid(char *) " << typeid(char *).hash_code() << endl;
  cout << "typeid(char) " << typeid(char).hash_code() << endl;
}