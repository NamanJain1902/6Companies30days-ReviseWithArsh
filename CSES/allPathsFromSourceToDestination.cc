class Solution {
public:
    vector<vector<int>> paths;
    int n;
    int dest;
    vector<int> visited;
    void dfs(vector<vector<int>> &graph, int node, vector<int> cpath) {
        
        if(node == dest) {
            paths.push_back(cpath);
            return;
        }
        
        visited[node] = true;
                
        for(auto child: graph[node]) {
            if(!visited[child]) {
                cpath.push_back(child);
                dfs(graph, child, cpath);
                cpath.pop_back();
            }
        }
        
        visited[node] = false;
    }
    struct Node{
        int node;
        vector<int> path;
    };
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        dest = n - 1;
        visited.resize(n, 0);
        
        queue<Node> q;
        q.push({0, {0}});
        while(!q.empty()) {
            int node = q.front().node;
            vector<int> cpath = q.front().path;
            q.pop();
            
            if(node == dest){
                paths.push_back(cpath);
                continue;
            }
            
            for(auto child: graph[node]) {
                if(!visited[child]) {
                    cpath.push_back(child);
                    q.push({child, cpath});
                    cpath.pop_back();
                }
            }
        }
        
        return paths;
    }
};