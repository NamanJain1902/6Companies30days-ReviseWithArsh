#include<bits/stdc++.h>
using namespace std;


// O(n^3)
int solve0(int k, int n, int *arr) {
    
    int dp[2][n];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=k; ++i) {
        for(int j=1; j<n; ++j) {
            int maxi = dp[(i%2)][j-1]; // if all transactions completed on the day before            
            // diff(arr[j], arr[k]) +  dp[i-i][k]
            for(int k=0; k<j; ++k) {
                maxi = max(maxi, arr[j] - arr[k] + dp[(i+1)%2][k]);
            }      

            dp[i%2][j] = maxi;
        }
    }
    return dp[k%2][n-1];
}

// O(n^2)
int solve(int k, int n, int *arr) {
    
    int dp[2][n];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=k; ++i) {
        int maxi = INT_MIN;
        for(int j=1; j<n; ++j) {
            maxi = max(maxi, dp[(i+1)%2][j-1] - arr[j-1]);
            dp[i%2][j] = max(dp[i%2][j-1], maxi + arr[j]);
        }
    }
    return dp[k%2][n-1];
}


            // int w = arr[j];
            // int y = arr[j-1];            
            // int v = w - y;
            
            // if(j == 1){
            //     dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] - arr[j-1] + arr[j]);
            //     maxi = dp[i][j];
            //     continue;
            // } 
            // maxi = max(v, v + maxi);
int main() {
    
    int k, n;cin>>k>>n;
    int prices[n];

    for(int i=0; i<n; ++i) {
        cin >> prices[i];
    }

    int result = solve(k, n, prices);
    cout << result << endl;
}
