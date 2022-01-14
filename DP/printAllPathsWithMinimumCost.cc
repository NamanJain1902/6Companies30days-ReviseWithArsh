#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &grid, int i, int j){
    if(i < 0 || j < 0 || i>=grid.size() || j>=grid[0].size()){
        return false;
    }
    return true;
}

void solve(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));


    for(int i=n-1; i>=0; --i){
        for(int j=m-1; j>=0; --j){
            if(i == n-1 and j == m-1){
                dp[i][j] = grid[i][j];
            } else if(i == n-1){
                dp[i][j] = grid[i][j] + dp[i][j+1];
            } else if(j == m-1){
                dp[i][j] = grid[i][j] + dp[i+1][j];
            } else{
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    // minimum cost
    cout << dp[0][0] << endl;


    queue<pair<pair<int, int>, string>> q;

    q.push({{0, 0}, ""});

    vector<vector<int>> moves = {{0, 1}, {1, 0}};

    while(!q.empty()){
        pair<pair<int, int>, string> tp = q.front();
        q.pop();
        int x = tp.first.first;
        int y = tp.first.second;
        string path = tp.second;

        // int cost = tp.second;

        if(x == dp.size()-1 and y == dp[0].size() - 1){ 
            cout << path << endl;
        } else if(x == dp.size() - 1){
            q.push({{x, y + 1}, path + "H"});
        } else if(y == dp[0].size() - 1){
            q.push({{x + 1, y}, path + "V"});
        } else{
            if(dp[x][y+1] < dp[x+1][y]){
                q.push({{x, y + 1}, path + "H"});
            } else if(dp[x][y+1] > dp[x+1][y]){
                q.push({{x + 1, y}, path + "V"});
            } else{
                q.push({{x + 1, y}, path + "V"});
                q.push({{x, y + 1}, path + "H"});
            }
        }
        // for(auto move : moves){
        //     int nextX = x + move[0];
        //     int nextY = y + move[1];
            


        //     if(isSafe(grid, nextX, nextY)){
        //         string val = "";
        //         if(move[0] == 0){
        //             val = "H";
        //         }
        //         if(move[0] == 1){
        //             val = "V";
        //         }
        //         q.push({{nextX, nextY}, path + val});
        //     }
        // }
    }
    
}
int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> grid[i][j];
        }
    }


    solve(grid);
}
