#include<bits/stdc++.h>
using namespace std;

int minCostToSupplyWater(int n, vector<int>&wells, vector<vector<int>>& pipes){
    // using greedy approach
    
}

class Solution
{
    public:
        Solution(){}
        Solution(int sz) : parent(n), rank(1, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int child){
            while(child != parent[child]){
                int temp = parent[parent[child]];
                child = parent[child];
                parent[child] = temp;
            }
            return child;
        }

        void _union(int A, int B) {
            int rootA = find(A);
            int rootB = find(B);

            if(rootA == rootB) return;
            
            if(rank[rootA] > rank[rootB]){
                parent[rootB] = rootA;
            } else if(rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootA] = rootB;
                rank[rootB] += 1;
            }
        }

        int minCostToSupplyWater(int n, int wells, vector<vector<int>> &pipes) {
            
        }
    private:
        vector<int> parent;
        vector<int> rank;
};

int main(){
    int v,e;
    cin>>v>>e;
    
    
    vector<int>wells(v);
    
    for(int i=0;i<v;i++){
        cin>>wells[i];
    }
      
    vector<vector<int>>pipes(e,vector<int>(3));
    
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }
    
    cout<<minCostToSupplyWater(v, wells, pipes)<<"\n";
    return 0;
}