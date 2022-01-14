#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

bool isPalindrome(string &s){
    int low = 0; int high = s.length() - 1;
    while(low < high){
        if(s[low] != s[high]) return false;
        low++;high--;
    }
    return true;
}

void getSS(string input, string output){
    if(input.empty()){
        if(isPalindrome(output)){
            cnt++;
        }
        return;
    }
    getSS(input.substr(1), output + input[0]);
    getSS(input.substr(1), output);
}

int main(){
    string s;cin>>s;
    getSS(s, "");
    cout << cnt - 1 << endl; // since it's counting empty output as palindrome.
}
