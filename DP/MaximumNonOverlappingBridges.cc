#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> vp(n);

    for(auto &x: vp){
        cin >> x.first >> x.second;
    }

    sort(vp.begin(), vp.end(), [&](pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    });
    
    for(auto x: vp){
    cout << x.first << ' ' << x.second  << endl;
    }

    vector<int> dp(n, 1);

    for(int  i=1; i<n; ++i) {
        if(vp[i].second > vp[i-1].second){
            dp[i] += dp[i-1]; 
        } else {
            dp[i] = dp[i-1];
        }
    }

    for(auto x: dp){cout << x << " " << endl;}
    
    cout << dp[n-1] << endl;
}

