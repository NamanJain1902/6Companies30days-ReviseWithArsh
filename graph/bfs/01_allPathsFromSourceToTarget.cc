#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if (graph.size() == 0) {
            return paths;
        }

        vector<int> path;
        queue<vector<int>> q;
        path.push_back(0);
        q.push(path);

        while (!q.empty()) {
            vector<int> currentPath = q.front();
            q.pop();
            int node = currentPath.back();
            for (int nextNode : graph[node]) {
                vector<int> tmpPath(currentPath.begin(), currentPath.end());
                tmpPath.push_back(nextNode);
                if (nextNode == graph.size() - 1) {
                    paths.push_back(tmpPath);
                } else {
                    q.push(tmpPath);
                }
            }
        }
        return paths;
    }
};

void bfs(vector<vector<int>> &graph, int src, int dest) {

    queue<int> q, temp;
    q.push(src);
    
    while(!q.empty()) {
        int tp = q.front();
        q.pop();
        
        
        for(auto child: graph[src]) {
            temp.push(child);
        }



    }
}


int main()
{
    int V;cin>>V;

    vector<vector<int>> adj = {{4,3,1},{3,2,4},{3},{4},{}};

    // for(int i=0; i<V; ++i) {
    //     int x;
    //     while(cin >> x){
    //         if(x == -1){
    //             adj[i].push_back({});
    //         } else{
    //             adj[i].push_back(x);
    //         }
    //     }
    // }

    // for(int i=0; i<V; ++i){
    //     for(int j=0; j<adj[i].size(); ++j){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    bfs(adj);

}