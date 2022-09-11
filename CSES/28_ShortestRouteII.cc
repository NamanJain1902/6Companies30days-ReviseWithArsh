/**
* @author NamanJain1902
* On: 24/07/2022 
* At: 06:41:12
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


int n, m, q;
vector<vector<int>> dist;
vector<vector<int>> graph;
vector<int> visited;
vector<bool> Set;
/*
dijkstra's algo funda
1. Assign infinite distance to each node except src.
2. On visiting a node, mark it as visited
3. Add all it's neighboring node to a set.
4. Choose the node which is at smallest distance from source node.
5. Repeat the process.
*/

int min_distance(vector<int> d) {
    int mini = INT_MAX;
    for(int i=0; i<n; ++i) {
        mini = min(mini, d[i]);
    }
    return mini;

}

void dijkstra_single_source(int src) {
    // visited[src] = true;

    dist[src][src] = 0;
    for(int c=0; c<n; ++c)  {
        int u = min_distance(dist[src]);

        Set[u] = true;

        // update dist value of the adjacent vertices of the picked vertices.
        for(int v=0; v<n; ++v) {
            if(!Set[v] and graph[u][v] and dist[src][u] != INT_MAX
                and dist[src][u] + graph[u][v] < dist[src][v]) {
                    dist[src][v] = dist[src][u] + graph[u][v];
                }
        }
    }

}

void solve(){
    cin >> n >> m;// >> q;

    graph.resize(n+1);
    dist.resize(n+1, vector<int>(n+1, INT_MAX));
    Set.resize(n+1, false);
    visited.resize(n+1, false);
    // dist[i][j] represents shortest distance 
    // between city i and city j.

    for(int i=1; i<=m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    // precomputing shortest distance 
    // between each pair of cities.
    // for(int i=1; i<=n; ++i){
        visited = vector<int>(n+1, -1);
        // Set     = vector<int>(n+1, false);
        Set.resize(n+1, false);
        int src= 1;
        dijkstra_single_source(src);
        Set.clear();
        visited.clear();
    // }
    for(auto x: dist[1]) {
        cout <<  x << " ";
    }
    puts("");
    // for(int i=1; i<=q; ++i){
    //     int firstCity, secondCity;
    //     cin >> firstCity >> secondCity;

    //     cout << (dist[firstCity][secondCity]) << endl;
    // }
}

signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
//   int t;
//   cin >> t;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
