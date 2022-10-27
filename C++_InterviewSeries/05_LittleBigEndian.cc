#include<iostream>
using namespace std;

int main() {
    unsigned int i = 1;
    char *c = (char*)&i;

    if(*c) {
        cout << "Little Endian\n";
    } else {
        cout << "Big Endian\n";
    }
}