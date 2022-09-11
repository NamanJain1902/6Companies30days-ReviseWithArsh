/**
* @author NamanJain1902
* On: 13/07/2022 
* At: 21:07:58
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
    string s;
    cin >> s;
    string temp;
    bool fine = true;
    bool iso = true;
    for(int i=0; i<n;) {
        if(iso){
            iso = false;
            temp += s[i];
            i++;
        } else {
            iso= true;
            int tl = temp.length();
            if(tl > n - i) {
                fine = false;
                break;
            }
            int j,k;
            for(k=0, j=i; k < tl; ++j, k++) {
                if(s[j] != temp[k]){
                    fine = false;
                    break;
                }
                temp += s[j];
            }
            if(!fine) break;
            i = j;
        }
    }
    if(fine) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
  int t;
  cin >> t;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
