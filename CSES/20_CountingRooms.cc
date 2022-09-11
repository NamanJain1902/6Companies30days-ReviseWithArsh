/**
* @author NamanJain1902
* On: 20/07/2022 
* At: 06:37:18
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


int moves[]={-1, 0, 1, 0, -1};

int n, m;
bool isValidMove(int i, int j) {
    if(i < 0 or i>=n or j < 0 or j >=m) return false;
    return true;
}
// multi start dfs
void dfs(int x, int y, vector<vector<int>> &visited) {

    // cerr << x << " " << y << endl;
    for(int k=0; k<4; ++k){
        int dx = x + moves[k];
        int dy = y + moves[k+1];

        if(isValidMove(dx, dy) and !visited[dx][dy]) {
            visited[dx][dy] = 2;
            dfs(dx, dy, visited);
        }
    }
}

void solve(){
    cin >> n >> m;
    vector<vector<int>> visited(n, vector<int>(m));
    // vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            char ch;
            cin >> ch;
            if(ch == '#') visited[i][j] = 2;
            else visited[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j) {
            if(visited[i][j] == 0) {
                ans++;
                dfs(i, j, visited);
            }
        }
    }
    cout << ans << endl;
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
