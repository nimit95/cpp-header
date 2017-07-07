#include <cstring>
#include <iostream>
#include "Hashmap.h"
#include "Trie.h"

using namespace std;
int main() {
  Trie trie;
  trie.insert("nimit");
  trie.insert("no");
  trie.insert("not");
  trie.insert("noughat");
  cout<<trie.isPresent("nou");
  return 0;
}
