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
    LinkedList(vector<T> ve) {
        s = 0;
        int temp = ve.size();
        for(int i=temp-1;i>=0;i--)
            pushAtFront(ve[i]);
        //cout<<s;
    }
    //LinkedList(LinkedListNode<T>* root) {
//        head = root;
//    }
    void pushAtBack(T data) {
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
    void pushAtFront(T data) {

        LinkedListNode<T>* temp = new LinkedListNode<T>(data);

        temp->next = head;
        head = temp;
        s++;
    }
    void print(){
        LinkedListNode<T>* temp = head;
        for(int i=0;i<s-1;i++) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout<<temp->val<<endl;
        cout<<"Size is "<<s<<endl;
    }
    bool isCircular(){
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
    void makeCircular(int pos){
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
    void swap(int pos1, int pos2){
        if (head == NULL)
            if (pos1 > pos2) {
                /// Swap pos1 and pos2
                pos1 = pos1 ^ pos2;
                pos2 = pos1 ^ pos2;
                pos1 = pos2 ^ pos1;
            }
        LinkedListNode<T> *prev1 = head, *prev2 = head, *temp, *temp2;
        for (int i = 0; i < pos1 - 2; i++)
            prev1 = prev1->next;
        for (int i = 0; i < pos2 - 2; i++)
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
    ///At
    // square brackets
    ///reverse
    T& operator[](int pos) {
        if(pos>s) {
            /// if pos is greater create nodes
            for(int i=0;i<s-pos;i++)
            {
                LinkedListNode<T>* temp = new LinkedListNode<T>();
                pushAtBack(temp);
            }
        }
        return *at(pos);

    }
    T* at(int pos) {
        if(pos>=s)
            return NULL;
        else {
            LinkedListNode<T>* temp = head;
            for(int i=0;i<pos;i++)
                temp = temp->next;
            return temp;
        }
    }
    void reverse() {
        head = rlist(head);
    }
    LinkedListNode<T>* reverse(LinkedListNode<T>* head) {
        if(head==NULL||head->next==NULL)
            return head;
        LinkedListNode<T>* temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    void rotateRight(int pos) {
        /// Rotating element ro the right;
        LinkedListNode<T>* temp = head;
        pos = pos % s ;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = head;
        temp = head;
        for(int i=0;i<pos-1;i++)
            temp = temp->next;
        head = temp->next;
        temp->next = NULL;
    }
    void erase(int pos) {
        /// Delete an element
        LinkedListNode<T>* temp;
        if(pos>=s)
            return ;
        else if(pos==s-1)
        {
            at(pos-1)->next = NULL;
            return;
        }
        temp = at(pos-1);
        temp->next = temp->next->next;

    }
    LinkedListNode<T>* mergePoint(LinkedListNode<T>* head1, LinkedListNode<T>* head2) {
        LinkedListNode<T>* temp1=head1;
        LinkedListNode<T> *temp2=head2;
        if(head1==NULL||head2==NULL)
            return NULL;
        while(head1!=head2) {
            head1 = head1->next;
            head2 = head2->next;
            if(head1==NULL && head2==NULL) return NULL;
            if(head1==NULL) head1 = temp2;
            if(head2==NULL) head2 = temp1;
        }
        return head1;
    }

};
#endif
