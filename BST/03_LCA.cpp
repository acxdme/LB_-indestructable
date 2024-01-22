// lc- 235
// tc : O(log N) , average time complexity
// sc : O(h) , height of the BST

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return root;

        // case -1
        if (root->val < p->val && root->val < q->val) {
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            return right;
        }
        // case -2
        if (root->val > p->val && root->val > q->val) {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            return left;
        }
        // case-3 & case -4

        return root;
    }
};
