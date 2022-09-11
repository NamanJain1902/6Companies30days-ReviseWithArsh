#include<bits/stdc++.h>
using namespace std;

int sv, ev;
vector<vector<int>> graph;
vector<int> visited;
vector<int> path;
vector<int> parentV;
bool detectCycleUndirectedGraph(int node, int parent) {   
 //   cerr << node << " " << parent << endl;
    visited[node] = true;
    parentV[node] = parent;
    for(auto childNode: graph[node]) {
        if(!visited[childNode]) {
            if(detectCycleUndirectedGraph(childNode, node)) {
                return true;
            }
        } else if(childNode != parent) {
            sv = childNode;
            ev = node;
            return true;
        }
    }
    return false;
}

/* Undirected Graph */
bool CycleDetectionDFS(vector<pair<int, int>> adj[], int node, int parent, vector<bool> &visited) {
    visited[node] = true;

    for(auto it: adj[node]) {
        if(!visited[it.first]) {
            if(CycleDetectionDFS(adj, it.first, node,  visited)) return true;;
        } 
        else if(it.first != parent) return true;
    }
    return false;
}

bool detectCycleDFS(int V, vector<pair<int, int>> adj[]) {
    vector<bool> visited(V+1, false);
    for(int i=0; i<V; ++i) {
        if(!visited[i]){
            if(CycleDetectionDFS(adj, i, -1, visited)){
                return true;
            }
        }
    }
    return false;
}

bool checkForCycle(int idx, int V, vector<pair<int, int>> adj[], vector<bool> &visited){
    queue<pair<int, int>> q;
    visited[idx] = true;
    q.push({idx, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto item: adj[node]) {
            if(!visited[item.first]) {
                q.push({item.first, node});
                visited[item.first] = true;
                // prev = item.first;
            }
            else if(par != item.first) {
                return true;
            } 
        }
    }
    return false;
}
bool CycleDetectionBFS(vector<pair<int, int>> adj[], int V){
    /**
     * @brief if at some point my neigbhor node is already visited node that 
     * I can say there's a cycle in undirected graph.
     * 
     */
    vector<bool> visited(V, false);

    for(int i=0; i<V; ++i){
        if(!visited[i]) {
            if(checkForCycle(i, V, adj, visited)) return true;
        }
    }
    return false;
}


int main()
{
    int V, E;cin>>V>>E;

  //  vector<pair<int, int>> adj[V];
    graph.resize(V+1);
    visited.resize(V+1, 0);
    parentV.resize(V+1, 0);
    for(int i=0; i<E; ++i) {
        int u, v, wt; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
//        adj[u].push_back({v, wt});
//        adj[v].push_back({u, wt});
    }
    
    cout << boolalpha;
    for(int i=1; i<=V; ++i){
        if(!visited[i]) {
            if(detectCycleUndirectedGraph(i, -1)){
//                cout << true << endl;
               
                int tv = ev;
                vector<int> ret;
                ret.push_back(ev);
                while(tv != sv) {
                    ret.push_back(parentV[tv]);
                    tv = parentV[tv];
                }
                ret.push_back(ev);
                cout << ret.size() << endl;
                for(auto x: ret) cout << x << " ";
                cout << "\n";
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
/*
    if(CycleDetectionBFS(adj, V)){
        cout << "BFS Detected Cycle in Undirected Graph\n";
    } else {
        cout << "BFS NOT Detected Any Cycle in Undirected Graph\n";
    }

    if(detectCycleDFS(V, adj)){
        cout << "DFS Detected Cycle in Undirected Graph\n";
    } else {
        cout << "DFS NOT Detected Any Cycle in Undirected Graph\n";
    }
    return 0;
*/
}
