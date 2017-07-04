# C++ Header File
These are multipurpose header files. These can be used to implement data structures. Useful fuctions are included with each header file.

### Getting started
Download or clone the repository, copy the required header file to location of your program and then include the header file(s) in your program. Eg. #include "Hashmap.h"
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
