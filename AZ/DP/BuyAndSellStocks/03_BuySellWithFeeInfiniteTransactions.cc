#include <iostream>
#include <vector>
using namespace std;

int fee;
vector<vector<int>> dp;
int rec(vector<int> prices, int idx, bool bought) {
  if(idx == prices.size()) {
    return 0;
  }
  if(dp[idx][bought] != -1) return dp[idx][bought];

  int profit = 0;
  if(!bought) {
      profit = max(-prices[idx] -fee /* like upfront fee */ 
                   + rec(prices, idx + 1, 1),
                  0 + rec(prices, idx + 1, 0));
  } else {
    profit = max(prices[idx] + rec(prices, idx + 1, 0),
                 0 + rec(prices, idx + 1, 1));
  }
  return dp[idx][bought] = profit;
}


int main() {
  int n;
  cin>> n;
  vector<int> arr(n,0);
  for (int i = 0; i < arr.size(); i++) {
        cin>> arr[i];
  }
  cin>> fee;
  dp.resize(n, vector<int>(2, -1));
  cout << rec(arr, 0, 0) << endl;
  return 0;
}

