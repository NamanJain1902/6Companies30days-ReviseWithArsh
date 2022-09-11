#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
const int INF = 1e17;
const int NINF = INF*(-1);
 
struct triplet{
	int first;
	int second;
	int third;
};
 
int n, m;	
vector<triplet> edges;
vector<int> dist;
 
void bellman_ford()
{
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], NINF);
		}
	} // n relaxations
 
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = max(dist[v], NINF);
			if(dist[u]+d < dist[v])
			{
				dist[v] = NINF;
			}
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	edges.resize(m);
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		inp.third *= -1; 
		edges[i] = inp;
	}
 
	for(int i = 2; i <= n; ++i)
	{
		dist[i] = INF;
	}
 
	bellman_ford();
	if(dist[n] == NINF)
	{
		cout << -1 << endl;
		return 0;
	} 
	cout << dist[n] * (-1) << endl;
}



// /**
// * @author NamanJain1902
// * On: 24/07/2022 
// * At: 17:11:22
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
// const int HMAX = 1e17;;
// const int HMIN = (-1 * HMAX);

// int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
// void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
// int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}

// struct Edge{
//   int u, v, wt;
// };

// int n, m;
// vector<Edge> edges;
// vector<int> dist;

// void bellman_ford(){
//     for(int i=1; i<n; ++i) {
//       for(auto edge: edges) {
//         if(dist[edge.u] + edge.wt < dist[edge.v]) {
//           dist[edge.v] = min(dist[edge.v], dist[edge.u] + edge.wt);
//           dist[edge.v] = max(dist[edge.v], HMIN);
//         }
//       }
//     }

//     for(auto edge: edges) {
//       if(dist[edge.u] + edge.wt < dist[edge.v]) {
//         dist[edge.v] = HMIN;
//       }
//     }
// }

// void solve(){
//     cin >> n >> m;
//     int score = 0;
//     // each tunnel increase/decrease score by x
//     // may go through a tunnel several times
//     // go from 1 to n
//     // maximum score you can get.
//     dist.resize(n+1, HMAX);
//     dist[1]=dist[0]=0;
//     edges.resize(m);
//     for(int i=1;i<=m;++i){
//       int a, b, wt;
//       cin >> a >> b >> wt;
//       edges.push_back({a, b, -1*wt});
//       // edges.push_back({b, a, -1*wt});
//     }
//     bellman_ford();
//     // for(auto x: dist) {
//     //   cout << x<<endl;
//     // }
//     if(dist[n] == HMIN) {
//       cout << -1 << endl;
//       return;
//     }
//     cout << dist[n] * (-1) << endl;
// }

// signed main(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
//   ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
//   // int t;
//   // cin >> t;
//   for(int i=1; i<=t; ++i){
//     solve();
//   }
// }
