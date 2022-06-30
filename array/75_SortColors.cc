class Solution {
public:
//     void sortColors(vector<int>& nums) {
        
//         int low   = 0;
//         int right = nums.size() - 1;
    
//         while(low < right) {
            
//             while(nums[low] == 0) low++;
//             while(nums[right]==2) right--;
            
//             if(nums[low] == 2) swap(nums[low], nums[right]);
            
//             if(nums[right] < nums[low]) swap(nums[right], nums[low]);
//         }
//     }
// Dutch flag algorithm
    void sortColors(vector<int> &nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while(mid <= high) {
            int value = nums[mid];
            
            switch(value) {
                case 0: 
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};