#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src;
        int dest;
        int wt;
};

bool comp(Edge a, Edge b){
    return a.wt < b.wt;
}

int getParent(int child, int *parent){
    if(child == parent[child]){
        return child;
    }
    return getParent(parent[child], parent);
}

Edge *kruskal(Edge *edges, int n, int E, int &total_weight){
    // Sorted the edges array in increasing order
    sort(edges, edges + E, comp);

    Edge *output = new Edge[n-1];
    int *parent  = new int[n];
    for(int i=0; i<n; ++i) parent[i] = i;

    int count = 0;
    int i = 0;
    while(count < (n - 1)) {
        // Check the topmost parent of v1 and v2. v1 and v2 are vertices of current Edge
        Edge currentEdge = edges[i];
        int srcParent = getParent(currentEdge.src, parent);
        int destParent = getParent(currentEdge.dest, parent);

        if(srcParent != destParent) {
            total_weight += currentEdge.wt;
            output[count] = currentEdge;
            count += 1;
            parent[srcParent] = destParent;
        } 

        i += 1;
    }
    return output;
}

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n, E;
        cin >> n >> E;
        Edge *edges = new Edge[E];

        for(int i=0; i<E; ++i){
            int s, d, w;
            cin >> s >> d >> w;

            edges[i].src  = s;
            edges[i].dest = d;
            edges[i].wt   = w;
        }
    
        int total_weight = 0;
        Edge* output = kruskal(edges, n, E, total_weight);
        
        // cout << "Cost of Minimum Spanning Tree is "  << total_weight << "\n";
        cout << total_weight << endl;
        // for(int i=0; i<n-1; ++i) {
        //     if(output[i].src < output[i].dest) {
        //         cout << output[i].src << " " << output[i].dest  << " " << output[i].wt << "\n"; 
        //     } else {
        //         cout << output[i].dest << " " << output[i].src  << " " << output[i].wt << "\n"; 
        //     }
        // }
    }

    return 0;
}