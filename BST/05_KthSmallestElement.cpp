// lc - 230
// tc - O(N)
// sc - O(h) , where h is the height of the tree.

class Solution {
public:
    void findKthNode(TreeNode* root, int& k, int& ans) {

        if (root == NULL) {
            return;
        }

        // left recursive call
        findKthNode(root->left, k, ans);

        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }

        findKthNode(root->right, k, ans);

        return;
    }
    int kthSmallest(TreeNode* root, int k) {

        // edge-case
        if (root == NULL) {
            return -1;
        }

        int ans = 0;

        findKthNode(root, k, ans);

        return ans;
    }
};
