#include <cstring>
#include <iostream>
using namespace std;
#ifndef HASHMAP_H
#define HASHMAP_H
namespace hashing {
    template<typename T>
    class Node {
    public:
        string key;
        T data;
        Node<T>* next;

        Node(string k, T d) {
            key = k;
            data = d;
            next = NULL;
        }
        ~Node() {
            if(next!=NULL)
                delete next;
        }
    };
}

template<typename T>
class hashmap {
    hashing::Node<T>** buckets;
    int ts;
    int cs;
    float lf;
    int hashFn(string key) {
        int p =1;
        int ans = 0 ;
        int l = key.length();
        for(int i=0;i<l;i++) {
            ans += key[l-i-1]*p;
            p =(p*37)%ts;
        }
        return ans%ts;
    }
    void rehash() {
        hashing::Node<T>** oldbuckets = buckets;
        buckets = new hashing::Node<T>*[ts*2];
        cs = 0;
        ts = ts * 2;
        for(int i=0;i<ts/2;i++)
        {
            hashing::Node<T>* temp = oldbuckets[i];
            while(temp!=NULL) {
                insert(temp->key, temp->data);
                temp = temp->next;
            }
            delete oldbuckets[i];
        }
        delete [] oldbuckets;
  }
public:
    hashmap(int t=7, float l=0.7) {
        ts = t;
        cs = 0 ;
        lf = l ;
        buckets = new hashing::Node<T>*[t];
    }
    void insert(string key, T value) {
        int i = hashFn(key);
        hashing::Node<T>* temp = buckets[i];
        hashing::Node<T>* toInsert = new hashing::Node<T>(key,value);
        toInsert->next = buckets[i];
        buckets[i] = toInsert;
        cs++;
        lf = (float)cs/ts;

        if(lf>0.7)
            rehash();
        }
    T* find(string key) {
        int i = hashFn(key);
        hashing::Node<T>* temp = buckets[i];
        while(temp!=NULL) {
            if(!temp->key.compare(key))
                return &temp->data;
            temp = temp->next;
        }
        return NULL;
    }
    void print() {
        for(int i=0;i<ts;i++) {
            cout<<"Bucket "<<i<<"-> ";
            hashing::Node<T>* temp = buckets[i];
            while(temp!=NULL) {
                cout<<temp->key<<"-> ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
    void erase(string key) {
        int i = hashFn(key);
        hashing::Node<T> *temp = buckets[i];
        hashing::Node<T> *prev = buckets[i];
        if(!temp->key.compare(key)){
            /// If the hashing::Node to delete is head
            buckets[i] = temp->next;
            return ;
        }
        temp = temp->next;
        while(temp!=NULL) {
            if(!temp->key.compare(key) ){
                prev->next = temp->next;
            return;
        }
        prev = temp;
        temp = temp->next;
        }
  }
    T& operator[](string key) {
        T* temp = find(key);
        if(temp==NULL) {
    /// create a new hashing::Node;
            T empty;
            insert(key, empty);
            return *find(key);
        }
        else {
      /// return reference
            return *temp;
        }
    }
};
#endif
