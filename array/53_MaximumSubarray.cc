class Solution {
public:
    int max(int a, int b){
        return (a >= b ? a : b);
    }
    int maxSubArray(vector<int>& nums) {
        
//         long long maxsum = INT_MIN;
//         int n = nums.size();
//         long long tradition = 0;\
            
//         for(int i=0; i<n; ++i) {
            
//             if(tradition + nums[i] > 0) {  
//                 tradition = max(tradition + nums[i], nums[i]);
//             } else {
//                 tradition = nums[i];
//             }          
//             maxsum = max(maxsum, tradition);
//         }
        
//         return maxsum;
        
        int mx = INT_MIN;
        rec(nums, 0, mx, 0);
        return mx;
                
    }
    void rec(vector<int> &nums, int sum, int &mx, int idx) {
        
        if(idx == nums.size()) {
            return;
        }
        
        sum += nums[idx];
        mx = max(sum, mx);
        if(sum < 0){
            sum = 0;
        }
        
        rec(nums, sum, mx, idx + 1);
    }
};

/**
Case 1: All numbers are negative so we will choose least negative.
Case 2: All numbers are positive so we will add all of them.
Case 3: if sum is positive adding add current number to old streak 
        else start a new one
        new element has two choices :-> this makes it a DP problem.
            i/ join the family 
            ii/ start it's own
*/