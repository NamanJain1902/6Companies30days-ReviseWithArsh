#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> route;
    unordered_map<string, vector<string>> umap;
    vector<pair<string, int>> visited;
        
    void dfs(string src){
        //if(umap.find(src) == umap.end()) return;
        sort(umap[src].begin(), umap[src].end());
        if(umap[src].size() == 0) return;
        // for(auto v: umap[src]){
        //     cout << v << " ";
        // }
        puts("");
        for(auto dest: umap[src]){
            string dt = dest;
            // cout  << dest << " - ";
            route.push_back(dest);
            auto itr = std::find(umap[src].begin(), umap[src].end(), dest);
            // cout << *itr << " ";
            if (itr != umap[src].end()) umap[src].erase(itr);
            // cout << *itr << "\n";
            dfs(dt);
        }
                
    }
    
    vector<string> findItinerary_0(vector<vector<string>>& tickets) {
        
        for(auto v: tickets){
            
            // if(umap.find(v[0]) != umap.end()){
                umap[v[0]].push_back(v[1]);
            // } else {
                // umap[v[0]] = {v[1]};
            // }
        }

        // visited.resize(umap.size(), {"", 0});

        // for(auto val: umap){
        //     cout << val.first << " --> ";
        //     for(auto item: val.second){
        //         cout << item  << " ";
        //     }
        //     cout << endl;
        // }

        route.push_back("JFK");
        dfs("JFK");
        
        // sort(route.begin(), route.end());        
        
        // for(auto it=route.begin(); it!=route.end(); ++it){
        //     if(*it == ""){
        //         route.erase(it);
        //         it--;
        //     }
        // }
        return route;
    }

    void findPath(string currNode, vector<string> &ret,  map<string, vector<string>> &graph, map<string, int> &outdegree){

        ret.push_back(currNode);
        while(outdegree[currNode]) {
            findPath(graph[currNode][--outdegree[currNode]], ret, graph, outdegree);
        }
    }

    vector<string> findInineary(vector<vector<string>> &tickets){
        vector<string> ret;

        string startNode = "JFK";
        map<string, vector<string>> graph;
        map<string, int> outdegree;

        for(auto e:tickets){
            graph[e[0]].push_back(e[1]);
            outdegree[e[0]]++;
        }

        for(auto &g: graph){
            sort(g.second.begin(), g.second.end(), greater<string>());
        }

        findPath(startNode, ret, graph, outdegree);
        return ret;
    }
};
int main()
{
    int n;cin>>n;
    vector<vector<string>> vvs;
    Solution sol;
    for(int i=0; i<n; ++i){
        string a, b;cin>>a>>b;
        vvs.push_back({a, b});
    }

    vector<string> ret = sol.findInineary(vvs);
    for(auto v: ret){
        cout << v << " ";
        if(v == ""){
            cout << 1 << " ";
        }
    }
    cout << endl;

    return 0;
}  