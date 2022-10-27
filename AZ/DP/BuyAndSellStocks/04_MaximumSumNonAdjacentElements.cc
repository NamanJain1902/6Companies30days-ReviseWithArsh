// f(i) => maximum subsequence sum from 0 to i such that
// no two  elements are adjacent in the given array.

// top-down approach
int rec(vector<int> &nums, int idx, int *dp) {
    if(idx == 0) return nums[idx];
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    
    int taken     = nums[idx] + rec(nums, idx - 2, dp);
    int not_taken = 0 + rec(nums, idx - 1, dp);
    
    return dp[idx] = max(taken, not_taken);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
//     int dp[nums.size() + 1]{0};
//     dp[0] = 0;
//     dp[1] = nums[0];
    int non_adjacent = 0;
    int adjacent = 0;
    int ans;
    // bottom-up approach
    for(int i=0; i<nums.size(); ++i) {
        int temp = adjacent;
        int taken = nums[i] + non_adjacent;
        int not_taken = 0 + adjacent;
        adjacent = max(taken, not_taken);
        non_adjacent = temp;
    }
    return adjacent;
//     for(int i=0; i<nums.size(); ++i) dp[i] = 0;
//     return rec(nums, nums.size() - 1, dp);
}
