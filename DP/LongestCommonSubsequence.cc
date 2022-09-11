class Solution {
public:
    int rec(string t1, string t2, int i, int j) {
        if(i == t1.length() || j == t2.length()) {
            return 0;
        }
        
        if(t1[i] == t2[j]) {
            return 1 + rec(t1, t2, i+1, j+1);
        } else {
            return max(rec(t1, t2, i+1, j), rec(t1, t2, i, j+1));
        }
    }
        int dp[1005][1005];
     int memo(string t1, string t2, int i, int j) {
        if(i == t1.length() || j == t2.length()) {
            return 0;
        }
         if(dp[i][j] != -1) return dp[i][j];
        
        if(t1[i] == t2[j]) {
            return dp[i][j] = 1 + memo(t1, t2, i+1, j+1);
        } else {
            return dp[i][j] =  max(memo(t1, t2, i+1, j), memo(t1, t2, i, j+1));
        }
    }
    
    int tabu(string t1, string t2) {
        int l1 = t1.length();
        int l2 = t2.length();
        
        int idp[l1+1][l2+1];
        // memset(idp, 0, sizeof(dp));
        
        for(int i=1; i<=l1; ++i) {
            for(int j=1; j<=l2; ++j) {
                
                if(t1[i-1] == t2[j-1]) {
                    idp[i][j] = 1 + idp[i-1][j-1];
                } else {
                    idp[i][j] = max(idp[i][j-1], idp[i-1][j]);
                }
                
            }
        }
        // for(int i=0; i<=l1; ++i){
        //     for(int j=0; j<=l2; ++j) {
        //         cout << idp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return idp[l1][l2];
    }
    int tabu1(string a, string b) {
        short m[2][1000] = {};
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            m[!(i % 2)][j + 1] = a[i] == b[j] ? m[i % 2][j] + 1 : max(m[i % 2][j + 1], m[!(i % 2)][j]);
    return m[a.size() % 2][b.size()];
        //  short m[1001][1001] = {};
        // for (auto i = 0; i < a.size(); ++i)
        //     for (auto j = 0; j < b.size(); ++j)
        //         m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
        // return m[a.size()][b.size()];
    }
    int longestCommonSubsequence(string text1, string text2) {
//         int lt1 = min(text1.length(), text2.length());
//         int lt2 = max(text1.length(), text2.length());
        
//         vector<vector<int>> dp(2, vector<int>(lt2+1, 0));
//             // dp[2][lt2+1]{0};
        
//         for(int i=0; i<lt1; ++i) {
//             for(int j=1; j<=lt2; ++j) {
//                 dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1])  + (text1[i] == text2[j-1]);
//             }
//         }
        
//         for(auto x: dp) {
//             for(auto y: x) {
//                 cout << y << " ";
//             }
//             cout << endl;
//         }
        
//         return dp[lt1%2][lt2];
        
        return tabu1(text1, text2);
         // memset(dp, -1, sizeof(dp));
        // return memo(text1, text2, 0, 0);
        // return rec(text1, text2, 0, 0);
    }
};
