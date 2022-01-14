#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    // we need to find the largest sub-string that is 
    // palindrome.
    int n = s.length();
    vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), 0));
    for(int g=0; g<n; ++g){
        for(int i=0,j=g; j<n; j++, i++){
            if(g == 0){
                isPalindrome[i][j] = true;
            } else if(g == 1){
                isPalindrome[i][j] = (s[i] == s[j]);
            } else {
                if(s[i] == s[j] and isPalindrome[i+1][j-1]){
                    isPalindrome[i][j] = true;
                } else{
                    isPalindrome[i][j] = false;
                }
            }
        }
    }

    vector<vector<int>> dp(s.length(), vector<int>(s.length()));

    for(int g=0; g<n; ++g){
        for(int i=0,j=g; j<n; j++, i++){
            if(g == 0){
                dp[i][j] = 0;
            } else if(g == 1){
                if(s[i] == s[j]){
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1;
                }
            } else {
                if(isPalindrome[i][j]){
                    dp[i][j] = dp[i+1][j-1];
                } else{
                //     dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1; // TODO: Consider boundary case
                    int mini = INT_MAX;
                    for(int k=i; k<j; ++k){
                        mini = min(mini, (dp[i][k] + dp[k+1][j] + 1));
                    }
                    dp[i][j] = mini;
                }
            }
        }
    }

    cout << dp[0][n-1] << endl;
}

