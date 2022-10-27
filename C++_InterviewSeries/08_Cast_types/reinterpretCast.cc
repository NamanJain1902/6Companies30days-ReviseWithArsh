#include<iostream>
using namespace std;

/*
1. It performs dangerous conversions as it can type cast any
    pointer to any other pointer.
*/

class Mango {
    public:
        void eatMango() {
            cout << "eating mango\n";
        }
};
class Banana {
    public: 
        void eatBanana() {
            cout << "eating banana\n";
        }
};

int main() {
    Banana *b = new Banana();
    Mango *m = new Mango();
    Banana *newBanana = reinterpret_cast<Banana*>(m);
    newBanana->eatBanana();
    return 0;
}