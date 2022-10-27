/*
How delete[] know how many objects to delete?

1. Over Allocation
2. Associative Array
*/
#include<iostream>

int const n = 10;

class Base {
    public:

    int b_var;
};

/*
WORDSIZE of 4 byte for 32 bit machine and 8 byte for 64 bit machine.
*/
int main() {
    Base *bp = new Base[n];
    /*
        char *tmp = (char*) operator new[] (WORDSIZE + n * sizeof(Base));
        Base* p = (Base*)(tmp + WORDSIZE);
        *(size_t*)tmp = n;
        for(int i=; i<n; ++i) {
            new(p + i) Base(); 
        }
    
    */


    delete[] bp;
    /*
        which is essentially

        size_t n = *(size_t*) ((char)*)p - WORDSIZE);
        while(n-->0) {
            (p + n)->~Base();
            operator delete[] ((char*))p - WORDSIZE);
        } 
    */

    return 1;
}