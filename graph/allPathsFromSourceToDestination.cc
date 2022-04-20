/**
* @author NamanJain1902
* On: 19/03/2022 
* At: 17:31:45
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("avx,avx2")

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <numeric>
#include <climits>

#include <array>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
 
#include <cstring>
#include <ostream>
#include <type_traits>
#include <utility>
#include <chrono>
#include <random>
 
using namespace std;

#define pr pair<int, int>
#define pb push_back
#define s second
#define f first
#define ll long long
#define int long long int
#define sz(x) ((int)x.size())

const int MAX = 100000 + 5;
const int HMAX = 1000000007;

int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}

class Solution {
public:
    void dfs_paths(vector<vector<int>> &graph,int src,vector<int> &curr,vector<vector<int>> &ans)
    {
        curr.push_back(src);
        if(src==graph.size()-1)
        {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        else 
        {
            for(auto node:graph[src])
            dfs_paths(graph,node,curr,ans);
        }    
        
        curr.pop_back();    //backtracking
    }

    vector<vector<int>> ret;
    void sol(vector<vector<int>> &graph, vector<bool> &visited, int node, vector<int> path) {
        
        if(node == (graph.size() - 1)) {
            ret.push_back(path);
            return;
        }
        visited[node] = true;

        for(auto child: graph[node]) {
            if(!visited[child]) {
                path.push_back(child);
                sol(graph, visited, child, path);
                path.pop_back();
            }
        }
        visited[node] = false;
    }
    
    vector<vector<int>> ret;
    void bfs(vector<vector<int>> &graph, int src, int dest){
        queue<int> q;
        q.push(src);
        // vector<bool> visited(graph.size(), false);
        // visited[0] = true;
        vector<int> t;
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            t.push_back(tp);
            
            if(tp == dest) { ret.push_back(t); }
            
            for(auto child: graph[tp]){
                visited[tp] = true;    
                q.push(child);
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n = graph.size();
        bfs(graph, 0, n);
        return ret;
    }
//     void dfs(vector<vector<int>> &graph, int src, int dest, vector<vector<int>> &paths, vector<int> &path){
        
//         for(auto child: )
//     }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        // dfs approach
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        int dest = n - 1;
        // dfs(graph, 0, n-1, paths, path);
        stack<int> st;
        st.push(0);
        vector<bool> visited(n, false);
        while(!st.empty()) {
            int tp = st.top();
            visited[tp] = true;
            path.push_back(tp);
            if(tp == dest) {
                paths.push_back(path);
            }
            for(auto child: graph[tp]) {
                if(!visited[child]) {
                    st.push(child);
                }
            }
        }
    }
};

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
//   int t=1;
    Solution sol;
    int v, e;
    cin >> v >> e ;
    vector<vector<int>> graph(e, vector<int>(3, 0));
    for(int i=0; i<e; ++i){
        graph.push_back()
    }
    vector<vector<int>> ret = sol.allPathsSourceTarget(graph);
    for(auto x: ret){
        cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
    }
    return 0;
}
