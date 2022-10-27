// CPP program without virtual destructor
// causing undefined behavior
#include <iostream>

using namespace std;

class base {
public:
 base() 
 { cout << "Constructing base\n"; }
 virtual ~base()
 { cout<< "Destructing base\n"; } 
};

class derived: public base {
public:
 derived() 
 { cout << "Constructing derived\n"; }
 ~derived()
 { cout << "Destructing derived\n"; }
};

int main()
{
derived *d = new derived();
base *b = d;
delete b;
return 0;
}

// #include<bits/stdc++.h>
// using namespace std;


// class A {
//     static int ic, id;
//     public:
//     A() {
//         cout << "Constructor: " << id << endl;
//         ic += 1;
//     };
//     ~A() {
//         cout << "Destructor: " << id << endl;
//         id += 1;
//     };

//     static int get_ic() {
//         return ic;
//     }
//     static int get_id() {
//         return id;
//     }
// };
// int A::ic = 1;
// int A::id = 1;

// int main() {
//     int n = 5;

//     while(n--) {
//         A ob;
//         cout << " n " << n << endl;
//     }

//     cout << "ic: " << A::get_ic() << endl;
//     cout << "id: " << A::get_id() << endl;

//     return 0;
// }
