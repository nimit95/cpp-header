#include <iostream>
#include "Vector.h"

class node{
public:
    int a;
    node* next ;
    node(int x):a(x),next(NULL) {}
};
using namespace std;
template<typename T>
void show(T* head) {
    //cout<<<<endl;
    void *ptr= head;
    cout<<((int*)ptr)<<endl;
    int* x= &(head->a);

    cout<<&(head->next)<<endl;
    T** temp = (T**)(void*)((int*)ptr+2);
    cout<<*temp<<endl;
}

int main() {
  Vector<long long int> v;
  for(int i=15;i>0 ;i--) {
      v.push_back(i+1);

  }
  v.sortVec();
  v.print();
 // node* head = new node(1);
  //head->next = new node(2);
  //int* ptr = &head;
  //show(head);
  //cout<<*(ptr+1)<<endl;


  return 0;
}
