/**
* @author NamanJain1902
* On: 16/07/2022 
* At: 15:10:00
* @link: https://usaco.guide/CPH.pdf#page=112
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
    int n, x;
    cin >> n >> x;
    int weights[n];
    for(int i=0; i<n; ++i) {
        cin >> weights[i];
    }

    int maxSubsets = 1 << n;
    pair<int, int> best[maxSubsets];
    best[0] = {1, 0};

    for(int s=1; s<maxSubsets; ++s) {
        // initial value: n+1 rides are needed
        best[s] = {n+1, 0};
        for(int p=0; p<n; ++p) {
            if(s & (1 << p)) {
                auto option = best[s ^ (1 << p)];
                
                if(option.second + weights[p] <= x) {
                    // add p to an existing ride.
                    option.second += weights[p];
                } else {
                    // reserve a new ride for p.
                    option.first++;
                    option.second = weights[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }

    // cout << ((best[maxSubsets-1].second == 0) ? best[maxSubsets-2].first : best[maxSubsets-2].first + 1) << '\n';
    // if(best[maxSubsets-1].second == 0) {
    cout << best[maxSubsets- 1].first << endl;
    // } else {
    //     cout << (best[maxSubsets - 2].first + 1)<< endl;
    // }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
