#include<bits/stdc++.h>
using namespace std;

// O(N^3)
void allSubsequences(string &s) {
    int n=s.length();

    for(int i=0; i<n; ++i){
        for(int j=i; i<n; ++j){
            for(int k=i; i<j; ++k){
                cout << s[k];
            }
            cout << endl;
        }
    }
}

void printSS(string ques, string ans){
    // write your code here
    if(ques.length() == 0){
        cout << ans << "\n";
        return;
    }
    char fst = ques[0];
    string ros = ques.substr(1);
    printSS(ros, ans+fst);
    printSS(ros, ans+"");
}

void printSubsequences(string s, int idx, string res){
    if(idx == s.length()){
        cout << res << endl;
    }
    printSubsequences(s, idx + 1, res + s[idx]);
    printSubsequences(s, idx + 1, res);
}

int main(){
    string s;
    cin >> s ;
//    allSubsequences(s);
    printSubsequences(s, 0, "");
}
