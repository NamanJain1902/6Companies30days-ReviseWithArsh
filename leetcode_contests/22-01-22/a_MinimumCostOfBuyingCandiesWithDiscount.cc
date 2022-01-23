class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int n = cost.size();
        int ans = 0; 
        for(int i=1; i<=n; ++i){
            ans += cost[i-1];
            if(i % 3 == 0){
                ans -= cost[i-1];
            }
        }
        return ans;
    }
};
