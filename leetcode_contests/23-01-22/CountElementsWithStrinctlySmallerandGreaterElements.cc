class Solution {
public:
    int countElements(vector<int>& nums) {
        
        int mini = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int cnt=0;
        for(auto x: nums){
            if(x > mini and x < mx){
                cnt++;
            }
        }
        
        return cnt;
        
//         // sort(nums.begin(), nums.end());
//         int cnt = 0;
//         vector<pair<int, int>> temp;
        
//         for(int i=0; i<nums.begin()){
//             if()
//         }
        
        
//         set<int> s;
//         vector<int> v;
//         int n = nums.size();
        
//         for(int i=1; i<n-1; ++i){
            
//             int li = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
//             int ui = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
//             if(li-1 > 0 and nums[ui] > nums[i]){
//                 cnt++;
//             }
//             // if(li != i )
//             // if( && )
//         }
        
        // v.push_back(nums[0]);
        // vector<int> dp(nums[nums.back()]+1, 1);
        // for(int i=1; i<n; ++i){
        //     if(v.back() == nums[i]){
        //         dp[nums[i]]++;
        //     }
        //     if(v.back() != nums[i]){
        //         v.push_back(nums[i]);
        //     }
        // }
        // for(int i=1; i<(int)v.size()-1; ++i){
        //     if(v[i] != v[i-1] and v[i] !=v[i+1]){
        //         cnt += dp[v[i]];
        //     }
        // }
        // return cnt;
    }
};

