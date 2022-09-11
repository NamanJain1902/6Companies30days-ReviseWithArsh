/**
* @author NamanJain1902
* On: 12/07/2022 
* At: 08:57:42
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

const uint MAX = 1000000;
const uint HMAX = 1000000007;

int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}
// unordered_set<pair<int, int>> uset;


unordered_map<int, int> umap;

int dp[MAX+2][2];
void preprocess(){
    dp[MAX+1][0] = dp[MAX+1][1] = 1;

    for(int i=MAX; i>=2; --i) {
        int op1 = (dp[i+1][1] + dp[i+1][0]) % HMAX;
        int op2 = dp[i+1][0];
        int op3 = (2*dp[i+1][0]) % HMAX;
        int op4 = dp[i+1][1];

        dp[i][0] = (op1 + op2 + op3) % HMAX;
        dp[i][1] = (op1 + op4) % HMAX;
    }
}

void solve(){
    int n;
    cin >> n;

    cout << ((dp[2][0] + dp[2][1]) % HMAX - (dp[n][0] + dp[n][1]) % HMAX + HMAX ) % HMAX << endl;
}





signed main(){
    // const uint maxN = 1e6+1;
    // int dp[maxN];
    // dp[1] = 2;
    // dp[2] = 8;
    // for(int i = 3; i < maxN; i++)
    //     dp[i] = ((6*dp[i-1] - 7*dp[i-2]) % HMAX + HMAX) % HMAX;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    preprocess();
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i) {
        // int n;
        // cin >> n;
        // cout << dp[n] << endl;
        solve();
    }
    return 0;
}

