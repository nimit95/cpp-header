#include <vector>
using namespace std;
#ifndef STACH_H
#define STACK_H
template<typename T>
class Stack {
    vector<T> s;
public:
    void push(T data) {
        s.push_back(data);
    }
    void pop() {
        s.pop_back();
    }
    T top() {
        return s.back();
    }
    int size() {
        return s.size();
    }
    bool empty(){
        return s.size()==0;
    }
};
#endif
