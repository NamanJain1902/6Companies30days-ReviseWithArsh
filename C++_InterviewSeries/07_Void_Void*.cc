/*
What is void and void pointer(void *) in C/C++?

// void
1. void is used to denote nothing.
2. if some function is not returning anything then we use void type to denote that.
3. if some function doesn't take any parameter then we use void type to denote that.
4. we can not create a variable of void type.
5. sizeof void is 1 in gcc compilers but in others it's not valid to check type of void.

// void*

1. void* is universal pointer.
2. we can convert any data type pointer to void* (Except function pointer, const, volatile)
3. void* can not be dereferenced.
*/

#include<iostream>
using namespace std;


int main() {
    int *a = new int(10);
    void *v = a;
    void *p = static_cast<void*>(a);

    cout << &a << "  " << a << "  " << v << "  " << p << endl;

    // go back and dereference v
    cout << *(static_cast<int*>(v)) << endl;
}

// Summary
/*
void means nothing
void* means pointer to anything except function pointer, const, volatile.
*/

// Use Cases
/*
1. malloc and calloc returns void* so that we can typecast to our desired data type.
2. void* is used to create generic functions in c. (compare function used in qsort() in c)
*/