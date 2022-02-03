#include<bits/stdc++.h>
using namespace std;


void printDFS(vector<pair<int, int>> adj[], int idx, vector<bool> &visited){

    cout << idx << " ";
    visited[idx] = true;


    for(auto item: adj[idx]) {
        if(!visited[item.first]){
            // cout << item.first << ' ';
            printDFS(adj, item.first, visited);
        }
    }
}


int main()
{
    int V, E;cin>>V>>E;

    vector<pair<int, int>> adj[V];

    for(int i=0; i<E; ++i) {
        int u, v, wt; cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<bool> visited(V, false);

    for(int i=0; i<V; ++i){
        if(!visited[i]) {
            printDFS(adj, i, visited);
            cout << endl;
        }
    }
    return 0;
}