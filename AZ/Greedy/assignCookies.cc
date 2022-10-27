class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int len = min(g.size(), s.size());
        int i,j;
        for(i=0, j=0; i<g.size() and j < s.size(); ++j) {
            if(s[j] >= g[i]) i++;
        }
        return i;
    }
};
