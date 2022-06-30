class Solution {
public:
    bool solve(TreeNode * r1, TreeNode * r2) {    
        if(r1 == NULL && r2 == NULL)
            return true; 

        else if(r1 == NULL || r2 == NULL || r1->val != r2->val)
            return false; 
        
        return (solve(r1->left, r2->right) && solve(r1->right, r2->left));
    }
    
    bool isSymmetric1(TreeNode* root) 
    {
        return solve(root->left, root->right);     
    }
    
    
    bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*> pending({ root->left, root->right });

		while (!pending.empty()) {
			TreeNode* l = pending.front();
			pending.pop();
			TreeNode* r = pending.front();
			pending.pop();

			if (!l && r || l && !r) return false;
			if (l) {
				if (l->val != r->val) return false;
				
                pending.push(l->left);
				pending.push(r->right);
				pending.push(l->right);
				pending.push(r->left);
			}
		}
		return true;
	}
    
};
// class Solution {
// public:
//     void preorder(TreeNode *root, vector<int> &v){
//         if(!root) return;
//         v.push_back(root->val);
//         preorder(root->left, v);
//         preorder(root->right, v);
//     }
//     void postorder(TreeNode *root, vector<int> &v){
//         if(!root) return;
//         postorder(root->left, v);
//         postorder(root->right, v);
//         v.push_back(root->val);
//     }
//     void inorder(TreeNode *root, vector<int> &v){
//         if(!root) return;
//         inorder(root->left, v);
//         v.push_back(root->val);
//         inorder(root->right, v);
//     }
//     bool isSymmetric(TreeNode* root) {
//         if(!root) return true;
//         vector<int> lt, rt;
//         inorder(root->left, lt);
//         inorder(root->right, rt);
//         reverse(rt.begin(), rt.end());
//         // for(auto x: lt)cout<<x<<" ";
//         // cout<<endl;
//         // for(auto x: rt)cout<<x<<" ";
       
//         if(lt.size() == rt.size()) {
//             for(int i=0; i<lt.size(); ++i) {
//                 if(lt[i]!=rt[i]) return false;
//             }
//             return true;
//         } 
        
//         return false;
//     }
// };

