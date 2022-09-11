#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &lin, vector<int> &isArticulation, vector<vector<int>> &adj, int timer) {
    vis[node] = 1;
    tin[node] = lin[node] = timer++;
    int child = 0;

    for(auto it: adj[node]) {
        if(it == parent) continue;

        if(vis[it] == 0) {
            dfs(it, node, vis, tin, lin, isArticulation, adj, timer);

            if(lin[it] >= tin[node] && parent != -1) {
                isArticulation[node] = 1;
            }
            child++;
        } else {
            lin[node] = min(lin[node], tin[it]);
        }
    } 
    if(parent != -1 and child > 1) isArticulation[node] = 1;
}

void printArticulation(vector<vector<int>> &adj, int n) {
    vector<int> vis(n, 0), tin(n, -1), lin(n, -1), isArticulation(n, 0);
    int timer = 0;

    for(int i=0; i<n; ++i) {
        if(vis[i] == 0) {
            dfs(i, -1, vis, tin , lin, isArticulation, adj, timer);
        }
    }

    for(auto x: isArticulation){
        cout << x << " ";
    }
    cout << endl;
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
    printArticulation(adj, n);

    return 0;
}