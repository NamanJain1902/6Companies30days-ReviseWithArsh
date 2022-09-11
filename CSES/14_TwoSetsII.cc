#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  int target = n*(n+1)/2;
  if (target%2) {
    cout << 0 << endl;
    return 0;
  }
  target /= 2;

  vector<vector<int>> dp(n,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-i;
      if (left >= 0) {
	(dp[i][j] += dp[i-1][left]) %= mod;
      }
    }
  }
  cout << dp[n-1][target] << endl;
}


// /**
// * @author NamanJain1902
// * On: 12/07/2022 
// * At: 19:13:41
// */

// #pragma GCC optimize ("O3")
// #pragma GCC target ("avx,avx2")

// #include <algorithm>
// #include <cassert>
// #include <iostream>
// #include <memory>
// #include <numeric>
// #include <climits>

// #include <array>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <tuple>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>
// #include <list>
 
// #include <cstring>
// #include <ostream>
// #include <type_traits>
// #include <utility>
// #include <chrono>
// #include <random>
 
// using namespace std;

// #define pr pair<int, int>
// #define pb push_back
// #define s second
// #define f first
// #define ll long long
// #define int long long int
// #define sz(x) ((int)x.size())

// const int MAX = 100000 + 5;
// const int HMAX = 1000000007;

// int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
// void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
// int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}


// void rec(int n, int sum1, int sum2, int i, int &cnt) {
//     if(i > n){ 
//         if(sum1 == sum2) cnt = (cnt + 1) % HMAX;
//         return;
//     }

//     rec(n, sum1 + i, sum2, i + 1, cnt);
//     rec(n, sum1, sum2 + i, i + 1, cnt);
// }

// void solve(){
//     int n;
//     cin >> n;

//     int sum1=0, sum2=0, cnt=0;
//     rec(n, sum1, sum2, 1, cnt);

//     cout << (cnt / 2) % HMAX << endl;
// }

// signed main(){
// // #ifndef ONLINE_JUDGE
// // freopen("input.txt", "r", stdin);
// // freopen("output.txt", "w", stdout);
// // #endif
//   ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
// //   int t;
// //   cin >> t;
//   for(int i=1; i<=t; ++i){
//     solve();
//   }
// }
