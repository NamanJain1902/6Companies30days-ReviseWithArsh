// AC-Copied
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int a = 1;
                    grid[i][j] = 0;
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
                                grid[r][c] = 0;
                                a++;
                                todo.push({r, c});
                            }
                        }
                    }
                    area = max(area, a);
                }
            }
        }
        return area;
    }
};


//  DFS-Copied
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int a = 0;
                    computeArea(grid, i, j, a);
                    area = max(area, a);
                }
            }
        }
        return area;
    }
private:
    void computeArea(vector<vector<int>>& grid, int i, int j, int& a) {
        int m = grid.size(), n = grid[0].size();
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j]) {
            a++;
            grid[i][j] = 0;
            computeArea(grid, i - 1, j, a);
            computeArea(grid, i + 1, j, a);
            computeArea(grid, i, j - 1, a);
            computeArea(grid, i, j + 1, a);
        }
    }
};


// 672/728 AC failed for {{0,1}, {1,0}}
class MySolution{
    public:
        int n, m;
        int cnt = 0;
        struct Cell{
            int x, y;
            Cell(){}
            Cell(int x, int y){
                this->x=x;
                this->y=y;
            }
        };
        
           
        void bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid){
            vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

            queue<Cell> q;
            q.push({i, j});
            visited[i][j] = true;

            auto isSafe = [&](int x, int y){
                return (x >= 0 and y >= 0 and x < n and y < m);
            };

            while(!q.empty()){
                Cell u = q.front();
                q.pop();
                
                if(grid[u.x][u.y] == 1)cnt++;
                
                for(auto p: moves){
                    int cx = u.x + p[0];
                    int cy = u.y + p[1];
                    
                    if(isSafe(cx, cy)  and !visited[cx][cy] and grid[cx][cy] == 1){
                        visited[cx][cy] = true;
                        q.emplace(cx, cy);
                    }
                }
            }

        }
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
            int ans = 0;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            for(int i=0 ;i<n; ++i){
                for(int j=0; j<m; ++j){
                    if(!visited[i][j]){
                        bfs(i, j, visited, grid);
                        ans = max(cnt, ans);
                        cnt = 0;
                    }
                }
            }
            
            return ans;
        }
};
