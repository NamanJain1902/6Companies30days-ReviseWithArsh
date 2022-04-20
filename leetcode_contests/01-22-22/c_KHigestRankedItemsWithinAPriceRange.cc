/*
Learning:
    1. How STL sort works on vector of vectors?
    2. Using queue with for loop.
    3. No need to use visited in every case. Other helper matrices can do the same trick.
*/
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dis(n, vector<int>(m)), que, items;
        
        int sx = start[0], sy = start[1];
        dis[sx][sy] = 1; // why not 0

        que.push_back({sx, sy});

        for(int i = 0; i < (int)que.size(); ++i) {
            ////
            auto &vec = que[i];
            ////

            int x = vec[0], y = vec[1];

            if(pricing[0] <= grid[x][y] && grid[x][y] <= pricing[1]) {
                items.push_back({dis[x][y], grid[x][y], x, y});
            }


            for(int dx = -1; dx <= 1; ++dx)
                for(int dy = -1; dy <= 1; ++dy) {
                    if(!!dx == !!dy)
                        continue;
                    int xx = x + dx, yy = y + dy;
                    if(xx < 0 || xx >= n || yy < 0 || yy >= m || !grid[xx][yy] || dis[xx][yy])
                        continue;

                    dis[xx][yy] = dis[x][y] + 1;
                    que.push_back({xx, yy});
                }
        }


        sort(items.begin(), items.end());

        vector<vector<int> > ret;
        for(int i = 0; i < (int)items.size() && i < k; ++i)
            ret.push_back({items[i][2], items[i][3]});
        return ret;
    }
};


/*

Computed wrong distance.

Should be dis[xx][yy] = dis[x][y] + 1;
Not abs(x-sx)+abs(y-sy)

Distance, defined as the length of the **shortest //possible// path** from the start.
*/
class Solution_WA {
public:
    struct Cell{
        int distance;
        int price;
        int row;
        int col;
        Cell(){}
        Cell(int distance, int price, int row, int col) {
            this->distance = distance;
            this->price = price;
            this->row = row;
            this->col = col;
        }
    };
    
    int low=0, high=0,m,n;
    int sx, sy;
    
    bool isSafe(vector<vector<int>>& grid, int i, int j, int low, int high){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        return true;
    }
    
    vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void bfs(vector<vector<int>>& grid, vector<Cell>& path, int i, int j, vector<vector<bool>> visited) {
        
        queue<pair<int, int>> q;
        q.emplace(i, j);
        vector<vector<int>> dist(n, vector<int>(m));
        
        if(grid[i][j] >= low and grid[i][j] <= high) 
        path.emplace_back(0, grid[i][j], i, j);
        visited[i][j] = true;
        dist[i][j] = 0;
        
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for(auto move : moves) {
                int x = r + move[0];
                int y = c + move[1];

                if(grid[r][c] >= low and grid[r][c] <= high) {
                    path.emplace_back(dist[r][c], grid[x][y], x, y);
                }
                if(isSafe(grid, x, y, low, high) && grid[i][j] != 0 && !visited[x][y]){
                    // int distance = abs(x-sx) + abs(y-sy);
                    dist[x][y] = dist[r][c] + 1;
                    // if(grid[x][y] >= low and grid[x][y] <= high) {
                    //     path.emplace_back(dist[x][y], grid[x][y], x, y);
                    // }

                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }
        }
    }
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>> res;
        vector<Cell> path;
        low = pricing[0];
        high = pricing[1];
        int i = start[0];
        int j = start[1];
        sx=i,sy=j;

        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
          
        bfs(grid, path, i, j, visited);


        sort(path.begin(), path.end(),  [&](Cell a, Cell b) {

            if(a.distance != b.distance){
                return a.distance < b.distance;
            }
            if(a.price != b.price){
                return a.price < b.price;
            }
            if(a.row != b.row){
                return a.row < b.row;
            }
            return a.col < b.col;
            // return (a.distance < b.distance || a.price < b.price || a.row < b.row || a.col < b.col);
        });
        
        for(auto cell : path){
            if(k == 0){
                break;
            }
            
            res.push_back({cell.row, cell.col});
            k--;
        }
        return res;
    }
};



class Solution {
public:
    struct Cell{
        int distance;
        int price;
        int row;
        int col;
        Cell(){}
        Cell(int distance, int price, int row, int col) {
            this->distance = distance;
            this->price = price;
            this->row = row;
            this->col = col;
        }
    };
    
    int low=0, high=0,m,n;
    int sx, sy;
    
    bool isSafe(vector<vector<int>>& grid, int i, int j, int low, int high){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        return true;
    }
    
    vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void bfs(vector<vector<int>>& grid, vector<Cell>& path, int i, int j, vector<vector<bool>> visited) {
        
        vector<vector<int>> dist(m, vector<int>(n));
        queue<pair<int, int>> q;
        q.emplace(i, j);
        dist[i][j] = 0;
        
        if(grid[i][j] >= low and grid[i][j] <= high) 
        path.emplace_back(0, grid[i][j], i, j);
        visited[i][j] = true;
        
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for(auto move : moves) {
                int x = r + move[0];
                int y = c + move[1];
                if(isSafe(grid, x, y, low, high) && grid[i][j]  && !visited[x][y]){
                    // int distance = abs(x-sx) + abs(y-sy);
                    dist[x][y] = dist[r][c] + 1;
                    
                    if(grid[x][y] >= low and grid[x][y] <= high) {
                        // path.emplace_back(distance, grid[x][y], x, y);
                        
                        path.emplace_back(dist[x][y], grid[x][y], x, y);
                        cout << "(" << x << "," << y << ") with diatance " << dist[x][y] << " and price  " << grid[x][y] << endl;
                    }
                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }
        }
    }
    
    // bool comp(Cell a, Cell b){
    //     if(a.distance < b.distance) {
    //         return true;
    //     } else if(a.distance > b.distance) {
    //         return false ;
    //     } 
    //     else if(a.price < b.price) {
    //         return a.price < b.price;
    //     }
    //     else if(a.price > b.price) {
    //         return false;
    //     }
    //     else if(a.row < b.row){
    //         return a.row < b.row;
    //     }
    //     else if(a.row > b.row){
    //         return false;
    //     }
    //     else if(a.col < b.col) {
    //         return a.col < b.col;
    //     }
    //     else if(a.col > b.col) {
    //         return false;
    //     }
    //     return false;
    // }
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>> res;
        vector<Cell> path;
        low = pricing[0];
        high = pricing[1];
        int i = start[0];
        int j = start[1];
        sx=i,sy=j;
        // if(grid[])
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
  
        
        bfs(grid, path, i, j, visited);
        // cout << path.size() << endl;
       
        sort(path.begin(), path.end(),  [&](Cell a, Cell b) {
            
            if(a.distance != b.distance){
                return a.distance < b.distance;
            }
            if(a.price != b.price){
                return a.price < b.price;
            }
            if(a.row != b.row){
                return a.row < b.row;
            }
            return a.col < b.col;
            // return (a.distance < b.distance || a.price < b.price || a.row < b.row || a.col < b.col);
        });
        
        for(auto cell : path){
            if(k == 0){
                break;
            }
            
            res.push_back({cell.row, cell.col});
            k--;
        }
        return res;
    }
};