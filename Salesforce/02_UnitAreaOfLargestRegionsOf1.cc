#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int findMaxArea(vector<vector<int>>& grid) {

            int cnt = 0;
            struct Cell{
                int x, y;
                Cell(){}
                Cell(int x, int y){
                    this->x=x;
                    this->y=y;
                }
            };

            int n = grid.size();
            int m = grid[0].size();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            vector<vector<int>> moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

            queue<Cell> q;
            q.push({0, 0});
            visited[0][0] = true;

            auto isSafe = [&](int x, int y){
                return (x >= 0 and y >= 0 and x < n and y < m);
            };

            while(!q.empty()){
                Cell u = q.front();
                q.pop();
                
                if(grid[u.x][u.y] == 1)cnt++;
//                cout << "PRE NODE ";
//                cout << u.x << " " << u.y << endl;
//                cout << "PRE NODE DONE" << endl;
                for(auto p: moves){
                    int cx = u.x + p[0];
                    int cy = u.y + p[1];
                    
//                    cout << "PRE EDGE ";
//                    cout << cx << " " << cy << endl;

                    if(isSafe(cx, cy)  and !visited[cx][cy] and grid[cx][cy] == 1){
//                        cout << "Value at " << cx << " " << cy << " is: " << grid[cx][cy] << endl;
                        visited[cx][cy] = true;

//                        cnt++;
                        q.emplace(cx, cy);
                    }
//                    cout << "POST EDGE" << endl;
                }
//                cout << "POST NODE " << u.x << " " << u.y << endl;
//                cout << "**********POST NODE DONE**********\tCount is: " << cnt <<  endl;
            }

            return cnt;
        }
};


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m , -1));

    for(int i=0; i<n; ++i){
        for(int j=0; j<m;  ++j){
            cin >> grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.findMaxArea(grid);
    cout  << ans << "\n";
    return 0;
}
