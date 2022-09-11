/**
* @author NamanJain1902
* On: 21/07/2022 
* At: 11:09:50
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
vector<int> visited;


const short ODD = 1;
const short EVEN = 0;
bool IMPOSSIBLE = false;
void dfs(int node, int group) {
    
    if(group == ODD) {
        visited[node] = 1;
    } else {
        visited[node] = 2;
    }

    for(auto child: graph[node]) {
        if(visited[child] and visited[node] == visited[child]) {
            IMPOSSIBLE = true;
            return;
        }
        else if(!visited[child]) {
            switch (group)
            {
                case ODD:
                    dfs(child, EVEN);
                    break;
                case EVEN:
                    dfs(child, ODD);
                    break;
            }
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    visited.resize(n+1, 0);
    graph.resize(n+1);

    for(int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    
    for(int i=1; i<=n; ++i){
        if(!visited[i]) {
            dfs(i, ODD);
        }
    }

    if(IMPOSSIBLE) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(int i=1; i<=n; ++i){
            cout << visited[i] << " ";
        }
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
