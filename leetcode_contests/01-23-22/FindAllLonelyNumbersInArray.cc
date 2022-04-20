class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        if(n == 1) return nums;
        
        unordered_map<int, int> umap;
        
        for(auto x: nums) umap[x]++;
        vector<int> ret;
        for(int i=0; i<n; ++i){
            
            if(umap[nums[i]] == 1 and umap.find(nums[i] -1) == umap.end() and umap.find(nums[i]+1) == umap.end())
                ret.push_back(nums[i]);
        }
        return ret;
    }
};
