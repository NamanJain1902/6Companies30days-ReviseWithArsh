#include<bits/stdc++.h>
using namespace std;


class UnionFind{

    public:
        UnionFind(int sz) : parent(sz), rank(sz, 1), count(sz), time(0) {
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int child){
            if (child == parent[child])
                return child;
            return parent[child]
                = find(parent[child]);
            // while(child != parent[child]){
            //     int temp = parent[child];
            //     parent[child] = parent[parent[child]];
            //     child = temp;
            // }
            // return child;
        }

        void _union(int A, int B, int rabtaTime){

            if(count == 1) return;

            int rootA = find(A);
            int rootB = find(B);

            if(rootA == rootB) return;

            if(rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if(rank[rootB] > rank[rootA]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA] += 1;
            }

            time = rabtaTime;
            count--;
        }

        int earliestTime(){
            return time;
        }
        int get_count(){
            return count;
        }

    private:
        vector<int> parent;
        vector<int> rank;
        int count;
        int time;
};



int main(){
    int n ;
    cin >> n;
    
    UnionFind uf(n);

    vector<vector<int>> vv;
    
    int u, v, t;
    while(cin >> u >> v >> t) {
        vv.push_back({u,v,t});
    } 

    sort(vv.begin(), vv.end(), [&](vector<int> a, vector<int> b){
        return a[2] <= b[2];
    });

    for(auto &it: vv){
        uf._union(it[0], it[1], it[2]);
    }

    if(uf.get_count() == 1){
        cout << uf.earliestTime() << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
