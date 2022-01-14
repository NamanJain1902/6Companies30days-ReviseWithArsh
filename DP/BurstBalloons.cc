#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int g=0; g<dp.size(); ++g){
        for(int i=0, j=g; j<dp.size(); ++j, i++){
            // if(g==0){
            //     dp[i][j] = nums[i];
            // } else if(g==1){
            //     dp[i][j] = nums[i] * nums[j];
            // } else {
                int mx = INT_MIN;
                for(int k=i; k<=j; ++k){
                    int lc = (k==i)?0: dp[i][k-1];
                    int rc = (k==j)?0: dp[k+1][j];
                    int mult = (i==0  ? 1: nums[i-1]) * nums[k] * (j == n-1?1:nums[j+1]);
                    mx = max(mx, lc + rc + mult);
                }
                dp[i][j] = mx;
            // }
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x: v)cin>>x;
    cout << maxCoins(v) << endl;
}
