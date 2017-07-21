# C++ Header File
These are multipurpose header files. These can be used to implement data structures. Useful functions are included with each header file. Some of the header files works faster than internally implemented STL.
### Requireents
Your computer should have a working c++ compiler.
### Getting started
Download or clone the repository, copy the required header file to location of your program and then include the header file(s) in your program. Eg. #include "Hashmap.h"
###### nimit.h is main header file which contains the following header files(can be included seperately as well). Header files in it are as follows -
* [Vector.h](#vectorh)
* [Stack.h](#stackh)
* [Linkedlist.h](#linkedlisth)
* [Trie.h](#trieh)
* [Hashmap.h](#hashmaph)
### Vector.h
#### Constructor
* **Vector()**  -->  Default constructor. Makes an empty vector.

* **Vector(int)** --> Allocates the given number of buckets in the hash table.
* **Vector(int, T)** -->  Allocates the given number of buckets in the hash table and specify the load factor as a float value
* **Vector(vector<T>)** --> Constructor of the class Vector and takes vector as a parameter.
#### Member Functons
* **append(vector<T> v)** --> Appends another vector of the same type T.
* **append(Vector<T> v)** --> Appends another Vector of the same type T.
* **back()** --> Returns reference to the last element of the vector.
* **capacity()** --> Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
* **erase(string)** --> Erases the corresponding string and key value. Return type- void
* **find(string)** --> Returns pointer to the value for the give key, if the key is not found return NULL.
* **operator["start:end"]** --> Returns a sliced Vector from start to end
* **operator[int]** --> [] can be used to access elements, replace values and add new value
* **operator+** --> Returns a vector with both vectors appended Eg. v1 + v2  
* **pop_back()** --> Pops the last element.
* **print()** --> Prints all the keys in the hashmap.
* **push_back(T)** --> Inserts a string key and value in the hashmap. Return type is void.
* **resize()** --> Resizes the vector to the new size given as parameter.
* **size()** --> Returns the size of the vector.
* **sortVec()** --> sorts the vector.
* **take_input(int start,int end)** --> Takes limits as parameter and input elements from (start-end).


### Stack.h
#### Constructor
* **Stack()**  -->  Default constructor. Makes an empty stack.

#### Member Functons
* **push(T)** --> Inserts an element at the top the stack.
* **pop()** --> Remove an element from top of the stack.
* **top()** --> Returns the element at the top.
* **size()** --> Returns size of the vector.
* **empty()** --> Erases the corresponding string and key value. Return type- void

### Linkedlist.h
#### Constructor
* **LinkedList()**  -->  Default constructor. Makes an empty stack.
* **LinkedList(vector<T>)** --> Creates linked list from a vector.
#### Member Functons
* **at(int)** -->
* **erase(int)**
* **isCircular()** --> prints all the keys in the hashmap.
* **makeCircular()** -->
* **mergePoint(LinkedListNode<T>, LinkedListNode<T>)**
* **operator[]** -->
* **pushAtBack(T)** --> insert a string key and value in the hashmap. Return type is void.
* **pushAtFront()** --> returns pointer to the value for the give key, if the key is not found return NULL.
* **reverse()** -->
* **rotateRight(int)** -->
* **size()** -->
* **swap()** --> Erases the corresponding string and key value. Return type- void
### Trie.h
#### Constructor
* **Trie()**  -->  Default constructor. Makes an empty stack.
#### Member Functons
* **insert(string)** --> insert a string key and value in the hashmap. Return type is void.
* **isPresent(string)** --> returns pointer to the value for the give key, if the key is not found return NULL.
* **top()** --> prints all the keys in the hashmap.


### Hashmap.h
* Hashmaps are associative containers that store elements formed by the combination of a key value and a mapped value, and which allows for fast retrieval of individual elements based on their keys.  

* This header file implements hashmap with string as the key and any type of value. hashmap is a templated calss.
    #### Constructor
    * **hasmap()**  -->  Default constructor. Allocates 7 buckets initially. Load Factor=0.7

    * **hashmap(int)** --> Allocates the given number of buckets in the hash table.
    * **hashmap(int, float)** -->  Allocates the given number of buckets in the hash table and specify the load factor as a float value

    #### Member Functons
    * **insert(string, T)** --> insert a string key and value in the hashmap. Return type is void

    * **find(string)** --> returns pointer to the value for the give key, if the key is not found return NULL.
    * **print()** --> prints all the keys in the hashmap.
    * **erase(string)** --> Erases the corresponding string and key value. Return type- void

    * **operator[]**--> [] can be used to access elements, replace values and add new value to the pair. <br>  Eg.<br>
    ```cpp
    hashmap<string> hm;
    hm["foo"] = "bar"; // assign bar value to foo key
    cout<<hm["foo"]; // will print bar
    hm["foo"] = "baaaaar" // change foo value
    cout<<hm["foo"]; //Will print baaaaar
    ```
