#include <iostream>
#include <vector>

using namespace std;

// O(2^N)
vector<vector<int>> dp;
int rec(vector<int> prices, int idx, bool bought) { 
    if(idx == prices.size()) {
        return 0;
    }
    if(dp[idx][bought] != -1) return dp[idx][bought];

    int profit = 0;
    if(!bought) {
        profit = max(-prices[idx] + rec(prices, idx + 1, 1),
                     0 + rec(prices, idx + 1, 0));
    } else {
        profit = max(prices[idx] + rec(prices, idx + 1, 0),
                    0 + rec(prices, idx + 1, 1));
    }
    return dp[idx][bought] = profit;
}

// O(N)
void transactions(vector<int> arr){
  // infinite transactions allowed
  // and there should be no overlapping 
  // transaction.
  // i.e. one transaction needs to be closed
  // before opening another transaction.

  int buying_day = 0;
  int selling_day = 0;
  int total_profit = 0;
  int total_days = arr.size();
  int current_profit = 0;

  for(int i=1; i<total_days; ++i) {
    // considering each day as potential
    // selling day
    selling_day = i;
    if(arr[selling_day] - arr[buying_day] > 0) {
      current_profit = max(current_profit, arr[selling_day] - arr[buying_day]);
    } else {
      total_profit += current_profit;
      buying_day = selling_day;
      current_profit = 0;
    }
  } 

  total_profit += current_profit;

  cout << total_profit << "\n";

}
  
int main() {
  int n ;
  cin>>n;
  vector<int> arr(n,0);
  for (int i = 0; i < arr.size(); i++) {
    cin>> arr[i];
  }
  
  transactions(arr);
  dp.resize(n, vector<int>(2, -1));
  int ans = rec(arr, 0, 0);
  cout << ans << endl;
  return 0;
}
