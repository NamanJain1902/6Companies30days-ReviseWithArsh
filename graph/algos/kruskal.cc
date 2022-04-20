#include<bits/stdc++.h>
using namespace std;

int find(int child, vector<int> &parent){
    if(child == parent[child]){
        return child;
    }
    return find(parent[child], parent);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int V, E;
        cin >> V >> E;
        
        vector<vector<int>> graph(E,vector<int>(3));
        for(int i=0; i<E; ++i){
            int s, d, w;
            cin >> s >> d >> w;
            graph[i] = {s, d, w};
        }
        
        // Step 1: Sort w.r.t weights...because kruskal want to choose minimum 
        // weighted edge first and include that in minimum spanning tree...condition 
        // applied that inclusion must not create cycle in graph or 
        // any incoming edge should keep new graph acyclic.
        sort(graph.begin(), graph.end(), [&](vector<int> a, vector<int> b){
            return a[2] < b[2];
        });


        // for(auto x: graph){
        //     cout << x[0] << ' ' << x[1]  << ' ' << x[2] << "\n";
        // }
        
        int count = 0; // count of edge 
        
        vector<int> parent(V);
        vector<int> rank(V, 0);
        iota(parent.begin(), parent.end(), 0);
        int idx = 0;
        int total_weight = 0;
        vector<vector<int>> output; //(V-1, vector<int>(3, 0));
        // for tree... if we have V edge then number of edge is V - 1 
        while(count < V - 1 ){
            
//             auto find = [](auto&& find, int child){
//                 // while(child != parent){
//                 // 	child = parent[child];
//                 // 	parent = parent[child];
//                 // }
//                 // return child;
//                 if(child == parent[child]){
//                     return child;
//                 }
                
//                 return find(find, parent[child]);
//             };
            
            auto _union = [&](int a, int b, int wt, vector<int> parent){
                int parentA = find(a, parent);
                int parentB = find(b, parent);
                
                /// connnected
                if(parentA == parentB){
                    return;
                }
                if(rank[a] > rank[b]){
                    parent[b] = a;
                } else if(rank[b] > rank[a]) {
                    parent[a] = b;
                } else{
                    parent[a] = b;
                    rank[b] += 1;
                }
                output.push_back({a, b, wt});
                count += 1;
                total_weight += wt;
                // output[count] = {a, b, wt};
            };
            
            
            _union(graph[idx][0], graph[idx][1], graph[idx][2], parent);
            // int a = graph[idx][0];
            // int b = graph[idx][1];
            // int wt = graph[idx][2];

            // int srcParent  = find(a, parent);
            // int destParent = find(b, parent);

            // if(srcParent != destParent) {
            //     output[count] = {a, b, wt}; 
            //     // output.push_back({a, b, wt});
            //     count += 1;
            //     total_weight += wt;
            //     parent[a] = parent[b];
            // }

            idx+=1;
        }
	    cout << total_weight << "\n";
        // for(auto p: output){
        //     cout << p[0] << ' ' << p[1] << ' ' << p[2]  << "\n";
        // }

    }
    
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// struct edge{
//   int src;
//   int dest;
//     int weight;
// };
// bool comp(edge &a,edge &b)
// {
//     return a.weight<b.weight;
        
// }
// unordered_map<int, int> parent;
//  int Find(int k)
//     {
//         // if `k` is root
//         if (parent[k] == k) {
//             return k;
//         }
 
//         // recur for the parent until we find the root
//         return Find(parent[k]);
//     }
 
//     // Perform Union of two subsets
//     void Union(int a, int b)
//     {
//         // find the root of the sets in which elements `x` and `y` belongs
//         int x = Find(a);
//         int y = Find(b);
 
//         parent[x] = y;
//     }
// int main(){
    
//     // write your code here
//     int t;
//     cin>>t;
//     while(t--)
//     {
//        int v,e;
//         cin>>v>>e;
//         edge *edges=new edge[e];
//         for(int i=0;i<e;i++)
//         {
//             cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
//         }
//         sort(edges,edges+e,comp);
//        // for(int i=0;i<e;i++)
//         //{
//         //    cout<<edges[i].weight<<" ";
//        // }
//         cout<<endl;
//         int count=0;
//          for (int i = 0; i < v; i++) {
//             parent[i] = i;}
//              int output=0;
//         while(count<v-1)
//         {
//             for(int i=0;i<e;i++)
//             {
//             int x = Find(edges[i].src);
//             int y = Find(edges[i].dest);
 
//             // if both `u` and `v` have the same parent, the cycle is found
//             if (x == y) {
//                 continue;
//             }
//             else {
//                 count++;
//                 output+=edges[i].weight;
//                 Union(x, y);
//             }
//             }
            
//         }
//              cout<<output<<endl;
//     }
//     return 0;
// }
