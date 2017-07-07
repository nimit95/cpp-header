#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#ifndef VECTOR_H
#define VECTOR_H
using namespace std;
template <typename T>
class Vector  {
    T* arr;
    int cs, ts;

public:
    Vector(int t = 0)    {
        cs = t;
        ts = 2 * t;
        if (t == 0)
            ts = 1;
        arr = new T[ts];
    }
    Vector(int t, T init){
        /// Intialise vector with init
        cs = t;
        ts = 2 * t;
        arr = new T[ts];
        for (int i = 0; i < cs; i++)
            arr[i] = init;
    }
    Vector(vector<T> v) {
        for(int i=0;i<v.size();i++)
            push_back(v[i]);
    }

    void push_back(T data){
        /// Push element on the back
        if ((cs + 1) >= ts / 2) {

            resize(ts);
            ts *= 2;
        }
        arr[cs] = data;
        cs++;
    }
    void pop_back(){
        /// pop the last element in the vector
        if (cs > 0)
            cs--;
        if (cs < ts / 4) {
            resize(ts / 4);
            ts /= 2;
        }
    }
    T& back(){
        return arr[cs - 1];
    }
    int size(){
        return cs;
    }
    void resize(int newsize){
        T* newarr = new T[2*newsize];
        for (int i = 0; i < cs; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }
    int capacity(){
        return ts;
    }
    // pos -ve,+ve>cs
    // append two vectors
     // vector slicing

    T& operator[](int pos){
        if(pos<0) {
            return arr[cs-pos];
        }
        return arr[pos];
    }

    Vector operator[](string s) {
        /// slice
        string a="", b="";
        int i;
        for(i=0;s[i]!=':';i++)
            a =a + s[i];
        i++;
        for(;i<s.length();i++)
            b = b + s[i];
        Vector<T> temp = Vector<T>();
        for(int i=stoi(a);i<stoi(b);i++)
            temp.push_back((*this)[i]);
        return temp;
    }
    void append(Vector<T> v) {
        for(int i=0;i<v.size();i++)
            push_back(v[i]);
    }
    Vector operator+(Vector<T> v) {
        /// append two vectors
        Vector<T> temp =Vector<T>(*this);
        temp.append(v);
        return temp;
    }
    void sortVec() {
        ///  sort vvector
        sort(arr,arr+cs);
    }/*
    void splice() {
        // delete element
    }*/
    ///erase an element
    void erase(int pos) {
        int rpos;
        if(pos<0)
            rpos = cs-pos;
        else
            rpos = pos;
        for(int i=rpos;i<cs-1;i++)
            arr[i] = arr[i+1];
        cs--;
    }
    void append(vector<T> v) {
        for(int i=0;i<v.size();i++)
            push_back(v[i]);
    }
    void print() {
        for(int i=0;i<cs;i++)
            cout<<arr[i]<<" ";
    }
    void take_input(int start,int end) {
        for(int i = start;i<end;i++) {
            T temp;
            cin>>temp;
            push_back(temp);
        }
    }
};
#endif
