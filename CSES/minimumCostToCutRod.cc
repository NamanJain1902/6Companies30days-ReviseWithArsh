#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int rec(vector<int> &cuts, int l, int h) {

    if(l > h) return 0;
    if(dp[l][h]  != -1) return dp[l][h];
    
    int mini = INT_MAX;
    for(int i=l; i<=h; ++i) {
        mini = min(mini, cuts[h+1] - cuts[l-1] + rec(cuts, l, i-1) + rec(cuts, i+1, h));
    }

    return dp[l][h] = mini;
}

void minCost(vector<int> &cuts, int len) {
    int n = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(len);
    dp.resize(n+1, vector<int>(n+1, -1));
    sort(cuts.begin(), cuts.end());
    cout << rec(cuts, 1, n) << endl;
}

int main() {
    int len, n;
    cin >> len >> n;
    vector<int> cuts(n);
    for(auto &x: cuts) cin >> x;

    // minCost(cuts, len);
    
}