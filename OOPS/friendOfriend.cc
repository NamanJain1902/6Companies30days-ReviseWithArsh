#include<bits/stdc++.h>
using namespace std;


class B; // forward declaration
class C{
    public:
        void showB(B&);
};

class B{
    int b;
    public:

    B() {b = 0;}
    B(int  b): b(b) {}
    friend void C::showB(B& x);
};

void C::showB(B& x) {
    cout << "B::b " << x.b << endl;
}

int main() {
    C c;
    B b(123);
    c.showB(b);

}

// class A{
//     int a;
//     int b;

//     public:
//         A(int _a, int _b) : a(_a), b(_b) {}
    
//         friend class B; // friend class

//         // friend void fun(A, B);
// };

// class B {
//     int a;
//     int b;

//     public:
//         B(int _a, int _b) : a(_a), b(_b) {}

//         void display(A &t) {
//             cout << t.a << " " << t.b << endl;
//         }
// };

// class Largest {
//     int a, b, m;

//     public:
//         Largest() {}
//         ~Largest() {}
//         Largest(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
//         void set_data();
//         friend int find_max(Largest);
// };
// // void fun(A aa, B    bb) {
// //     cout << (bb.a - aa.a) << " " << (bb.b - aa.b) << endl;
// //     // cout << ob.a << " " << ob.b << endl;
// // }

// int main() {

//     A a(1, 2);
//     B b(3, 4);

//     // fun(a, b);
//     b.display(a);
// }