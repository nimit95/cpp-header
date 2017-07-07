#ifndef VECTOR_H
#define VECTOR_H
template<typename T>
class Vector{
  T *arr;
  int cs,ts;

public:
  Vector(int t=0){
    cs = t;
    ts = 2*t;
    if(t==0)
      ts=1;
    arr = new T[ts];
  }
  Vector(int t, T init){
    /// Intialise vector with init
    cs = t;
    ts = 2*t;
    arr = new T[ts];
    for(int i=0;i<cs;i++)
      arr[i] = init;
  }
  void push_back(T data) {
    /// Push element on the back
    if((cs+1)>=ts/2) {

      resize(2*ts);
      ts*=2;
    }
    arr[cs] = data;
    cs++;
  }
  void pop_back() {
    /// pop the last element in the vector
    if(cs>0)
      cs--;
    if(cs<ts/4) {
      resize(ts/2);
      ts/=2;
    }
  }
  T& back() {
    return arr[cs-1];
  }
  int size() {
    return cs;
  }
  void resize(int cap) {
    T* newarr = new int[cap];
    for(int i=0;i<cs;i++) {
      newarr[i] = arr[i];
    }
    delete[] arr;
    arr = newarr;
  }
  int capacity() {
    return ts;
  }
  T& operator[](int pos) {
    return arr[pos];
  }
};
#endif
