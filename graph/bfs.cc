#include<bits/stdc++.h>
using namespace std;

void BFS(vector<pair<int, int>> adj[], int V){
    vector<int> bfs;
    vector<bool> visited(V, false);


    for(int i=0; i<V; ++i){
        if(!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                bfs.push_back(u);

                for(auto item: adj[u]) {
                    if(!visited[item.first]) {
                        q.push(item.first);
                        visited[item.first] = true;
                    }
                }
            }
            for(auto x: bfs)cout<<x<<' ';
            cout << "\n";
        }
    }


    cout<<"\n";
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

    BFS(adj, V);
    return 0;
}