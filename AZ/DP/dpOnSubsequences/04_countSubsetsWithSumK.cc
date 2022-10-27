#include<cstring>

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    if(n == 1) {
        return num[0] == tar;
    }
    // Write your code here.
    int dp[n+1][tar+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; ++i) {
        dp[i][0] = 1;
    }
    
    for(int i=1; i<=n; ++i) {
        // j==0 for handling cases when element is 0.
        for(int j=0; j<=tar; ++j) {
            dp[i][j] = dp[i-1][j];
            if(num[i-1] <= j) {
                dp[i][j] += dp[i-1][j-num[i-1]];
            }
        }
    }
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=tar; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][tar];
}
