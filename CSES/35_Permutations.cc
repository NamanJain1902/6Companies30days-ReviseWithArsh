/**
* @author NamanJain1902
* On: 31/07/2022 
* At: 14:57:10
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

void solve(){
    int n;
    cin >> n;
    vector<int> dp(n);

    if(1 < n and n < 4){
        cout << "NO SOLUTION\n";
    } else if(n == 4){
        dp[0] = 2;
        dp[1] = 4;
        dp[2] = 1;
        dp[3] = 3;

        for(auto x: dp){
            cout << x << " ";
        }
        cout << endl;
    } 
    else {
        int k = 1;
        for(int i=0; i<n; i+=2) {
            dp[i] = k++;
        }
        for(int i=1; i<n; i+=2) {
            dp[i] = k++;
        } 
        for(auto x: dp){
            cout << x << " ";
        }
        cout << endl;
    }
    return;
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
