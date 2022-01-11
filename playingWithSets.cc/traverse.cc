#include<iostream>
#include<iterator>
#include<set>

using namespace std;


int main()
{
    // empty set container
    set<int> s1; // by default: elements arranged ascending order
    // <-------- To change default behavior to descending order ---->
    set<int, greater<int>> s2;


    // insert elements in random order
    s1.insert(20); s1.insert(20);
    s1.insert(10); s2.insert(10);
    s1.insert(40); s2.insert(40);
    s1.insert(34); s2.insert(34);
    s1.insert(99); s2.insert(99);

    // only one 10 will be added to the set
    s1.insert(10);
    
    // printing set
    set<int>::iterator itr, rev;
    cout << "s1 s2" << endl;
    for(itr = s1.begin(),rev=s2.begin() ; itr != s1.end() && rev!=s2.end(); itr++, rev++){
        cout<<*itr<< " " << *rev << endl;
    }
    cout<<endl;
//    set<int>::iterator temp;

//    temp = s1.begin();
//    *temp = 1; <------------ Sets are immutable ---------->
//    <------ to change value, remove old val and add modified value -------->
//    cout << "Printing set s1 after changing first value." << endl;
//    for(itr = s1.begin(); itr != s1.end(); itr++){
//        cout<<*itr<<endl;
//    }
}
