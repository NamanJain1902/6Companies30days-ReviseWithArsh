/**
* @author NamanJain1902
* On: 11/07/2022 
* At: 10:46:20
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

void solve() {
    int n, X;
    cin >> n >> X;
    vector<int> v(n);
    for(auto &x: v) cin >> x;

    vector<int> dp(X+1, MAX);
    dp[0] = 0;

    for(int i=1; i<=X; ++i) {
        for(int j=0; j<n; ++j) {
            int coin = v[j];
            if(i - coin >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    
    cout << (dp[X] == MAX? -1: dp[X]) << endl;
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
