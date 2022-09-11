/**
* @author NamanJain1902
* On: 14/07/2022 
* At: 01:05:04
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
// dp[x] = minimum ending value of an increasing subsequence of length x+1, using the elements considered so far.


void solve_binarySearch(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x: v) cin >> x;

    vector<int> ret;
    for(auto x: v){
      if(ret.size() == 0 or ret.back() < x) {
        ret.push_back(x);
      } else {
        cout << *lower_bound(ret.begin(), ret.end(), x) << endl;
        int i = lower_bound(ret.begin(), ret.end(), x) - ret.begin();

        ret[i] = x;
      }
    }
    cout << ret.size() << endl;
}

signed main(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
  // int t;
  // cin >> t;
  for(int i=1; i<=t; ++i){
    solve_binarySearch();
  }
}
