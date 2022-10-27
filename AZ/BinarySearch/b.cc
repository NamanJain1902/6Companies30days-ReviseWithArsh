#include<bits/stdc++.h>
using namespace std;


int res = INT_MAX;
vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1,0}, {0, -1}};

bool isSafe(vector<vector<char>> &grid, int x, int y) {
    if(x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size() or grid[x][y] == 'T') 
        return false;
    return true;
}
void dfs(vector<vector<char>> &grid, int si, int sj, int di, int dj, vector<vector<int>> &visited, int cnt) {

    if(si == di and sj == dj) {
        res = min(res, cnt);
        return;
    }

    for(auto move: moves) {
        int dx = si + move[0];
        int dy = sj + move[1];

        if(!isSafe(grid, dx, dy) || visited[dx][dy] == 1) continue;

        visited[dx][dy] = true;
        dfs(grid, dx, dy, di, dj, visited, cnt + 1);
        visited[dx][dy] = false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> vv(n, vector<char>(n, 'P'));
    int si=0, sj=0, di=-1, dj=-1;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> vv[i][j];
            if(vv[i][j] == 'S') {
                si = i;
                sj = j;
            } 
            else if(vv[i][j] == 'E'){
                di = i;
                dj = j;
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    dfs(vv, si, sj, di, dj, visited, 0);

    cout << res << endl;
}