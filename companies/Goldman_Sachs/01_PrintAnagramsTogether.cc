class Solution{
    public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
    
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;

        for(auto s: string_list){
            string temp = s;
            
            sort(temp.begin(), temp.end());
            
            umap[temp].push_back(s);
        }

        for(auto s: umap){
            res.push_back(s.second);
        }
        return res;
    }
};