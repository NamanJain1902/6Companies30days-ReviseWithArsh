#include<bits/stdc++.h>
using namespace std;

// O(N^2)
void kadane(vector<int> &price){
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(j - i < 0){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = ((dp[i][j-i] + price[i-1]) > dp[i-1][j]) ?
                                (dp[i][j-i] + price[i-1]) :
                                dp[i-1][j];
            }
        }
    }
    cout << dp[n][n]  << endl;
}

// left to right strategy
void sol(vector<int> &price)
{
    vector<int> prices(price.size()+1);
    for(int i=0; i<price.size(); ++i){
        prices[i+1] = price[i];
    }
    
    vector<int> dp(prices.size());
    dp[0]=0;
    dp[1]=prices[1];
    for(int i=2; i<prices.size();  ++i){
        dp[i] = prices[i];

        int p=1;
        int q=i-1;

        while(p<=q){
            dp[i] = max(dp[i], dp[p] + dp[q]);
            p++;q--;
        }
    }

    cout  << dp[price.size()]  << endl;

}
int main()
{
    int n;cin>>n;
    vector<int> price(n);
    for(auto &x: price) cin >> x;  
}

