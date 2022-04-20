class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};
        
        vector<vector<int>> ret;
        ret.push_back({1});ret.push_back({1, 1});
        
        for(int i=2; i<numRows; ++i) {          
            vector<int> t;
            t.push_back(1);
            for(int j=0; j<ret[i-1].size() - 1; j++) {
                t.push_back(ret[i-1][j] + ret[i-1][j+1]);
            }
            t.push_back(1);
            ret.push_back(t);
            t.clear();
        }
        return ret;
    }
};