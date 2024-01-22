// lc - 98
// tc : O(N)
// sc : O(h) , where h is the height of the tree.

class Solution {
public:
    bool checkBST(TreeNode* root, long long int& mini, long long int& maxi) {
        // base-case
        if (root == NULL)
            return true;

        // check data
        if (root->val > mini && root->val < maxi) {
            long long int rootData = root->val;
            bool leftAns = checkBST(root->left, mini, rootData);

            bool rightAns = checkBST(root->right, rootData, maxi);

            return (leftAns && rightAns);
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {

        long long int maxi = pow(2, 32);
        long long int mini = -pow(2, 32);
        bool result = checkBST(root, mini, maxi);

        return result;
    }
};
