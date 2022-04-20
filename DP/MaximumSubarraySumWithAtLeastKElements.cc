/**
* @author NamanJain1902
* On: 18/04/2022 
* At: 08:28:21
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("avx,avx2")

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <numeric>
#include <climits>

#include <array>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
 
#include <cstring>
#include <ostream>
#include <type_traits>
#include <utility>
#include <chrono>
#include <random>
 
using namespace std;

#define pr pair<int, int>
#define pb push_back
#define s second
#define f first
#define ll long long
#define int long long int
#define sz(x) ((int)x.size())

const int MAX = 100000 + 5;
const int HMAX = 1000000007;

int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}

/*
7
2 -4 5 1 -2 3 5
3
*/
void solve(){
  int n;cin>>n;
  vector<int> v(n);
  for(auto &x: v) cin >> x;
  int k; cin >> k;

  // kadane
  vector<int> dp(n);
  dp[0] = v[0];
  for(int i=1; i<n; ++i) {
    if(dp[i-1] > 0) {
      dp[i] = dp[i-1] + v[i] ;
    } else {
      dp[i] = v[i];
    }
  }

  int window_sum = 0;
  for(int i=0; i<k; ++i) {
    window_sum += v[i];
  }

  int osum = window_sum;
  
  for(int i=k; i<n; ++i) {
    window_sum += (v[i] - v[i-k]);
    if(window_sum > osum){
      osum = window_sum;
    }
    if(window_sum + dp[i-k] > osum) {
      osum = window_sum + dp[i-k];
    }
  }

  // cout << "\nMaximum subarray sum with at least K elements is " << osum << endl;
  cout << osum << endl;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
  int t=1;
  // cin >> t;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
