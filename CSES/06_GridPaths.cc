/**
* @author NamanJain1902
* On: 11/07/2022 
* At: 11:43:59
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


//recursive solution : traverse and find all possible path : dfs approach
char grid[1000][1000];
int n, cnt=0;

void dfs(int i, int j) {
    if(i == n-1 and j == n-1) {cnt = (cnt + 1) % HMAX; return;}
    if(grid[i][j] == '*' or i >= n or j >= n) return;

    dfs(i, j + 1); // right
    dfs(i + 1, j); // down
}

void solve() {
    cin>>n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> grid[i][j];
        }
    }
    int dp[1000][1000];

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(grid[i][j] == '*') dp[i][j] = 0;
            else if(i == n-1 and j == n-1) dp[i][j] = 1;
            else if(i == n-1) dp[i][j] = dp[i][j+1];
            else if(j == n-1) dp[i][j] = dp[i+1][j];
            else dp[i][j] = (dp[i][j+1] + dp[i+1][j]) % HMAX;
            
        }
    }

    // int ans = 0; // totals paths from upper left to lower right
    // if(grid[n-1][n-1] != '*')
    // dfs(0, 0);

    cout << (dp[0][0] % HMAX) << endl;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
//   int t;
//   cin >> t;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
