#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursive(vector<int> &cost, int idx, int fair) {
        if(idx < 0){
            return INT_MAX;
        }
        if(idx == 0 or idx == 1) {
            return fair;
        }
        int one_step = recursive(cost, idx - 1, fair + cost[idx - 1]);
        int two_step = recursive(cost, idx - 2, fair + cost[idx - 2]);
        return min(one_step, two_step);
    }
    
    int memoized(vector<int> &cost, int idx, vector<int> &dp) {
        if(idx < 0){
            return 0;
        }
        if(idx == 0 or idx == 1) {
            return cost[idx];
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int one_step = memoized(cost, idx - 1, dp);
        int two_step = memoized(cost, idx - 2, dp);
        return dp[idx] = cost[idx] + min(one_step, two_step);
    }

    int tabu(vector<int> &cost) {
        // 1-D DP array
        int n = cost.size();
        vector<int> dp(n+1, 0);
        int prev2 = cost[0];
        int prev  = (cost.size() >= 2) ? cost[1]: prev2;
        for(int i=2; i<n; ++i) {
            int curr = min(prev, prev2) + cost[i]; 
            prev2 = prev;
            prev  = curr;
        }
        return min(prev2, prev);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int ret = min(memoized(cost, n-1, dp), memoized(cost, n-2, dp));
        for(auto x: dp){
            cout << x << ' ';
        }
        puts("");
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    int n = cost.size();
    int fair = 0;
    cout << sol.recursive(cost, n, fair) << endl;
    cout << sol.minCostClimbingStairs(cost) << endl;
    cout << sol.tabu(cost) << endl;
}
