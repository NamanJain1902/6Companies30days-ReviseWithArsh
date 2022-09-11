#include<bits/stdc++.h>
using namespace std;


void dfs(int i, vector<vector<int>> &visited) {

    if(!visited[i]) visited[i] =
    for(int )
}

void secondApproach() {
    // find number of connected components...let's say there are
    // k connected components...we can connect these components using 
    // heads of all k-1 nodes.
    int n,m;
    cin >> n >> m;
    vector<bool> visited(n+1);
    for(int i=1; i<=m; ++i){
        int a, b;
        cin >> a >> b;
        visited[a] = visited[b] = true;
    }
    vector<int> v;
    for(int i=1; i<=n; ++i) {
        if(!visited[i]) {
            v.push_back(i);
            dfs(i, visited);
        }
    }
}

class UnionFind1 {
    int cnt;
    vector<int> parent;
    vector<int> rank;
    vector<vector<int>> vv;
    int m;
    public:

        // UnionFind(int n) : rank(n), iota(rank.begin(), rank.end(), 0), parent(n, -1);
        UnionFind1(int n, int m) : parent(n) {
            cnt = 0;
            this->m = m;
            iota(parent.begin(), parent.end(), 0);
        }

        // this will return the root of current component.
        int find(int child) {
            while(child != parent[child]) {
                parent[child] = parent[parent[child]];
                child = parent[child];
            }
            return child;
        } 

        void unionSet(int nodeA, int nodeB) {
            int parentA = find(nodeA);
            int parentB = find(nodeB);

            if(parentA != parentB) {
                parent[nodeA] = parentB;
                cnt++;
                if(cnt > m)
                vv.push_back({nodeA, nodeB});
            }
        }

        int get_cnt(){
            return this->cnt - this->m;
        }

        void new_roads(){
            for(auto x: vv){
                for(auto y: x){
                    cout << y << ' ';
                }
                cout << endl;
            }
        }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind1 obj(n, m);

    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        obj.unionSet(a, b);
    }   

    // for(int i=1; i<=n-1; ++i) {
    //     obj.unionSet(i, i+1);
    // }

    cout << obj.get_cnt() << endl;
    obj.new_roads();
}