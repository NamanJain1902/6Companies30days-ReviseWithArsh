#include<bits/stdc++.h>
using namespace std;


int countPalindromicSubsequence(string &s){
    int n = s.length();

    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int gap=0;gap<n;++gap){
        for(int i=0, j=gap; j<n; ++i,++j){
            if(gap == 0){
                dp[i][j] = 1;
            } else if(gap == 1){
                dp[i][j] = (s[i] == s[j]) ? 3: 2;
            } else {
                if(s[i] == s[j]){
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
            }
        }
    }

    return dp[0][n-1];
}

int main(){
    string s;cin>>s;
    int n = s.length();

    cout << countPalindromicSubsequence(s) << endl;
}
