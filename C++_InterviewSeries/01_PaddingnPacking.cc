/*
What is structural padding and packing in C++?

It is a way to speed up CPU utilization.
*/

/**
padding: adding some extra bits to some size.
packing: if you don't want to do padding, so 
         you'll be doing packing.
*/

#include<bits/stdc++.h>
using namespace std;

// #pragma pack(1) // disables padding.

struct Base1 {
    char a;
    char b;
    int i;
    char c;
};

struct Base2 {
    char a; // 1
    char b; // 1
    char c; // 1
    int i;  // 4 
};


int main() {
    long a;
    cout << sizeof(a) << endl;
    cout << sizeof(Base1) << endl; // 12
    /*
        pads in multiple of maximum available 
        data type.
    */

    cout << sizeof(Base2) << endl; // 8

    return 0;
}

/*

1 word is 4 byts in 32 bit processor.
1 word is 8 byte in 64 bit processor.

Case 1:

struct Base {
    char a;
    char b;
    int p;
};

|a|b|-|-|p|p|p|p|
 0 1 2 3 4 5 6 7



Case 2:

struct Base {
    char a;
    int p;
    char b;
};

|a|-|-|-|p|p|p|p|b|-|-|-|
 0 1 2 3 4 5 6 7 8 9 10 11


When program runs it gets divided into pages
and stored in hardisk.

A 32 bit processor can process 32 bits at once(in 1 clock cycle). 
same for 64 bits processor.


! How data gets memory slots?

1 Byte => can be stored at multiple of 1 memory slot.
2 Byte => can be stored at multiple of 2 memory slot.
4 Byte => can be stored at multiple of 4 memory slot.
8 Byte => can be stored at multiple of 8 memory slot.

*/