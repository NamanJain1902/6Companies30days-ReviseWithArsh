#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> v(n);
    for(auto &x: v)cin>>x;
    vector<vector<int>> dp(n-1, vector<int>(n-1, 0));

    for(int g=0; g<dp.size(); g++) {
        for(int i=0, j=g; j<dp.size(); ++i, j++){
            if(g == 0){
                dp[i][j] = 0;
            } else if(g == 1){
                dp[i][j] = (v[i] * v[j] * v[j+1]);
            } else {
                // dp -> i,k left half and k+1,j right half
                // v -> i*(k+1) left half and (k+1)*(j+1) right half
                int mini = INT_MAX;               
                for(int  k=i; k<j; ++k){
                    int left = dp[i][k];
                    int right = dp[k+1][j];
                    int mult = (v[i] * v[k+1] * v[j+1]);
                    int tc = left + right + mult;
                    mini = min(mini, tc);
                }
                dp[i][j] = mini;
            }
        }
    }

    cout << dp[0][dp.size()-1] << endl;
}
