#include <iostream>
#include <vector>
using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
class LinkedListNode {
    public:
    T val;
    LinkedListNode* next;

    LinkedListNode(T data) {
        next = NULL;
        val = data;
    }
    ~LinkedListNode()
    {
        if (next != NULL)
            delete next;
    }
};
template<typename T>
class LinkedList {
    LinkedListNode<T>* head;
    int s;

public:
    LinkedList()
    {
        head = NULL;
        s = 0;
    }
    LinkedList(int* arr) {
        //s = ve.size();
        //for(int i:ve) {
        //    cout<<i;
            //pushAtFront(2);
            //pushAtFront(3);
        //}
        int si = sizeof(arr)/sizeof(arr[0]);
        cout<<si;
        //for(int i=0;i<si;i++)
        //    pushAtFront(arr[i]);
    }
    LinkedList(LinkedListNode<T>* root) {
        head = root;
    }
    void pushAtBack(T data)
    {
        if (head == NULL) {
            head = new LinkedListNode<T>(data);
            return;
        }
        else {
            LinkedListNode<T>* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new LinkedListNode<T>(data);
        }
        s++;
    }
    void pushAtFront(T data)
    {

        LinkedListNode<T>* temp = new LinkedListNode<T>(data);

        temp->next = head;
        head = temp;
        s++;
    }
    void print()
    {
        LinkedListNode<T>* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
    }
};
#endif
