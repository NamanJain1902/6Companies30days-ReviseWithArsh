#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2 strings 
// It should return the required output
int binomialCoeff(int n, int k) {
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
  
    // Recur
    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}
 
void func(string S, string T) {
 //Write your code here
 // a->3    a->1
 // b->2    b->1
 // c->1    c->1
 // 3C1 = 3, 2C1 = 2, 1C1 = 1
 // L.C.M of (3, 2, 1) = 6

 // a->3    a->2
 // b->2    b->1
 // c->1    c->1
 // 3C2=3, 2C1=2, 1C1=1

    

    unordered_map<char, int> h1, h2;
    for(auto x: S) h1[x]++;
    for(auto x: T) h2[x]++;


    int lcm = 1;

    for(auto ump1: h1){
        char key = ump1.first;
        int val = ump1.second;

        if(h2.find(key) == h2.end()) {
            lcm = 0;
            break;
        }

        lcm *= (binomialCoeff(val, h2[key]));
    }

    cout << lcm << endl;
}
 
 
int main(){
    string s,t;
    cin>>s>>t;
 
    func(s, t);
}

