#include<bits/stdc++.h>
using namespace std;

int omax = 0;
class Cell {
    public:
    int x,y;

    Cell(){}
    Cell(int x, int y){
        this->x = x;
        this->y = y;
    }
};

void bfs(vector<vector<int>> &mine, int i, int j, vector<vector<int>> &dp){
    queue<Cell> q;

    int amt = mine[i][j];
    dp[i][j] = amt;
    q.emplace(i, j);
    

    while(!q.empty()){
        struct Cell curr = q.front();
        q.pop();
        int x = curr.x;
        int y = curr.y;

        if(y == mine[0].size() - 1){ 
            omax = max(omax, dp[x][y]);
            return;    
        }

        if(x == 0){
            dp[x][y+1] = max(mine[x][y+1] + dp[x][y], dp[x][y+1]);
            dp[x+1][y+1] = max(mine[x+1][y+1] + dp[x][y], dp[x+1][y+1]);

            q.emplace(x, y+1);
            q.emplace(x+1, y+1);
        
        } else if(x == mine.size() - 1){
            dp[x][y+1] = max(mine[x][y+1] + dp[x][y], dp[x][y+1]);
            dp[x-1][y+1] = max(mine[x-1][y+1] + dp[x][y], dp[x-1][y+1]);

            q.emplace(x, y+1);
            q.emplace(x-1, y+1);
        } else{
            dp[x-1][y+1] = max(mine[x-1][y+1] + dp[x][y], dp[x-1][y+1]);
            dp[x][y+1] = max(mine[x][y+1] + dp[x][y], dp[x][y+1]);
            dp[x+1][y+1] = max(mine[x+1][y+1] + dp[x][y], dp[x+1][y+1]);

            q.emplace(x-1, y+1);
            q.emplace(x, y+1);
            q.emplace(x+1, y+1);
        }
    }
}
void printMaxPath(vector<vector<int>> &dp, int x, vector<vector<int>> &mine){
    int n = dp.size();
    int m = dp[0].size();
    vector<int> path;
    path.push_back(mine[x][m-1]);

    for(int j=m-2; j>=0; j--){
        if(x == 0){
            dp[x][j] >= dp[x+1][j] ? x: x + 1;
        } else if(x == n-1){
            x = dp[x-1][j] > dp[x][j] ? x - 1: x;
        } else{
            // x = mine[x-1][j] > mine[x][j] ? 
            //     mine[x-1][j] > mine[x+1][j] ? x-1: x+1 
            //                             :
            //                              mine[x][j] > mine[x+1][j] ? x: x+1;

            if(dp[x-1][j] > dp[x][j] && dp[x-1][j] > dp[x+1][j]){
                x = x - 1;
            } else if(dp[x-1][j] < dp[x][j] && dp[x+1][j] < dp[x][j]){
                x = x;
            } else{
                x = x + 1;
            }
        }

        path.push_back(mine[x][j]);
    }
    // reverse(path.begin(), path.end());
    for(auto x: path){
        cout << x << " ";
    }
    cout  << endl;
    path.clear();
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> mine(n, vector<int>(m, 0));
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> mine[i][j];
        }
    }

    // using backtracking
    // using dp

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i=0; i<n; ++i){
        bfs(mine, i, 0, dp);
    }    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout  << dp[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> xs;
    for(int i=0; i<n; ++i){
        if(dp[i][dp[0].size()-1] > omax){
            omax = dp[i][dp[0].size()-1];
        }
    }
    for(int i=0; i<n; ++i){
        if(dp[i][dp[0].size()-1] == omax){
            omax = dp[i][dp[0].size()-1];
            xs.push_back(i);
        }
    }
    cout << omax << endl;
    cout << xs.size() << " " << xs[0] << endl;
    for(auto x: xs){
        printMaxPath(dp, x, mine);
    }
    return 0;
}

