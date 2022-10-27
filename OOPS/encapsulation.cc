// fully encapsulated class: all data members are private.  
// encapsulation is information hiding/data hiding.

// advantage
/*
1. data hiding => security more
2. if we want, we can make class read only.
3. code resuseability.
4. helps in unit testing.
*/
#include<bits/stdc++.h>
using namespace std;

class Human {
    public :
        int height;
    private:
        int weight;
    protected:
        int age;    

    public:

        int get_age() {
            return age;
        }
        void setWeight(int _weight) {
            this->weight = _weight;
        }
};

class Male: public Human {
    
    public:

    string color;

    void sleep() {
        cout << "Male sleeping\n";
    }
};

int main() {
    Male obj1;
    cout << obj1.height << endl;
    // cout << obj1.weight << endl;
    // cout << obj1.age << endl;
    cout << obj1.color << endl; 
}