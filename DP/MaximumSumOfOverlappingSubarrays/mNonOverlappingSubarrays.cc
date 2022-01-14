#include<bits/stdc++.h>
using namespace std;

int sol(vector<int> &v, int idx, int k, int m, vector<vector<int>> dp, vector<int> &prefixSum){

    if(m == 0)    return 0;

    if(idx >= v.size()){
        return 0;
    }

    if(dp[idx][m] != 0){
        return dp[idx][m];
    }

    int exclude = sol(v, idx+1, k, m, dp, prefixSum);
    int include = prefixSum[idx] + sol(v, idx+k, k, m-1, dp, prefixSum);

    int ans= max(include, exclude);
    dp[idx][m] = ans;
    return ans;
}


int main(){
    int n;cin >> n;
    vector<int> v(n,0);
    for(auto &x: v)cin>>x;
    int k,m;cin>>m>>k;

    vector<int> prefixSum(n, 0);
    int sm=0;
    for(int i=0; i<k;  ++i){sm += v[i];}    
    prefixSum[0]=sm;

    for(int i=k, j=0; i<n; ++i, j++) {
        sm += (v[i] - v[j]);
        prefixSum[i - k + 1] = sm;
    }
    
    vector<vector<int>> dp(n, vector<int>(m));
    cout << sol(v, 0, k, m, dp, prefixSum) << endl;
}