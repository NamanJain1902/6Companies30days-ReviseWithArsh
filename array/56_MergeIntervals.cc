class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b){ return a[0] < b[0];});
        
        int n = intervals.size();
        vector<vector<int>> ret;

        for(int i=0; i<n; ++i) {            
            if(ret.empty() || ret.back()[1] < intervals[i][0]){
                ret.push_back(intervals[i]);                
            } else{
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
        }
        
        return ret;
    }
};