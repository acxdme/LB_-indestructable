// lc- 124
// tc - O(N)
// sc - O(h) , h :  height of the binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getMaxPathSum(TreeNode* root, int sum, int& maxSum) {
        // base-case
        if (root == NULL) {
            return 0;
        }

        // left sum
        int leftSum = getMaxPathSum(root->left, sum, maxSum);
        // right sum
        int rightSum = getMaxPathSum(root->right, sum, maxSum);

        // current sum including root->val
        int currSum = max(root->val, root->val + max(leftSum, rightSum));

        // currMax
        int currMax = max(currSum, root->val + leftSum + rightSum);
        // update maxSum
        maxSum = max(maxSum, currMax);

        // pass the max subTree sum + node->val to return
        return currSum;
    }

    int maxPathSum(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int sum = 0;
        int maxSum = INT_MIN;
        int temp = getMaxPathSum(root, sum, maxSum);

        return maxSum;
    }
};

