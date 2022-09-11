#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u;
    int v;
    int wt;

    Edge(){}
    Edge(int _u, int _v, int _wt) {
        this->u = _u;
        this->v = _v;
        this->wt = _wt;
    }
};

int main()
{   
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;
    vector<int> visited(V+1, 0);

    // directed graph
    for(int i=0; i<V; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(Edge(u, v, wt));
    }
    int src;
    cin >> src;

    int inf = 1e6;
    vector<int> dist(V+1, inf);
    dist[src] = 0;

    for(int i=1; i<=V-1; ++i) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]){
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    
    bool fl = false;
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]){
            cout << "Negative Cycle\n";
            fl = true;
            break;
        }
    }

    if(!fl) {
        for(int i=1; i<=V; ++i) {
            cout << i << " " << dist[i] << "\n";
        }
    }

    return 0;
}
