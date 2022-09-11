#include<bits/stdc++.h>
using namespace std;

struct Node {
    int node;
    int weight;
    Node(int _node, int _weight) {
        this->node = _node;
        this->weight = _weight;
    }
    bool operator()(const Node a, const Node b) {
        return a.weight < b.weight;
    }
};
int n, m;
vector<vector<Node>> graph;

int brute() {
    vector<int> parent(n), key(n), mstSet(n);

    for(int i=0; i<n; ++i) {
       key[i]=INT_MAX, mstSet[i]=false;
    }

    key[0]=0;
    parent[0] = -1;


    for(int count = 0; count < n - 1; ++count) {
        int mini = INT_MAX, u;

        // to find te minimal key value and store it's index
        // and also make sure that's not part of MST.
        for(int v = 0; v < n; ++v) {
            if(mstSet[v] == false and key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }
        // once u found out such index, mark it visited in mst  
        mstSet[u] = true;


        // iterate for all it's adjacent node
        for(auto it: graph[u]) {
            int v = it.node;
            int weight = it.weight;

            if(mstSet[v] == false  and weight < key[v]) {
                parent[v] = u, key[v] = weight;
            }
        }
    }

    for(int i=0; i<n; ++i){
        cout << parent[i]  << "  -  " << i << endl;
    }

    return accumulate(key.begin(), key.end(), 0);
}

void optimal() {
    vector<int> parent(n), key(n), mstSet(n);

    for(int i=0; i<n; ++i) {
       key[i]=INT_MAX, mstSet[i]=false;
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    key[0]=0;
    parent[0] = -1;
    pq.push({0, 0});

    for(int count = 0; count < n - 1; ++count) {

        int tp = pq.top(); // minimum key value in logN using priority_queue
        pq.pop();

        if(mstSet[tp.node] == true) continue;

        int u = tp.node;
        mstSet[u] = true;

        for(auto it: graph[u]) {
            int v = it.node;
            int wt = it.weight;
            if(mstSet[v] == false and wt < key[v]) {
                parent[v] = u;
                pq.push({v, wt});
                key[v] = wt;
            }
        }
    }

    for(int i=0; i<n; ++i){
        cout << parent[i]  << "  -  " << i << endl;
    }

    return accumulate(key.begin(), key.end(), 0);

}
int main() {
    cin >> n >> m;

    graph.resize(n+1);

    int a, b, c;
    for(int i=1; i<=m; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cout << optimal() << endl;
}

