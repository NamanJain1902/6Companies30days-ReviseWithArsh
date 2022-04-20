class Solution {
public:
    // finding every possible permutation of nums sort them and finding next to given nums array ... O(N!) to find all posiible permutation of given array
    // how do we find it?
    // well, it's just rearrangement of array element one at a time or shifting the array left or right one by one for size(array) times since shifting once takes O(n) and we'll repeat this for n,n-1,n-2,...1 times time complexity is O(n);
    void reverse(vector<int> &nums, int start) {
        int left  = start;
        int right = nums.size() - 1;
        while(left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
    void nextPermutation(vector<int>& nums) {    
        int n = nums.size();
        int i = n - 2;
        
        while(i>=0 and nums[i+1] <= nums[i]) {
            i--;
        }
        if(i >= 0) {
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1);
    }
};
