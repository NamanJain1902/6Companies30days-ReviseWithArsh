#include<bits/stdc++.h>
using namespace std;

/**
 * @details graphs that can be colored using exactly 2 colors
 * such that no two adjacent nodes have same colors.
 * 
 * Also, it a graph has odd length cycle it's not a bipartite graph
 * else it's a bipartite graph.
 */

bool colorGraphDFS(vector<int> adj[], int node, vector<int> &colorv){

    for(auto child: adj[node]) {
        if(colorv[child] == -1) { // if that node is not visited or it's uncolored
            colorv[child] = (colorv[node] == 1 ? 2 : 1); // then color it with alternate color that it's parent has.

            if(!colorGraphDFS(adj, child, colorv)) return false;
        } else if(colorv[child] == colorv[node]) return false;
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int V) {
    vector<int> colorv(V, -1);

    for(int i=0; i<V; ++i) {
        if(colorv[i] == -1) {
            colorv[i] = 1;
            if(!colorGraphDFS(adj, i, colorv)) return false;
        }
    }

    for(auto x: colorv) {
        cout << x << ' ';
    }
    cout << endl;

    return true;
}

bool bipartiteBFS(vector<int> adj[], vector<int> oddeve) {
    
    queue<int> q;
    oddeve[0] = 1;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto x: adj[u]){
            if(oddeve[x] == -1){
                oddeve[x] = (oddeve[u] == 1 ? 2: 1);
                q.push(x);
            } else if(x != u and oddeve[x] == oddeve[u]) {
                return false;
            }
        }
    }

    for(auto x: oddeve){
        cout << x  << ' ';
    }
    cout << endl;
    return true;
}

int main() {
    int V, E; cin >> V >> E;
    vector<int> adj[V];
    for(int i=0; i<V; ++i) {
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> oddeve(V, -1);

    if(bipartiteBFS(adj, oddeve)){
        cout << "BFS::Bipartite Graph\n";
    } else{
        cout << "BFS::Non-Bipartite Graph\n";
    }

   

    
    if(checkBipartite(adj, V)) {
        cout << "DFS::Bipartite Graph\n";
    } else{
        cout << "DFS::Non-Bipartite Graph\n";
    }
    return 0;
}