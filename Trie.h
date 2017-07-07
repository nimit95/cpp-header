#include <unordered_map>
#include <cstring>
using namespace std;
#ifndef TRIE_H
#define TRIE_H
namespace trie {
class Node {
public:
  unordered_map<char, Node*> mp;
  char data;
  bool isWord;
  Node(char c) {
    data = c;
    isWord = false;
  }
};
}

class Trie {
trie::Node* root;
public:
  Trie() {
    root = new trie::Node('\0');
  }
  void insert(string s) {
    trie::Node* temp = root;
    for(int i=0;s[i]!='\0';i++){
      auto it = temp->mp.find(s[i]);
      if(it==temp->mp.end()) {
        trie::Node* newNode = new trie::Node(s[i]);
        temp->mp[s[i]] = newNode;
        temp = newNode ;
      }
      else {
        temp = it->second;
      }
    }
    temp->isWord = true;
  }
  bool isPresent(string s) {
    trie::Node* temp = root;
    for(int i=0;s[i]!='\0';i++){
      auto it = temp->mp.find(s[i]);
      if(it==temp->mp.end()) {
        return false;
      }
      else
        temp = it->second;
    }
    return temp->isWord;
  }
};
#endif
