/**
* @author NamanJain1902
* On: 12/07/2022 
* At: 17:15:16
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

#define PLAYER1 1
#define PLAYER2 2


int maxa = INT_MIN;
void rec(vector<int> &v, int left, int right, int csum, int prev) {
    if(left > right) {
        maxa = max(maxa, csum); 
        return;
    }

    if(prev == PLAYER2) {
        if(v[left] > v[right]) {
            rec(v, left + 1, right, csum + v[left], PLAYER1);
        } else {
            rec(v, left, right - 1, csum + v[right], PLAYER1);
        }
    } else {
        if(v[left] > v[right]) {
            rec(v, left + 1, right - 1, csum, PLAYER2);
            // rec(v, left + 1, right, csum + v[left], PLAYER1);
        } else {
            rec(v, left + 1, right, csum, PLAYER2);
        }
    }
        // if(prev == PLAYER2) {
        // } else {
        //     rec(v, left, right - 1, csum, PLAYER2);
        // }
    // }
}


#define S 5005
ll dp[S][S];
vector<int> v;

ll fun(ll i,ll j)
{

    //Base case
    if(i > j)
    return 0;

    //Lookup case
    if(dp[i][j] != -1)
    return dp[i][j];

    //Recursion case
    // if I takes ith coin then
    // opponent left with i+1 th coin and jth coin
    // and i would have i+2th coin or j-1 th coin
    // depending what coin the opponent will take.
    ll op1 = v[i] + min(fun(i+2, j), fun(i+1,j-1) );
    ll op2 = v[j] + min(fun(i+1,j-1), fun(i,j-2) );

    return dp[i][j] = max(op1,op2);
}

void solve(){
    int n;
    cin >> n;
    v.resize(n);
    for(auto &x : v) cin >> x;

    // int left = 0;
    // int right = n-1;
    // rec(v, left, right, 0, 2);
    // cout << maxa << endl;
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,n-1)<<endl;
    return;
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
