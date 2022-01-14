#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int expandAroundCenter(string &s, int start, int end){
        while(s[start] == s[end] and start >=0 and end < s.length()){
            start--; end++;
        }
        return end - start - 1;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLength = 0;
        int startIndex = -1;
        int endIndex = -1;
        
        for(int i=0; i<n; ++i){
            int oddLength = expandAroundCenter(s, i, i);
            int evenLength = expandAroundCenter(s, i, i+1);
            
            if(oddLength > maxLength){
                maxLength = oddLength;
                startIndex = (i - oddLength / 2);
                endIndex = (i + oddLength / 2);
            }
            
            if(evenLength > maxLength){
                maxLength = evenLength;
                startIndex = (i - (evenLength - 1) / 2);
                endIndex = (i + evenLength / 2);
            }
        }
        cout <<"EndIndex: " << endIndex << " \t StartIndex: " << startIndex << endl;
        return s.substr(startIndex, endIndex - startIndex + 1);
    }
    
//     string longestPalindrome(string s) {
//         int n = s.length();
//         vector<vector<int>> isp(n, vector<int> (n, 0));
//         for(int gap=0; gap<n; ++gap){
//             for(int i=0, j=gap; j<n; ++i, ++j){
//                 if(gap == 0){
//                     isp[i][j] = 1;
//                 } else if(gap == 1){
//                     if(s[i] == s[j]){
//                         isp[i][j] = 1;
//                     }else{
//                         isp[i][j] = 0;
//                     }
//                 } else{
//                     if(s[i] == s[j]){
//                         if(isp[i+1][j-1] == 1){
//                             isp[i][j] = 1;
//                         }
//                     }
//                 }
//             }
//         }
        
        
//         vector<vector<int>> dp(n, vector<int> (n, 0));
//         int I,J, omax=0;
//         for(int gap=0;gap<n;++gap){
//             for(int i=0, j=gap; j<n; ++j, ++i){
//                 if(gap == 0){
//                     dp[i][j] = 1;
//                 } else if(gap == 1){
//                     dp[i][j] = (s[i] == s[j]) ? 2: 1;
//                 } else{
//                     if(s[i] == s[j]){
//                         if(isp[i+1][j-1] == true){
//                             dp[i][j] = 2 + dp[i+1][j-1];
//                         } else{
//                             dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//                         }
//                     } else{
//                         dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//                     }
//                     // dp[i][j] = (s[i] == s[j]) ? 2 + dp[i+1][j-1] :
//                                     // max(dp[i+1][j], dp[i][j-1]);
//                 }                
                
//                 if(dp[i][j] > omax){
//                     omax = dp[i][j];
//                     I = i;
//                     J = j;
//                 }
//             }
//         }
        
//         return s.substr(I, J-I+1);
//     }
};

int main(){
    string s;cin>>s;
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
}
