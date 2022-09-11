/**
* @author NamanJain1902
* On: 20/07/2022 
* At: 16:05:43
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

vector<vector<int>> graph;
vector<bool> visited;
// vector<int> from_where;
map<int, int> from_where;


void minComputersInPath(int source, int destination) {

    queue<int> q;
    q.push(source);
    visited[source] = true;


    while(!q.empty()) {
        int u = q.front();
        q.pop();
        // cout << u << endl;
        visited[u] = true;
        if(u == destination) break;
        for(auto nextComputer: graph[u]) {
            
            if(!visited[nextComputer]){
                from_where[nextComputer] = u;
                visited[nextComputer] = true;
                q.push(nextComputer);
            }
        }
    }
}

int minComputersInPath_dfs(int source, int destination) {
    
    if(source == destination) {
        return 1;
    }

    int minHops = INT_MAX;
    visited[source] = true;
    for(auto nextComputer: graph[source]) {
        if(!visited[nextComputer]){
            // from_where.push_back(soruce);
            // if(from_where.find(nextComputer) == from_where.end())
            // from_where[nextComputer] = source;
            minHops = min(minHops, 1 + minComputersInPath_dfs(nextComputer, destination));
        }
    }
    visited[source] = false;
    return minHops;

}

void solve(){
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    visited.resize(n+1, false);

    for(int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // int k=0;
    // for(auto x: graph){
    //     cout << k++ << " -> ";
    //     for(auto y: x){
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // int ans =  
    minComputersInPath(1, n);
    // cout<<boolalpha;
    // for(auto x: visited)cout<<x<<endl;
    if(!visited[n]) {
        cout << "IMPOSSIBLE\n";
    } else {
        int val = n;
        vector<int> ret;
        ret.push_back(val);
        while(from_where[val] != 1) {
            // cout << from_where[val] << " ";
            ret.push_back(from_where[val]);
            val = from_where[val];
        }
        ret.push_back(1);
        reverse(ret.begin(), ret.end());
        cout << ret.size() << endl;
        for(auto x: ret){
            cout << x << ' ';
        }
        cout << endl;
    }

    
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
