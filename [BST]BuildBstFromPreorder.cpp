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
    TreeNode* buildBST(TreeNode* root , int& data){
        if(root == NULL){
            TreeNode* root = new TreeNode(data);
            return root;
        }

        if(data < root->val){
            root->left = buildBST(root->left,data);
        }else{
            root->right =buildBST(root->right,data);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        int n = preorder.size();
        if(n == 0) return root;
        root = new TreeNode(preorder[0]);
        for(int i = 1 ; i < n ;i++){
         root = buildBST(root,preorder[i]);
        }

        return root;
        
    }
};
