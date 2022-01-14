#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;

long long countDistinctSubsequence(string &s){
    int n = s.length();

    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    unordered_map<char,int> uset;
    vector<int> last(MAX_CHAR, -1);

    for(int i=1; i<=n; ++i){
        char ch = s[i-1];
        long long val = 0;
        long long idx = s.find(ch);
        // if(idx != (i-1)){
        //     val = dp[idx - 1];
        // }
        // if(uset.find(ch) != uset.end()){
        //     val = dp[idx - 1];
        // }

        // uset[ch] = i - 1; 
        if (last[s[i - 1]] != -1)
            val = dp[last[s[i - 1]]];
 
        dp[i] = 2 * dp[i-1] - val;
        
        // Mark occurrence of current character
        last[s[i - 1]] = (i - 1);
    }
    return dp[n] - 1;
}

int main(){
    string s;cin>>s;
    
    cout << countDistinctSubsequence(s) << endl;
}
