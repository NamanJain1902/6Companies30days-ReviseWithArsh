// Prefix Sum
class Solution {
public:
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix_xor(n);
        prefix_xor[0] = arr[0];
        for(int i=1; i<n; ++i){
            prefix_xor[i] = prefix_xor[i-1] ^ arr[i]; 
        }
        /*
            1  2   6   14 
             1^3 2^4  6^8
             001 010 0110
             011 100 1000
        */
        
        // 1 ^ 3 ^ 4 ^ 1
        vector<int> ret;
        for(auto x: queries){
            int l = x[0];
            int r = x[1];
            
            int valr = prefix_xor[r];
            if(l > 0) {
                ret.push_back(valr ^ prefix_xor[l-1]);
            } else {
                ret.push_back(valr);
            }
        }
        
        return ret;
    }
};


// Segment Tree
class Solution {

public:
    void buildTree(vector<int> &arr, int *tree, int treeNode, int l, int r) {
        if(l == r) {
            tree[treeNode] = arr[l];
            return; 
        }
        int mid = l + (r - l) / 2;
        buildTree(arr, tree, 2*treeNode,  l, mid);
        buildTree(arr, tree, 2*treeNode+1, mid+1, r);
        tree[treeNode] = tree[2*treeNode] ^ tree[2*treeNode+1];
    }

    int query(int *tree, vector<int> &arr, int l, int r, int &start, int &end, int treeNode) {
        // outside range
        if(r < start or l > end) return 0;

        // completely inside range
        if(start <= l and r <= end) return tree[treeNode];

        // partially inside and partially outside
        int mid = l + (r - l) / 2;
        int lt = query(tree, arr, l, mid, start, end, 2*treeNode);
        int rt = query(tree, arr, mid+1, r, start, end, 2*treeNode+1);
        return lt ^ rt;
    }

    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        int tree[4*n];
        buildTree(arr, tree, 1, 0, n-1);
        vector<int> ret;
        
        for(auto x: queries) {
            ret.push_back(query(tree, arr, 0, n-1, x[0], x[1], 1));
        }
        
        return ret;
    }

};


// Sqrt Decomposition
