#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int INF = 9e17;

struct Node{
    int v;
    int wt;
    Node(int _v, int _wt) {
        this->v = _v;
        this->wt = _wt;
    }
};

vector<vector<Node>> graph;

// finding negative cycle using bellman ford
bool bellman_ford() {
    int n, m;
    cin >> n >> m;
    vector<int> dist(n+1, INF), parent(n+1);
    dist[1] = 0;
    // src distance 0
    // destination is n
    bool hasCycle = false;

    vector<int> cycle;

    for(int i=1; i<=n;++i) {
        for(int v=1; v<=n; v++){
            for(auto node: graph[v]) {
                int vertex = node.v;
                int weight = node.wt;
                if(dist[v] + weight < dist[vertex]) {
                    dist[vertex] = dist[v] + weight;
                    parent[vertex] = v;
                    hasCycle = true;
                }
            }
        }
    }

    return hasCycle;
}

// using floyd warshall algo
void floyd_warshall() {

}

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
// const int INF = 1000000000;
vector<int> cycle;
bool solve()
{
    vector<int> d(n+1);
    vector<int> p(n+1, -1);
    int x = -1;
    for (int i = 1; i <= n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        return false;
    } else {
        for (int i = 1; i <= n; ++i){
            x = p[x];
        }

        
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        
    }
    return true;
}

int32_t main() {
    cin >> n >> m;

    for(int i=1; i<=m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    if(solve()){
        cout << "YES\n";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    } else {
        cout << "NO\n";
    }
    return 0;
}



/*
https://www.ericsson.com/en/about-us
Ericsson 5G
https://www.ericsson.com/en/5g
Ericsson Mobility Report
https://www.ericsson.com/en/reports-and-papers/mobility-report
Ericsson Business Support System Product Portfolio
https://www.ericsson.com/en/telecom-bss
Ericsson AI
https://www.ericsson.com/en/ai
Ericsson enabling India
https://www.ericsson.com/en/about-us/new-world-of-possibilities/imagine-possible-india
*/
