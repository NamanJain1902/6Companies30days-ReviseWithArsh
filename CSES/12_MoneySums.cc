/**
* @author NamanJain1902
* On: 12/07/2022 
* At: 16:22:02
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


void rec(vector<int> &v, int i, set<int> &ret, int csum) {
    if(i == v.size()) {
        if(csum != 0) ret.insert(csum); 
        return;
    }

    rec(v, i + 1, ret, csum);
    rec(v, i + 1, ret, csum + v[i]);
}

void solve(){
    int n;
    cin>>n;
    int sm = 0;
    vector<int> v(n);for(auto &x: v) {cin >> x; sm += x;}

    set<int> ret;
    // rec(v, 0, ret, 0);
    // cout << ret.size() << "\n";

    // using knapsack appproach
    /* Approach:
        It is possible to make x with the first i coins, if either 
        it was possible with the first i-1 coins, or we chose the
        i'th coin, and it was possible to make j — <value of i'th coin> 
        using the first i-1 coins.
    */
    bool dp[n+1][sm+1] = {false};
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<=n; ++i) dp[i][0] = true;

    for(int i=1; i<=n ;++i) {
        for(int j=1; j<= sm; ++j) {

            int val = v[i-1];

            if(dp[i-1][j] == true) dp[i][j] = true;
            else if(j - val >= 0){
                dp[i][j] = dp[i-1][j-val] | dp[i-1][j];
            }

            if(dp[i][j]) ret.insert(j);
        }
    }    
    cout << ret.size() << endl;
    for(auto x: ret) cout << x << " ";
    cout << "\n";
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
