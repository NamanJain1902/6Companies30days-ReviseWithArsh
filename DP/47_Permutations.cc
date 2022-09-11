void helper(vector<vector<int>>& res, vector<int>& nums, int pos) {
    
    if (pos == nums.size()) {
        res.push_back(nums);
    } else {
        for (int i = pos; i < nums.size(); ++i) {
            if (i > pos && nums[i] == nums[pos]) continue;
            swap(nums[pos], nums[i]);
            helper(res, nums, pos + 1);

        }
        // restore nums
        for (int i = nums.size() - 1; i > pos; --i) {
            swap(nums[pos], nums[i]);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    helper(res, nums, 0);
    return res;
}


class Solution {
public:
    void dfs(vector<vector<int>> &ret, vector<int> &nums, vector<int> &used, vector<int> &temp, int idx) {
        
        if(temp.size() == nums.size()) {
            ret.push_back(temp);
            return;
        }
        
        for(int i=0; i<(int)nums.size(); ++i) {
            if(i > 0 and nums[i] == nums[i-1] and !used[i-1]) continue;
            if(used[i] != 1){
                temp.push_back(nums[i]);
                used[i] = 1;
                dfs(ret, nums, used, temp, i);
                temp.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> used(n), temp;
        int idx = 0; // 
        
        
        dfs(ret, nums, used, temp, idx);
        
        return ret;
    }
};