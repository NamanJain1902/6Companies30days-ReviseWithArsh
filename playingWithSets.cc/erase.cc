#include<iostream>
#include<iterator>
#include<set>
#include<typeinfo>
using namespace std;


int main()
{
    // empty set container
    set<int> s1; // by default: elements arranged ascending order
    // <-------- To change default behavior to descending order ---->
    set<int, greater<int>> s2;


    // insert elements in random order
    s1.insert(20); s2.insert(20);
    s1.insert(10); s2.insert(10);
    s1.insert(40); s2.insert(40);
    s1.insert(34); s2.insert(34);
    s1.insert(99); s2.insert(99);

    // only one 10 will be added to the set
    s1.insert(10);
    cout << "Size of s1: " << s1.size() << endl;
    cout <<"s1 12th location: "<< typeid(s1.find(12)).name() << " \tval: " << *s1.find(12) << endl;

    cout << "\ns2 after removal of elements less than 30 "
        ":\n";

    s2.erase(s2.begin(), s2.find(34));
    cout <<"S2 size:" << s2.size() << endl;


    // printing set
    set<int>::iterator itr, rev;
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "s1 s2" << endl;
    for(itr = s1.begin(),rev=s2.begin() ; itr != s1.end() && rev!=s2.end(); itr++, rev++){
        cout<<*itr<< " " << *rev << endl;
    }
    cout<<endl;
}

