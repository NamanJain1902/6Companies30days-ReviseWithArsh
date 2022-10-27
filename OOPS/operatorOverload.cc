#include<bits/stdc++.h>
using namespace std;


class B{

    int a;
    int b;

    public:

    B(int _a, int _b) {
        a = _a; 
        b = _b;
    }

    int add() {
        return (a + b);
    }    
    void operator+ (B &obj) {
        int value1 = this->a;
        int value2 = this->b;
        cout << "output " << (value2 - value1) << endl;
    }
};
int main() {
    B ob(2, 15), ob1(3, 7);
    // cout << ob + ob1;
    (ob + ob1) + ob1;
}