
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(N^2) passed 18/19 test cases : Runtime error on 19th
    int gap_strategy(int target, vector<int> &nums) {
        int n = nums.size();
        int dp[n][n];
        int minlen = INT_MAX;
        for(int gap=0; gap<n; ++gap) {
            for(int i=0,j=gap; j<n; i++, j++) {
                if(gap == 0) {
                    dp[i][j] = nums[i];
                } else if(gap == 1) {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j];
                } else {
                    dp[i][j] = dp[i][j-1] + nums[j];
                }
                
                if(dp[i][j] >= target) {
                    minlen = min(minlen, abs(i-j)+1);
                    return minlen;
                }
            }
        }

        return (minlen != INT_MAX ? minlen : 0);
    }
    int minSubArrayLen_gap_strategy(int target, vector<int>& nums) {
        
        return gap_strategy(target, nums);
    }

    // Time : O(N^2) but AC
    // Space: O(N)
    // using prefix sum to find sum of subarray. 
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int dp[n];
        dp[0] = nums[0];
        for(int i=1; i<n; ++i) {
            dp[i] = dp[i-1] + nums[i];
        }
        
        int minlen = INT_MAX;
        // return gap_strategy(target, nums);
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                int sum = dp[j] - dp[i] + nums[i];
                if(sum >= target) {
                    minlen = min(minlen, (j - i + 1));
                    break; // found the smallest subarray with sum >= target starting with index i, hence move to next index.
                }
            }
        }
        return (minlen != INT_MAX ? minlen : 0);
    }

    // O(N) and O(1) space
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        long long sm=0, minlen=INT_MAX;

        while(j < n and i < n) {
            sm += nums[j];
            while(sm >= target){
                minlen = min(minlen, j - i + 1);
                sm -= nums[i++];
            } 
            j++;
        }
        return (minlen != INT_MAX ? minlen : 0);
    }
    
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol. << endl;
    return 0;
}
    