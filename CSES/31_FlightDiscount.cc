/**
* @author NamanJain1902
* On: 25/07/2022 
* At: 19:33:27
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
const int INF = 9e17;
int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}



struct City {
  int city;
  int cost;
  City(int _city, int _cost) : city(_city), cost(_cost) {}
};

struct Invoice {
  int cost;
  int city;
  bool is_discount_valid;

  Invoice(int _cost, int _city, bool _is_discount_valid) 
    : cost(_cost), city(_city), is_discount_valid(_is_discount_valid) {}
};

struct CompareCost {
  bool operator()(Invoice const &objA, Invoice const &objB) {
    if(objA.cost != objB.cost) {
      return objA.cost < objB.cost;
    } else if(objA.city != objB.city) {
      return objA.city < objB.city;
    }
    return objA.is_discount_valid < objB.is_discount_valid;
  }
};

#define VALID 0
#define INVALID 1

int AC(int, int);
vector<vector<City>> network;

void sol() {
  int n, m;
  cin >> n >> m;
  
  network.resize(n+1);

  for(int i=1; i<=m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    network[a].push_back({b, c});
  }

  cout << AC(n, m) << endl;
}

int AC(int n, int m) {
  vector<int> full(n+1, INF), disc(n+1, INF);
  full[0] = disc[0] = 0;
  full[1] = disc[1] = 0;
  priority_queue<Invoice, vector<Invoice>, CompareCost> pq;
  pq.emplace(0, 1, 0);

  while(!pq.empty()) {
    int cost = pq.top().cost;
    int city = pq.top().city;
    int is_discount_valid = pq.top().is_discount_valid;
    pq.pop();

    if(is_discount_valid == INVALID) {
      if(disc[city] < cost) continue;
    } else if(is_discount_valid == VALID) {
      if(full[city] < cost) continue;
    }

    for(auto neighbor: network[city]) {
      int neighborCity = neighbor.city;
      int flightCost   = neighbor.cost; 

      // if no discount applied to travel from city to negihboring city
      if(is_discount_valid == VALID) {
        if(cost + flightCost < full[neighborCity]) {
          full[neighborCity] = cost + flightCost;
          pq.emplace(full[neighborCity], neighborCity, VALID);
        }
        // if applying discount on current route
        if(cost + (flightCost / 2) < disc[neighborCity]) {
          disc[neighborCity] = cost + (flightCost / 2);
          pq.emplace(disc[neighborCity], neighborCity, INVALID);
        }
      } else {
        // if applying discount on current route
        if(cost + flightCost < disc[neighborCity]) {
          disc[neighborCity] = cost + (flightCost);
          pq.emplace(disc[neighborCity], neighborCity, INVALID);
        }
      }
    }
  }
  
  // return (min(full[n], disc[n]));
  // cout << disc[n] << endl;
  return disc[n];
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
  for(int i=1; i<=t; ++i){
    sol();
  }
}
