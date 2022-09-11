#include<bits/stdc++.h>
using namespace std;


void transposeGraph(vector<vector<int>> &graph, vector<vector<int>> &transposed_graph) {
    for(int node=0; node<graph.size(); ++node) {
        for(auto x: graph[node]) {
            transposed_graph[x].push_back(node);
        }
    }
}
void printGraph(vector<vector<int>> &graph) {
    for(int node = 0; node < graph.size(); ++node) {
        cout << node << " -> ";
        for(auto x: graph[node]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void topologicalSort(vector<vector<int>> &graph, int node, stack<int> &st, vector<int> &visited) {
    visited[node] = 1;
    for(auto x: graph[node]) {
        if(!visited[x]){
            topologicalSort(graph, x, st, visited);
        }
    }
    st.push(node);
}

void dfs(vector<vector<int>> &graph, int node, vector<int> &visited, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);

    for(auto x: graph[node]) {
        if(!visited[x]){
            dfs(graph, x, visited, component);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V+1), transposed_graph(V+1);
    vector<int> visited(V+1, 0);
    vector<vector<int>> strongly_connected_components;

    // directed graph
    for(int i=0; i<V; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    for(int i=0; i<=V; ++i){
        if(!visited[i]) {
            topologicalSort(adj, i, st, visited);
        }
    }
    visited.clear();
    visited.assign(V+1, 0);

    // transposed Graph
    transposeGraph(adj, transposed_graph);
    printGraph(transposed_graph);
    
   
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(visited[node] or node==0) {
            continue;
        }
        vector<int> component;
        for(auto x: transposed_graph[node]) {
            if(!visited[x]) {
                dfs(transposed_graph, x, visited, component);
            }
        }   
        if(component.size() == 0){ component.push_back(node); visited[node] = true;}

        strongly_connected_components.push_back(component);
        component.clear();
    }
    printGraph(strongly_connected_components);

    return 0;   
}