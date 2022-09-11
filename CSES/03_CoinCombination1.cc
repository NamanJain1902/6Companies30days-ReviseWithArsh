/**
* @author NamanJain1902
* On: 11/07/2022 
* At: 11:04:35
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

const int MAX = 1000000 + 5;
const int HMAX = 1000000007;

int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &a: v) cin >> a;
    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for(int j=1; j<=x; ++j) {
        for(int i=0; i<n; ++i) {
        int coin = v[i];
            if(j - coin >= 0) {
                dp[j] = (dp[j] + dp[j-coin]) % HMAX;
            }
        }
    }
    cout << (dp[x] % HMAX) << endl; 
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
