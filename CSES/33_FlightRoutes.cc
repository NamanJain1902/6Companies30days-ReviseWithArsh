#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int INF = 9e16;

struct Edge {
    int v, wt;
};

int n, m, k;
vector<int> ret;
vector<int> visited;
vector<vector<Edge>> graph; 
priority_queue<int> pq;

void dfs(int node, int cost) {
    if(node == n) {
        pq.push(cost);
        if(pq.size() > k) {
            pq.pop();
        }
        return;
    }

    visited[node] = true;
    for(Edge child: graph[node]) {
        if(!visited[child.v]) {
            dfs(child.v, cost + child.wt); 
        } 
    }
    visited[node] = false;
}


void dij() {
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>> 
    > pq;
    pq.push({0, 1});
    vector<vector<int>> dist(n+1, vector<int>(k, INF));

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist[u][k-1] < d) continue;

        for(auto e: graph[u]) {
            int v = e.v;
            int c = e.wt;

            if(dist[v][k-1] > c + d) {
                dist[v][k-1] = c + d;
                pq.push({dist[v][k-1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }

    for(auto x: dist[n]) {
        cout << x << ' ';
    }
    cout << endl;
}

int32_t main() {
    cin >> n >> m >> k;
    graph.resize(n+1);
    visited.resize(n+1, 0);

    // input city network as directed graph
    for(int i=1; i<=m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dij();

    // dfs(1, 0);    
    // vector<int> ret;
    // while(!pq.empty()){
    //     ret.push_back(pq.top());
    //     pq.pop();
    // }
    // sort(ret.begin(), ret.end());
    // for(auto x: ret) {
    //     cout << x << ' ';
    // }
    // cout << endl;
    // shortest path finding algo
    // dijkstra...
    // finding k shortest path, given shortest 
    // path from source to each node of graph.
    
    // i can do bfs on that shortest distances 
    // vector to find the k shortest paths
    return 0;    
}