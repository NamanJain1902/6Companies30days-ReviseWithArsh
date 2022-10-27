#include<bits/stdc++.h>
using namespace std;

class Animal {
    public: 
        int age;
        int weight;

    public:
    
    void speak() {
        cout << "Barking.\n";
    }
};

class Human{

    public:
    string color;

    public:


    void speak() {
        cout << "Speaking.\n";
    }
};

class Hybrid: public Animal, public Human {

};

int main() {
    Hybrid ob;
        ob.Human::speak();
        ob.Animal::speak();
}