/**
* @author NamanJain1902
* On: 12/07/2022 
* At: 13:39:36
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
const int INF = 0x3f3f3f3f;
int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}

// // WA
void solve(){
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while(true) {
        if(a == b) break;
        
        int mini = min(a, b);
        int maxi = max(a, b);

        a = mini;
        b = maxi - mini;
        cnt++;
    }

    cout << cnt << endl;
}

int ans = INT_MAX;
vector<vector<int>> dp;

int rec(int a, int b) {
    if(a > b) swap(a, b);
    if(a == b) return dp[a][b] = 0; 
    else if(dp[a][b] != INF) return dp[a][b];
    else if(a == 1) return dp[a][b] = b - 1;
    else if(b == 1) return dp[a][b] = a - 1;

    // row recursive calls
    for(int i=1; i<a; ++i) {
        dp[a][b] = min(dp[a][b], rec(i, b) + rec(a - i, b) + 1);
    }

    // column recursive calls
    for(int j=1; j<b; ++j) {
        dp[a][b] = min(dp[a][b], rec(a, j) + rec(a, b - j) + 1);
    }

    return dp[a][b];
}

// memo solution
void sol() {
    int a, b; 
    cin >> a >> b;

    dp.resize(501, vector<int>(501, INF));

    cout << rec(a, b) << endl;
}

signed main(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
//   int t;
//   cin >> t;
  for(int i=1; i<=t; ++i){
    sol();
  }
}
