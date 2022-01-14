#include<bits/stdc++.h>
using namespace std;

int gapStrategy(string s){
    int n = s.length();
    int dp[n][n]{0};
    int cnt = 0;
    for(int gap=0; gap<n; ++gap){
        for(int i=0, j=gap; j<n; ++i, ++j){
            if(gap == 0){
                dp[i][j] = 1;
                cnt++;
            } else if(gap == 1){
                if(s[i] == s[j]){
                    dp[i][j] = 1;
                    cnt++;
                }else{
                    dp[i][j] = 0;
                }
            } else{
                if(s[i] == s[j]){
                    if(dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    string s;
    cin >> s;
    cout << gapStrategy(s) << endl;
}
