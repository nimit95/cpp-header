#include <iostream>
#include "Linkedlist.h"
#include <vector>
using namespace std;

int main() {
    vector<int> v(6);
    for(int i=0;i<6;i++)
        v[i] = i+1;
    LinkedList<int> l(v); /// Vector to linked list
    l.print(); // print linked list (1->2->3->4->5->6)


    l.pushAtFront(0); /// Push 0 at Fron of the linked list
    l.pushAtBack(7); /// Push 7 at the back of linked list
    l.print(); /// print the linked list (0->1->2->3->4->5->6->7)

    cout<<"Is link list Circular "<<l.isCircular()<<endl; /// Check list is circular or not
    l.makeCircular(3); /// Make the list circular
    cout<<"Is link list Circular "<<l.isCircular()<<endl; /// Check for circle
    l.print(); /// print the list

    l.swap(2,5); //Swap 2nd and 5th Node
    l.print(); /// print the list
}
