/**
* @author NamanJain1902
* On: 24/07/2022 
* At: 09:48:46
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

int n, m;
vector<int> dist;
vector<vector<pair<int, int>>> graph;
vector<int> visited;


void dijkstra(int src) {

    // mark all cities as unvisited
    fill(visited.begin(), visited.end(), false);

    // set all distance to inf
    fill(dist.begin(), dist.end(), INT_MAX);
    // and set src distance to 0
    dist[src] = 0;
    
    // using multiset as min-prioority queue to extract
    // adjacent city with minimum distance from current city.
    multiset<pair<int, int>> ms;
    ms.insert({0, 1}); // {distance, nodeValue}

    while(!ms.empty()) {
        int cdist = (*ms.begin()).first;
        int node = (*ms.begin()).second;

        ms.erase(ms.begin()); 

        if(visited[node] == true) continue;
        visited[node] = true;

        for(auto childNode: graph[node]) {
            if(visited[childNode.first]) continue;
            
            if(dist[childNode.first] > cdist + childNode.second) {
                dist[childNode.first] = (cdist + childNode.second);
                ms.insert({dist[childNode.first], childNode.first});
            }
        }
    }
}

void solve(){
    cin >> n >> m;// >> q;

    graph.resize(n+1);
    dist.resize(n+1, INT_MAX);
    visited.resize(n+1, false);

    for(int i=1; i<=m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(1);

    for(int i=1; i<=n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    for(int i=1; i<=t; ++i){
        solve();
    }
}
