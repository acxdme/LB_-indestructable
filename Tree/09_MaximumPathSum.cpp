// lc- 124
// tc - O(N)
// sc - O(h) , h :  height of the binary tree

class Solution {
public:
    int getMaxPathSum(TreeNode* root, int sum, int& maxSum) {
        // base-case
        if (root == NULL) {
            return 0;
        }

        // left sub-tree sum
        int leftSum = getMaxPathSum(root->left, sum, maxSum);
        // right sub-tree sum
        int rightSum = getMaxPathSum(root->right, sum, maxSum);

        // current sum value, i.e max of node val , node val + max from left or right
        int currSum = max(root->val, root->val + max(leftSum, rightSum));

        // current maximum value
        int currMax = max(currSum, root->val + leftSum + rightSum);
        // update maxSum
        maxSum = max(maxSum, currMax);

        // pass the current sum
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

