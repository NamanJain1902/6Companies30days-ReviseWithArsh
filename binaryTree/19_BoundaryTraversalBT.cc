/************************************************************

  Following is the Binary Tree node structure:

  template <typename T>
  class TreeNode {
  public :
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(T data) {
  this -> data = data;
  left = NULL;
  right = NULL;
  }

  ~TreeNode() {
  if(left)
  delete left;
  if(right)
  delete right;
  }
  };

 ************************************************************/

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ret;
    vector<int> endv;
    // hlevel -> (idx, vlevel, val) sorted by idx
    // 
    map<int, vector<vector<int>> > m;
    queue<pair<TreeNode*, vector<int>>> q;
    int last_level;
    while(!q.empty()) {
        int n = q.size();
        int startIdx = q.front().second;
        for(int i=0; i<n; ++i) {
            TreeNode *node = q.front().first;
            int idx = q.front().second[0] - startIdx;
            int hlevel = q.front().second[1];
            int vlevel = q.front().second[2];
            q.pop();

            if(hlevel > last_level) last_level = hlevel;
            if(idx == 1) ret.push_back(node->data);
            //             if(idx == n-1) endv.push_back(node->data);

            //             if(idx !=1 and idx!=n-1){
            m[level].push_back({idx, vlevel, node->val});
            //             }

            if(node->left) q.push({node->left, {2*idx, hlevel+1, vlevel-1}});
            if(node->right) q.push({node->right, {2*idx+1, hlevel+1, vlevel+1}});
        }        
    }

    if(!ret.empty()) ret.pop_back();

    int last_idx;
    int last_vlevel;
    for(auto itr=m.rbegin(); itr!=m.rend(); ++itr) {
        if(*itr.first == last_level) {
            for(auto y: *itr.second){
                for(auto x: y) {
                    ret.push_back(x[2]);
                    last_idx = x[0];
                    last_vlevel = x[1];
                }
            }
        } else {
            if(last_idx > 0) last_idx--;
            int lvl = *itr.first
                vector<int> temp = *itr.second;


            for(int i=0; i<temp.size(); ++i){
                if(temp[i][])
            }

        }
    }

    return ret;
}
