/**
* @author NamanJain1902
* On: 25/02/2022 
* At: 14:40:52
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

const unsigned int X[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const unsigned int Y[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool solve(char **matrix, bool **visited){
    string s;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    s += matrix[0][0];

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if(s == "CODINGNINJA") 
            return true;

        for(int i=0; i<8; ++i) {
            int dx = x + X[i];
            int dy = y + Y[i];

            if(dx < 0 || dy < 0 || dx >= matrix.size() || dy >= matrix[0].size() || visited[dx][dy] == true) 
                continue;

            q.emplace(dx, dy);
            s += matrix[dx][dy];
        }
    }

    return false;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    char **matrix = new char*[n];
    bool **visited = new bool*[n];
    for(int i=0; i<n; ++i){
        matrix[i]  = new char[m];
        visited[i] = new bool[m];
    }

    // string s[n];

    for(int i=0; i<n; ++i){

        for(int j=0; j<m; ++j) {
            cin >> matrix[i][j];
            visited[i][j] = false;
        }
    }

}
