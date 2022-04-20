
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, int> m;
    vector<int> dp;
    int maxPoints(int num) {
        if(num == 0){
            return 0;
        }
        if(num == 1){
            return m[1];
        }
        
        if(dp[num] != -1) return dp[num];
        
        return dp[num] = max(maxPoints(num-1), m[num] + maxPoints(num - 2));
    }

    int deleteAndEarn(vector<int>& nums) {
        int num = -1;
        for(auto x: nums){
            m[x] += x;
            num = max(num, x);
        }
        int n = nums.size();
        
        // dp.resize(num+1, -1);
        // return maxPoints(num);
        
        // dp.resize(num+1, 0); // stores the maximum amount of points we can gain
        // if we only considered numbers from 0 to num(inclusive).
        int maxnum = num;
        // dp[1] = m[1];
        
        if(maxnum < n + n * log(n)){
            // approach 3
            int prev2 = 0;
            int prev = m[1];
            for(int i=2; i<=maxnum; ++i) {
                int curr = max(prev, prev2 + m[i]);
                prev2 = prev;
                prev = curr;
            }
            return prev;
        } else {
            // approach 4
            int prev2 = 0;
            int prev = m[nums[0]], curr;
            for(int i=1; i<n; ++i) {
                if(abs(nums[i]-prev) == 1) {
                    curr  = max(prev, prev2 + m[nums[i]]);
                    prev2 = prev;
                    prev  = curr;
                } else {
                    prev2 = prev;
                    prev += m[nums[i]];
                }
            }
            
            return prev;
        }
    }

};

int main(){
    int n;
    // cin >> n;
    Solution sol;
    vector<int> v = {2,2,3,3,3,4};

    cout << sol.deleteAndEarn(v) << endl;
    return 0;
}
