
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
int solve(int n, int m, vector<int>& v)
{
    int dp[n+2][m+2];
    memset(dp, 0, sizeof dp);
 
    for(int i = 1; i <= n; i++)
    {
        for(int x = 1; x <= m; x++)
        {
            if(i == 1)
            {
                if(v[i] == 0 || v[i] == x)
                    dp[i][x] = 1;
                else dp[i][x] = 0;
            }
            else
            {
                if(v[i] == 0 || v[i] == x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1])%mod;
                }
                else dp[i][x] = 0;
            }
        }
    }
 
    int ans = 0;
    for(int x = 1; x <= m; x++)
        ans = (ans + dp[n][x]) % mod;
    return ans;
}
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        int n,m;
        cin >> n >> m;
        vector<int> v(n+1);
        fr(1,n+1)
            cin >> v[i];
        cout << solve(n,m,v);
   }
   return 0;
}

// /**
// * @author NamanJain1902
// * On: 11/07/2022 
// * At: 19:52:35
// */

// #pragma GCC optimize ("O3")
// #pragma GCC target ("avx,avx2")

// #include <algorithm>
// #include <cassert>
// #include <iostream>
// #include <memory>
// #include <numeric>
// #include <climits>

// #include <array>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <tuple>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>
// #include <list>
 
// #include <cstring>
// #include <ostream>
// #include <type_traits>
// #include <utility>
// #include <chrono>
// #include <random>
 
// using namespace std;

// #define pr pair<int, int>
// #define pb push_back
// #define s second
// #define f first
// #define ll long long
// #define int long long int
// #define sz(x) ((int)x.size())

// const int MAX = 100000 + 5;
// const int HMAX = 1000000007;

// int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
// void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
// int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> v(n);
//     for(auto &x: v) {
//         cin >> x;   
//     }  // value b/w 1 and m
//     int res = 1;
//     for(int i=1;i<sz(v)-1;++i){
//         int cnt = 0;
//         set<int> s1, s2;
//         if(v[i] == 0) {
//             if(i - 1 >= 0) {
//                 s1.insert(v[i-1]);
//                 s1.insert(v[i-1]-1);
//                 s1.insert(v[i-1]+1);
//             }
//             if(i + 1 <n) {
//                 s2.insert(v[i+1]);
//                 s2.insert(v[i+1]-1);
//                 s2.insert(v[i+1]+1);
//             } 
//             for(auto x: s1){
//                 if(s2.find(x) != s2.end()){
//                     cnt++;
//                 }
//             }
//             if(cnt!=0)
//             res *= cnt;
//             res %= HMAX;
//         }
//     }
//     cout << (res % HMAX) << endl;
// }

// signed main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL);
// //   int t=1;
//   int t=1;
// //   cin >> t;
//   for(int i=1; i<=t; ++i){
//     solve();
//   }
// }
