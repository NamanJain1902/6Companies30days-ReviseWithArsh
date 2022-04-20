/**
* @author NamanJain1902
* On: 15/03/2022 
* At: 22:05:07
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


class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid.size();
        if(rows==0)     //Empty grid boundary case
            return 0;
        int cols = grid[0].size();
        
        int no_of_islands = 0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='1')
                {
                    mark_current_island(grid,i,j,rows,cols);
                    no_of_islands += 1;
                }
            }
        }
        return no_of_islands;
    }
    int numIslands__AC__BFS(vector<vector<char>>& grid) { 
        
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        

        auto isValid = [&](int x, int y, vector<vector<char>> &grid) {
            return !(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0');
        };

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] != '0') {
                    cnt += 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while(!q.empty()) {
                        pair<int, int> f = q.front();
                        q.pop();

                        for(auto move: moves) {
                            int dx = f.first  + move[0];
                            int dy = f.second + move[1];

                            if(isValid(dx, dy, grid)) {
                                q.push({dx, dy});
                                grid[dx][dy] = '0';
                            }
                        }
                    }
                }

            }
        }
        return cnt;
    }
    int numIslands_two_test_cases_failed(vector<vector<char>>& grid) { 
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        auto isValid = [&](int x, int y, vector<vector<char>> grid){
            return !(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y]=='0');  
        };
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(!visited[i][j]) {
                    
                    if(grid[i][j] == '0'){
                        visited[i][j] = true;
                        continue;
                    }
                    cnt+=1;
                    
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        pair<int, int> f = q.front();
                        q.pop();
                        
                        for(auto move: moves) {
                            int dx = f.first  + move[0];
                            int dy = f.second + move[1];
                            
                            if(isValid(dx, dy, grid) and !visited[dx][dy]) {
                                q.push({dx, dy});
                                visited[dx][dy] = true;
                            }
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};

void solve(){
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> grid[i][j];
        }
    }


    Solution sol;
    cout << sol.numIslands(grid) << endl;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
  int t;
  cin >> t;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
