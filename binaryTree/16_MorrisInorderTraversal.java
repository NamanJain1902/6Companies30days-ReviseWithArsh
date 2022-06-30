/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class MorrisInorderTraversal {
    public static TreeNode getRightMostNode(TreeNode leftNode, TreeNode root) {
        if(leftNode.right==null) return leftNode;
        else if(leftNode.right == root) return leftNode;
        return getRightMostNode(leftNode.right, root);
    }
    
    public static List<Integer> morrisInorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        TreeNode curr = root;
        
        while(curr != null) {
            TreeNode leftNode = curr.left;
            if(leftNode == null) {
                res.add(curr.val);
                curr = curr.right;
            } else {
                TreeNode rightMostNode = getRightMostNode(leftNode, curr);
                
                if(rightMostNode.right == null) { // => we need to create thread
                    rightMostNode.right = curr;
                    curr = curr.left;
                } else { 
                    // => thread was already there and we are here to destroy it.
                    rightMostNode.right = null;
                    res.add(curr.val);
                    curr = curr.right;
                }
            }
        }
        return res;
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        return morrisInorderTraversal(root);
    }
}
