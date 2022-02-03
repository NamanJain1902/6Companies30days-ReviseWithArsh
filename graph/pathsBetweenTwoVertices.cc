#include<bits/stdc++.h>
using namespace std;

template<class T>
void print(vector<T> v){
    for(auto x:v)cout<<x<<' ';cout<<endl;
}

vector<int> path;

void findAllPaths(vector<int> const adj[], int currnode, int dest, vector<int> &path) {

    visited[currnode] = true;

    for(auto child: adj[currnode]) {
        if(child == dest){
            print<int>(path);
            return;
        } else {
            path.push_back(child);
            findAllPaths(adj, child, dest, path);
        }
    }
}


int main(){
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i=0; i<V; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src, dest;cin>>src>>dest;
    vector<bool> visited(V, false);
    for(int i=0; i<V; ++i){
        if(!visited[i]){
            path.clear();
            visited[dest] = false;
            findAllPaths(adj, src, dest, path);
        }
    }
}