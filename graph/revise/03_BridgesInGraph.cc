#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &visited, vector<int> &tin ,vector<int> &lin, vector<vector<int>> &adj, int timer) {
    visited[node] = 1;
    tin[node] = lin[node] = timer++;

    for(auto it: adj[node]) {
        if(it == parent) continue;

        if(visited[it] == 0) {
            dfs(it, node, visited, tin, lin, adj, timer);
            
            lin[node] = min(lin[node], lin[it]);

            if(lin[it] > tin[node]) {
                cout << it << " " << node << endl;
            }
        } else {
            lin[node] = min(lin[node], tin[it]);
        }
    }
}

void printBridges(vector<vector<int>> &adj, int n) {
    vector<int> visited(n), insertion_time(n, -1), lowest_insertion_time_among_negihbors(n, -1);

    int timer = 0;
    for(int i=0; i<n; ++i) {
        if(visited[i] == 0) {
            dfs(i, -1, visited, insertion_time, lowest_insertion_time_among_negihbors, adj, timer);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<n; ++i){
        int u, v;
        cin >> u >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printBridges(adj, n);

    return 0;
}