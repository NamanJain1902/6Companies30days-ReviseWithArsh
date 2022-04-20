class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0, a = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j]) {
                    a = maxArea(grid, i, j);
                    ret = max(ret, a);                    
                }
            }
        }
        return ret;
    }
private:
    void computeArea(vector<vector<int>> &grid, int x, int y, int &a) {
        if(x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size() and grid[x][y] == 1) {
            a++;
            grid[x][y] = 0;
            computeArea(grid, x - 1 , y, a); // up
            computeArea(grid, x, y + 1, a);  // right
            computeArea(grid, x + 1, y, a);  // down
            computeArea(grid, x, y - 1, a);  // left
        }
    }
    
    int maxArea(vector<vector<int>> &grid, int x, int y) {
        
        if(x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] != 1) {
            return 0; 
        }
        
        grid[x][y] = 2;
        
        int up = maxArea(grid, x - 1, y);
        int right = maxArea(grid, x, y + 1);
        int down = maxArea(grid, x + 1, y);
        int left = maxArea(grid, x, y - 1);
        
        return 1 + up + right + down + left;
    }
};
