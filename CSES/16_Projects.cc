/*
Even though days can go up to 109, we only care about days where we either start or
just finished a project. So before doing anything else, we compress all days to their 
index among all interesting days (i.e days corresponding to ai or bi+1 for some i). 
This way, days range from 0 to less than 2n≤4⋅105.

dp[i] = maximum amount of money we can earn before day i.

On day i, maybe we just did nothing, so we earn what we earned on day i-1, i.e dp[i-1]. 
Otherwise, we just finished some project. We earned some money doing the project,
and use dp[start of project] to know how much money we could have earned before 
starting the project. Loop through all projects finishing just before day i, and 
take the best one.

The complexity is O(n⋅logn), log comes from day compression.

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int,int> compress;
  vector<int> a(n), b(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> p[i];
    b[i]++;
    compress[a[i]], compress[b[i]];
  }

  int coords = 0;
  for (auto&v : compress) {
    v.second = coords++;
  }

  vector<vector<pair<int,int>>> project(coords);
  for (int i = 0; i < n; i++) {
    project[ compress[b[i]] ].emplace_back( compress[a[i]], p[i] );
  }

  vector<long long> dp(coords, 0);
  for (int i = 0; i < coords; i++) {
    if (i > 0) {
      dp[i] = dp[i-1];
    }
    for (auto p : project[i]) {
      dp[i] = max(dp[i], dp[p.first]+p.second);
    }
  }
  cout << dp[coords-1] << endl;
}

// /**
// * @author NamanJain1902
// * On: 14/07/2022 
// * At: 15:56:18
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

// struct Project {
//     int start;
//     int end;
//     int money;
// };
// void solve() {
//     int n;
//     cin >> n;
//     vector<Project> v(n);
//     for(auto &x: v){
//         cin >> x.start >> x.end >> x.money;
//     }

//     int amount = 0;
//     sort(v.begin(), v.end(), [&](Project a, Project b) {
//         double r1 = (a.money * 1.0 / (a.end - a.start));
//         double r2 = (b.money * 1.0 / (b.end - b.start));
//         if(r1 == r2) {
//             return a.start < b.start;
//         } else {
//             return r1 > r2;
//         }
//     });

//     // for(auto x: v) {
//     //     cout << x.start << " " << x.end << " " << x.money << "\n";
//     // }

//     int canStart = 0;
//     for(int i=0; i<v.size(); ++i) {
//         if(v[i].start > canStart) {
//             amount += v[i].money;
//             canStart = v[i].end;
//         }
//     }

//     cout << amount << "\n";
// }

// signed main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
//   for(int i=1; i<=t; ++i){
//     solve();
//   }
// }
