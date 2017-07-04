#include <iostream>
#include "Hashmap.h"

using namespace std;
int main() {
  hashmap<int> hm;
  hm.insert("Mango", 100);
  hm.insert("Apple", 150);
  hm.insert("Aprictot", 190);
  hm.insert("Pineapple", 190);
  hm.insert("Guava", 150);
  // hm.insert("Guava", 150);
  hm.print();
  string s;

  hm.erase("Guava");
  hm["Mango"] = 1000;
  cin>>s;
  cout<<*hm.find(s)<<endl;
  return 0;
}
