
struct BST{
  bool isbst=false;
  int mini=0, mx=0;
  BST(){}
  BST(bool isbst, int mini, int mx){
    this->isbst = isbst;
    this->mini = mini;
    this->mx = mx;
  }
};

BST isBst(Node* node){
  if(node == nullptr){
    return  BST(true, INT_MAX, INT_MIN);
  }

  BST lt = isBst(node->left);
  BST rt = isBst(node->right);

  BST mp;// = new BST();
  mp.isbst = lt.isbst && rt.isbst &&
              (node->data >= lt.mx && node->data <= rt.mini);
  
  mp.mini = min(node->data, min(lt.mini, rt.mini));
  mp.mx = max(node->data, max(lt.mx, rt.mx));
  return mp;
}


// O(N^2) because for every node we traverse it's subtree which happens in O(N).
int maxTree(Node* root) {
  return (root == NULL) ? INT_MIN : max(maxTree(root->left),  max(maxTree(root->right), root->data));
}
int minTree(Node *root) {
  return (root == NULL) ? INT_MAX : min(minTree(root->left), min(minTree(root->right), root->data));
}
bool Bst(Node* root){
  if(root == NULL) return true;
  if(root->left == NULL and root->right == NULL) return true;
  int lmx = maxTree(root->left);
  int rmin = minTree(root->right);
  // cout << lmx << " " << rmin << endl;
  
  if(root->data < lmx || root->data > rmin) return false; 
  
  Bst(root->left);
  Bst(root->right);

  return true;
}



class Solution {
    private:
        TreeNode* prev = nullptr;
    public:
        /* using property: inorder traversal of bst is sorted */
        bool inorder(TreeNode* root){

            if(!root) return true;

            if(!inorder(root->left)) return false;
            // }

            if(prev && root->val <= prev->val){
                // prev = root;    
                return false;
            }
            prev = root;
            // if(root->right)
            if(!inorder(root->right)) return false;

            return true;
        }
        
        bool isValidBST(TreeNode* root) {
            return inorder(root);
        }
};
