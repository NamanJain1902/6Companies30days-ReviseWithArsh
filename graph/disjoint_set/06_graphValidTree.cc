#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {       
        if (n - 1 != edges.size()) return false;
        vector<int> parent(n);

        for (int i = 0; i < n; ++ i) {
            parent[i] = i;
        }
        
        for (const auto &e: edges) {
            int x = find(parent, e[0]);
            int y = find(parent, e[1]);
            // if parents are equal, we know there is a cycle.
            if (x == y) return false;
            // make two nodes same parent (group)
            parent[x] = y;        
        }
        return true;
    }
    
private:
    int find(vector<int> &parent, int i) {
        while (i != parent[i]) {
            parent[i] = parent[parent[i]]; // compress the disjoint set
            i = parent[i];
        }
        return i;
    }
};


class Solution {
public:
    bool validTree(int n, vector<vector <int>>& edges) {       
        if (n - 1 != edges.size()) return false;
        if (edges.size() == 0) return true;
        vector<bool> v(n, false);
        vector<unordered_set<int>> g(n); // adjacency matrix
        for (const auto &e: edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        queue<int> Q;
        Q.push(edges[0][0]);
        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            for (const auto x: g[p]) {
                if (!v[x]) {
                    Q.push(x);
                    v[x] = true;
                }
            }
        }
        for (const auto &n: v) {
            if (!n) return false;
        }
        return true;
    }
};





bool validTree(int n, vector<vector<int>> &edges) {
    if(n - 1  != edges.size()) return false;
    if(edge.size() == 0) return true;
    vector<bool> v(n, false);
    vector<unordered_set<int>>


    for(auto [u, v]: edges) {
                    
    }

}




vector<int> roots;
vector<int> ranks;

bool find(int child){
    while(child != roots[child]){
        roots[child] = roots[roots[child]];
        child = roots[child];
    }
    return child;
}
bool connected(int x, int y) {
    return find(x) == find(y);
}   
void _union(int A, int B){
    int rootA = find(A);
    int rootB = find(B);

    if(rootA != rootB){
        if(ranks[rootA] > ranks[rootB]){
            roots[rootB] = rootA;
        } else if(ranks[rootA] < ranks[rootB]){
            roots[rootA] = rootB;
        } else {
            roots[rootA] = rootB;
            ranks[rootB]+=1;
        }
    }
}
bool isGraphConnected(vector<vector<int>> adj, int V) {

    roots.resize(V, 0);
    ranks.resize(V, 1);    

    for(int i=0; i<V; ++i){
        roots[i] = i;
    }

    for(auto const& child: adj) {
        if() {

        }
    }

    return true;

}

int main(){
    // for displaying boolean as string literals.
    cout << boolalpha; 
    
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for(int i=0; i<E; ++i){
        int x, y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


}