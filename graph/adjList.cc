#include<iostream>
#include<vector>
using namespace std;


const bool undirected = false;
const bool directed = true;


int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i=0; i<E; ++i) {
        int u, v;cin>>u>>v;

        if(undirected){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(directed) {
            adj[u].push_back(v);
        }
    }

    for(int i=0; i<V; ++i) {
        cout << i << ' ';
        for(auto item: adj[i]) {
            cout << item << ' ';
        }
        cout << "\n";
    }
}