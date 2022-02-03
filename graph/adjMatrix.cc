#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const bool undirected = true;
const bool directed = false;

int main()
{
    int V, E;
    cin >> V >> E;

    int adj[V][V] = {0};
    memset(adj, 0, sizeof(adj));
    // vector<vector<int>> adj(V, vector<int>(V, 0));

    for(int i=0; i<E; ++i) {
        int u, v; 
        cin >> u >> v;

        if(undirected){
            // showing edge between u and v.
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        if(directed) {
            // showing edge from u to v.
            adj[u][v] = 1;
        }
    }

    for(int i=0; i<V; ++i) {
        for(int j=0; j<V; ++j) {
            cout << adj[i][j] << ' ';
        }
        cout << "\n";
    }
}
