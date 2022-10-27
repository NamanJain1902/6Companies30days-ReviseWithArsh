/*
new is internally calling kernel 
this means you are shifting from 
user mode to kernel mode and kernel
is searching for the asked space.

*/

#include<iostream>
using namespace std;

class Base {
    int a;
    public:
        Base() {
            cout << "Constructor" << endl;
        }
        ~Base {
            cout << "Destructor" << endl;
        }
};

int main() {

// Normal Case:
    cout << "Normal Case: " << endl;
    Base *obj = new Base();
    delete obj;


// New Placement Case:
    cout << "Placement new case: " << endl;
    char *memory = new char[10 * sizeof(Base)];

    // memory is having [40] byte array. so
    // here we are creating a 'memory pool'
    // instead of dynamically requesting for more
    // memory everytime (where my kernel has to do
    // work to find space at run time considering 
    // optimization and calculations), I have asked
    // for a pool of memory in advance.
    // and when you don't want that object you 
    // explicitly call that destructor.

    /*
        new has 2 proceses

        1. asking memory from the kernel.
        2. constructing the object at that memory 
           location.
    */
    Base *obj1 = new (&memory[0]) Base();
    Base *obj2 = new (&memory[4]) Base();
    Base *obj3 = new (&memory[8]) Base();

    obj1->~Base();
    obj2->~Base();
    obj3->~Base();

    delete[] memory;

    return 1;
}