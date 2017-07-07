#include <iostream>
#include "Vector.h"


using namespace std;
int main() {
  Vector< Vector<int> > v(3,Vector<int>(3,4));
  cout<<v.size();
  cout<<v[0].size();

  for(int i=0;i<v.size();i++)
    cout<<v[i][0];
  // hm.insert("Guava", 150);
  return 0;
}
