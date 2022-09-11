/**
* @author NamanJain1902
* On: 11/07/2022 
* At: 13:12:05
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

struct Book{
    int price;
    int pages;
    Book(int _price, int _pages) {
        this->price = _price;
        this->pages = _pages;
    }
};
// WA
int maximumPages(int n, int x, vector<int> &prices, vector<int> &pages) {

    vector<Book> vp;

    for(int i=0; i<n; ++i) {
        vp.push_back({prices[i], pages[i]});
    }

    sort(vp.begin(), vp.end(), [&](Book a, Book b){
        return (a.pages/a.price > b.pages/b.price);
    });

    int ans = 0;

    for(Book book: vp) {
        if(x - book.price >= 0){
            ans += book.pages;
            x -= book.price;
        }
    }

    return ans;
}


// using dp, space optimized
int maximumPagesPriceX(int n, int x, vector<int> &prices, vector<int>& pages) {
    int dp[2][x+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=x; ++j) { // j should start with 0
            if(j - prices[i-1] >= 0) {
                dp[i%2][j] = max(dp[(i+1)%2][j], pages[i-1] + dp[(i+1)%2][j-prices[i-1]]);
            } else {
                dp[i%2][j] = dp[(i+1)%2][j];
            }
        }
    }
    return dp[n%2][x];
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> prices(n, 0), pages(n, 0);
    for(int i=0; i<n; ++i) {cin >> prices[i];}
    for(int i=0; i<n; ++i) {cin >> pages[i]; }

    cout << maximumPagesPriceX(n, x, prices, pages) << endl;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
