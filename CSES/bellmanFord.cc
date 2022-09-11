#include<bits/stdc++.h>
using namespace std;

struct Node {
    int u, v, wt;
    Node(int _u, int _v, int _wt) {
        this->u = _u;
        this->v = _v;
        this->wt= _wt;
    }
};
int main() {
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int N, M;
    cin >> N >> M;
    vector<Node> edges;
    for(int i=0; i<M; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Node(u, v, wt));
    }
    int src=1;
    // cin >> src;

    int inf = 1e6;
    vector<int> dist(N, inf);
    dist[src] = 0;

    for(int i=1; i<=N-1; ++i) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int fl = 0;
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle\n"; fl = 1; break;
        }
    }

    if(!fl) { for(auto x: dist) { cout << x << ' '; } cout << endl; }

    return 0;
}