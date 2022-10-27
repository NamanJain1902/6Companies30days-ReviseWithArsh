#include<iostream>
#include <string>
#include "Hero.h"
using namespace std;



// empty class has size
// 1 for it's identification
class A{
    public:
    static int var;
        virtual void fun(){}
        virtual void fun1(){}
        static void f(){
            cout << "A  static function.\n";
        }
};
class B{
    public:
        void fun(){}
        void fun1(){}

};
class Power: public Hero {

    public:
        int get_health() {
            cout << "\n Power get.\n";
            return this->health;
        }
};

class Power2: public Hero {

    public:
        int get_health() {
            cout << "\n Power get.\n";
            return this->health;
        }
};


int main() {
    Hero hulk(1000, "khitehulkjlk");
    cout << " Hulk health is " << hulk.get_health() << endl;

    Hero *h = new Hero; 

    cout << " h health is " << h->get_health() << endl;
    (*h).set_health(100);
    cout << " h health is " << h->get_health() << endl;
    
    cout << "Size of h an *h " << sizeof(h) << " " << sizeof(*h) << endl;  


    Power hulk_power;
    cout << "size of hero class and power class : " << sizeof(hulk) << " " << sizeof(hulk_power) << endl;

    // Power *ptr = new Hero;
    // Hero *ptr= new Power;
    // cout << ptr->get_health() << endl;

    A a;
    B b;
    cout << sizeof(a) << " " << sizeof(b) << endl;
    cout << sizeof(a.var) << endl;
    A::f();

    cout << hulk << endl;


    // copy constructor             
    Hero she_hulk(hulk);
    
    cout << she_hulk << endl;
}