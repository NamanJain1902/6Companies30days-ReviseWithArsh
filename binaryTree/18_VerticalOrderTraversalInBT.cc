/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    class Pair{
        public:
        TreeNode *node;
        int vlevel;
        int hlevel;
        
        Pair(){}
        Pair(TreeNode* node, int v, int h){
            this->node = node;
            this->vlevel = v;
            this->hlevel = h;
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // queue<pair<TreeNode*, pair<int,int>>> q;
        queue<Pair> q;
        q.emplace(root, 0, 0);
        vector<vector<int>> vvi;
        map<int, map<int, vector<int>>> mv;
        // sort slblings in same vertical order
        while(!q.empty()) {
            // pair<TreeNode*, pair<int,int>> t = q.front();
            Pair t = q.front();
            q.pop();
            TreeNode* node = t.node;
            int h = t.hlevel;
            int v = t.vlevel;
            
            mv[v][h].push_back(node->val);
            // mv[t.second.first][t.second.second].push_back(t.first->val);
            
            if(node->left){
                q.emplace(node->left, v - 1, h + 1);
                // q.emplace(t.first->left, t.second.first - 1, t.second.second + 1);
            }
            if(node->right){
                q.emplace(node->right, v + 1, h + 1);
                // q.emplace(t.first->right, t.second.first + 1, t.second.second + 1);
            }
        }
        
        for(auto x: mv){
            vector<int> t;
            for(auto y: x.second){
                sort(y.second.begin(), y.second.end());
                t.insert(t.end(), y.second.begin(), y.second.end());
                // for(auto z:y.second){
                //     t.push_back(z);
                // }
            }
            // sort(x.second.begin()+1, x.second.end());
            
            vvi.push_back(t);
        }
        return vvi;
        
    }
};
