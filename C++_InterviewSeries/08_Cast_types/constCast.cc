#include<iostream>
using namespace std;

/*
The expression const_cast<T>(v) can be used to change the
const or volatile qualifiers of pointers or references.

, where T must be a pointer, reference or pointer-to-member type.
*/


// // Case 1: When the actual referenced object/variable is not const.
// int main() {
//     const int a = 10;
//     const int *b = &a;
//     int *d = const_cast<int*>(b);
//     *d = 15; // invalid and undefined behavior

//     cout << a << endl;
//     cout << *d << endl;

//     int A = 20;
//     const int *B = &A;
//     int *D = const_cast<int*>(B);
//     *D = 30; // valid code

//     return 0;
// }

// 2. When we need to call some 3'rd party library 
// where it is taking variable/object as not-cosnt 
// but not changing that.

void thirdPartyLibrary(int *x) {
    int k = 10;
    cout << k + *(x) << endl;
}

signed main() {
    const int x = 20;
    const int *px = &x;
    thirdPartyLibrary(const_cast<int*>(px));
}