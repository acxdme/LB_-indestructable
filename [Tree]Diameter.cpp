/*
  Get clarity from the question as to what is considered height , # of nodes or # of edges.
*/
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int ans = 1+ max(height(root->left) , height(root->right));

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        // diameter of left subtree
        int a = diameterOfBinaryTree(root->left);
        // diameter of right subtree
        int b = diameterOfBinaryTree(root->right);
        //height of root's left + height of root's right (including the root)
        int c = height(root->left)  + height(root->right);
        
        // ans is maximum of option a , b and c.
        int ans = max(a,max(b,c));

        return ans;
    }
};
