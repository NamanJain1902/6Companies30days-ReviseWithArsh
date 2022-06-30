/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

*/

// Approach 1: Floyd's Tortoise and Hare (Cycle Detection)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // with space: hashing using map or vector(size(max(nums)+1))
        
        int tortoise = nums[0];
        int hare     = nums[0];
        
        do{
            tortoise = nums[tortoise];
            hare     = nums[nums[hare]];
        } while(tortoise != hare);
        
        // find the "entrance" to the cycle
        tortoise = nums[0];
        while(tortoise != hare) {
            tortoise = nums[tortoise];
            hare     = nums[hare];
        }
        
        return hare;
    }
};



// Approach 2: Negative Marking
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i=0; i<n; ++i){
            int cur = abs(nums[i]);
            if(nums[cur] < 0){ ans = cur; break;}
            nums[cur] *= -1;
        }
        // restore the numbers
        for(auto &x: nums){
            x = abs(x);
        }
        
        return ans;
    }
};