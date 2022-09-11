/**
* @author NamanJain1902
* On: 16/07/2022 
* At: 15:38:46
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

int cnt = 0;
// int dp[11][1001];
int rec(int i, int j) {
    cout << i << " " << j << "\n";
    if(i < 0 or j < 0) return 0;
    if(i == 0 and j == 0) {
        // cnt += 1;
        return 1;
    }
    // if(dp[i][j] != -1) return dp[i][j];
    // dp[i][j] = 1;

    return 1 + rec(i, j-2) + rec(i-2, j);
}
void solve(){
    int r,c;
    cin >> r >> c;

    
    cout << rec(r, c) << endl;
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
