#include<bits/stdc++.h>
using namespace std;


class Base {
    public:
        virtual void show() = 0;
};
void Base::show() {
    cout << "Base show\n";
}
class Derived : public Base {
    public:
        void show(){}
        //     // cout << "In derived\n";
};
int main() {
    Base *ptr = new Derived;
    ptr->show();
    return 0;
}
