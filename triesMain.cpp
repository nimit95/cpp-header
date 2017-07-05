#include <cstring>
#include <iostream>
#include "Hashmap.h"
#include "Trie.h"
using namespace std;
class A {
public:
    virtual void show() {
        cout<<"hello";
    }
};
class B:public A {
public:
    void show() {
        cout<<"Hi";
    }
};

int main() {
  // Trie trie;
  // trie.insert("nimit");
  // trie.insert("no");
  // trie.insert("not");
  // trie.insert("noughat");
  // cout<<trie.isPresent("nou");
  A* a = new B();
  a->show();
  return 0;
}
