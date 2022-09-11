#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s){
        int low = 0;
        int high = s.length() - 1;
        while(low < high){
            if(s[low] != s[high]){
                return false;
            }
            low++; high--;
        }
        return true;
    }
    int max(int a, int b){
        if(a >= b)  return a;
        return b;
    }
    void getSS(string s, string os, int &omax){
        if(s.length() == 0){
            if(isPalindrome(os)){
                omax = max(omax, os.length());
            }
            return;
        }
        getSS(s.substr(1), os + s[0], omax);
        getSS(s.substr(1), os, omax);
    }
    
    int longestPalindromeSubseq(string s) {
       int omax = 0;
       getSS(s, "", omax);
       return omax;
    }


    
};

int main()
{
    string s;cin>>s;
    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << endl;

    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    // length of longest palindrome subsequence of string s
    int slen = s.size();
    int dp[slen][slen];
    for(int i=0; i<slen; ++i){
        dp[i][i] = 1;
    }
    for(int i=1; i<slen; ++i){
        for(int j=i, g=0; j<slen; ++j, ++g){
            // if(i == 0){
            //     dp[g][j] = 1;
            // }
            if(i == 1){
                dp[g][j] = s[g] == s[j] ? 2 : 1;
            }
            else{
                if(s[g] == s[j]){
                    dp[g][j] = 2 + dp[g+1][j-1];
                }else{
                    dp[g][j] = max(dp[g+1][j], dp[g][j-1]);
                }
            }
        }
    }

    cout << dp[0][slen-1] << endl;
}
