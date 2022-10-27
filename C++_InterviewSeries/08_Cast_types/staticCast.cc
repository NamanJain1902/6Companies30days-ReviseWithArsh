#include<iostream>
using namespace std;


// 1. It performs implicit conversion between types.
// 2. Type casting at compile time.
void basic() {
    float f = 3.5;
    int a;

    a = f;
    a = static_cast<int>(f);
}

// Q. Why to use static_cast when implicit conversion is involved?
// A. Because C-Style cast is hard to find in code, but we can 
//    search static_cast keyword.

/*
2. Use static cast when conversion between different types
   is provided through conversion operator or conversion
   constructor.
*/
class Int {
    int x;
public:

    Int(int x = 0) : x(x) {
        cout << "conversion constructor\n";
    }

    operator string() {
        cout << "conversion operator\n";
        return to_string(x);
    }
};

void movingOn() {
    Int obj(3);
    
    string str1 = obj;
    obj = 20;

    string str2 = static_cast<string>(obj);
    obj = static_cast<Int>(30);
}

/*
3. static_cast is more restrictive than C-style.
    e.g.
        char* to int* is allowed in C-style but not with
        static_cast.
*/
void restrictive() {
    char c; // 1 byte data
    int *p = (int*)&c; // 4 byte data
    *p = 5; // pass at compile time but FAIL at runtime. (that's why it's dangerous)

    // int *ip = static_cast<int*>(&c);
}

/*
4. static_cast avoid cast from derived to private base pointer.
*/
// class Base{};
// class Derived: private Base {};

// int main() {
//     // basic();
//     // movingOn();
//     // restrictive();
//     Derived d1;
//     Base *bp1 = (Base*)&d1; // allowed at compile time.
//     // Base *bp2 = static_cast<Base*>(&d1); // not allowed at compile time.

//     return 0;
// }

/*
5. Use for all upcasts, but never use for confused down casts
*/

class Base{};
class Derived1: public Base{};
class Derived2: public Base{};

int main1() {
    Derived1 d1;
    Derived2 d2;

    Base *bp1 = static_cast<Derived1*>(&d1);
    Base *bp2 = static_cast<Derived2*>(&d2);

    Derived1 *d1p = static_cast<Derived1*>(bp2);
    Derived2 *d2p = static_cast<Derived2*>(bp1);

    return 0;
}

/*
6. static_cast should be prefered when converting to void* OR from void*.
*/

int main() {
    int i = 10;
    void *v = static_cast<void*>(&i);
    int *ip = static_cast<int*>(v);
    return 0;
}

/*
1. For compatible type conversion, such as float or int.
2. For conversion operator and conversion constructors.
3. To avoid unrelated pointer conversion.
4. Avoids derived to private base pointer conversion.
5. Use for all up-cast but never use for confused down-cast 
   becuase there are no runtime check's performed for static_cast
   conversions.
6. Intensions are more clear in C++ style cast(express your intent
   better and make code review easier).
7. Error found at compile-time.
8. Finding static conversion statement is easy.

*/