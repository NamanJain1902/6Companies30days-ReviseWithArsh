// vector<vector<long long int>> dp;
#include<bits/stdc++.h>
using namespace std;

bool rec(vector<int> &v, int tar, int idx, int csum, vector<vector<int>> &dp) {
    if(csum == tar) {
        return true;
    }
    if(csum > tar) return false;
    if(idx == v.size()) return false;
    if(dp[csum][idx] != 0) return dp[idx][csum];
    
    if(dp[csum][idx] = rec(v, tar, idx + 1, csum + v[idx], dp)) return true;
    if(dp[csum][idx] = rec(v, tar, idx + 1, csum, dp)) return true;

    return false;
}

int memo(vector<int> &v, int tar, int idx, vector<vector<int>> &dp) {
    if(tar == 0) return 1;    
    if(tar < 0)  return 0;
    if(idx == v.size()) return 0;
    if(dp[idx][tar] != -1) return dp[idx][tar];
    
    int taken =  memo(v, tar - v[idx], idx + 1, dp);
    int not_taken = memo(v, tar, idx + 1, dp);
    
    return dp[idx][tar] = (taken | not_taken);
}

bool subsetSumToK(int n, int k, vector<int> &v) {
    // Write your code here.
    vector<vector<int>> dp;
    dp.resize(n+1, vector<int>(k+1, 0));
//     dp.resize()
//     unordered_map<long long int, unordered_map<int, int>> dp;
//     return  rec(arr, k, 0, 0, dp);
//     return memo(arr, k, 0, dp);
        for(int i=0; i<=n; ++i) {
            dp[i][0] = 1;
        }
//        if(v[0] <= k)
//         dp[0][v[0]] = 1;
       for(int i=1; i<=n; ++i) {
           for(int j=1; j<=k; ++j) {
               int not_take = dp[i-1][j];
               int take = dp[i][j];
               if(v[i-1] <= j) {
                   take = dp[i-1][j - v[i-1]];
               }
//                if(j - v[i] >= 0) {
//                    dp[i][j] = ( | dp[i-1][j - v[i]]);
//                } else {
//                    dp[i][j] = dp[i-1][j];
//                }
               dp[i][j] = take | not_take;
           }
       }
    return dp[n][k];
  
//     bool dp[n+1][n+1];
//     memset(dp, 0, sizeof(dp));
    
//     for(int i=0; i<n; ++i) {
//         for(int j=0; j<n; j++) {
                    
//         }
//     }
}

// approach 1: generate all possible subsequences 
// and check if there's any subsequence that adds 
// to K. If after generating such subsequences no
// such subsequence found. Then return false, 
// else return true.

// there's overlapping substructure problem in this.
// for a given index considered to be part of subsequence
// we can store sum it'll contribute in both cases
// i.e. when taken and not taken.


