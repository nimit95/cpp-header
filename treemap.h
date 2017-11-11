#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {
    
public:
    
    const Key k;
    Value v;


    KeyValuePair():k(0) {

    }
    KeyValuePair(Key key, Value value):k(key) {
        this->v = value;
    }

    KeyValuePair(Key key): k(key) {
    }


    bool operator<( KeyValuePair<Key, Value> &obj1 ) const {
        return this->k < obj1.k ;
    }
    // TODO your code for KeyValuePair goes here




};



template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {
  
private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;
    
public:

    
    
    KeyValuePair<Key,Value> * insert( const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }

    KeyValuePair<Key,Value> * find(Key key)  {
        KeyValuePair<Key, Value> keyValuePair(key);
        return &((tree.find(keyValuePair))->data);
    }

    
    void write(ostream & o) const {
        tree.write(o);
    }
    
    // TODO your code for TreeMap goes here:
    
    /*
    class TreeNodeIterator{

        unique_ptr<BinarySearchTree<KeyValuePair<Key,Value> > > root;


    };
    */
    
};


// do not edit below this line

#endif
