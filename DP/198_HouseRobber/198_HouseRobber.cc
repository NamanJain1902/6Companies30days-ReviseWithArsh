
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rec(vector<int> &nums, int idx, bool included){
        
        if(idx == nums.size()){
            return 0;
        }
        int inc =  0, exc = 0;
        if(included){
            // exclude
            exc = rec(nums, idx + 1, false);
        } else {
            // include
            inc = nums[idx] + rec(nums, idx + 1, true);
        }
        
        return max(inc, exc);
    }
    int memo(vector<int> &nums, int idx, vector<int> &dp) {
        
        if(idx == 0) return nums[idx];
        else if(idx < 0) return 0;
        else if(dp[idx] != -1) return dp[idx];
        
        int pick  = nums[idx] + memo(nums, idx - 2, dp);
        int npick = 0 + memo(nums, idx - 1, dp);
        
        return dp[idx] = max(pick, npick);
    }
   
    int tabu(vector<int> &nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev  = nums[0];
        
        for(int i=1; i<n; ++i) {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return max(prev, prev2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return rec(nums, 0, false);
        vector<int> dp(n+1, -1);
        return rec2(nums, nums.size() - 1, dp);
    }
};



int main(){
    int n;
    // cin >> n;
    vector<int> v = {1,2,3,1};
    
    Solution sol;
    cout << sol.rec2(v) << endl;
    return 0;
}
    