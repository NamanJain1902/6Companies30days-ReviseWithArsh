// Attempt 1:AC:: without heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> m;
        vector<pair<int, int>> vp; 
        for(auto x: nums){
            m[x]++;
        }
        for(auto p: m){
            vp.push_back(p);
        }
        vector<int> ret;
        sort(vp.begin(), vp.end(), [&](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });

        for(auto [a, b]: vp) {
            ret.push_back(a);
            if(k==1)break;
            k--;
        }
        return ret;
    }
};

// Attepmt 2:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>> pq;
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
       while(k--){
           temp.push_back(pq.top().second);
           pq.pop();
       }
        return temp;
    }
};


