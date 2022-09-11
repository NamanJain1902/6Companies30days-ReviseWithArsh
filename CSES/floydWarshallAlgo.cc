/**
* @author NamanJain1902
* On: 24/07/2022 
* At: 10:35:55
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
vector<vector<int>> graph, dist;

// dist[i][j] == -1 => i and j are unreachable.
void floydWarshall() {

    dist.resize(n+1, vector<int>(n+1, -1));
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // checks for k intermediate nodes
    for(int k = 1; k <= n; ++k) {
        // take each node as start node
        for(int i=1; i<=n; ++i) {
            // and remaining nodes as destination node
            for(int j=1; j<=n; ++j) {
                if(i != j) { //
                    // if k is connected to both i and j
                    if(dist[i][k] != -1 and dist[k][j] != -1 ){ 
                        if(dist[i][j] == -1) dist[i][j] = dist[i][k] + dist[k][j];
                        else
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                } else {
                    dist[i][j] = 0;
                }
            } 
        }
    }

    long long sum = 0;
    for(int i=1; i<n; ++i) {
        for(int j=i; j<n; +j) {
            sum += dist[i][j];
        }
    }

    // string res;
    // while(sum > 0) {
    //     int r = sum % 2;
    //     res += to_string(r);
    //     sum >>= 2;
    // }
    // reverse(res.begin(), res.end());
    // cout << res << endl;
}

void solve(){
    cin >> n >> m;

    graph.resize(n+1, vector<int>(n+1, -1));
    for(int i=0; i<m; ++i) {
        int a, b, wt;
        cin >> a >> b >> wt;
        graph[a][b] = wt;
        graph[b][a] = wt;
    }
    floydWarshall();

    for(auto x: dist){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
}

signed main(){

  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
