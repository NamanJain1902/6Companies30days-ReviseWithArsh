/*
How to stop someon from taking address of your object?

Two ways

1. Overload & operator and keep it private
2. Delete & operator 
*/

#include<iostream>
using namespace std;


class Base {
    int x;

    public:

    Base() {}
    Base(int x) {x=x;}

    // & is overloaded by default in class.
    Base* operator &() {
        cout << "BIN\n";
        return this;
    }
};


// m1
// class Base1 {

// private:

//     int x;
//     Base1* operator &() {
//         cout << "BIN\n";
//         return this;
//     }

// public:

//     Base11() {}
//     Base1(int x) {x=x;}
// };


// m2
class Base1 {

private:
    int x;

public:

    Base11() {}
    Base1(int x) {x=x;}

    Base1* operator &() = delete;
};


int main() {
    Base b;
    Base *bp = &b;
    cout << bp << endl;
    cout << &b << endl;

    Base1 b1;
    Base1 *bp1 = &b1;
    cout << bp1 << endl;
    cout << &b1 << endl;
}