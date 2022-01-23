class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size()/2;
     vector<int> pos, neg;
        for(auto x: nums){
            if(x<0)neg.push_back(x);
            else pos.push_back(x);
        }
        vector<int> res;
        for(int i=0; i<n; ++i){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
};
