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
    bool isCircular()
    {
        /// SLow and fast pointers
        if (head == NULL)
            return false;
        LinkedListNode<T>* slow = head;
        LinkedListNode<T>* fast = head;
        while (fast != NULL&& fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
    void makeCircular(int pos)
    {
        /// To make Linked List CIrcular
        /// join end to the position
        LinkedListNode<T> *temp = head;
        LinkedListNode<T>* nodeToJoin;
        int i = 0;

        while (temp->next != NULL) {
            if (i == pos)
                nodeToJoin = temp;
            temp = temp->next;
            i++;
        }
        temp->next = nodeToJoin;
    }
    void swap(int pos1, int pos2)
    {
        if (head == NULL)
            if (pos1 > pos2) {
                /// Swap pos1 and pos2
                pos1 = pos1 ^ pos2;
                pos2 = pos1 ^ pos2;
                pos1 = pos2 ^ pos1;
            }
        LinkedListNode<T> *prev1 = head, prev2 = head, temp, temp2;
        for (int i = 0; i < pos1 - 1; i++)
            prev1 = prev1->next;
        for (int i = 0; i < pos2 - 1; i++)
            prev2 = prev2->next;
		temp = prev1->next->next;
		prev1->next->next = prev2->next->next;
		prev2->next->next = temp;
		temp2= prev1->next;
		prev1->next = prev2->next;
		prev2->next = temp2;

    }
    int size() {
        return s;
    }
    

};
#endif
