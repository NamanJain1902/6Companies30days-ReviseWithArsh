/**
* @author NamanJain1902
* On: 31/07/2022 
* At: 19:37:20
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
    int n,m;
    cin >> n >> m;
    string a, b;
    cin >> a>>b;
    
    if(b.size() > a.size()) {
      cout << "NO\n";
    } else {
      int fa1 = -1, fa0 = -1;
      bool oz = false;
      for(int i=0; i<n; ++i) {
        if(a[i] == '1' and fa1==-1){
          fa1 = i;
        }
        if(a[i] == '0' and fa0 == -1){
          fa0 = i;
        }
        if(fa1 != -1 and fa0 != -1) break;
      }
      int fb1 = -1, fb0 = -1;
      for(int i=0; i<m; ++i){
        if(b[i] == '1' and fb1==-1){
          fb1 = i;
        }
        if(b[i] == '0' and fb0 == -1){
          fb0 = i;
        }
        if(fb1 != -1 and fb0 != -1) break;
      }

      // cout << fa1 << " " << fa0 << " " << fb1 << " " << fb0 << endl;
      
      if(fa1 <= fb1 and fa0 <= fb0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
}

signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
  int t;
  cin >> t;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
