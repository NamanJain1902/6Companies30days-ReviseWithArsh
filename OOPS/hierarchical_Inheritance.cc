#include<bits/stdc++.h>
using namespace std;

/*
while inheriting in protected mode

private -> can't inherit.
protected -> becomes private in derived class.
public -> becomes protected in derived class.
*/
#define quote(x) #x
class Parent{
    int name;
    std::string acquired_traits;

    public:
        string gene_info;

        void P(){
            cout << "Parent called by " << this << endl;
        }
        Parent &refP() {
            return *this;
        }
};

class Son: public Parent {
    
    public:


        void S(){
            cout << "Parent called by " << this << endl;
        }
        Son &refS() {
            return *this;
        }
};

class Daughter: public Parent {

    public:
        void D(){
            cout << "Parent called by " << this << endl;
        }
        Daughter &refD() {
            return *this;
        }
};
int main() {

    Parent p;
    Son s;
    Daughter d;

    p.P();
    s.S();
    d.D();

    d.refD().P();
    s.refS().P();

    std::cout<<typeid(d.refD()).name()<<"\t"<< quote(Son) <<"\n";
    // typeid(A).name();
}