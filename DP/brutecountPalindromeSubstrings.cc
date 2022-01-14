#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int low = 0;
    int high = s.length() - 1;

    while( low < high){
        if(s[low] != s[high]){
            return false;
        }
        low++; high--;
    }
    return true;
}
// O(N^4) : O(N^3) to find substring + O(N) to check if it's palindrome
int getSS(string s){
    int cnt =0;
    int n = s.length();
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            string ss = s.substr(i, j-i+1);
            if(isPalindrome(ss)){
                // cout << ss << endl;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    string s;
    cin >> s;
    cout << getSS(s) << endl;
}
