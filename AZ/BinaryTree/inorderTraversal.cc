class Solution {
public:
    // threaded binary tree data structure
    vector<int> inorderMorrisTraversal(TreeNode* root) {
        TreeNode* curNode = root;
        vector<int> nodes;

        while (curNode != NULL) {
            if (curNode -> left) {
               //ifa) Make current as right child of the rightmost node in current's left subtree
                TreeNode* predecessor = curNode -> left;
                while (predecessor -> right && predecessor -> right != curNode) //second condition used when reverting
                    predecessor = predecessor -> right;
                
                if ((predecessor -> right)==NULL) 
                {
                    predecessor -> right = curNode;
                    curNode = curNode -> left; //ifb) Go to this left child
                }
                else 
                {
                    //Revert back the changes
                    predecessor -> right = NULL;
                    nodes.push_back(curNode -> val);
                    curNode = curNode -> right;
                }
            }
            else {
                nodes.push_back(curNode -> val);  //ea)
                curNode = curNode -> right;  //eb)
            }
        }
        return nodes;
    }
};
