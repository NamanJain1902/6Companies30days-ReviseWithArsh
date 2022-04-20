#include<bits/stdc++.h>
using namespace std;


vector<int> parent, ranks;
int find(int child) {
    while(child != parent[child]){
        parent[child] = parent[parent[child]];
        child = parent[child];
    }
    return child;
    // if(child == parent[child]) {
    //     return child;
    // }
    // return parent[child] = find(parent[child]);
}

void _union(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);

    if(rootA == rootB) return;

    if(rootA != rootB) {
        if(ranks[rootA] > ranks[rootB]) {
            parent[rootB] = rootA;
        } else if(ranks[rootB] < ranks[rootA]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            ranks[rootB] += 1;
        }
    }
}

bool connected(int A, int B) {
    return find(A) == find(B);
}


class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        count = sz;
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    /* After finding the root node, we can update the parent node of all 
    traversed elements to their root node. When we search for the root node 
    of the same element again, we only need to traverse two elements to find 
    its root node */
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return; // => connected

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootX] = rootY;
                rank[rootY] += 1;
            }
        }
        count--;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    //getters
    vector<int> get_root(){
        return root;
    }
    vector<int> get_rank(){
        return rank;
    }
    int get_count(){
        return count;
    }

    void print_root(){
        for(auto x: root){
            cout << x << ' ';
        }
        puts("");
    }
    void print_rank(){
        for(auto x: rank){
            cout << x << ' ';
        }
        puts("");
    }

    string solve(string s){
        int n = s.length();
        map<int, string> m;
        for(int i=0; i<n; i++){      //adding the char one by one in map corresponding to root
            int rt  = find(i);
            root[i] = rt;
            m[rt]   += s[i];
        }
        for(auto x: m){
            cout << x.first << " -> "  << x.second << "\n\n";
        }
        if(count==1){             //if the whole graph is connected, simply return string after sorting
            sort(s.begin(), s.end());
            return s;
           
        }
        
        for(auto pairs:m){           //if whole graph is not completely connected, sort the char in disconnected graphs
            int i=pairs.first;
            string s=pairs.second;
            sort(s.begin(), s.end(), greater<char>());
            m[i]=s;
        }
        
        for(int i=0; i<n; i++){     //storing the back into the string
            int root = find(i);
            s[i]     = m[root].back();
            m[root].pop_back();
        }
        return s;
    }
private:
    vector<int> root;
    vector<int> rank;
    int count;
};
int main()
{
    string s;cin>>s;
    int n = s.length();

    UnionFind UF(n);

    parent.resize(n);
    ranks.resize(n, 1);

    iota(parent.begin(), parent.end(), 0);

    int x, y;
    while(cin >> x >> y){
        UF.unionSet(x, y);
        _union(x, y);
    }


    // vector<pair<int, string>> groups(n);
    unordered_map<int, string> groups(n);
    for(int i=0; i<n; ++i){
        // groups[parent[find(i)]].push_back(i);
        groups[parent[find(i)]] += s[i];
    }

    for(auto item: umap){
        int idx = item.first;
        string ss = item.second;
        sort(ss.begin(), ss.end());
        groups[idx] = ss;
    }


    // for(auto v: groups){
    //     for(auto x: v){
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }
    for(int i=0; i<groups.size(); ++i){
        cout << i << " ";
        for(int j=0; j<groups[i].size();  ++j){
            cout << groups[i][j] << ' ';
        }
        cout << endl;
    }
    // string ret;
    // for(auto x: groups){
    //     if(x.size() > 0){
    //         string tmp;
    //         for(auto idx: x){
    //             tmp += s[idx];
    //         }
    //         sort(tmp.begin(), tmp.end());
    //         ret += tmp;
    //     }
    // }
    
    cout << "OP " << s << endl;
    cout << "UF " << UF.solve(s) << endl;
    // cout << "MN " << ret << "\n";    

    return 0;
}



class UnionFind{
 
public:
    
    UnionFind(int n): root_(vector<int>(n)), rank_(n, 1), count_(n){
        for (int i = 0;  i < n; ++i){
            root_[i] = i; 
        }
    }
    
    int find(int x){    
        
        if (x == root_[x]){
            return x;
        }
        
        return root_[x] = find(root_[x]);
    }
    
    void unionSet(int x, int y){
        
        int root_x = find(x);
        int root_y = find(y);
        
        if (root_x == root_y){
            return; 
        }
        
        if (rank_[root_x] < rank_[root_y]){
            root_[root_x] = root_y;
        } else if (rank_[root_x] > rank_[root_y]){
            root_[root_y] = root_x;
        } else {
            root_[root_y] = root_x;
            ++rank_[root_x];
        }
        
        --count_;
    }
        
    int getCount(){
        return count_;
    }
    
    int isConnected(int x, int y){
        return find(x) == find(y);
    }
    
 private:
    
    vector<int> root_;
    vector<int> rank_;
    int count_;
    
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        UnionFind union_find(s.length());
        
        for (const auto& paired: pairs){
            union_find.unionSet(paired[0], paired[1]);
        }
        
        const int m = union_find.getCount();
        vector<string> components(s.length());
        
        for (int idx=0; idx < s.size(); ++idx){
            int root_idx = union_find.find(idx);    // s and roots are of same size 
            components[root_idx].push_back(s[idx]);
        }
        
        for (auto& component: components){
            sort(component.begin(), component.end(), greater<char>{});
        }
                 
        string result{""};         
        for (int idx=0; idx < s.size(); ++idx){
            int root_idx = union_find.find(idx);
            auto& component = components[root_idx];
            result.push_back(component.back());
            component.pop_back();
        }    
        
        return result;
        
    }
};
