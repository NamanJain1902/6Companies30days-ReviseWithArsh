/**
* @author NamanJain1902
* On: 12/07/2022 
* At: 10:38:39
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

/*
  x M O V I E
x 0 1 2 3 4 5
L 1 1 2 3 4 5
O 2 1 1 2 3 4 
V 3 1 1 1 2 3 
E 4 1 2 2 3 2 <- ans


  x L O V E
x 0 1 2 3 4
M 1 1 2 3 4   
O 2 2 1 2 3
V 3 3 2 1 2
I 4 4 3 2 2
E 5 5 4 3 2 <- ans

*/
void solve(){
    string a, b;
    cin >> a >> b;

    int A = sz(b);
    int B = sz(a);
    
    int dp[A+1][B+1];

    // (i, j) stores  the minimum operation required such that a[0..i] == b[0..j]
    
    // null set equals null set
    dp[0][0] = 0;

    // forming a when null set is given
    for(int i=1; i<=A;++i)
        dp[i][0] = i;

    // forming b when null set is given
    for(int j=1; j<=B; ++j) {
        dp[0][j] = j;
    }

    for(int i=1; i<=A; ++i) {
        for(int j=1; j<=B; ++j) {
            
            dp[i][j] = (b[i-1] == a[j-1] ? dp[i-1][j-1] 
                                     : 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}));
        }
    }

    // for(int i=0; i<=A; ++i){
    //     for(int j=0; j<=B; ++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[A][B] << endl;
    
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
//   for(int i=1; i<=t; ++i){
    solve();
//   }
}
