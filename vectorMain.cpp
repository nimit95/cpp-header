#include <iostream>
#include "Vector.h"
#include <vector>

using namespace std;
int main() {
  Vector<long long int> v;
  for(long long int i=0;i<10000000 ;i++) {
      v.push_back(i+1);
    
  }

  return 0;
}
