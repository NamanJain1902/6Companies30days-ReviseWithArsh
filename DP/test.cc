#include<bits/stdc++.h>
using namespace std;

int omax = 0;
class Cell {
    public:
    int x,y;
    string dir;

    Cell(){}
    Cell(int x, int y, string dir=""){
        this->x = x;
        this->y = y;
        this->dir = dir;
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

// dfs to find path
void printMaxPathBFS(vector<vector<int>> &dp, int x,  vector<vector<int>> &mine){
    int n = mine.size();
    int m = mine[0].size();
    vector<string> path;
    queue<Cell> st;
    st.emplace(x, m-1, to_string(mine[x][m-1]));

    while(!st.empty()){
        Cell curr = st.front();
        int x = curr.x;
        int j = curr.y - 1;
        string dir = curr.dir;
        st.pop();
        path.push_back(dir);

        if(j == 0){
            for(auto p: path){
                cout << p << " ";
            }
            cout << endl;
        }

        if(x == 0){
            if(dp[x][j] > dp[x+1][j]){
                x = x - 1;
                dir = "d1";
            } else if(dp[x][j] < dp[x+1][j]){
                x =  x;
                dir = "d2";
            } else{
                st.emplace(x-1, j, "d1");
                st.emplace(x, j, "d2");
                continue;
            }
        } else if(x == n-1){
            if(dp[x-1][j] > dp[x][j]){
                x = x - 1;
                dir = "d1";
            } else if(dp[x-1][j] < dp[x][j]){
                x =  x;
                dir = "d2";
            } else{
                // when equal
                st.emplace(x-1, j, "d1");
                st.emplace(x, j, "d2");
                continue;
            }
        } else{
            if(dp[x-1][j] > dp[x][j] && dp[x-1][j] > dp[x+1][j]){
                x = x - 1;
                dir = "d1";
            } else if(dp[x-1][j] < dp[x][j] && dp[x+1][j] < dp[x][j]){
                x = x;
                dir = "d2";
            } else if(dp[x+1][j] > dp[x][j] && dp[x+1][j] > dp[x-1][j]){
                x = x + 1;
                dir = "d3";
            } else{
                // equal cases
                if(dp[x-1][j] == dp[x][j] && dp[x-1][j] == dp[x+1][j]){
                    st.emplace(x - 1, j, "d1");
                    st.emplace(x, j, "d2");
                    st.emplace(x + 1, j, "d3");
                    continue;
                } else if(dp[x-1][j] == dp[x][j]){
                    st.emplace(x - 1, j, "d1");
                    st.emplace(x, j, "d2");
                    continue;
                } else if(dp[x-1][j] == dp[x+1][j]){
                    st.emplace(x - 1, j, "d1");
                    st.emplace(x + 1, j, "d2");
                    continue;
                } else if(dp[x][j] == dp[x+1][j]) {
                    st.emplace(x, j, "d2");
                    st.emplace(x + 1, j, "d1");
                    continue;
                }
            }
        }

        st.emplace(x, j, dir);
        
    }
}
void printMaxPath(vector<vector<int>> &dp, int x, vector<vector<int>> &mine){
    int n = dp.size();
    int m = dp[0].size();
    vector<string> path;
    path.push_back(to_string(mine[x][m-1]));
    string s;
    for(int j=m-2; j>=0; j--){
        if(x == 0){
            if(dp[x][j] >= dp[x+1][j]){
                x = x - 1;
                s = "d1";
            } else{
                x =  x;
                s = "d2";
            }
        } else if(x == n-1){
            if(dp[x-1][j] > dp[x][j]){
                x = x - 1;
                s = "d1";
            } else{
                x =  x;
                s = "d2";
            }
        } else{
            // x = mine[x-1][j] > mine[x][j] ? 
            //     mine[x-1][j] > mine[x+1][j] ? x-1: x+1 
            //                             :
            //                              mine[x][j] > mine[x+1][j] ? x: x+1;

            if(dp[x-1][j] > dp[x][j] && dp[x-1][j] > dp[x+1][j]){
                x = x - 1;
                s = "d1";
            } else if(dp[x-1][j] < dp[x][j] && dp[x+1][j] < dp[x][j]){
                x = x;
                s = "d2";
            } else{
                x = x + 1;
                s = "d3";
            }
        }

        path.push_back(s);
        s = "";
    }
    // reverse(path.begin(), path.end());
    for(auto x: path){
        cout << x << " ";
    }
    cout  << endl;
    path.clear();
}

void printMaxPath1(vector<vector<int>> &dp, int x, vector<vector<int>> &mine){
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

void printMaxPathOP(vector<vector<int>> &dp, vector<int> &xs, vector<vector<int>> &mine){
    queue<Cell> q;
    int n = mine.size(); int m = mine[0].size();

    for(auto x: xs){
        q.emplace(x, m-1, to_string(mine[x][m-1]));
    }

    while(!q.empty()){
        Cell curr = q.front();
        q.pop();
        int x = curr.x;
        int y = curr.y;


        if(y == 0){
            cout << curr.dir << endl;
        } else if(x == 0){
            int g = max(dp[x][y-1], dp[x+1][y-1]);

            if(g == dp[x][y-1]){
                q.emplace(x, y-1, curr.dir + " d2");
            }

            if(g == dp[x+1][y-1]){
                q.emplace(x+1, y-1, curr.dir + " d3");
            }
        } else if(x == n-1){
            int g = max(dp[x][y-1], dp[x-1][y-1]);

            if(g == dp[x-1][y-1]){
                q.emplace(x-1, y-1, curr.dir + " d1");
            }

            if(g == dp[x][y-1]){
                q.emplace(x, y-1, curr.dir + " d2");
            }
        } else {
            int g = max(dp[x][y-1], max(dp[x+1][y-1], dp[x-1][y-1]));

            if(g == dp[x-1][y-1]){
                q.emplace(x-1, y-1, curr.dir + " d1");
            }

            if(g == dp[x][y-1]){
                q.emplace(x, y-1, curr.dir + " d2");
            }

            if(g == dp[x+1][y-1]){
                q.emplace(x+1, y-1, curr.dir + " d3");
            }
        }
    }
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
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<m; ++j){
    //         cout  << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
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
    // cout << xs.size() << " " << xs[0] << endl;
    // for(auto x: xs){
    printMaxPathOP(dp, xs, mine);
    // }
    return 0;
}

