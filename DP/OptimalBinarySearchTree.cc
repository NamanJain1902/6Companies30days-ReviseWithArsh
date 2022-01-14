#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(auto &x: v){cin >> x;}

    vector<int> freq(n);
    for(auto &x: freq){cin >> x;}

    vector<int> freq_sum(n);
    freq_sum[0] = freq[0];
    for(int i=1; i<n; ++i){
        freq_sum[i] = freq_sum[i-1] + freq[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int g=0; g<n; ++g){
        for(int i=0, j=g; j<n; ++i, j++){
            if(g==0){
                dp[i][j] = freq[i];
            } else if(g == 1){
                int f1 = freq[i] + 2 * freq[j];
                int f2 = freq[j] + 2 * freq[i];
                dp[i][j] = min(f1, f2);
            } else {
                int mini =  INT_MAX;
                for(int k=i; k<=j; ++k){
                    int left = (k == i) ? 0 : dp[i][k-1];
                    int right = (k == j) ? 0 : dp[k+1][j];
                    int fs = freq_sum[j] - ((i==0) ? 0 : freq_sum[i-1]);

                    mini = min(mini, (left + right + fs));
                    dp[i][j] = mini;
                }
            }
        }
    }

    cout << dp[0][n-1] << endl;
}
