#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
const int MAXD = 30; // ceil(log2(10^9))

// number of planets and queries
int n, q;
// parent matrix where [i][j] corresponds to i's (2^j)th parent
int parent[MAXN][MAXD];

int jump(int a, int d) {
	for(int i=0; i<MAXD; i++) if(d & (1<<i))
		a = parent[a][i];
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		cin >> parent[i][0];
	}
	// evaluate the parent matrix
	for(int d=1; d<MAXD; d++)
	for(int i=1; i<=n; i++) {
		parent[i][d] = parent[parent[i][d-1]][d-1];
	}
	// process queries
	while(q--) {
		int a, d;
		cin >> a >> d;
		cout << jump(a, d) << '\n';
	}
}
// /**
// * @author NamanJain1902
// * On: 25/07/2022 
// * At: 07:05:39
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

// const int MAX = 2 * 1e5;
// const int HMAX = 1000000007;

// int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
// void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
// int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}
// /*
// 4 3
// 2 1 1 4
// 1 2
// 3 4
// 4 1

// 1 -> 2
// 2 -> 1
// 3 -> 1
// 4 -> 4

// 1->2->1
// 3->1->2->1->2
// 4->4
// */

// vector<vector<int>> graph, dp;
// void solve(){
//     int n, q;
//     cin >> n >> q;

//     int h = ceil(log2(n));
//     dp.resize(h+1, vector<int>(n+1));
//     for(int i=1; i<=n ;++i){
//       int x;
//       cin >> x;
//       dp[0][i] = x;
//     }
//     // preprocessing
//     for(int i=1; i<=h; ++i) {
//       for(int v=1; v<=n; ++v) {
//         dp[i][v] = dp[i-1][dp[i-1][v]]; 
//       }
//     }
//     for(int i=1; i<=q; ++i) {
//       int t, k;
//       cin >> t >> k;
//       for(int j=0; j<30; ++j) {
//         if(k & (1 << j)) {
//           t = dp[j][t];
//         }
//       }
//       cout << t << endl;
//     }
// }
// void sol(){
//     int n, q;
//     cin >> n >> q;
//     // vector<int> v(n);
//     map<int, int> m;
//     for(int i=1; i<=n; ++i) {
//         int x; cin >> x;
//         m[i] = x;
//     }
//     for(int i=1; i<=q; ++i) {
//         int t, times;
//         cin >> t >> times;
//         times %= MAX;
  
//         while(times) {
//             t = m[t];
//             times--;    
//         }
//         cout << t << endl;
//     }
//     return;
// }

// signed main(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
//   ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
// //   int t;
// //   cin >> t;
//   for(int i=1; i<=t; ++i){
//     solve();
//   }
// }
